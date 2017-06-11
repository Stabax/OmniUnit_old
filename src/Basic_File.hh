//Basic_File.hh

/*
*Cette classe à sémentique d'entitée
*permet de manipuler des fichiers
*sans utiliser leur contenu
*(création, suppression, renommage, déplacement, tests...).
*/


#ifndef BASIC_FILE_HH_
#define BASIC_FILE_HH_

#include <fstream>

#include "Directory_Item.hpp"
#include "Exception.hpp"


namespace stb
{

//========================================================================================
//========================================================================================

//DEFINITION DES EXCEPTIONS

  class File_Exception : public Exception
  {
    public:
    File_Exception(std::string const& senderFunction, std::string const& senderFile, std::string const& logPath = defaultLogPath) noexcept;
    virtual const char* what() const noexcept {return "Unknown file Exception";}
  };

  class File_Read_Only : public File_Exception
  {
    public:
    File_Read_Only(std::string const& senderFunction, std::string const& senderFile, std::string const& logPath = defaultLogPath) noexcept;
    virtual const char* what() const noexcept {return "File is read-only";}
  };

  class File_Read_Only_Mode : public File_Exception
  {
    public:
    File_Read_Only_Mode(std::string const& senderFunction, std::string const& senderFile, std::string const& logPath = defaultLogPath) noexcept;
    virtual const char* what() const noexcept {return "File is open in read-only mode";}
  };
  
  class File_Permission_Denied : public File_Exception
  {
    public:
    File_Permission_Denied(std::string const& senderFunction, std::string const& senderFile, std::string const& logPath = defaultLogPath) noexcept;
    virtual const char* what() const noexcept {return "Permission to work with file DENIED";}
  };

  class File_Unlinked : public File_Exception
  {
    public:
    File_Unlinked(std::string const& senderFunction, std::string const& senderFile, std::string const& logPath = defaultLogPath) noexcept;
    virtual const char* what() const noexcept {return "File is unlinked";}
  };

  class File_Invalid_Argument : public File_Exception
  {
    public:
    File_Invalid_Argument(std::string const& senderFunction, std::string const& senderFile, std::string const& logPath = defaultLogPath) noexcept;
    virtual const char* what() const noexcept {return "Invalid argument";}
  };

  class File_Exist : public File_Exception
  {
    public:
    File_Exist(std::string const& senderFunction, std::string const& senderFile, std::string const& logPath = defaultLogPath) noexcept;
    virtual const char* what() const noexcept {return "File already exists";}
  };

  class File_Open : public File_Exception
  {
    public:
    File_Open(std::string const& senderFunction, std::string const& senderFile, std::string const& logPath = defaultLogPath) noexcept;
    virtual const char* what() const noexcept {return "File is open and need to be close";}
  };

  class File_End_Reached : public File_Exception
  {
    public:
    File_End_Reached(std::string const& senderFunction, std::string const& senderFile, std::string const& logPath = defaultLogPath) noexcept;
    virtual const char* what() const noexcept {return "Cannot read requested line : end of file has been reached";}
  };

//========================================================================================
//========================================================================================



  class Basic_File : public Directory_Item
  {
  //raison de changement : modification de std::filesystem
  
    //fonctions amies

  public:  
    //constructeurs
    Basic_File(Basic_File const& Obj) = delete;
    explicit Basic_File(std::string const&path, mode_t mode = defaultMode);

    //destructeur
    virtual ~Basic_File();

    //méthodes statiques
    static bool exist(std::string const& path);
    static void create(std::string const& name, mode_t  mode = defaultMode);
    static void createAll(std::string const& name, mode_t mode = defaultMode);
    protected:
    static std::fstream* newFile(std::string const& path, mode_t mode = defaultMode); //permet d'initialiser l'attribut _file dans la liste d'initialisation du constructeur (create fait un chmod, indispensable)
    public:
    static mode_t getDefaultMode();
    static void setDefaultMode(mode_t mode);

    //accesseurs
    std::fstream::iostate getState() const;
    std::string getStateStr() const;
    bool good() const;
    bool eof() const;
    bool bad() const;
    bool fail() const;

    //mutateurs

    //méthodes
    virtual bool exist() const;
    virtual bool isOpen() const;
    void create(mode_t mode = defaultMode) const; //(crée tout le chemin du fichier s'il n'existe pas) et crée le fichier
    void createAll(mode_t mode = defaultMode) const;
    void open(mode_t mode = defaultMode); //ouvre (et crée s'il n'existe pas) le fichier
    void close();
    void rename(std::string const& name);
    void move(std::string const& dir);
    void remove() const;

    //opérateurs méthodes ( =, (), [], ->, +=, -=, /=, *=, %=, --, ++)
    Basic_File& operator=(Basic_File const& Obj) = delete;
    
  protected:
    //attributs
    std::fstream *_file;

    static mode_t defaultMode;
  };
  typedef Basic_File BFile;

  //opérateurs non méthodes (+, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

}//namespace

#endif //BASIC_FILE_HH_
