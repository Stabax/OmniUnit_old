//Directory.hpp

/*
*Cette classe permet la gestion des dossiers
*(création, accès et visualisation de leur contenu)
*/

#ifndef DIRECTORY_H_
#define DIRECTORY_H_

#include "Directory_Item.hpp"
#include <cerrno>
#include <dirent.h>
#include <unistd.h>
#include <vector>
#include <sys/stat.h>
#include "mode.hpp"

#if defined (_WIN16) || defined (_WIN32) || defined (_WIN64)
#define mkdir(path, mode) mkdir(path) //il n'y a pas de permissions sous windows
#endif //defined (_WIN16) || defined (_WIN32) || defined (_WIN64)

#ifndef PATH_MAX
#define PATH_MAX 1024 //compatibilité optimale pour MAC OS
#endif //PATH_MAX

class Directory : public Directory_Item
{
  //fonctions amies

public:
  //constructeurs
  Directory(std::string const& path = "");
  Directory(Directory const &Other) = delete;

  //destructeur
  ~Directory();

  //méthodes statiques et swap
  static bool exist(std::string const& path); //retourne false si le répertoire n'existe pas ou que les droits ne permettent pas de s'y déplacer
  static char* getDirPath(); //retourne le chemin absolu du répertoire courrant
  static std::string firstDir(std::string const& path); //retourne le nom du répertoire le plus proche de la racine d'un path
  static bool create(std::string const& path, mode_t mode);
  static bool createAll(std::string const& name, mode_t mode);

  //accesseurs

  //mutateurs

  //méthodes
  virtual bool exist() const; //retourne false si le répertoire n'existe pas ou que les droits ne permettent pas de s'y déplacer
  virtual bool isOpen() const;
  std::string extractDirPath() const = delete;
  void open();
  void close();
  bool create(mode_t mode);
  bool createAll(mode_t mode);
  std::vector<std::string> getContent();
  std::vector<long> getId();
  bool remove();

  //opérateurs méthodes ( =, (), [], ->, +=, -=, /=, *=, %=)
  Directory& operator=(Directory const &Other) = delete; 
  

  //attributs
  DIR *_dir;

};
typedef Directory Folder;
//opérateurs non méthodes (+, ++, -, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

#endif //DIRECTORY_H_
