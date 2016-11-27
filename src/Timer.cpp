//Timer.cpp

#include "Timer.hpp"

Timer::Timer() : _Begin(std::chrono::high_resolution_clock::now()), _BeginPause(), _PausedTime(0), _isPaused(false), _isStopped(false)
{
}

Timer::~Timer()
{
}

unsigned long long Timer::getNano() const
{
  if(! _isPaused && ! _isStopped)
    return (static_cast<unsigned long long>(((std::chrono::high_resolution_clock::now() - _Begin) - _PausedTime).count()));
  else
  {
    std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> Now = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds ActualPausedTime = Now - _BeginPause;
    return (static_cast<unsigned long long>(((Now - _Begin) - (_PausedTime + ActualPausedTime)).count()));
  }
}

unsigned long long Timer::getMicro() const
{
  return getNano()/(1000);
}

unsigned long long Timer::getMilli() const
{
  return getNano()/(1000*1000);
}

unsigned long long Timer::getSec() const
{
  return getNano()/(1000*1000*1000);
}

unsigned long long Timer::get() const
{
  return getNano()/(1000*1000*1000);
}

unsigned long long Timer::getMin() const
{
  return getSec()/60;
}

unsigned long long Timer::getHour() const
{
  return getSec()/(60*60);
}

std::chrono::nanoseconds Timer::getNanoDuration() const
{
  if(! _isPaused && ! _isStopped)
    return ((std::chrono::high_resolution_clock::now() - _Begin) - _PausedTime);
  else
  {
    std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> Now = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds ActualPausedTime = Now - _BeginPause;
    return ((Now - _Begin) - (_PausedTime + ActualPausedTime));
  }
}

std::chrono::microseconds Timer::getMicroDuration() const
{
  return std::chrono::duration_cast<std::chrono::microseconds>(getNanoDuration());
}

std::chrono::milliseconds Timer::getMilliDuration() const
{
  return std::chrono::duration_cast<std::chrono::milliseconds>(getNanoDuration());
}

std::chrono::seconds Timer::getSecDuration() const
{
  return std::chrono::duration_cast<std::chrono::seconds>(getNanoDuration());
}

std::chrono::seconds Timer::getDuration() const
{
  return std::chrono::duration_cast<std::chrono::seconds>(getNanoDuration());
}

std::chrono::minutes Timer::getMinDuration() const
{
  return std::chrono::duration_cast<std::chrono::minutes>(getNanoDuration());
}

std::chrono::hours Timer::getHourDuration() const
{
  return std::chrono::duration_cast<std::chrono::hours>(getNanoDuration());
}

std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> Timer::getBegin() const
{
  return _Begin;
}

void Timer::start()
{
  if(_isPaused)
  {
    _PausedTime += (std::chrono::high_resolution_clock::now() - _BeginPause);
    _isPaused = false;
  }
  if(_isStopped)
  {
    _Begin = std::chrono::high_resolution_clock::now();
    _PausedTime = std::chrono::nanoseconds::zero();
    _isStopped = false;
  }
}

void Timer::pause()
{
  if(! _isPaused && ! _isStopped)
  {
    _isPaused = true;
    _BeginPause = std::chrono::high_resolution_clock::now();
  }
}

void Timer::stop()
{
  _isStopped = true;
  if(! _isPaused)
  {
    _isPaused = true;
    _BeginPause = std::chrono::high_resolution_clock::now();
  }
}
