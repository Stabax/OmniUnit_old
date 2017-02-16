//Failure.hpp

/*
*Ces classes sont des classe abstraite
*servant de base pour les classes d'exception
*et pour les classes d'erreur
*(détaillants ou non les occurences)
*/

#ifndef FAILURE_H
#define FAILURE_H

#include "time.hpp"


class Failure
{
  //fonctions amies

public:
  //constructeurs
  Failure(std::string const &reason) noexcept;

  //destructeur
  virtual ~Failure();

  //méthodes statiques et swap
  
  //méthodes
  
  //mutateurs

  //accesseurs
   std::string getReason() const noexcept;
   std::string getDate() const noexcept;

  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)
  
protected:
  //attributs
  std::string _reason; //quelle est le problème ?
  std::string _date; //quand le problème est il survenu ?
};
//opérateurs non méthodes (+, ++, -, --, *, /, %, ==, !=, <, >, <=, >=, <<, >> )


////////////////////////////////////////////////////////////////////////////////////


class Detailed_Failure : virtual public Failure
{
  //fonctions amies

public:
  //constructeurs
  Detailed_Failure(std::string const &reason, std::string const &senderFunction, std::string const &senderFile) noexcept;

  //destructeur
  virtual ~Detailed_Failure();

  //méthodes statiques et swap
  
  //méthodes

  //mutateurs

  //accesseurs
  std::string getSenderFunction() const noexcept;
  std::string getSenderFile() const noexcept;

  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)

protected:
  //attributs
  std::string _senderFunction; //dans quelle fonction a été créé Le problème ?
  std::string _senderFile; //dans quel fichier CPP a été créé le problème ?
};
//opérateurs non méthodes (+, ++, -, --, *, /, %, ==, !=, <, >, <=, >=, <<, >> )
typedef Detailed_Failure DFailure;

#endif //FAILURE_H
