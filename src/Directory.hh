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
//#include <sys/stat.h>

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
    Directory_Exception(std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath) noexcept;
    virtual const char* what() const noexcept {return "Unknown Directory Exception";}
  };

  class Directory_Path_Too_Long : public Directory_Exception
  {
    public:
    Directory_Path_Too_Long(std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath) noexcept;
    virtual const char* what() const noexcept {return "Directory Path exeeds PATH_MAX macro";}
  };

  class Directory_Permission_Denied : public Directory_Exception
  {
    public:
    Directory_Permission_Denied(std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath) noexcept;
    virtual const char* what() const noexcept {return "Permission to work with directory DENIED";}
  };

  class Directory_Unlinked : public Directory_Exception
  {
    public:
    Directory_Unlinked(std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath) noexcept;
    virtual const char* what() const noexcept {return "Directory is unlinked";}
  };

  class Directory_Unable_Access : public Directory_Exception
  {
    public:
    Directory_Unable_Access(std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath) noexcept;
    virtual const char* what() const noexcept {return "Unable to access directory";}
  };

  class Directory_Read_Only : public Directory_Exception
  {
    public:
    Directory_Read_Only(std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath) noexcept;
    virtual const char* what() const noexcept {return "Directory is read-only";}
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
