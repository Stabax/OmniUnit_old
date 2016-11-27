//general_exceptions.cpp

#include "general_exceptions.hpp"
#include "GroupedKeyWordFile.hpp" //cet include est ici, et non dans le .hpp pour éviter l'inclusion multiple (car Basic_File.hpp inclue déjà general_exceptions.hpp)


StrException::StrException(std::string const& reason) noexcept : _reason(reason)
{
}


StrException::~StrException()
{
}


const char* StrException::what() const noexcept
{
  return _reason.c_str();
}


/////////////////////////////////////////////////////////////////////////////

std::string Log_Exception::defaultLogFilePath = "exception.log";


Log_Exception::Log_Exception(std::string const &reason) noexcept : Failure(reason, defaultLogFilePath)
{
}


Log_Exception::Log_Exception(std::string const &reason, std::string const &logPath) noexcept : Failure(reason, logPath)
{
}


Log_Exception::~Log_Exception()
{
}


void Log_Exception::setDefaultLogFilePath(std::string const &path)
{
  defaultLogFilePath = path;
}


/////////////////////////////////////////////////////////////////////////////

std::string Loaded_Exception::defaultSourceFilePath = "exception.src";


Loaded_Exception::Loaded_Exception(unsigned const &line) noexcept : Failure(loadException(defaultSourceFilePath, line), defaultLogFilePath), Log_Exception(loadException(defaultSourceFilePath, line))
{
}


Loaded_Exception::Loaded_Exception(std::string const &keyword, std::string const &parser) noexcept : Failure(loadException(defaultSourceFilePath, keyword, parser), defaultLogFilePath), Log_Exception(loadException(defaultSourceFilePath, keyword, parser))
{
}


Loaded_Exception::Loaded_Exception(std::string const& group, std::string const &keyword, std::string const &parser) noexcept : Failure(loadException(defaultSourceFilePath, group, keyword, parser), defaultLogFilePath), Log_Exception(loadException(defaultSourceFilePath, group, keyword, parser))
{
}


Loaded_Exception::Loaded_Exception(std::string const &sourcePath, unsigned const &line) noexcept : Failure(loadException(sourcePath, line), defaultLogFilePath), Log_Exception(loadException(sourcePath, line))
{
}

/*
Loaded_Exception::Loaded_Exception(std::string const &sourcePath, std::string &keyword, std::string const &parser) noexcept : Failure(loadException(sourcePath, keyword, parser) defaultLogFilePath), Log_Exception(loadException(sourcePath, keyword, parser))
{
}
*/

Loaded_Exception::Loaded_Exception(std::string const &sourcePath, std::string const& group, std::string const& keyword, std::string const &parser) noexcept : Failure(loadException(sourcePath, group, keyword, parser), defaultLogFilePath), Log_Exception(loadException(sourcePath, group, keyword, parser))
{
}


Loaded_Exception::Loaded_Exception(unsigned const &line, std::string const &logPath) noexcept : Failure(loadException(defaultSourceFilePath, line), logPath), Log_Exception(loadException(defaultSourceFilePath, line), logPath)
{
}

/*
Loaded_Exception::Loaded_Exception(std::string const &keyword, std::string const &logPath, std::string const &parser) noexcept : Failure(loadException(defaultSourceFilePath, keyword, parser), logPath), Log_Exception(loadException(defaultSourceFilePath, keyword, pasrer), logPath)
{
}
*/
/*
Loaded_Exception::Loaded_Exception(std::string const& group, std::string const &keyword, std::string const &logPath, std::string const &parser) noexcept : Failure(loadException(defaultSourceFilePath, group, keyword, parser), logPath), Log_Exception(loadException(defaultSourceFilePath, group, keyword, parser), logPath)
{
}
*/

Loaded_Exception::Loaded_Exception(std::string const &sourcePath, unsigned const &line, std::string const &logPath) noexcept : Failure(loadException(sourcePath, line), logPath), Log_Exception(loadException(sourcePath, line), logPath)
{
}

/*
Loaded_Exception::Loaded_Exception(std::string const &sourcePath, std::string &keyword, std::string const &logPath, std::string const &parser) noexcept : Failure(loadException(sourcePath, keyword, parser), logPath), Log_Exception(loadException(sourcePath, keyword, parser), logPath)
{
}
*/

