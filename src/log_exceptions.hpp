//log_exceptions.hpp

/*
*Ces classes dérivent toutes des classes
*d'exceptions de la stblib. Elles donnent à ces
*dernières des méthodes pour être loggé dans des fichiers
*/

#ifndef LOG_EXCEPTIONS_H
#define LOG_EXCEPTIONS_H

#include "Loggable.hpp"
#include "general_exceptions.hpp"


//classe abstraite servant à definir l'attribut defaultLogPath
class Log_Exception_Base : public Loggable
{
//fonctions amies

public:
  //constructeurs
  Log_Exception_Base(std::string const& logPath = "") noexcept;

  //destructeur
  virtual ~Log_Exception_Base();

  //méthodes statiques et swap
  static void setDefaultLogPath(std::string const& logPath);
  
  //méthodes
  virtual void log() const noexcept = 0;

  //mutateurs

  //accesseurs

  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)

protected:
  //attributs
  static std::string defaultLogPath;
};
//opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)
typedef Log_Exception_Base LogExceptionB;


/////////////////////////////////////////////////////////////////////////////


class Log_Exception : public Exception, public Log_Exception_Base
{
//fonctions amies

public:
  //constructeurs
  Log_Exception(std::string const& reason, std::string const& logPath = defaultLogPath) noexcept;

  //destructeur
  virtual ~Log_Exception();

  //méthodes statiques et swap
  
  //méthodes
  virtual void log() const noexcept;

  //mutateurs

  //accesseurs

  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)

protected:
  //attributs
};
//opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)
typedef Log_Exception LogException;


/////////////////////////////////////////////////////////////////////////////


class Log_Detailed_Exception : public Detailed_Exception, public Log_Exception_Base
{
  //fonctions amies

public:
  //constructeurs
  Log_Detailed_Exception(std::string const& reason, std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath) noexcept;

  //destructeur
  virtual ~Log_Detailed_Exception();

  //méthodes statiques et swap
  
  //méthodes
  virtual void log() const noexcept;

  //mutateurs

  //accesseurs

  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)

protected:
  //attributs
};
//opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)
typedef Detailed_Exception LogDException;


/////////////////////////////////////////////////////////////////////////////


class Log_Loaded_Exception : public Loaded_Exception, public Log_Exception_Base
{
  //fonctions amies
  
public:
  //constructeurs
  //les constructeurs doivent passer les paramètres directement à Failure à cause de l'héritage virtuel de Failure dans Exception
  Log_Loaded_Exception(unsigned const& line, std::string const& logPath = defaultLogPath) noexcept;
  Log_Loaded_Exception(std::string const& keyword, std::string const& logPath = defaultLogPath, char const &parser = '=') noexcept;
  Log_Loaded_Exception(std::string const& group, std::string const &keyword, std::string const& logPath = defaultLogPath, char const &parser = '=') noexcept;
  
  Log_Loaded_Exception(File& sourceFile, unsigned const &line, std::string const& logPath = defaultLogPath) noexcept;
  Log_Loaded_Exception(KWFile& sourceFile, std::string &keyword, std::string const& logPath = defaultLogPath, char const &parser = '=') noexcept; 
  Log_Loaded_Exception(GFile& sourceFile, std::string const& group, std::string const& keyword, std::string const& logPath = defaultLogPath, char const &parser = '=') noexcept;
  
  //destructeur
  virtual ~Log_Loaded_Exception();
  
  //méthodes statiques et swap

public:  
  //méthodes
  virtual void log() const noexcept;

  //mutateurs

  //accesseurs

  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)
  
protected:
  //attributs
};
//opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)
typedef Log_Loaded_Exception LogLException;


/////////////////////////////////////////////////////////////////////////////


class Log_Detailed_Loaded_Exception : public Detailed_Loaded_Exception, public Log_Exception_Base
{
  //fonctions amies
  
public:
  //constructeurs
  //les constructeurs doivent passer les paramètres directement à Failure à cause de l'héritage virtuel de Failure dans Exception
  Log_Detailed_Loaded_Exception(unsigned const& line, std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath) noexcept;
  Log_Detailed_Loaded_Exception(std::string const& keyword, std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath, char const &parser = '=') noexcept;
  Log_Detailed_Loaded_Exception(std::string const& group, std::string const &keyword, std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath, char const &parser = '=') noexcept;
  
  Log_Detailed_Loaded_Exception(File& sourceFile, unsigned const &line, std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath) noexcept;
  Log_Detailed_Loaded_Exception(KWFile& sourceFile, std::string &keyword, std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath, char const &parser = '=') noexcept; 
  Log_Detailed_Loaded_Exception(GFile& sourceFile, std::string const& group, std::string const& keyword, std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath, char const &parser = '=') noexcept;
  
  //destructeur
  virtual ~Log_Detailed_Loaded_Exception();
  
  //méthodes statiques et swap

public:  
  //méthodes
  virtual void log() const noexcept;

  //mutateurs

  //accesseurs

  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)
  
protected:
  //attributs
};
//opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)
typedef Log_Detailed_Loaded_Exception LogDLException;

#endif //LOG_EXCEPTIONS_H
