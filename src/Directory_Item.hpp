//Directory_Item.hpp

/*
*Cette classe à sémentique d'entité est une interface
*représentant tous ce que l'on peut trouver dans un répertoire
*(répertoire, son, executable, image, txt...)
*/


#ifndef DIRECTORY_ITEM_HPP_
#define DIRECTORY_ITEM_HPP_

#include <string>

#include "mode.h"


/*les modes pour POSIX:
*3 chiffres
*u g o (user group other)
*0 = aucun droit
*1 = execution, 2 = écriture, 3 = execution + écriture 
*4 = lecture, 5 = execution + lecture, 6 = lecture + écriture
*7 = tout les droits
*/


namespace stb
{

  mode_t getMode(mode_t mode);

  class Directory_Item
  {
    //fonctions amies

  public:
    //constructeurs
    explicit Directory_Item(std::string const& path);
    Directory_Item(Directory_Item const& Obj) = delete;

    //destructeur
    virtual ~Directory_Item();

    //méthodes statiques et swap
    static std::string extractDirPath(std::string const &path);

    //accesseurs
    std::string getPath() const;

    //mutateurs

    //méthodes
    virtual bool exist() const = 0;
    virtual bool isOpen() const = 0;
    std::string extractDirPath() const;

    //opérateurs méthodes ( =, (), [], ->, +=, -=, /=, *=, %=)
    Directory_Item& operator=(Directory_Item const& Obj) = delete;

  protected:
    //attributs
    std::string _path;
  };
  //opérateurs non méthodes (+, ++, -, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

}//namespace

#endif //DIRECTORY_ITEM_HPP_