Loaded_Exception::Loaded_Exception(std::string const &sourcePath, std::string const& group, std::string const& keyword, std::string const &logPath, std::string const &parser) noexcept : Failure(loadException(sourcePath, group, keyword, parser), logPath), Log_Exception(loadException(sourcePath, group, keyword, parser), logPath)
{
}


Loaded_Exception::~Loaded_Exception()
{
}


void Loaded_Exception::setDefaultSourceFilePath(std::string const &path)
{
  defaultSourceFilePath = path;
}


std::string Loaded_Exception::loadException(std::string const &path, unsigned const &line)
{
  File sourceFile(path);
  sourceFile.open();
  std::string toReturn = sourceFile.readLine(line);
  sourceFile.close();
  return toReturn;
}


std::string Loaded_Exception::loadException(std::string const &path, std::string const &keyword, std::string const &parser)
{
  KeyWordFile sourceFile(path);
  sourceFile.open();
  std::string toReturn = sourceFile.readKeywordValue(keyword, parser);
  sourceFile.close();
  return toReturn;
}


std::string Loaded_Exception::loadException(std::string const &path, std::string const& group, std::string const& keyword, std::string const &parser)
{
  GroupedKeyWordFile sourceFile(path);
  sourceFile.open();
  std::string toReturn = sourceFile.readGKeywordValue(group, keyword, parser);
  sourceFile.close();
  return toReturn;
}


const char* Loaded_Exception::what() const noexcept
{
  return ("Exception : [" + _date + "] : " + _reason).c_str();
}


void Loaded_Exception::log() const noexcept
{
  File Log(_logFilePath);
  if(! Log.exist())
    Log.create();
  Log.open();
  Log.insert(what(), 1);
  Log.close();
}


/////////////////////////////////////////////////////////////////////////////

Detailed_Exception::Detailed_Exception(std::string const &reason, std::string const &senderFunction, std::string const &senderFile) noexcept : Failure(reason, defaultLogFilePath), Log_Exception(reason), Detailed_Failure(reason, senderFunction, senderFile, defaultLogFilePath)
{
}


Detailed_Exception::Detailed_Exception(std::string const &reason, std::string const &senderFunction, std::string const &senderFile, std::string const &logPath) noexcept : Failure(reason, logPath), Log_Exception(reason, logPath), Detailed_Failure(reason, senderFunction, senderFile, logPath)
{
}


Detailed_Exception::~Detailed_Exception()
{
}


void Detailed_Exception::printDetails() const noexcept
{
  std::cout << "Exception : [" << _date << "] : " << _reason << ", from function : " << _senderFunction << ", from file : " << _senderFile<< ".\n";
}


const char* Detailed_Exception::Detailed_Exception::what() const noexcept
{
  return ("Exception : [" + _date + "] : " + _reason).c_str();
}


void Detailed_Exception::Detailed_Exception::log() const noexcept
{
  std::string toLog("Exception : [" + _date + "] : " + _reason + ", from function : " + _senderFunction + ", from file : " + _senderFile + ".");
  File Log(_logFilePath);
  if(! Log.exist())
    Log.create();
  Log.open();
  Log.insert(toLog, 1);
  Log.close();
}
/////////////////////////////////////////////////////////////////////////////

/*
Detailed_Loaded_Exception::Detailed_Loaded_Exception(unsigned const &line, std::string const &senderFunction) noexcept : Loaded_Exception(line), Detailed_Exception(Loaded_Exception(line).what(), senderFunction)
{
}


Detailed_Loaded_Exception::Detailed_Loaded_Exception(std::string const &exceptionSourceFilePath, unsigned const &line, std::string const &senderFunction) noexcept : Loaded_Exception(exceptionSourceFilePath, line), Detailed_Exception("unknown", senderFunction)
{
}


Detailed_Loaded_Exception::~Detailed_Loaded_Exception()
{
}


const char* Detailed_Loaded_Exception::what() const noexcept
{
  return (_reason.c_str());
}


void Detailed_Exception::Detailed_Exception::log() const noexcept
{
  std::string toLog = "Exception : [" + _date + "] : " + _reason + ", from function : " + _senderFunction + ", from file : " + _senderLine + ".";
  File Log(_logFilePath);
  if(! Log.exist())
    Log.create();
  Log.open();
  Log.insert(toLog, 1);
  Log.close();
}
*/
/////////////////////////////////////////////////////////////////////////////

