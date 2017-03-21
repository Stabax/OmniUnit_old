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
  class File_Close : public File_Exception
  {
    public:
    File_Close(std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath) noexcept;
    virtual const char* what() const noexcept {return "File is close";}
  };




  
  class File : public Basic_File
  {
    //fonctions amies

  public:
    //constructeurs
    explicit File();
    explicit File(std::string const &filePath);

    //destructeur

    //méthodes statiques

    //accesseurs

    //mutateurs

    //méthodes
    unsigned getLineCount();  
    std::string readLine(unsigned const &Line);
    std::vector<std::string> readLine(unsigned const &line, unsigned n); //retourne n lignes a partir de line (inclu) (n = 0 : fin du fichier)  
    void removeLine(unsigned const &line, unsigned const &n = 1); //supprime n lignes a partir de line (inclu) (n = 0 : jusqu'à la fin du fichier)  
    void write(std::string const &text, unsigned n = 0); //remplace le texte déjà existant à partir de la ligne n (n et tout ce qui suit sont remplacés)                                                       //n = 0 pour écrire sans rien remplacer à la fin du fichier
    void write(std::vector<std::string> const &text, unsigned const &n = 0);    
    void insert(std::string const &text, unsigned const &n); //insert le texte avant la ligne n
    void insert(std::vector<std::string> const &text, unsigned const &n);  
    bool isSameContent(File &a);

    //opérateurs méthodes ( =, (), [], ->, +=, -=, /=, *=, %=)

  protected:
    //attributs
  };
  //opérateurs non méthodes (+, ++, -, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

}//namespace

#endif //FILE_HH_
