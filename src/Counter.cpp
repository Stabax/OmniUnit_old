//Counter.cpp

#include "Counter.hpp"


Counter::Counter() : _End(), _Timer(), _initialized(false)
{
}


Counter::~Counter()
{
}


unsigned long long Counter::getNano() const
{
  if(! _initialized)
    throw Detailed_Exception("Counter not initialized", "unsigned long long Couter::getNano()", __FILE__);
  if((_End - std::chrono::high_resolution_clock::now()).count() < 0)
    return 0;
  return static_cast<unsigned long long>(((_End - _Timer._Begin) - _Timer.getNanoDuration()).count());
}


std::chrono::nanoseconds Counter::getNanoDuration() const
{
  if(! _initialized)
    throw Detailed_Exception("Counter not initialized", "unsigned long long Couter::getNanoDuration()", __FILE__);
  if((_End - std::chrono::high_resolution_clock::now()).count() < 0)
    return std::chrono::nanoseconds(0);
  return (_End - _Timer._Begin) - _Timer.getNanoDuration();
}


void Counter::start()
{
  _Timer.start();
}


void Counter::pause()
{
  _Timer.pause();
}
