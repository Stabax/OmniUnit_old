//Timer.cpp

#include "Timer.hpp"


Timer::Timer() : _Begin(std::chrono::high_resolution_clock::now()), _BeginPause(), _PausedTime(0), _isPaused(true), _isStopped(true)
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
    std::chrono::nanoseconds CurrentPausedTime = Now - _BeginPause;
    return (static_cast<unsigned long long>(((Now - _Begin) - (_PausedTime + CurrentPausedTime)).count()));
  }
}


std::chrono::nanoseconds Timer::getNanoDuration() const
{
  if(! _isPaused && ! _isStopped)
    return ((std::chrono::high_resolution_clock::now() - _Begin) - _PausedTime);
  else
  {
    std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> Now = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds CurrentPausedTime = Now - _BeginPause;
    return ((Now - _Begin) - (_PausedTime + CurrentPausedTime));
  }
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
