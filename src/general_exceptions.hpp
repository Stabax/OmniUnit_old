//general_exceptions.hpp

/*
*Ces classes dérivent toutes de std::exception.
*Elles ont pour rôle de pouvoir créer des exceptions spécialisées
*dans chaque type de problème afin de mieux êtres traitées.
*/

#ifndef GENERAL_EXCEPTIONS_H_
#define GENERAL_EXCEPTIONS_H_

#include "Failure.hpp"
#include <exception>


//une simple exception stockant un string
class StrException : public std::exception
{
  //fonctions amies

public:
  //constructeurs
  StrException(std::string const& reason) noexcept;

  //destructeur
  virtual ~StrException();

  //méthodes statiques et swap
  
  //méthodes
  virtual const char* what() const noexcept;

  //mutateurs

  //accesseurs

  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)

protected:
  //attributs
  std::string _reason;
};
//opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)
typedef StrException StrExcept;





//classe abstraite, présente uniquement pour stocker la variable defaultLogFilePath, commune à toutes les exceptions loggables
class Log_Exception : public std::exception, virtual public Failure
{
  //fonctions amies
  
public:
  //constructeurs
  Log_Exception(std::string const &reason) noexcept;
  Log_Exception(std::string const &reason, std::string const &logPath) noexcept;
  
  //destructeur
  virtual ~Log_Exception();
  
  //méthodes statiques et swap
  static void setDefaultLogFilePath(std::string const &path);

  //méthodes
  virtual const char* what() const noexcept = 0; //virtuelle pure car cette classe n'a pas à être instanciée
  
  //mutateurs
  
  //accesseurs
  
  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)
  
protected:
  //attributs
  static std::string defaultLogFilePath;
};
//opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)





//Permet de charger le texte de l'exception depuis un fichier.
class Loaded_Exception : virtual public Log_Exception
{
  //fonctions amies
  
public:
  //constructeurs
  Loaded_Exception(unsigned const &line) noexcept;
  Loaded_Exception(std::string const &keyword, std::string const &parser = "=") noexcept;
  Loaded_Exception(std::string const& group, std::string const &keyword, std::string const &parser = "=") noexcept;
  
  Loaded_Exception(std::string const &sourceFilePath, unsigned const &line) noexcept;
  //Loaded_Exception(std::string const &sourceFilePath, std::string &keyword, std::string const &parser = "=") noexcept; 
  //cette méthode n'est jamais appelée car Loaded_Exception(std::string const& group, std::string const &keyword, std::string const &parser = "=") noexcept; est déclaré avant et a les memes arguments. Il faudrait remplacer les variables "path" par des types PATH de la lib std (C++17)
  Loaded_Exception(std::string const &sourceFilePath, std::string const& group, std::string const& keyword, std::string const &parser = "=") noexcept;
  
  Loaded_Exception(unsigned const &line, std::string const &logPath) noexcept;
  //Loaded_Exception(std::string const &keyword, std::string const &logPath, std::string const &parser = "=") noexcept;
  //Loaded_Exception(std::string const& group, std::string const &keyword, std::string const &logPath, std::string const &parser = "=") noexcept;
  
  Loaded_Exception(std::string const &sourceFilePath, unsigned const &line, std::string const &logPath) noexcept;
  //Loaded_Exception(std::string const &sourceFilePath, std::string &keyword, std::string const &parser = "=") noexcept; 
  //cette méthode n'est jamais appelée car Loaded_Exception(std::string const& group, std::string const &keyword, std::string const &logPath, std::string const &parser = "=") noexcept; est déclaré avant et a les memes arguments. Il faudrait remplacer les variables "path" par des types PATH de la lib std (C++17)
  Loaded_Exception(std::string const &sourceFilePath, std::string const& group, std::string const& keyword, std::string const &logPath, std::string const &parser = "=") noexcept;
  
  //destructeur
  virtual ~Loaded_Exception();
  
  //méthodes statiques et swap
  static void setDefaultSourceFilePath(std::string const &path);
protected:
  static std::string loadException(std::string const &path, unsigned const &line);
  static std::string loadException(std::string const &path, std::string const &keyword, std::string const &parser);
  static std::string loadException(std::string const &path, std::string const& group, std::string const& keyword, std::string const &parser);

public:  
  //méthodes
  virtual const char* what() const noexcept;
  virtual void log() const noexcept;

  //mutateurs

  //accesseurs

  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)
  
protected:
  //attributs
  static std::string defaultSourceFilePath;
};
//opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)
typedef Loaded_Exception LException;
typedef Loaded_Exception LExcept;





//permet d'envoyer une exception contenant plus d'informations.
class Detailed_Exception : virtual public Log_Exception, public Detailed_Failure
{
  //fonctions amies
  
public:
  //constructeurs
  Detailed_Exception(std::string const &reason, std::string const &senderFunction, std::string const &senderFile) noexcept;
  Detailed_Exception(std::string const &reason, std::string const &senderFunction, std::string const &senderFile, std::string const &logPath) noexcept;
  
  //destructeur
  ~Detailed_Exception();
  
  //méthodes statiques et swap
  
  //méthodes
  virtual void printDetails() const noexcept;
  virtual const char* what() const noexcept;
  virtual void log() const noexcept;
  
  //mutateurs

  //accesseurs

  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)

protected:
  //attributs 
};
//opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)
typedef Detailed_Exception DException;
typedef Detailed_Exception DExcept;





//permet d'envoyer une exception contenant plus d'informations
//en chargeant le texte de l'exception depuis un fichier.
class Detailed_Loaded_Exception : public Loaded_Exception, public Detailed_Exception
{
  //fonctions amies
  
public:
  //constructeurs
  Detailed_Loaded_Exception(unsigned const &line) noexcept;
  Detailed_Loaded_Exception(std::string const &keyword, std::string const &parser = "=") noexcept;
  Detailed_Loaded_Exception(std::string const& group, std::string const &keyword, std::string const &parser = "=") noexcept;
  
  Detailed_Loaded_Exception(std::string const &sourceFilePath, unsigned const &line) noexcept;
  //Loaded_Exception(std::string const &sourceFilePath, std::string &keyword, std::string const &parser = "=") noexcept; 
  //cette méthode n'est jamais appelée car Loaded_Exception(std::string const& group, std::string const &keyword, std::string const &parser = "=") noexcept; est déclaré avant et a les memes arguments. Il faudrait remplacer les variables "path" par des types PATH de la lib std (C++17)
  Detailed_Loaded_Exception(std::string const &sourceFilePath, std::string const& group, std::string const& keyword, std::string const &parser = "=") noexcept;
  
  //destructeur
  virtual ~Detailed_Loaded_Exception();
  
  //méthodes
  virtual void printDetails() const noexcept;
  virtual const char* what() const noexcept;
  virtual void log() const noexcept;
  
  //mutateurs

  //accesseurs

  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)
  
protected:
  //attributs
};
//opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)
typedef Detailed_Loaded_Exception DLException;
typedef Detailed_Loaded_Exception DLExcept;

#endif //GENERAL_EXCEPTIONS_H_
