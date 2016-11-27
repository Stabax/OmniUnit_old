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

//int mkdir(const char *path, mode_t mode); //sur posix => mode est le niveau de permission du dossier, sous forme octale (mode_t est unsigned int)
//int rmdir(const char *path);
//char* getcwd (char* path, size_t size); //retourne le chemin absolu du répertoire courrant
//int chdir(const char *path); //change le répertoire courrant, retourne -1 si le dossier n'existe pas ou si les permissions ne sont pas bonnes
//int chmod(const char *path, mode_t mode); //sur posix => change les permissions (sous forme octale) du fichier/répertoire

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
  static bool exist(std::string path); //retourne false si le répertoire n'existe pas ou que les droits ne permettent pas de s'y déplacer
  static char* getDirPath(); //retourne le chemin absolu du répertoire courrant
  static const char* firstDir(const std::string path); //retourne le répertoire d'un path le plus proche de la racine

  //accesseurs

  //mutateurs

  //méthodes
  void open();
  void close();
  bool exist(); //retourne false si le répertoire n'existe pas ou que les droits ne permettent pas de s'y déplacer
  bool create(mode_t mode);
  std::vector<std::string> getContent();
  std::vector<long> getId();
  bool remove();

  //opérateurs méthodes ( =, (), [], -> )
  Directory& operator=(Directory const &Other) = delete; 
  

  //attributs
  DIR *_dir;

};
//opérateurs non méthodes (+, ++, -, --, +=, -=, /=, *=, %=, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

#endif //DIRECTORY_H_
