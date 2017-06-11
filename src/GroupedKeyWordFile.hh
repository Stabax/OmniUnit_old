//GroupedKeyWordFile.hh

/*
*Cette classe à sémentique d'entité est un fichier
*possédant des parseurs pour chercher/modifier
*la valeur associée à un mot clé dans une structure.
*/


#ifndef GROUPEDKEYWORDFILE_HH_
#define GROUPEDKEYWORDFILE_HH_

#include "KeyWordFile.hh"


namespace stb
{
//raison de changement : modification de la forme des groupes dans les fichiers

  class GroupedKeyWordFile : public KeyWordFile
  {
    //fonctions amies

  public:
    //constructeurs
    explicit GroupedKeyWordFile(std::string const& filePath);

    //destructeur

    //méthodes statiques

    //accesseurs

    //mutateurs

    //méthodes
    //retournent les lignes où il y a les accolades ouvrantes et fermantes (inclues):
    protected:
    unsigned BegEndGoup(std::vector<std::string> const& group, bool isBeg);
    public:
    unsigned findBegGroup(std::string const& group);
    unsigned findBegGroup(std::vector<std::string> const& group);
    unsigned findEndGroup(std::string const& group);
    unsigned findEndGroup(std::vector<std::string> const& group);



    template <typename T> //T est std::string OU std::vector<std::string>
    bool groupExist(T const& group)
    {
      if(findBegGroup(group) != 0 && findEndGroup(group) != 0)
        return true;
      return false;
    }



    template <typename T>
    unsigned findGKeyword(T const &group, std::string const &keyword, char parser)
    {
      if(isOpen())
      {
        if(groupExist(group))
        {
          unsigned counter = findBegGroup(group) + 1;
          unsigned end = findEndGroup(group);
          std::string lineContent;
          size_t keywordSize = keyword.size();
          while(counter < end)
          {
            lineContent = readLine(counter);
            if(lineContent.substr(0, keywordSize + 1) == keyword+parser) //+1 pour le parser
	            return (counter);
	          counter++;
          }
          return (0);
        }
        else
          return (0);
      }
      else
        throw File_Close("template <typename T> unsigned stb::GroupedKeyWordFile::findGKeyword(T const&, std::string const&, char)", __FILE__);
    }

    

    template <typename T>
    bool gKeywordExist(T const &group, std::string const &keyword, char parser)
    {
      if(findGKeyword(group, keyword, parser) != 0)
        return true;
      return false;
    }



    template <typename T>
    std::string readGKeywordValue(T const &group, std::string const &keyword, char parser)
    {
      if(isOpen())
      {
        if(groupExist(group))
	      {
	        unsigned line = findGKeyword(group, keyword, parser);
	        if(line != 0)
	        {
	          std::string content = readLine(line);
	          return content.substr(keyword.size() + 1, content.size());  //+1 pour le parser
	        }
	        else
	          return ("");
	      }
        else
	        return ("");
      }
      else
        throw File_Close("template <typename T> std::string stb::GroupedKeyWordFile::readGKeywordValue(T const&, std::string const&, char)", __FILE__);
    }



    template <typename T>
    void writeGKeywordValue(T const &group, std::string const &keyword, std::string const &text, char parser)
    {
      if(isOpen())
      {
        if(groupExist(group))
	      {
	        unsigned line = findGKeyword(group, keyword, parser);
	        removeLine(line);
	        insert(keyword + parser + text, line);
	      }
      }
    }



    template <typename T>
    void addGKeyword(T const &group, std::string const &keyword, char const &parser, std::string const &text)
    {
      if(! gKeywordExist(group, keyword, parser))
        insert(keyword + parser + text, findEndGroup(group));
    }



    template <typename T>
    void removeGKeyword(T const &group, std::string const &keyword, char parser)
    {
      removeLine(findGKeyword(group, keyword, parser));
    }



    template <typename T>
    void addGroup(T const &name)
    {
      if(! groupExist(name))
      {
        write(name + "{", 0);
        write("}" + name, 0);
      }
    }



    template <typename T>
    void removeGroup(T const &name)
    {
      removeLine(findBegGroup(name), findEndGroup(name) - findBegGroup(name) + 1);
    }

  //opérateurs méthodes ( =, (), [], ->, +=, -=, /=, *=, %=)

  protected:
    //attributs
  };
  typedef GroupedKeyWordFile GFile;
  typedef GroupedKeyWordFile GKWFile;
  //opérateurs non méthodes (+, ++, -, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

}//namespace

#endif //GROUPEDKEYWORDFILE_HH_
