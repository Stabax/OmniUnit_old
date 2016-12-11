//File.hpp

/*
*Cette classe contient toutes les méthodes
*nécéssaires pour manipuler des fichiers et
*pour lire ou écrire dans ces fichiers
*/

#ifndef FILE_H_
#define FILE_H_

#include "Basic_File.hpp"
#include <vector>

class File : public Basic_File
{
  //fonctions amies

public:
  //constructeurs
  File();
  File(std::string const &filePath);

  //destructeur
  virtual ~File();

  //méthodes statiques

  //accesseurs

  //mutateurs

  //méthodes
  unsigned getLineCount();
  std::string readLine(unsigned const &Line);
  std::vector<std::string> readLine(unsigned const &line, unsigned n); //retourne n lignes a partir de line (inclu) (n = 0 : fin du fichier):  
  void removeLine(unsigned const &line, unsigned const &n = 1); //supprime n lignes a partir de line (inclu) (n = 0 : jusqu'à la fin du fichier):  
  void write(std::string const &text, unsigned n = 1); //remplace le texte déjà existant à partir de la ligne n (n et tout ce qui suit sont remplacés)
                                                       //n = 0 pour écrire sans rien remplacer à la fin du fichier
  void write(std::vector<std::string> const &text, unsigned const &n = 1);  
  void insert(std::string const &text, unsigned const &n); //insert le texte avant la ligne n
  void insert(std::vector<std::string> const &text, unsigned const &n);
  bool isSameContent(File &a);

  //opérateurs méthodes ( =, (), [], ->, +=, -=, /=, *=, %=)

protected:
  //attributs
};
//opérateurs non méthodes (+, ++, -, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )


#endif //FILE_H_
