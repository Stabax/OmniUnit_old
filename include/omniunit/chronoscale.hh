//chronoscale.hh

/*
Copyright (c) 2019, Denis Tosetto All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

  Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.

  Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

  Neither the name of Denis Tosetto nor the names
  of its contributors may be used to endorse or promote products derived
  from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef CHRONOSCALE_HH_
#define CHRONOSCALE_HH_

#include "omniunit.hh"

#include <ctime>   // gmtime, localtime, time, tm
#include <exception>  // exception
#include <memory>  // unique_ptr



namespace omni
{

//=============================================================================
//=============================================================================
//=============================================================================
//=== EXCEPTIONS DEFINITION ===================================================
//=============================================================================
//=============================================================================
//=============================================================================

class Exception : public std::exception
{
public:

  Exception(std::string const& msg, std::string const& name):
  _msg("[OmniUnit.exception - " + name + " : " + msg + "]")
  {
  }

  virtual ~Exception()
  {
  }

  virtual const char* what() const noexcept
  {
    return _msg.c_str();
  }

protected:
  std::string const _msg;
};

class Date_exception : public Exception
{
public:

  Date_exception(std::string const& msg):
  Exception(msg, "Date_exception")
  {
  }

  virtual ~Date_exception()
  {
  }
};



//=============================================================================
//=============================================================================
//=============================================================================
//=== TIMER DEFINITION ========================================================
//=============================================================================
//=============================================================================
//=============================================================================



class Timer
{
public:

  friend class Countdown;

  explicit Timer() :
  _Begin(std::chrono::steady_clock::now()),
  _BeginPause(_Begin),
  _PausedTime(0),
  _addedTime(0),
  _state(State::stopped)
  {
  }


  virtual ~Timer()
  {
  }


  template<typename durationType = second<long long>>
  durationType get() const
  {
    return omni::unit_cast<durationType>(getNano());
  }


  void start()
  {
    if(_state == State::paused)
    {
      _PausedTime += (std::chrono::steady_clock::now() - _BeginPause);
      _state = State::active;
    }
    if(_state == State::stopped)
      _state = State::active;
  }


  void pause()
  {
    if(_state == State::active)
    {
      _BeginPause = std::chrono::steady_clock::now();
      _state = State::paused;
    }
  }


  void stop()
  {
    _Begin = std::chrono::steady_clock::now();
    _PausedTime = std::chrono::nanoseconds::zero();
    clear();
    _state = State::stopped;
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


  template <typename Rep, typename Period, double const& Origin>
  Timer& operator+=(Unit<Duration, Rep, Period, Origin> const& duration)
  {
    _addedTime += duration;
    return *this;
  }


  template <typename Rep, typename Period, double const& Origin>
  Timer& operator-=(Unit<Duration, Rep, Period, Origin> const& duration)
  {
    Unit<Duration, Rep, Period, Origin> current = get<Unit<Duration, Rep, Period, Origin>>();
    if(duration < current)
      _addedTime -= duration;
    else
      _addedTime -= current;
    return *this;
  }


protected:

  enum class State {active, paused, stopped};

  virtual std::chrono::nanoseconds getNano() const
  {
    std::chrono::nanoseconds CurrentPausedTime = std::chrono::nanoseconds::zero();
    std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> Now = std::chrono::steady_clock::now();
    if(_state == State::paused)
      CurrentPausedTime = Now - _BeginPause;
    return ((Now - _Begin) - (_PausedTime + CurrentPausedTime) + _addedTime);

  }

  //Point of the first start() following the last stop
  std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> _Begin;
  //Point of last pause
  std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> _BeginPause;
  //total time elapsed in pause since last stop
  std::chrono::nanoseconds _PausedTime;
  //added/subtracted time
  std::chrono::nanoseconds _addedTime;
  State _state;
};


template <typename Rep, typename Period, double const& Origin>
Timer operator+(Timer const& tim, Unit<Duration, Rep, Period, Origin> const& duration)
{
  return tim += duration;
}


template <typename Rep, typename Period, double const& Origin>
Timer operator+(Unit<Duration, Rep, Period, Origin> const& duration, Timer const& tim)
{
  return tim += duration;
}


template <typename Rep, typename Period, double const& Origin>
Timer operator-(Timer const& tim, Unit<Duration, Rep, Period, Origin> const& duration)
{
  return tim -= duration;
}


template <typename Rep, typename Period, double const& Origin>
Timer operator-(Unit<Duration, Rep, Period, Origin> const& duration, Timer const& tim)
{
  return tim -= duration;
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== COUNTDOWN DEFINITION ====================================================
//=============================================================================
//=============================================================================
//=============================================================================



class Countdown
{
public:

  explicit Countdown() :
   _End(std::chrono::steady_clock::now()),
   _Timer(std::make_unique<Timer>())
   {
   }


  template <typename Rep, typename Period, double const& Origin>
  explicit Countdown(Unit<Duration, Rep, Period, Origin> const& duration) :
  _End(std::chrono::steady_clock::now() + duration),
  _Timer(std::make_unique<Timer>())
  {
  }


  explicit Countdown(std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> const& timpoint) :
  _End(timpoint),
  _Timer(std::make_unique<Timer>())
  {
  }


protected:

  //these constructor is only accessible to RelativeCountdown
  explicit Countdown(Timer const& tim) :
   _End(std::chrono::steady_clock::now()),
   _Timer(std::make_unique<Timer>(tim))
   {
   }


  template <typename Rep, typename Period, double const& Origin>
  explicit Countdown(Unit<Duration, Rep, Period, Origin> const& duration, Timer const& tim) :
  _End(std::chrono::steady_clock::now() + duration),
  _Timer(std::make_unique<Timer>(tim))
  {
  }


  explicit Countdown(std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> const& timpoint, Timer const& tim) :
  _End(timpoint),
  _Timer(std::make_unique<Timer>(tim))
  {
  }

public:

  template<typename durationType>
  durationType get() const
  {
    return unit_cast<durationType>(getNano());
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
    _Timer->start();
  }

  void pause()
  {
    _Timer->pause();
  }

  void reset()
  {
    _Timer->pause();
    _End = std::chrono::steady_clock::now();
    _Timer->_Begin = _End;
  }

protected:
  std::chrono::nanoseconds getNano() const
  {
    return (_End - _Timer->_Begin) - _Timer->getNano();
  }

  std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> _End;
  //_Timer is a pointer in order to use polymorphism (with RelativeTimer)
  std::unique_ptr<Timer> _Timer;
};



//=============================================================================
//=============================================================================
//=============================================================================
//=== RELATIVE INTERFACE DEFINITION ===========================================
//=============================================================================
//=============================================================================
//=============================================================================



class Relative
{
public:

protected:
  float beta;
  float gamma;

};



//=============================================================================
//=============================================================================
//=============================================================================
//=== RELATIVE TIMER DEFINITION ===============================================
//=============================================================================
//=============================================================================
//=============================================================================



class RelativeTimer : public Timer
{
public:

  RelativeTimer(double gamma):
  _gamma(gamma)
  {
  }

protected:

  virtual std::chrono::nanoseconds getNano() const
  {
    return std::chrono::nanoseconds(
    std::llround(static_cast<double>(Timer::getNano().count()) * _gamma));
  }

  double _gamma;
};



//=============================================================================
//=============================================================================
//=============================================================================
//=== RELATIVE COUNTDOWN DEFINITION ===========================================
//=============================================================================
//=============================================================================
//=============================================================================



class RelativeCountdown : public Countdown
{
public:
  RelativeCountdown(double gamma):
  Countdown(RelativeTimer(gamma))
  {
  }
};



//=============================================================================
//=============================================================================
//=============================================================================
//=== DATE DEFINITION =========================================================
//=============================================================================
//=============================================================================
//=============================================================================



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

    throw Date_exception("Only omniunit::second, omniunit::minute, omniunit::hour, omniunit::week, omniunit::month and omniunit::year are allowed.");
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



} // namespace omni



#endif //CHRONOSCALE_HH_
