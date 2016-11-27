//Failure.hpp

/*
*Ces classes sont des classe abstraite
*servant de base pour les classes d'exception
*et pour les classes d'erreur
*(détaillants ou non les occurences)
*/

#ifndef FAILURE_H_
#define FAILURE_H_

#include "time.hpp"


class Failure
{
  //fonctions amies

public:
  //constructeurs
  Failure(std::string const &reason, std::string const &path) noexcept;

  //destructeur
  virtual ~Failure();

  //méthodes statiques et swap
  
  //méthodes
  virtual void log() const noexcept = 0; //log la failure dans un fichier
                                         //virtuelle pure car cette classe n'a pas a être instanciée
  //mutateurs
  void setLogFilePath(std::string const& path) noexcept;

  //accesseurs
  const char* getReason() const noexcept;
  const char* getDate() const noexcept;

  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)
  
protected:
  //attributs
  std::string _reason; //quelle est le problème ?
  std::string _logFilePath; //dans quel fichier ce problème sera loggé ?
  std::string _date; //quand le problème est il survenu ?
};
//opérateurs non méthodes (+, ++, -, --, *, /, %, ==, !=, <, >, <=, >=, <<, >> )





class Detailed_Failure : virtual public Failure
{
  //fonctions amies

public:
  //constructeurs
  Detailed_Failure(std::string const &reason, std::string const &senderFunction, std::string const &senderFile, std::string const &path) noexcept;

  //destructeur
  virtual ~Detailed_Failure();

  //méthodes statiques et swap
  
  //méthodes
  virtual void printDetails() const noexcept = 0; //virtuelle pure car cette classe n'a pas a être instanciée

  //mutateurs

  //accesseurs
  const char* getFunction() const noexcept;
  const char* getFile() const noexcept;

  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)

protected:
  //attributs
  std::string _senderFunction; //dans quelle fonction a été créé Le problème ?
  std::string _senderFile; //dans quel fichier CPP a été créé le problème ?
};
//opérateurs non méthodes (+, ++, -, --, *, /, %, ==, !=, <, >, <=, >=, <<, >> )
typedef Detailed_Failure DFailure;

#endif //FAILURE_H_
