//Date.hh

/*
Copyright (c) 1998, Regents of the University of California All rights
reserved. Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
    Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
    Neither the name of the University of California, Berkeley nor the names
    of its contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef DATE_HH_
#define DATE_HH

#include <ctime>      // gmtime, localtime, time, tm
#include <string>     // string, to_string
#include "exception.hh"

namespace stb
{



  class Date
  {
  public:

    enum class Location {local, gmt, timezone};
    static const Location local = Location::local;
    static const Location gmt = Location::gmt;
    static const Location timezone = Location::timezone;

    enum class Unit {second, minute, hour, day, week, month, year};
    static const Unit second = Unit::second;
    static const Unit minute = Unit::minute;
    static const Unit hour = Unit::hour;
    static const Unit day = Unit::day;
    static const Unit week = Unit::week;
    static const Unit month = Unit::month;
    static const Unit year = Unit::year;

    Date() = delete;

    static void setTimeLag(int hours)
    {
      timeLag = hours * 3600;
    }

    static std::string time(Location place = Location::gmt)
    {
      struct tm* instant = getTm(place);
      std::string toReturn;
      toReturn += std::to_string(instant->tm_hour);
      toReturn += ":";
      toReturn += std::to_string(instant->tm_min);
      toReturn += ":";
      toReturn += std::to_string(instant->tm_sec);
      return toReturn;
    }

    static std::string date(Location place = Location::gmt)
    {
      struct tm* instant = getTm(place);
      std::string toReturn;
      toReturn += std::to_string(instant->tm_mday);
      toReturn += "/";
      toReturn += std::to_string(instant->tm_mon+1);
      toReturn += "/";
      toReturn += std::to_string(instant->tm_year+1900);
      return toReturn;
    }

    //unit must be one of the typedef on std::ratio defined in the namespace stb
    static int get(Unit unit, Location place)
    {
      struct tm* instant = getTm(place);

      if(unit == Unit::second)
        return (instant->tm_sec);
      if(unit == Unit::minute)
        return (instant->tm_min);
      if(unit == Unit::hour)
        return (instant->tm_hour);
      if(unit == Unit::day)
        return (instant->tm_mday);
      if(unit == Unit::week)
        return (static_cast<int>(std::ceil((instant->tm_mday)/7.)));
      if(unit == Unit::month)
        return (instant->tm_mon + 1);
      if(unit == Unit::year)
        return (instant->tm_year + 1900);

      throw Date_exception("Only stb::second, stb::minute, stb::hour, stb::week, stb::month and stb::year are allowed.");
    }

  protected:
    static tm* getTm(Location place)
    {
      time_t seconds = std::time(nullptr);
      if(seconds == -1)
        throw Date_exception("Unable to get time");
      if(place == Location::gmt)
        return (gmtime(&seconds));
      else if(place == Location::timezone)
      {
        seconds += timeLag;
        return (gmtime(&seconds));
      }
      else
        return (localtime(&seconds));
    }

    static int timeLag;
  };
  int Date::timeLag = 0;



} //namespace stb

#endif //DATE_HH_
