//stblib.hh

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

#ifndef STBLIB_HH_
#define STBLIB_HH_

#include <chrono>     // duration, high_resolution_clock, time_point
#include <ctime>      // gmtime, localtime, time, tm
#include <string>     // string, to_string
#include <thread>     // sleep_for, sleep_until

namespace stb
{



class exception : public std::exception
{
public:

  exception(std::string const& msg, std::string const& name):
  _msg("[stblib.exception : " + name + msg + "]")
  {
  }

  virtual const char* what() const noexcept
  {
    return _msg.c_str();
  }

protected:
  std::string const _msg;
};





class Date_exception : public exception
{
public:

  Date_exception(std::string const& msg):
  exception(msg, "Date_exception")
  {
  }
};



typedef std::ratio<1, 1> second;
typedef std::ratio<60, 1> minute;
typedef std::ratio<60*60, 1> hour;
typedef std::ratio<60*60*24, 1> day;
typedef std::ratio<60*60*24*7, 1> week;
typedef std::ratio<60*60*24*30, 1> month;
typedef std::ratio<60*60*24*365, 1> year;





class Date
{
public:

  enum location {local, gmt, timezone};

  Date() = delete;

  static void setTimeLag(int hours)
  {
    timeLag = hours * 3600;
  }

  static std::string time(location place = location::local)
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

  static std::string date(location place = location::local)
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
  template<typename unit>
  static int get(location place)
  {
    struct tm* instant = getTm(place);
    if(typeid(unit) == typeid(second))
      return (instant->tm_sec);
    else if(typeid(unit) ==typeid(minute))
      return (instant->tm_min);
    else if(typeid(unit) == typeid(hour))
      return (instant->tm_hour);
    else if(typeid(unit) == typeid(day))
      return (instant->tm_mday);
    else if(typeid(unit) == typeid(month))
      return (instant->tm_mon + 1);
    else if(typeid(unit) == typeid(year))
      return (instant->tm_year + 1900);
    else
      throw Date_exception("Invalid ratio (unit), use the ratio defined in stb:: instead.");
  }

  static std::string dateTime(location type = location::local) noexcept; //retourne la date et l'heure. noexcept car cette fonction est utilisée dans les classes d'exceptions

protected:
  static struct tm* getTm(location type)
  {
    time_t seconds = std::time(nullptr);
    if(seconds == -1)
      throw Date_exception("Unable to get time");
    if(type == location::gmt)
      return (gmtime(&seconds));
    else if(type == location::timezone)
    {
      seconds += timeLag;
      return (gmtime(&seconds));
    }
    else
      return (localtime(&seconds));
  }

protected:

  static int timeLag;
};
int Date::timeLag = 0;





class Timer
{
public:

  friend class Countdown;

  explicit Timer() :
  _Begin(std::chrono::high_resolution_clock::now()),
  _BeginPause(_Begin),
  _PausedTime(0),
  _addedTime(0),
  _isPaused(true),
  _isStopped(true)
  {
  }

  template<typename ratio, typename returnType = int>
  returnType get() const
  {
    return static_cast<returnType>(getDuration<std::chrono::duration<returnType, ratio>>().count());
  }

  template<typename unit>
  unit getDuration() const
  {
    return std::chrono::duration_cast<unit>(getNanoDuration());
  }

  void start()
  {
    if(_isPaused && ! _isStopped)
    {
      _PausedTime += (std::chrono::high_resolution_clock::now() - _BeginPause);
      _isPaused = false;
    }
    if(_isStopped)
    {
      _Begin = std::chrono::high_resolution_clock::now();
      _PausedTime = std::chrono::nanoseconds::zero();
      _isStopped = false;
      _isPaused = false;
      clear();
    }
  }

  void pause()
  {
    if(! _isPaused)
    {
      _isPaused = true;
      _BeginPause = std::chrono::high_resolution_clock::now();
    }
  }

  void stop()
  {
    pause();
    _isStopped = true;
  }

  template<typename ratio, typename durationType>
  void add(durationType time)
  {
    _addedTime += std::chrono::duration<long long, ratio>(time);
  }

