//Counter.cpp

#include "Counter.hh"


unsigned long long stb::Counter::getNano() const
{
  if((_End - std::chrono::high_resolution_clock::now()).count() < 0)
    return 0;
  return static_cast<unsigned long long>(((_End - _Timer._Begin) - _Timer.getNanoDuration()).count());
}


std::chrono::nanoseconds stb::Counter::getNanoDuration() const
{
  if((_End - std::chrono::high_resolution_clock::now()).count() < 0)
    return std::chrono::nanoseconds(0);
  return (_End - _Timer._Begin) - _Timer.getNanoDuration();
}


void stb::Counter::start()
{
  _Timer.start();
}


void stb::Counter::pause()
{
  _Timer.pause();
}
