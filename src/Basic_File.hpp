//Basic_File.hpp

/*
*Cette classe est une base pour manipuler des fichiers.
*Cette classe permet de controler la création/suppression,
*le nom et l'emplacement des fichiers.
*/

#ifndef BASIC_FILE_H_
#define BASIC_FILE_H_

#include "general_exceptions.hpp"
#include "Directory.hpp"
#include <fstream>
#include <iostream>

class Basic_File : public Directory_Item
{
  //fonctions amies

public:
  enum class state
  {
    good,
    //le fichier est fermé... erreur
    close,
    //le fichier est ouvert ... erreur
    open,
    //mauvais argument envoyé
    badarg,
    //le fichier n'a pas de chemin spécifié
    nopath,
    //autre erreur, la reqête n'a pas aboutie
    fail,
  };
  
  //constructeurs
  Basic_File();
  Basic_File(std::string const &path);
  Basic_File(Basic_File const &Other) = delete;

  //destructeur
  virtual ~Basic_File();

  //méthodes statiques
  static bool exist(std::string const &path);
  static bool create(std::string const& name, mode_t mode);
  static bool createAll(std::string const& name, mode_t mode);

  //accesseurs
  std::string getStateStr() const;
  state getState() const;
  int rdstate() const;

  //mutateurs

  //méthodes
  protected:
  void clearState();
  public:
  virtual bool exist() const;
  virtual bool isOpen() const;
  bool isGood() const;
  bool create(mode_t mode = m777); //(crée tout le chemin du fichier s'il n'existe pas) et crée le fichier
  bool createAll(mode_t mode = m777);
  void open(); //ouvre (et crée s'il n'existe pas) le fichier
  void open(std::string const& path);
  void close();
  void rename(std::string const &name);
  void move(std::string const &dir = "");
  void remove();

  //opérateurs méthodes ( =, (), [], -> )
  Basic_File& operator=(Basic_File const &Other) = delete; 

protected:
  //attributs
  std::fstream *_file;
  state _state;
};

typedef Basic_File::state fstate;
typedef Basic_File BFile;

//opérateurs non méthodes (+, ++, -, --, +=, -=, /=, *=, %=, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

#endif //BASIC_FILE_H_
