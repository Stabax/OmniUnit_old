//Failure.cpp

#include "Failure.hpp"


//////////////////////////////////////////////////////////////////

Failure::Failure(std::string const &reason, std::string const &path) noexcept : _reason(reason), _logFilePath(path), _date(Date::dateTime())
{
}


Failure::~Failure()
{
}


void Failure::setLogFilePath(std::string const& path) noexcept
{
  _logFilePath = path;
}


const char* Failure::getReason() const noexcept
{
  return _reason.c_str();
}


const char* Failure::getDate() const noexcept
{
  return _date.c_str();
}


//////////////////////////////////////////////////////////////////

Detailed_Failure::Detailed_Failure(std::string const &reason, std::string const &senderFunction, std::string const &senderFile, std::string const &path) noexcept : Failure(reason, path), _senderFunction(senderFunction), _senderFile(senderFile)
{
}


Detailed_Failure::~Detailed_Failure()
{
}


const char* Detailed_Failure::getFunction() const noexcept
{
  return _senderFunction.c_str();
}


const char* Detailed_Failure::getFile() const noexcept
{
  return _senderFile.c_str();
}
