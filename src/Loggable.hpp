//Loggable.hpp

/*
*Cees classes à sémentique d'entité sont des interfaces
*pour toute autre classe ayant pour vocation à logguer des données.
*/


#ifndef LOGGABLE_HPP_
#define LOGGABLE_HPP_

#include <string>


namespace stb
{

  enum class file
  {
    source,
    log
  };



  class Loggable
  {
    //fonctions amies

  public:  
    //constructeurs
    explicit Loggable(std::string const& logPath);

    //destructeur
    virtual ~Loggable();

    //méthodes statiques et swap
    
    //méthodes
    virtual void log() const = 0;

    //mutateurs

    //accesseurs

    //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)

  protected:
    //attributs
    std::string _logPath;
  };
  //opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)



  //////////////////////////////////////////////////////////////////////////



  class Loggable_Exception : public Loggable
  {
  //fonctions amies

  public:
    //constructeurs
    explicit Loggable_Exception(std::string const& logPath = defaultLogPath) noexcept;

    //destructeur
    virtual ~Loggable_Exception() noexcept;

    //méthodes statiques et swap
    static void setDefaultLogPath(std::string const& logPath);
    static std::string getDefaultLogPath();
    
    //méthodes
    virtual void log() const noexcept = 0;

    //mutateurs

    //accesseurs

    //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)

  protected:
    //attributs
    
    static std::string defaultLogPath;
  };
  //opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)



  //////////////////////////////////////////////////////////////////////////



  class Loggable_Error : public Loggable
  {
  //fonctions amies

  public:
    //constructeurs
    explicit Loggable_Error(std::string const& logPath = defaultLogPath);

    //destructeur

    //méthodes statiques et swap
    static void setDefaultLogPath(std::string const& logPath);
    static std::string getDefaultLogPath();
    
    //méthodes

    //mutateurs

    //accesseurs

    //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)

  protected:
    //attributs
    
    static std::string defaultLogPath;
  };
  //opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)

  
}//namespace

#endif //LOGGABLE_HPP_