  template<typename ratio, typename durationType>
  void subtract(durationType time)
  {
    long long current = get<ratio, long long>();
    if(time < current)
      _addedTime -= std::chrono::duration<long long, ratio>(time);
    else
      _addedTime -= std::chrono::duration<long long, ratio>(current);
  }

  template<typename unit>
  void addDuration(unit const& time)
  {
    _addedTime += time;
  }

  template<typename unit>
  void subtractDuration(unit const& time)
  {
    unit current = get<unit>();
    if(time < current)
      _addedTime -= time;
    else
      _addedTime -= current;
  }

  void clear()
  {
    _addedTime = std::chrono::nanoseconds::zero();
  }

  void reset()
  {
    stop();
    start();
  }

protected:

  std::chrono::nanoseconds getNanoDuration() const
  {
    if(! _isPaused)
      return ((std::chrono::high_resolution_clock::now() - _Begin) - _PausedTime) + _addedTime;
    else
    {
      std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> Now = std::chrono::high_resolution_clock::now();
      std::chrono::nanoseconds CurrentPausedTime = Now - _BeginPause;
      return ((Now - _Begin) - (_PausedTime + CurrentPausedTime) + _addedTime);
    }
  }


  std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> _Begin; //point du premier start() suivant le dernier stop()
  std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> _BeginPause; //point du dernier pause()
  std::chrono::nanoseconds _PausedTime; //stock le temps total passé en pause() depuis le dernier stop()
  std::chrono::nanoseconds _addedTime; //temps ajouté / retiré (add ou substract)
  bool _isPaused;
  bool _isStopped;
};





class Countdown
{
public:

  explicit Countdown() :
   _End(std::chrono::high_resolution_clock::now()),
   _Timer()
   {
   }

  template<typename ratio, typename returnType = int>
  returnType get() const
  {
    return static_cast<returnType>(getDuration<std::chrono::duration<returnType, ratio>>().count());
  }

  template<typename unit>
  unit getDuration() const
  {
    return std::chrono::duration_cast<unit>(getNanoDuration());
  }

  template<typename ratio, typename durationType>
  void add(durationType duration)
  {
    _End = _End + std::chrono::duration<long long, ratio>(duration);
  }

  template<typename ratio, typename durationType>
  void subtract(durationType duration)
  {
    _End = _End - std::chrono::duration<long long, ratio>(duration);
  }

  template<typename durationType>
  void addDuration(durationType const& duration)
  {
     _End = _End + duration;
  }
  template<typename durationType>
  void subtractDuration(durationType const& duration)
  {
    _End = _End - duration;
  }

  template<typename timePointType>
  void setEnd(timePointType const& timePoint)
  {
    _End = timePoint;
  }

  void start()
  {
    _Timer.start();
  }

  void pause()
  {
    _Timer.pause();
  }

  void reset()
  {
    _Timer.pause();
    _End = std::chrono::high_resolution_clock::now();
    _Timer._Begin = _End;
  }

protected:
  std::chrono::nanoseconds getNanoDuration() const
  {
    std::chrono::nanoseconds current = (_End - _Timer._Begin) - _Timer.getNanoDuration();
    return current.count() < 0 ? std::chrono::nanoseconds::zero() : current;
  }

  std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> _End;
  Timer _Timer;
};





//durationType is implicitly deduced.
template<typename ratio, typename durationType>
void sleep(durationType const& duration)
{
  std::this_thread::sleep_for(std::chrono::duration<long long, ratio>(duration));
}

//durationType is implicitly deduced.
template<typename durationType>
void sleep(durationType const& duration)
{
  std::this_thread::sleep_for(duration);
}

void sleep(Timer const& tim)
{
  std::this_thread::sleep_for(tim.getDuration<std::chrono::nanoseconds>());
}

void sleep(Countdown const& count)
{
  std::this_thread::sleep_for(count.getDuration<std::chrono::nanoseconds>());
}



}//namespace stb

#endif //STBLIB_HH_
