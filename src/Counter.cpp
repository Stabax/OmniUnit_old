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
  return static_cast<unsigned long long>(((_End - _Timer.getBegin()) - _Timer.getNanoDuration()).count());
}

unsigned long long Counter::getMicro() const
{
  return getNano() / (1000);
}

unsigned long long Counter::getMilli() const
{
  return getNano() / (1000 * 1000);
}

unsigned long long Counter::getSec() const
{
  return getNano() / (1000 * 1000 * 1000);
}

unsigned long long Counter::get() const
{
  return getNano() / (1000 * 1000 * 1000);
}

unsigned long long Counter::getMin() const
{
  return get() / (60);
}

unsigned long long Counter::getHour() const
{
  return get() / (60 *60);
}

std::chrono::nanoseconds Counter::getNanoDuration() const
{
  if(! _initialized)
    throw Detailed_Exception("Counter not initialized", "unsigned long long Couter::getNanoDuration()", __FILE__);
  if((_End - std::chrono::high_resolution_clock::now()).count() < 0)
    return std::chrono::nanoseconds(0);
  return (_End - _Timer.getBegin()) - _Timer.getNanoDuration();
}

std::chrono::microseconds Counter::getMicroDuration() const
{
  return std::chrono::duration_cast<std::chrono::microseconds>(getNanoDuration());
}

std::chrono::milliseconds Counter::getMilliDuration() const
{
  return std::chrono::duration_cast<std::chrono::milliseconds>(getNanoDuration());
}

std::chrono::seconds Counter::getSecDuration() const
{
  return std::chrono::duration_cast<std::chrono::seconds>(getNanoDuration());
}

std::chrono::seconds Counter::getDuration() const
{
  return std::chrono::duration_cast<std::chrono::seconds>(getNanoDuration());
}

std::chrono::minutes Counter::getMinDuration() const
{
  return std::chrono::duration_cast<std::chrono::minutes>(getNanoDuration());
}

std::chrono::hours Counter::getHourDuration() const
{
  return std::chrono::duration_cast<std::chrono::hours>(getNanoDuration());
}

void Counter::start()
{
  _Timer.start();
}

void Counter::pause()
{
  _Timer.pause();
}
