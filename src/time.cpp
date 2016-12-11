//time.cpp

#include "time.hpp"


int Date::timeLag = 0;
 
 
void Date::setTimeLag(int const& hour)
{
  timeLag = hour * 3600;
}


struct tm* Date::getTm(location const& type)
{
  time_t seconds = std::time(nullptr);
  if(seconds == -1)
    throw std::string("Unable to get current time, from function : struct tm* Date::getTm(place const&), from file : ") + __FILE__;
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


std::string Date::time(location const& type)
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


std::string Date::date(location const& type)
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


int Date::time(unit const& value, location const& type)
{
  struct tm* instant = getTm(type);
  if(value == unit::second)
    return (instant->tm_sec);
  else if(value == unit::minute)
    return (instant->tm_min);
  else if(value == unit::hour)
    return (instant->tm_hour);
  else if(value == unit::day)
    return (instant->tm_mday);
  else if(value == unit::month)
    return (instant->tm_mon + 1);
  else
    return (instant->tm_year + 1900);
}


std::string Date::dateTime(location const& type) noexcept
{
  std::string toReturn;
  
  try
  {
    toReturn = (date(type) + "-" + time(type));
  }
  catch(std::string const& except)
  {
    toReturn = "?/?/?-?:?:?";
  }
  //on gère l'exception ici pour pas que cette fonction puisse elle même en envoyer
  //car cette fonction est utilisée dans les classes d'exceptions
    
  return (toReturn);
}
