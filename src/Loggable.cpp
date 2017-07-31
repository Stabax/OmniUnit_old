//Loggable.cpp

#include "Loggable.hpp"


stb::Loggable::Loggable(std::string const& logPath) : _logPath(logPath)
{

}


stb::Loggable::~Loggable()
{
}



  /////////////////////////////////////////////////////////////////////////////////////



std::string stb::Loggable_Error::defaultLogPath = "error.log";


stb::Loggable_Error::Loggable_Error(std::string const& logPath) : Loggable(logPath)
{
}


void stb::Loggable_Error::setDefaultLogPath(std::string const& logPath)
{
  defaultLogPath = logPath;
}


std::string stb::Loggable_Error::getDefaultLogPath()
{
  return defaultLogPath;
}
