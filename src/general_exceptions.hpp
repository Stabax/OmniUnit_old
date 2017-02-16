//general_exceptions.hpp

/*
*Ces classes dérivent toutes de std::exception.
*Elles ont pour rôle de pouvoir créer des exceptions spécialisées
*dans chaque type de problème afin de mieux êtres traitées.
*/

#ifndef GENERAL_EXCEPTIONS_H
#define GENERAL_EXCEPTIONS_H

#include "Failure.hpp"
#include "GroupedKeyWordFile.hpp"
#include <exception>


//une simple exception stockant un string
class Exception : public std::exception, virtual public Failure
{
  //fonctions amies

public:
  //constructeurs
  Exception(std::string const& reason) noexcept;

  //destructeur
  virtual ~Exception();

  //méthodes statiques et swap
  
  //méthodes
  virtual const char* what() const noexcept;

  //mutateurs

  //accesseurs

  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)

protected:
  //attributs
};
//opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)


////////////////////////////////////////////////////////////////////////////////////


class Detailed_Exception : virtual public Exception, public Detailed_Failure
{
  //fonctions amies

public:
  //constructeurs
  Detailed_Exception(std::string const& reason, std::string const &senderFunction, std::string const &senderFile) noexcept;

  //destructeur
  virtual ~Detailed_Exception();

  //méthodes statiques et swap
  
  //méthodes

  //mutateurs

  //accesseurs

  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)

protected:
  //attributs
};
//opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)
typedef Detailed_Exception DException;


////////////////////////////////////////////////////////////////////////////////////


//Permet de charger le texte de l'exception depuis un fichier.
class Loaded_Exception : virtual public Exception
{
  //fonctions amies
  
public:
  //constructeurs
  //les constructeurs doivent passer les paramètres directement à Failure à cause de l'héritage virtuel de Failure dans Exception
  Loaded_Exception(unsigned const& line) noexcept;
  Loaded_Exception(std::string const& keyword, char const &parser = '=') noexcept;
  Loaded_Exception(std::string const& group, std::string const &keyword, char const &parser = '=') noexcept;
  
  Loaded_Exception(File& sourceFile, unsigned const &line) noexcept;
  Loaded_Exception(KWFile& sourceFile, std::string const& keyword, char const& parser = '=') noexcept; 
  Loaded_Exception(GFile& sourceFile, std::string const& group, std::string const& keyword, char const &parser = '=') noexcept;
  
  //destructeur
  virtual ~Loaded_Exception();
  
  //méthodes statiques et swap
  static void setDefaultSourceFilePath(std::string const &path);
protected:
  static std::string loadException(std::string const &path, unsigned const &line);
  static std::string loadKWException(std::string const &path, std::string const &keyword, char const &parser = '=');
  static std::string loadGKWException(std::string const &path, std::string const& group, std::string const& keyword, char const &parser = '=');

public:  
  //méthodes

  //mutateurs

  //accesseurs

  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)
  
protected:
  //attributs
  static std::string defaultSourceFilePath;
};
//opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)
typedef Loaded_Exception LException;


////////////////////////////////////////////////////////////////////////////////////


//permet d'envoyer une exception contenant plus d'informations
//en chargeant le texte de l'exception depuis un fichier.
class Detailed_Loaded_Exception : public Loaded_Exception, public Detailed_Exception
{
  //fonctions amies
  
public:
  //constructeurs
  Detailed_Loaded_Exception(unsigned const& line, std::string const &senderFunction, std::string const &senderFile) noexcept;
  Detailed_Loaded_Exception(std::string const& keyword, std::string const &senderFunction, std::string const &senderFile, char const &parser = '=') noexcept;
  Detailed_Loaded_Exception(std::string const& group, std::string const &keyword, std::string const &senderFunction, std::string const &senderFile, char const &parser = '=') noexcept;
  
  Detailed_Loaded_Exception(File& sourceFile, unsigned const &line, std::string const &senderFunction, std::string const &senderFile) noexcept;
  Detailed_Loaded_Exception(KWFile& sourceFile, std::string const &keyword, std::string const &senderFunction, std::string const &senderFile, char const &parser = '=') noexcept; 
  Detailed_Loaded_Exception(GFile& sourceFile, std::string const& group, std::string const& keyword, std::string const &senderFunction, std::string const &senderFile, char const &parser = '=') noexcept;
  
  //destructeur
  virtual ~Detailed_Loaded_Exception();
  
  //méthodes
  
  //mutateurs

  //accesseurs

  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)
  
protected:
  //attributs
};
//opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)
typedef Detailed_Loaded_Exception DLException;

#endif //GENERAL_EXCEPTIONS_H
