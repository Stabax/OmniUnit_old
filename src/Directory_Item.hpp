//Directory_Item.hpp

/*
*Cette classe abstraite est une base
*représentant tout ce qu'on peut
*trouver dans un répertoire
*(répertoire, son, executable, image, txt...)
*/

#ifndef DIRECTORY_ITEM_H_
#define DIRECTORY_ITEM_H_

//#include <sys/stat.h>
#include <string>

/*les modes pour POSIX:
*3 chiffres
*u g o (user group other)
*0 = aucun droit
*1 = execution, 2 = écriture, 3 = execution + écriture 
*4 = lecture, 5 = execution + lecture, 6 = lecture + écriture
*7 = tout les droits
*/

mode_t getMode(short mode);

class Directory_Item
{
  //fonctions amies

public:
  //constructeurs
  Directory_Item(std::string const& path);
  Directory_Item(Directory_Item const& Obj) = delete;

  //destructeur
  virtual ~Directory_Item();

  //méthodes statiques et swap
  static std::string extractDirPath(std::string const &path);

  //accesseurs
  std::string getPath() const;

  //mutateurs
  bool setPath(std::string const& path);

  //méthodes
  virtual bool exist() const = 0;
  virtual bool isOpen() const = 0;
  bool isPathSet() const;
  virtual bool remove() const = 0;
  std::string extractDirPath() const;

  //opérateurs méthodes ( =, (), [], ->, +=, -=, /=, *=, %=)
  Directory_Item& operator=(Directory_Item const& Obj) = delete;

protected:
  //attributs
  std::string _path;
};
//opérateurs non méthodes (+, ++, -, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

#endif //DIRECTORY_ITEM_H_
