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

  class GroupedKeyWordFile : public KeyWordFile
  {
    //fonctions amies

  public:
    //constructeurs
    explicit GroupedKeyWordFile(std::string const &filePath);

    //destructeur

    //méthodes statiques

    //accesseurs

    //mutateurs

    //méthodes
    //retournent les lignes où il y a les accolades ouvrantes et fermantes (inclues):
    unsigned findBegGroup(std::string const &group);
    unsigned findEndGroup(std::string const &group);
    bool groupExist(std::string const &group);
    
    unsigned findGKeyword(std::string const &group, std::string const &keyword, char const &parser);
    bool gKeywordExist(std::string const &group, std::string const &keyword, char const &parser);
    
    std::string readGKeywordValue(std::string const &group, std::string const &keyword, char const &parser);
    void writeGKeywordValue(std::string const &group, std::string const &keyword, std::string const &text, char const &parser);
    void addGKeyword(std::string const &group, std::string const &keyword, char const &parser, std::string const &text = "");
    void removeGKeyword(std::string const &group, std::string const &keyword, char const &parser);
    
    void addGroup(std::string const &name);
    void removeGroup(std::string const &name);

    std::vector<std::string> readGOpt(std::string const &group, std::string const &keyword, char const &parser);
    void addGOpt(std::string const &group, std::string const &keyword, char const &parser, std::string const& opt);
    void removeGOpt(std::string const &group, std::string const &keyword, char const &parser, std::string const& opt = "");

    std::vector<std::string> groupList();


  //opérateurs méthodes ( =, (), [], ->, +=, -=, /=, *=, %=)

  protected:
    //attributs
  };
  typedef GroupedKeyWordFile GFile;
  typedef GroupedKeyWordFile GKWFile;
  //opérateurs non méthodes (+, ++, -, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

}//namespace

#endif //GROUPEDKEYWORDFILE_HH_
