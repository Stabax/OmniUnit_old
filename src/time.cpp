//time.cpp

#include "time.h"

stb::Date_Exception::Date_Exception(std::string const &senderFunction, std::string const &senderFile, std::string const& logPath) noexcept : Exception(senderFunction, senderFile, logPath){}

stb::Date_Current_Unaviable::Date_Current_Unaviable(std::string const &senderFunction, std::string const &senderFile, std::string const& logPath) noexcept : Date_Exception(senderFunction, senderFile, logPath){}


int stb::Date::timeLag = 0;
 
 
void stb::Date::setTimeLag(int const& hour)
{
  timeLag = hour * 3600;
}


struct tm* stb::Date::getTm(location const& type)
{
  time_t seconds = std::time(nullptr);
  if(seconds == -1)
    throw Date_Current_Unaviable("struct tm* stb::Date::getTm(location const&)", __FILE__);
  if(type == location::gmt)
    return (gmtime(&seconds));
  else if(type == location::timeZone)
  {
    seconds += timeLag;
    return (gmtime(&seconds));
  }
  else
    return (localtime(&seconds));
}


std::string stb::Date::time(location const& type)
{
  struct tm* instant = getTm(type);
  std::string toReturn;
  toReturn += std::to_string(instant->tm_hour);
  toReturn += ":";
  toReturn += std::to_string(instant->tm_min);
  toReturn += ":";
  toReturn += std::to_string(instant->tm_sec);
  return (toReturn);
}


std::string stb::Date::date(location const& type)
{
  struct tm* instant = getTm(type);
  std::string toReturn;
  toReturn += std::to_string(instant->tm_mday);
  toReturn += "/";
  toReturn += std::to_string(instant->tm_mon+1);
  toReturn += "/";
  toReturn += std::to_string(instant->tm_year+1900);
  return (toReturn);
}


std::string stb::Date::dateTime(location const& type) noexcept
{
  std::string toReturn;
  
  try
  {
    toReturn = (date(type) + "-" + time(type));
  }
  catch(Date_Exception const& e)
  {
    toReturn = "?/?/?-?:?:?";
  }
  //on gère l'exception ici pour pas que cette fonction puisse elle même en envoyer
  //car cette fonction est utilisée dans les classes d'exceptions
    
  return (toReturn);
}
