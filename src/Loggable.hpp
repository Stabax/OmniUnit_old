//Loggable.hpp

/*
*Cette classe abstraite sert de base
*pour toute autre classe ayant pour
*vocation à logger, voire enregistrer des données dans un fichier
*/

#ifndef LOGGABLE_H
#define LOGGABLE_H

#include <string>

class Loggable
{
  //fonctions amies

public:
  //constructeurs
  Loggable(std::string const& logPath = "");

  //destructeur
  virtual ~Loggable();

  //méthodes statiques et swap
  
  //méthodes
  virtual void log() const = 0;

  //mutateurs
  void setLogPath(std::string const& path);

  //accesseurs

  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)

protected:
  //attributs
  std::string _logPath;
};
//opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)

#endif //LOGGABLE_H
