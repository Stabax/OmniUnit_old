//log_exceptions.cpp

#include "log_exceptions.hpp"


std::string Log_Exception_Base::defaultLogPath = "exception.log";

Log_Exception_Base::Log_Exception_Base(std::string const& logPath) noexcept : Loggable(logPath)
{
}


Log_Exception_Base::~Log_Exception_Base()
{
}


void Log_Exception_Base::setDefaultLogPath(std::string const& logPath)
{
  defaultLogPath = logPath;
}


/////////////////////////////////////////////////////////////////////////////

Log_Exception::Log_Exception(std::string const& reason, std::string const& logPath) noexcept : Failure(reason), Exception(reason), Log_Exception_Base(logPath)
{
}


Log_Exception::~Log_Exception()
{
}


void Log_Exception::log() const noexcept
{
  std::string toLog = "[" + _date + "] : " + _reason + ".";
  File Log(_logPath);
  if(! Log.exist())
    Log.create();
  Log.insert(toLog, 1);
}


/////////////////////////////////////////////////////////////////////////////

Log_Detailed_Exception::Log_Detailed_Exception(std::string const& reason, std::string const &senderFunction, std::string const &senderFile, std::string const& logPath) noexcept : Failure(reason), Exception(reason), Detailed_Exception(reason, senderFunction, senderFile), Log_Exception_Base(logPath)
{
}


Log_Detailed_Exception::~Log_Detailed_Exception()
{
}


void Log_Detailed_Exception::log() const noexcept
{
  std::string toLog = "[" + _date + "] : " + _reason + ". Sent from function : " + _senderFunction + ", from file : " + _senderFile + ".";
  File Log(_logPath);
  if(! Log.exist())
    Log.create();
  Log.insert(toLog, 1);
}


/////////////////////////////////////////////////////////////////////////////

Log_Loaded_Exception::Log_Loaded_Exception(unsigned const &line, std::string const& logPath) noexcept : Failure(loadException(defaultSourceFilePath, line)), Exception(_reason), Loaded_Exception(line), Log_Exception_Base(logPath)
{
}


Log_Loaded_Exception::Log_Loaded_Exception(std::string const &keyword, std::string const& logPath, char const &parser) noexcept : Failure(loadKWException(defaultSourceFilePath, keyword, parser)), Exception(_reason), Loaded_Exception(keyword, parser), Log_Exception_Base(logPath)
{
}


Log_Loaded_Exception::Log_Loaded_Exception(std::string const &group, std::string const& keyword, std::string const& logPath, char const &parser) noexcept : Failure(loadGKWException(defaultSourceFilePath, group, keyword, parser)), Exception(_reason), Loaded_Exception(group, keyword, parser), Log_Exception_Base(logPath)
{
}


Log_Loaded_Exception::Log_Loaded_Exception(File& sourceFile, unsigned const &line, std::string const& logPath) noexcept : Failure(sourceFile.readLine(line)), Exception(_reason), Loaded_Exception(sourceFile, line), Log_Exception_Base(logPath)
{
}


Log_Loaded_Exception::Log_Loaded_Exception(KWFile& sourceFile, std::string &keyword, std::string const& logPath, char const &parser) noexcept : Failure(sourceFile.readKeywordValue(keyword, parser)), Exception(_reason), Loaded_Exception(sourceFile, keyword, parser), Log_Exception_Base(logPath)
{
}


Log_Loaded_Exception::Log_Loaded_Exception(GFile& sourceFile, std::string const& group, std::string const& keyword, std::string const& logPath, char const &parser) noexcept : Failure(sourceFile.readGKeywordValue(group, keyword, parser)), Exception(_reason), Loaded_Exception(sourceFile, group, keyword, parser), Log_Exception_Base(logPath)
{
}


Log_Loaded_Exception::~Log_Loaded_Exception()
{
}


void Log_Loaded_Exception::log() const noexcept
{
  std::string toLog = "[" + _date + "] : " + _reason + ".";
  File Log(_logPath);
  if(! Log.exist())
    Log.create();
  Log.insert(toLog, 1);
}



/////////////////////////////////////////////////////////////////////////////

Log_Detailed_Loaded_Exception::Log_Detailed_Loaded_Exception(unsigned const &line, std::string const &senderFunction, std::string const &senderFile, std::string const& logPath) noexcept : Failure(loadException(defaultSourceFilePath, line)), Exception(_reason), Detailed_Loaded_Exception(line, senderFunction, senderFile), Log_Exception_Base(logPath)
{
}


Log_Detailed_Loaded_Exception::Log_Detailed_Loaded_Exception(std::string const &keyword, std::string const &senderFunction, std::string const &senderFile, std::string const& logPath, char const &parser) noexcept : Failure(loadKWException(defaultSourceFilePath, keyword, parser)), Exception(_reason), Detailed_Loaded_Exception(keyword, senderFunction, senderFile, parser), Log_Exception_Base(logPath)
{
}


Log_Detailed_Loaded_Exception::Log_Detailed_Loaded_Exception(std::string const &group, std::string const& keyword, std::string const &senderFunction, std::string const &senderFile, std::string const& logPath, char const &parser) noexcept : Failure(loadGKWException(defaultSourceFilePath, group, keyword, parser)), Exception(_reason),Detailed_Loaded_Exception(group, keyword, senderFunction, senderFile, parser), Log_Exception_Base(logPath)
{
}


Log_Detailed_Loaded_Exception::Log_Detailed_Loaded_Exception(File& sourceFile, unsigned const &line, std::string const &senderFunction, std::string const &senderFile, std::string const& logPath) noexcept : Failure(sourceFile.readLine(line)), Exception(_reason), Detailed_Loaded_Exception(sourceFile, line, senderFunction, senderFile), Log_Exception_Base(logPath)
{
}


Log_Detailed_Loaded_Exception::Log_Detailed_Loaded_Exception(KWFile& sourceFile, std::string &keyword, std::string const &senderFunction, std::string const &senderFile, std::string const& logPath, char const &parser) noexcept : Failure(sourceFile.readKeywordValue(keyword, parser)), Exception(_reason), Detailed_Loaded_Exception(sourceFile, keyword, senderFunction, senderFile, parser), Log_Exception_Base(logPath)
{
}


Log_Detailed_Loaded_Exception::Log_Detailed_Loaded_Exception(GFile& sourceFile, std::string const& group, std::string const& keyword, std::string const &senderFunction, std::string const &senderFile, std::string const& logPath, char const &parser) noexcept : Failure(sourceFile.readGKeywordValue(group, keyword, parser)), Exception(_reason), Detailed_Loaded_Exception(sourceFile, group, keyword, senderFunction, senderFile, parser), Log_Exception_Base(logPath)
{
}


Log_Detailed_Loaded_Exception::~Log_Detailed_Loaded_Exception()
{
}


void Log_Detailed_Loaded_Exception::log() const noexcept
{
  std::string toLog = "[" + _date + "] : " + _reason + ". Sent from function : " + _senderFunction + ", from file : " + _senderFile + ".";
  File Log(_logPath);
  if(! Log.exist())
    Log.create();
  Log.insert(toLog, 1);
}
