//KeyWordFile.hh

/*
*Cette classe à sémentique d'entité est un fichier
*possédant des parseurs pour chercher/modifier
*la valeur associée à un mot clé.
*/


#ifndef KEYWORDFILE_HH_
#define KEYWORDFILE_HH_

#include "File.hh"


namespace stb
{

  class KeyWordFile : public File
  {
    //fonctions amies

  public:
    //constructeurs
    explicit KeyWordFile(std::string const &path);

    //destructeur

    //méthodes statiques

    //accesseurs

    //mutateurs

    //méthodes
    //parser représente les caratères qui séparent le KeyWord et la valaur qui lui est associée
    std::string removeSpaces(std::string const& line, char parser);
    
    unsigned findKeyword(std::string const &keyword, char const &parser);
    bool keywordExist(std::string const &keyword, char const &parser);
    std::string readKeywordValue(std::string const &keyword, char const &parser);
    void writeKeywordValue(std::string const &keyword, std::string const &text, char const &parser);
    void addKeyword(std::string const &keyword, char const &parser, std::string const &text = "");
    void removeKeyword(std::string const &keyword, char const &parser);

    std::vector<std::string> readOpt(std::string const &keyword, char const &parser);
    void addOpt(std::string const &keyword, char const &parser, std::string const& opt);
    void removeOpt(std::string const &keyword, char const &parser, std::string const& opt = "");
    
    //opérateurs méthodes ( =, (), [], ->, +=, -=, /=, *=, %=)

  protected:
    //attributs
  };
  typedef KeyWordFile KWFile;
  //opérateurs non méthodes (+, ++, -, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

}//namespace

#endif //KEYWORDFILE_HH_
