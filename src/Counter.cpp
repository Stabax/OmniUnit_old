//Counter.cpp

#include "Counter.hh"


stb::Counter::Counter() : _End(std::chrono::high_resolution_clock::now()), _Timer()
{}


std::chrono::nanoseconds stb::Counter::getNanoDuration() const
{
  std::chrono::nanoseconds current = (_End - _Timer._Begin) - _Timer.getNanoDuration();
  return current.count() < 0 ? std::chrono::nanoseconds::zero() : current;
}


void stb::Counter::start()
{
  _Timer.start();
}


void stb::Counter::pause()
{
  _Timer.pause();
}

void stb::Counter::reset()
{
  _Timer.pause();
  _End = std::chrono::high_resolution_clock::now();
  _Timer._Begin = _End;
}
