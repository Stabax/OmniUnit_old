//File.hh

/*
*Cette classe à sémentique d'entité permet de
*manipuler des fichiers et leur contenu, ligne par ligne
*(lecture et écriture)
*/


#ifndef FILE_HH_
#define FILE_HH_

#include <vector>

#include "Basic_File.hh"


namespace stb
{
  class File : public Basic_File
  {
  //raison de changement : modification de std::fstream
  
    //fonctions amies

  public:
    //constructeurs
    explicit File(std::string const &filePath);

    //destructeur

    //méthodes statiques

    //accesseurs

    //mutateurs

    //méthodes
    public:
    unsigned getLineCount();
    std::string readLine(unsigned Line);
    std::vector<std::string> readLine(unsigned line, unsigned nbLines); //retourne n lignes a partir de line (inclu) (n = 0 : fin du fichier)
    std::vector<std::string> readUntilEnd(unsigned line);
    
    void removeLine(unsigned line, unsigned nbLines = 1); //supprime n lignes a partir de line (inclu) (n = 0 : jusqu'à la fin du fichier)  
    void write(std::string const &text, unsigned n = 0); //remplace le texte déjà existant à partir de la ligne n (n et tout ce qui suit sont remplacés)                                                       //n = 0 pour écrire sans rien remplacer à la fin du fichier
    void write(std::vector<std::string> const &text, unsigned n = 0);    
    void insert(std::string const &text, unsigned n); //insert le texte avant la ligne n
    void insert(std::vector<std::string> const &text, unsigned n);
     
    bool isSameContent(File &a);

    //opérateurs méthodes ( =, (), [], ->, +=, -=, /=, *=, %=)

  protected:
    //attributs
  };
  //opérateurs non méthodes (+, ++, -, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

}//namespace

#endif //FILE_HH_
