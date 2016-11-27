//time.hpp

/*
*Ce header contient:
*une classe gérant dates,
*des fonctions pour la pause des threads
*/

#ifndef TIME_H_
#define TIME_H_

#include "conversion.hpp"
#include <ctime>
#include <thread>
#include <string>

class Date
{
public:
  enum class unit {second, minute, hour, day, month, year};
  enum class location {local, gmt, timeZone};  //timeZone permet d'avoir l'heure GMT + décalage (timeLag)
                                            //gmt permet d'avoir l'heure GMT
                                            //local permet d'avoir l'heure... locale

  static void setTimeLag(int const& hour); //enregistre le décalage horraire en heure (par rapport à l'heure GMT)
  static struct tm* getTm(location const& type);
  static std::string time(location const& type = location::local); //retourne l'heure actuelle
  static std::string date(location const& type = location::local); //retourne la date actuelle
  static int time(unit const& value, location const& type = location::local); //ne retourne qu'une valeur (seconde OU minutes OU heure OU jour...)
  static std::string dateTime(location const& type = location::local) noexcept; //retourne la date et l'heure. noexcept car cette 
                                                                                //fonction est utilisée dans les classes d'exceptions

  static int timeLag; //contient le décalage horraire en heure par rapport à l'heure GMT
};

namespace std
{
  typedef ratio<1, 1> second;
  typedef ratio<60, 1> minute;
  typedef ratio<60*60, 1> hour;
}

//ratio peut être std::hour std::minute std::second std::milli, std::micro, std::nano ...
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

#endif //TIME_H_
