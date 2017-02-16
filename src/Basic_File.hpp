//Basic_File.hpp

/*
*Cette classe est une base pour manipuler des fichiers.
*Cette classe permet de controler la création/suppression,
*le nom et l'emplacement des fichiers.
*/

#ifndef BASIC_FILE_H_
#define BASIC_FILE_H_

#include "Directory.hpp"
#include <fstream>
#include <iostream>

class Basic_File : public Directory_Item
{
  //fonctions amies

public:  
  //constructeurs
  Basic_File();
  Basic_File(std::string const &path, mode_t mode = m755);
  Basic_File(Basic_File const &Other) = delete;

  //destructeur
  virtual ~Basic_File();

  //méthodes statiques
  static bool exist(std::string const &path);
  static bool create(std::string const& name, mode_t  mode = m755);
  static bool createAll(std::string const& name, mode_t mode = m777);
  protected:
  static std::fstream* newFile(std::string const& path, mode_t mode = m755); //permet d'initialiser l'attribut _file dans la liste d'initialisation du constructeur (create fait un chmod, indispensable)
  public:

  //accesseurs
  int getState() const;
  std::string getStateStr() const;

  //mutateurs

  //méthodes
  virtual bool exist() const;
  virtual bool isOpen() const;
  bool create(mode_t mode = m755) const; //(crée tout le chemin du fichier s'il n'existe pas) et crée le fichier
  bool createAll(mode_t mode = m755) const;
  bool open(mode_t mode = m777); //ouvre (et crée s'il n'existe pas) le fichier
  bool open(std::string const& path, mode_t mode = m755);
  bool close();
  bool rename(std::string const &name);
  bool move(std::string const &dir = "");
  virtual bool remove() const;

  //opérateurs méthodes ( =, (), [], ->, +=, -=, /=, *=, %=)
  Basic_File& operator=(Basic_File const &Other) = delete; 

protected:
  //attributs
  std::fstream *_file;
};
typedef Basic_File BFile;

//opérateurs non méthodes (+, ++, -, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

#endif //BASIC_FILE_H_
