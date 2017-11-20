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

#include "units.hh"
#include <chrono>     // duration, high_resolution_clock, time_point
#include <ctime>      // gmtime, localtime, time, tm
#include <string>     // string, to_string
#include <thread>     // sleep_for, sleep_until

namespace stb
{
//=============================================================================
//=============================================================================
// EXCEPTIONS DEFINITION ======================================================
//=============================================================================
//=============================================================================



class exception : public std::exception
{
public:

  exception(std::string const& msg, std::string const& name):
  _msg("[stblib.exception - " + name + " : " + msg + "]")
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





//=============================================================================
//=============================================================================
// DATES CLASS ================================================================
//=============================================================================
//=============================================================================



class Date
{
public:

  enum class Location {local, gmt, timezone};

  static const Location local = Location::local;
  static const Location gmt = Location::gmt;
  static const Location timezone = Location::timezone;

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
  template<typename unit>
  static int get(Location place)
  {
    place = place; //without this, cannot compile (unused place)
    throw Date_exception("Invalid duration type used, only second, minute, hour, week, month and year are allowed.");
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

//cannot compile if specialization in defined inside the class body
template<>
int Date::get<second>(Location place)
{
  struct tm* instant = getTm(place);
  return (instant->tm_sec);
}
template<>
int Date::get<minute>(Location place)
{
  struct tm* instant = getTm(place);
  return (instant->tm_min);
}
template<>
int Date::get<hour>(Location place)
{
  struct tm* instant = getTm(place);
  return (instant->tm_hour);
}
template<>
int Date::get<day>(Location place)
{
  struct tm* instant = getTm(place);
  return (instant->tm_mday);
}
template<>
int Date::get<month>(Location place)
{
  struct tm* instant = getTm(place);
  return (instant->tm_mon + 1);
}
template<>
int Date::get<year>(Location place)
{
  struct tm* instant = getTm(place);
  return (instant->tm_year + 1900);
}





//=============================================================================
//=============================================================================
// TIMERS CLASS ===============================================================
//=============================================================================
//=============================================================================



// TIMER DEFINITION ===========================================================



class Timer
{
public:

  friend class Countdown;

  explicit Timer() :
  _Begin(std::chrono::high_resolution_clock::now()),
  _BeginPause(_Begin),
  _PausedTime(0),
  _addedTime(0),
  _state(State::stopped)
  {
  }

  virtual ~Timer()
  {
  }

  template<typename durationType>
  durationType get() const
  {
    //std:: qualifier needed to avoid ambiguity
    return stb::duration_cast<durationType>(getNano());
  }

  void start()
  {
    if(_state == State::paused)
    {
      _PausedTime += (std::chrono::high_resolution_clock::now() - _BeginPause);
      _state = State::active;
    }
    if(_state == State::stopped)
    {
      _Begin = std::chrono::high_resolution_clock::now();
      _PausedTime = nanosecond_f::zero();
      _state = State::active;
      clear();
    }
  }

  void pause()
  {
    if(_state == State::active)
    {
      _state = State::paused;
      _BeginPause = std::chrono::high_resolution_clock::now();
    }
  }

  void stop()
  {
    pause();
    _state = State::stopped;
  }

  //durationType is implicitly deduced.
  template<typename durationType>
  void add(durationType const& time)
  {
    _addedTime += time;
  }

  //durationType is implicitly deduced.
  template<typename durationType>
  void subtract(durationType const& time)
  {
    durationType current = get<durationType>();
    if(time < current)
      _addedTime -= time;
    else
      _addedTime -= current;
  }

  void clear()
  {
    _addedTime = nanosecond_f::zero();
  }

  void reset()
  {
    stop();
    start();
  }

protected:

  enum class State {active, paused, stopped};

  virtual nanosecond_f getNano() const
  {
    if(_state == State::stopped)
      return nanosecond_f::zero();
    nanosecond_f CurrentPausedTime = nanosecond_f::zero();
    std::chrono::time_point<std::chrono::high_resolution_clock, nanosecond_f> Now = std::chrono::high_resolution_clock::now();
    if(_state == State::paused)
      CurrentPausedTime = Now - _BeginPause;
    return ((Now - _Begin) - (_PausedTime + CurrentPausedTime) + _addedTime);

  }

  //Point of the first start() following the last stop
  std::chrono::time_point<std::chrono::high_resolution_clock, nanosecond_f> _Begin;
  //Point of last pause
  std::chrono::time_point<std::chrono::high_resolution_clock, nanosecond_f> _BeginPause;
  //total time elapsed in pause since last stop
  nanosecond_f _PausedTime;
  //added/subtracted time
  nanosecond_f _addedTime;
  State _state;
};





// COUNTDOWN DEFINITION =======================================================



class Countdown
{
public:

  explicit Countdown() :
   _End(std::chrono::high_resolution_clock::now()),
   _Timer()
   {
   }

  template<typename durationType>
  durationType get() const
  {
    return std::chrono::duration_cast<durationType>(getNano());
  }

  //durationType is implicitly deduced.
  template<typename durationType>
  void add(durationType const& duration)
  {
    _End = _End + duration;
  }

  //durationType is implicitly deduced.
  template<typename durationType>
  void subtract(durationType const& duration)
  {
    _End = _End - duration;
  }

  //timePointType is implicitly deduced.
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
  nanosecond_f getNano() const
  {
    nanosecond_f current = (_End - _Timer._Begin) - _Timer.getNano();
    return current.count() < 0 ? nanosecond_f::zero() : current;
  }

  std::chrono::time_point<std::chrono::high_resolution_clock, nanosecond_f> _End;
  Timer _Timer;
};





// SLEEP OVERLOADS ============================================================



//durationType is implicitly deduced.
template<typename durationType>
void sleep(durationType const& duration)
{
  std::this_thread::sleep_for(duration);
}

void sleep(Timer const& tim)
{
  std::this_thread::sleep_for(tim.get<nanosecond_f>());
}

void sleep(Countdown const& count)
{
  std::this_thread::sleep_for(count.get<nanosecond_f>());
}





//=============================================================================
//=============================================================================
// RELATIVITY =================================================================
//=============================================================================
//=============================================================================



// RELATIVE TIMER DEFINITION ==================================================



class RelativeTimer : public Timer
{
public:

  RelativeTimer(double gamma):
  _gamma(gamma)
  {
  }

protected:

  virtual nanosecond_f getNano() const
  {
    return _gamma * Timer::getNano();
  }

  double _gamma;
};





}//namespace stb

#endif //STBLIB_HH_
