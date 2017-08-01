//Directory.hh

/*
*Cette classe à sémentique d'entitée
*permet la navigation au sein des dossiers
*ainsi que leur gestion
*(création, suppression, renommage, visualisation du contenu...)
*/


#ifndef DIRECTORY_HH_
#define DIRECTORY_HH_

#include <cerrno>
#include <dirent.h>
#include <unistd.h>
#include <vector>
#include <sys/stat.h>

#include "Directory_Item.hpp"
#include "Exception.hpp"


#if defined (_WIN16) || defined (_WIN32) || defined (_WIN64)
#define mkdir(path, mode) mkdir(path) //il n'y a pas de permissions sous windows
#endif //defined (_WIN16) || defined (_WIN32) || defined (_WIN64)

#ifndef PATH_MAX
#define PATH_MAX 1024 //compatibilité optimale pour MAC OS
#endif //PATH_MAX


namespace stb
{

  class Directory_Exception : public Exception
  {
    public:
    Directory_Exception(std::string const &reason, std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath) noexcept;
  };





  class Directory : public Directory_Item
  {
    //fonctions amies

  public:
    //constructeurs
    explicit Directory(std::string const& path = "");
    Directory(Directory const &Other) = delete;

    //destructeur
    virtual ~Directory();

    //méthodes statiques et swap
    static bool exist(std::string const& path); //retourne false si le répertoire n'existe pas ou que les droits ne permettent pas de s'y déplacer
    static char* getDirPath(); //retourne le chemin absolu du répertoire courrant
    static std::string firstDir(std::string const& path); //retourne le nom du répertoire le plus proche de la racine d'un path
    static bool create(std::string const& path, mode_t mode = m755);
    static bool createAll(std::string const& name, mode_t mode = m755);

    //accesseurs

    //mutateurs

    //méthodes
    virtual bool exist() const; //retourne false si le répertoire n'existe pas ou que les droits ne permettent pas de s'y déplacer
    virtual bool isOpen() const;
    std::string extractDirPath() const = delete;
    void open();
    void close();
    bool create(mode_t mode = m755);
    bool createAll(mode_t mode = m755);
    std::vector<std::string> getContent();
    std::vector<long> getId();

    //opérateurs méthodes ( =, (), [], ->, +=, -=, /=, *=, %=)
    Directory& operator=(Directory const &Other) = delete; 
    

    //attributs
    DIR *_dir;

  };
  typedef Directory Folder;
  //opérateurs non méthodes (+, ++, -, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

}//namespace

#endif //DIRECTORY_HH_
