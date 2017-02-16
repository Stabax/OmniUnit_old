//Loggable.cpp

#include "Loggable.hpp"


Loggable::Loggable(std::string const& logPath) : _logPath(logPath)
{

}


Loggable::~Loggable()
{
}


void Loggable::setLogPath(std::string const& path)
{
  _logPath = path;
}
