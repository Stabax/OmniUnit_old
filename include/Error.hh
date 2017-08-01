//Error.hh

/*
*Ces classes à sémentique d'entité
*représentent des d'erreurs pouvant
*avoir lieu lors de l'execution du programme.
*/


#ifndef ERROR_HH_
#define ERROR_HH_

#include "Loggable.hpp"

namespace stb
{

  class Error
  {
    //fonctions amies
    
  public:    
    //constructeurs
    Error(Error const& Obj) = delete;
    explicit Error(std::string const& reason);

    explicit Error(unsigned const& line, std::string const& sourcePath = defaultSourcePath);
    explicit Error(std::string const& keyword, char const &parser, std::string const& sourcePath = defaultSourcePath);

    //destructeur
    virtual ~Error();

    //méthodes statiques et swap
  protected:
    static std::string loadReason(unsigned const &line, std::string const &path);
    static std::string loadReason(std::string const &keyword, char const &parser, std::string const &path);
  public:
    static void setDefaultSourcePath(std::string const &path);
    static std::string getDefaultSourcePath();

    //accesseurs
    std::string getDate() const;

    //mutateurs

    //méthodes
    virtual const char* err() const;
    
    //opérateurs méthodes ( =, (), [], ->, +=, -=, /=, *=, %=)
    Error& operator=(Error const& Obj) = delete;

  protected:
    //attributs
    std::string _reason; //quel est le problème ?
    std::string _date; //quand le problème est il survenu ?    

    static std::string defaultSourcePath;
  };
  
  //opérateurs non méthodes (+, ++, -, --, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )



  //////////////////////////////////////////////////////////////////////////



  class Detailed_Error : public Error
  {
    //fonctions amies

  public:
    //constructeurs
    explicit Detailed_Error(std::string const& reason, std::string const &senderFunction, std::string const &senderFile);

    explicit Detailed_Error(unsigned const& line, std::string const &senderFunction, std::string const &senderFile, std::string const& sourcePath = defaultSourcePath);
    explicit Detailed_Error(std::string const& keyword, std::string const &senderFunction, std::string const &senderFile, char const &parser, std::string const& sourcePath = defaultSourcePath);

    //destructeur

    //méthodes statiques et swap

    //accesseurs
    std::string getSenderFunction() const noexcept;
    std::string getSenderFile() const noexcept;

    //mutateurs

    //méthodes

    //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)

  protected:
    //attributs
    std::string _senderFunction; //dans quelle fonction a été créé Le problème ?
    std::string _senderFile; //dans quel fichier CPP a été créé le problème ?
  };
  typedef Detailed_Error DError;
  
  //opérateurs non méthodes (+, ++, -, --, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )



    //////////////////////////////////////////////////////////////////////////



  class Source;
  class Log;


  class Log_Error : public Error, public Loggable_Error
  {
    //fonctions amies
    
  public:
    //constructeur    
    explicit Log_Error(std::string const& reason, std::string const& logPath = defaultLogPath);
    explicit Log_Error(unsigned const& line);
    explicit Log_Error(std::string const& keyword, char const &parser);

    explicit Log_Error(unsigned const& line, file const& type, std::string const& path);
    explicit Log_Error(std::string const& keyword, char const &parser, file const& type, std::string const& path);

    explicit Log_Error(unsigned const& line, std::string const& sourcePath, std::string const& logPath);
    explicit Log_Error(std::string const& keyword, char const &parser, std::string const& sourcePath, std::string const& logPath);
    
    //destructeur
    
    //méthodes statiques et swap

  public:  
    //méthodes
    virtual void log() const;

    //mutateurs

    //accesseurs

    //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)
    
  protected:
    //attributs
  };
  typedef Log_Error LogError;
  
  //opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)



    //////////////////////////////////////////////////////////////////////////



  class Log_Detailed_Error : public Detailed_Error, public Loggable_Error
  {
  //fonctions amies

  public:
    //constructeurs
    explicit Log_Detailed_Error(std::string const& reason, std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath);
    explicit Log_Detailed_Error(unsigned const& line, std::string const &senderFunction, std::string const &senderFile);
    explicit Log_Detailed_Error(std::string const& keyword, std::string const &senderFunction, std::string const &senderFile, char const &parser);

    explicit Log_Detailed_Error(unsigned const& line, std::string const &senderFunction, std::string const &senderFile, file const& type, std::string const& path);
    explicit Log_Detailed_Error(std::string const& keyword, std::string const &senderFunction, std::string const &senderFile, char const &parser, file const& type, std::string const& path);

    explicit Log_Detailed_Error(unsigned const& line, std::string const &senderFunction, std::string const &senderFile, std::string const& sourcePath, std::string const& logPath);
    explicit Log_Detailed_Error(std::string const& keyword, std::string const &senderFunction, std::string const &senderFile, char const &parser, std::string const& sourcePath, std::string const& logPath);

    //destructeur

    //méthodes statiques et swap
    
    //méthodes
    virtual void log() const;

    //mutateurs

    //accesseurs

    //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)

  protected:
    //attributs
  };
  typedef Log_Detailed_Error LogDError;
  
  //opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)
  //opérateurs non méthodes (+, ++, -, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

}//namespace

#endif //ERROR_HH_
