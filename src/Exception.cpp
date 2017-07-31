//Exception.cpp

#include "Exception.hpp"
#include "File.hh"
#include "time.h"


std::string stb::Exception::defaultLogPath = "exception.log";


stb::Exception::Exception(std::string const &reason, std::string const& senderFunction, std::string const& senderFile, std::string const& logPath) noexcept : Loggable(logPath), _reason(reason), _date(Date::dateTime()), _senderFunction(senderFunction), _senderFile(senderFile)
{
}


stb::Exception::~Exception() noexcept
{
}


void stb::Exception::setDefaultLogPath(std::string const& logPath) noexcept
{
  defaultLogPath = logPath;
}


std::string stb::Exception::getDefaultLogPath() noexcept
{
  return defaultLogPath;
}


std::string stb::Exception::getDate() const noexcept
{
  return _date;
}


std::string stb::Exception::getSenderFunction() const noexcept
{
  return _senderFunction;
}


std::string stb::Exception::getSenderFile() const noexcept
{
  return _senderFile;
}


const char* stb::Exception::what() const noexcept
{
  return _reason.c_str();
}

void stb::Exception::log() const noexcept try
{
  std::string toLog = "[" + _date + "] : " + what() + ". Sent from function : " + _senderFunction + ", from file : " + _senderFile + ".";
  File Log(_logPath);
  Log.insert(toLog, 1);
}
catch(Exception const& e)
{
  std::string err = "Exception : [" + e.getDate() + "] : Exception thrown while logging another unknown exception. Here is the current one : " + e.what() + ", at function : " + e.getSenderFunction() + ", at file : " + e.getSenderFile() + "   ... terminate() is called !\n";

  File file(Exception::getDefaultLogPath());
  file.write(err, 0);
}
