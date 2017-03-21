//time.h

/*
*Ce header contient:
*une classe statique permettant de représenter des dates,
*et des fonctions pour la pause des threads
*/


#ifndef TIME_H_
#define TIME_H_

#include <ctime>
#include <thread>
#include <string>

#include "conversion.h"
#include "Exception.hpp"


namespace stb
{

  typedef std::ratio<1, 1> second;
  typedef std::ratio<60, 1> minute;
  typedef std::ratio<60*60, 1> hour;
  typedef std::ratio<60*60*24, 1> day;
  typedef std::ratio<60*60*24*30, 1> month;
  typedef std::ratio<60*60*24*365, 1> year;



  class Date_Exception : public Exception
  {
    public:
    Date_Exception(std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath) noexcept;
    virtual const char* what() const noexcept {return "Unknown date exception";}
  };

    class Date_Current_Unaviable : public Date_Exception
  {
    public:
    Date_Current_Unaviable(std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath) noexcept;
    virtual const char* what() const noexcept {return "Unable to get current time";}
  };



  
  
  class Date
  {
  public:
    enum class location {local, gmt, timeZone};  //timeZone permet d'avoir l'heure GMT + décalage (timeLag) ==> heur dans un fiseau horraire
                                                 //gmt permet d'avoir l'heure GMT
                                                 //local permet d'avoir l'heure... locale (de la machine)

    //constructeurs
    Date() = delete;

    //méthodes statiques
    static void setTimeLag(int const& hour); //enregistre le décalage horraire (en heure) par rapport à l'heure GMT
    static struct tm* getTm(location const& type);
    static std::string time(location const& type = location::local); //retourne l'heure actuelle
    static std::string date(location const& type = location::local); //retourne la date actuelle

    template<typename unit>
    static int time(location const& type = location::local) //ne retourne qu'une valeur (seconde OU minutes OU heure OU jour, etc...)
    {
      struct tm* instant = getTm(type);
      if(isSameType<unit, second>())
        return (instant->tm_sec);
      else if(isSameType<unit, minute>())
        return (instant->tm_min);
      else if(isSameType<unit, hour>())
        return (instant->tm_hour);
      else if(isSameType<unit, day>())
        return (instant->tm_mday);
      else if(isSameType<unit, month>())
        return (instant->tm_mon + 1);
      else if(isSameType<unit, year>())
        return (instant->tm_year + 1900);
      else
        throw std::string("");
    }
    
    static std::string dateTime(location const& type = location::local) noexcept; //retourne la date et l'heure. noexcept car cette fonction est utilisée dans les classes d'exceptions

    protected:
    //attributs
    
    static int timeLag; //contient le décalage horraire en heure par rapport à l'heure GMT
  };

  //ratio peut être stb::hour stb::minute stb::second std::milli, std::micro, std::nano ...
  template<typename ratio, typename durationType>
  void sleep(durationType const& duration)
  {
    std::this_thread::sleep_for(std::chrono::duration<long long, ratio>(duration));
  }

  //permet de sleep en envoyant une durée définie par la lib standard
  template<typename durationType>
  void sleep(durationType const& duration)
  {
    std::this_thread::sleep_for(duration);
  }

}//namespace

#endif //TIME_H_
