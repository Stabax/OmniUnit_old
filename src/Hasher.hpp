//Hasher.hpp

/*
*Cette classe contient
*toutes les méthodes nécéssaires
*pour hasher des chaines de caractères
*/

#ifndef HASHER_H_
#define HASHER_H_

#include "conversion.hpp"
#include <string>
#include <vector>

class Hasher
{
  //fonctions amies

public:
  //constructeurs
  Hasher(std::string salt = "");
  
  //destructeur
  virtual ~Hasher();
  
  //méthodes statiques

  //accesseurs
  std::string getSalt() const;

  //mutateurs
  void setSalt(std::string salt);

  //méthodes
protected:
  void salting(std::string &text) const;
  void salting(std::vector<std::string> &text) const;
public:
  //retourne le nombre de caractère total:
  std::string hashTotalSize(std::string text) const;
  std::string hashTotalSize(std::vector<std::string> text) const;
  
  //met à la suite le nombre de charactère de chaque ligne:
  std::string hashLineSize(std::string text) const;
  std::string hashLineSize(std::vector<std::string> text) const;
  
  //additionne tout les charactères
  std::string hashTotalChar(std::string text) const;
  std::string hashTotalChar(std::vector<std::string> text) const;

  // additionne les charactères ligne par ligne et met les résultats à la suite:
  std::string hashLineChar(std::string text) const;
  std::string hashLineChar(std::vector<std::string> text) const;
    
  //sha256:
  std::string sha256(std::string text) const;
  std::string sha256(std::vector<std::string> text) const;
  
  //sha512:
  std::string sha512(std::string text) const;
  std::string sha512(std::vector<std::string> text) const;
  
protected:
  
  //opérateurs méthodes ( =, (), [], -> )

protected:
  //attributs
  std::string m_salt;
  
};
//opérateurs non méthodes (+, ++, -, --, +=, -=, /=, *=, %=, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

#endif //HASHER_H_
