//GroupedKeyWordFile.hpp

/*
*Cette classe contient toutes les méthodes
*nécéssaires pour manipuler des fichiers et
*pour lire ou écrire dans ces fichiers et
*possède des parseurs pour chercher/modifier
*la valeur associée à un mot clé et
*possède des parseur pour chercher/modifier la valeur
*associée à un mot clé dans une structure
*/

/*
*Les goupes doivent être présentés comme suit:
*
*groupname{
*keyword1=xxx
*keyword2=xxx
*}
*
*/

#ifndef GROUPEDKEYWORDFILE_H_
#define GROUPEDKEYWORDFILE_H_

#include "KeyWordFile.hpp"

class GroupedKeyWordFile : public KeyWordFile
{
  //fonctions amies

public:
  //constructeurs
  GroupedKeyWordFile(std::string const &filePath = "");

  //destructeur
  virtual ~GroupedKeyWordFile();

  //méthodes statiques

  //accesseurs

  //mutateurs

  //méthodes
  //retournent les lignes où il y a les accolades ouvrantes et fermantes (inclues):
  unsigned findBegGroup(std::string const &group);
  unsigned findEndGroup(std::string const &group);
  bool groupExist(std::string const &group);
  unsigned findGKeyword(std::string const &group, std::string const &keyword, std::string const &parser = "=");
  bool gKeywordExist(std::string const &group, std::string const &keyword, std::string const &parser = "=");
  std::string readGKeywordValue(std::string const &group, std::string const &keyword, std::string const &parser = "=");
  void writeGKeywordValue(std::string const &group, std::string const &keyword, std::string const &text, std::string const &parser = "=");
  void addGKeyword(std::string const &group, std::string const &keyword, std::string const &text = "", std::string const &parser = "=");
  void removeGKeyword(std::string const &group, std::string const &keyword, std::string const &parser = "=");
  void addGroup(std::string const &name);
  void removeGroup(std::string const &name);

//opérateurs méthodes ( =, (), [], -> )

protected:
  //attributs
};
typedef GroupedKeyWordFile GFile;
//opérateurs non méthodes (+, ++, -, --, +=, -=, /=, *=, %=, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

#endif //GROUPEDKEYWORDFILE_H_
