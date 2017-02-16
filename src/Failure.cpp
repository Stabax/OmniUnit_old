//Failure.cpp

#include "Failure.hpp"


//////////////////////////////////////////////////////////////////

Failure::Failure(std::string const &reason) noexcept : _reason(reason), _date(Date::dateTime())
{
}


Failure::~Failure()
{
}


std::string Failure::getReason() const noexcept
{
  return _reason;
}


std::string Failure::getDate() const noexcept
{
  return _date;
}


//////////////////////////////////////////////////////////////////

Detailed_Failure::Detailed_Failure(std::string const &reason, std::string const &senderFunction, std::string const &senderFile) noexcept : Failure(reason), _senderFunction(senderFunction), _senderFile(senderFile)
{
}


Detailed_Failure::~Detailed_Failure()
{
}


std::string Detailed_Failure::getSenderFunction() const noexcept
{
  return _senderFunction;
}


std::string Detailed_Failure::getSenderFile() const noexcept
{
  return _senderFile;
}
