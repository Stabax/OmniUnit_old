//Timer.cpp

#include "Timer.hh"


stb::Timer::Timer() : _Begin(std::chrono::high_resolution_clock::now()), _BeginPause(_Begin), _PausedTime(0), _addedTime(0), _isPaused(true), _isStopped(true)
{
}


std::chrono::nanoseconds stb::Timer::getNanoDuration() const
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


void stb::Timer::start()
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


void stb::Timer::pause()
{
  if(! _isPaused)
  {
    _isPaused = true;
    _BeginPause = std::chrono::high_resolution_clock::now();
  }
}


void stb::Timer::stop()
{
  pause();
  _isStopped = true;
}


void stb::Timer::clear()
{
  _addedTime = std::chrono::nanoseconds::zero();
}


void stb::Timer::reset()
{
  stop();
  start();
}
