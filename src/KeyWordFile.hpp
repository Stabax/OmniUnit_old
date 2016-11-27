//KeyWordFile.hpp

/*
*Cette classe contient toutes les méthodes
*nécéssaires pour manipuler des fichiers et
*pour lire ou écrire dans ces fichiers et
*possède des parseurs pour chercher/modifier
*les valeurs associées à des mots clés
*/

#ifndef KEYWORDFILE_H_
#define KEYWORDFILE_H_

#include "File.hpp"

class KeyWordFile : public File
{
  //fonctions amies

public:
  //constructeurs
  KeyWordFile(std::string const &path = "");

  //destructeur
  virtual ~KeyWordFile();

  //méthodes statiques

  //accesseurs

  //mutateurs

  //méthodes
  //parser représente les caratères qui séparent le KeyWord et la valaur qui lui est associée
  unsigned findKeyword(std::string const &keyword, std::string const &parser = "=");
  bool keywordExist(std::string const &keyword, std::string const &parser = "=");
  std::string readKeywordValue(std::string const &keyword, std::string const &parser = "=");
  void writeKeywordValue(std::string const &keyword, std::string const &text, std::string const &parser = "=");
  void addKeyword(std::string const &keyword, std::string const &text = "", std::string const &parser = "=");
  void removeKeyword(std::string const &keyword, std::string const &parser = "=");

  //opérateurs méthodes ( =, (), [], -> )

protected:
  //attributs
};
typedef KeyWordFile KWFile;
//opérateurs non méthodes (+, ++, -, --, +=, -=, /=, *=, %=, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

#endif //KEYWORDFILE_H_
