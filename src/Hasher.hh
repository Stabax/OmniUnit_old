//Hasher.hh

/*
*Cette classe à sementique d'entité contient
*permet le hashage de chaines decaractères.
*/


#ifndef HASHER_HH_
#define HASHER_HH_

#include <string>

#include "conversion.h"


namespace stb
{

  class Hasher
  {
    //fonctions amies

  public:
    //constructeurs
    explicit Hasher(std::string salt = "");
    
    //destructeur
    
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

}//namespace

#endif //HASHER_HH_
