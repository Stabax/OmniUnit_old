//Date.hh

/*
*Ce header contient:
*une classe statique permettant de représenter des dates,
*et des fonctions pour la pause des threads
*/


#ifndef TIME_HH_
#define TIME_HH_

#include <ctime>
#include <thread>
#include <string>

#include "conversion.h"
#include "Exception.hpp"
#include "timeTypes.h"


namespace stb
{

  class Date_Exception : public Exception
  {
    public:
    Date_Exception(std::string const &reason, std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath) noexcept;
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
    static void setTimeLag(int hour); //enregistre le décalage horraire (en heure) par rapport à l'heure GMT
    protected:
    static struct tm* getTm(location type);
    public:
    static std::string time(location type = location::local); //retourne l'heure actuelle
    static std::string date(location type = location::local); //retourne la date actuelle

    template<typename unit>
    static int time(location type = location::local) //ne retourne qu'une valeur (seconde OU minutes OU heure OU jour, etc...)
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
    
    static std::string dateTime(location type = location::local) noexcept; //retourne la date et l'heure. noexcept car cette fonction est utilisée dans les classes d'exceptions

    protected:
    //attributs
    
    static int timeLag; //contient le décalage horraire en heure par rapport à l'heure GMT
  };

}//namespace

#endif //TIME_HH_
