//Error.cpp

#include "Error.hh"
#include "KeyWordFile.hh"
#include "time.h"


std::string stb::Error::defaultSourcePath = "error.src";


stb::Error::Error(std::string const& reason) : _reason(reason), _date(Date::dateTime())
{
}


stb::Error::Error(unsigned const &line, std::string const& sourcePath) : _reason(loadReason(line, sourcePath)), _date(Date::dateTime())
{
}


stb::Error::Error(std::string const &keyword, char const &parser, std::string const& sourcePath) : _reason(loadReason(keyword, parser, sourcePath)), _date(Date::dateTime())
{
}


stb::Error::~Error()
{
}


std::string stb::Error::loadReason(unsigned const& line, std::string const &path)
{
  File sourceFile(path);
  return sourceFile.readLine(line);
}


std::string stb::Error::loadReason(std::string const &keyword, char const &parser, std::string const &path)
{
  KeyWordFile sourceFile(path);
  return sourceFile.readKeywordValue(keyword, parser);
}


void stb::Error::setDefaultSourcePath(std::string const& path)
{
  defaultSourcePath = path;
}


std::string stb::Error::getDefaultSourcePath()
{
  return defaultSourcePath;
}


std::string stb::Error::getDate() const
{
  return _date;
}


const char* stb::Error::err() const
{
  return _reason.c_str();
}



  /////////////////////////////////////////////////////////////////////////////////////



stb::Detailed_Error::Detailed_Error(std::string const& reason, std::string const &senderFunction, std::string const &senderFile) : Error(reason), _senderFunction(senderFunction), _senderFile(senderFile)
{
}


stb::Detailed_Error::Detailed_Error(unsigned const &line, std::string const &senderFunction, std::string const &senderFile, std::string const& sourcePath) : Error(line, sourcePath), _senderFunction(senderFunction), _senderFile(senderFile)
{
}


stb::Detailed_Error::Detailed_Error(std::string const &keyword, std::string const &senderFunction, std::string const &senderFile, char const &parser, std::string const& sourcePath) : Error(keyword, parser, sourcePath), _senderFunction(senderFunction), _senderFile(senderFile)
{
}


std::string stb::Detailed_Error::getSenderFunction() const noexcept
{
  return _senderFunction;
}


std::string stb::Detailed_Error::getSenderFile() const noexcept
{
  return _senderFile;
}



  /////////////////////////////////////////////////////////////////////////////////////



stb::Log_Error::Log_Error(std::string const& reason, std::string const& logPath) : Error(reason), Loggable_Error(logPath)
{
}


stb::Log_Error::Log_Error(unsigned const &line) : Error(line, defaultSourcePath), Loggable_Error(defaultLogPath)
{
}


stb::Log_Error::Log_Error(std::string const &keyword, char const &parser) : Error(keyword, parser, defaultSourcePath), Loggable_Error(defaultLogPath)
{
}


stb::Log_Error::Log_Error(unsigned const& line, file const& type, std::string const& path) : Error(line, type == file::source ? path : defaultSourcePath), Loggable_Error(type == file::log ? path : defaultLogPath)
{
}


stb::Log_Error::Log_Error(std::string const& keyword, char const &parser, file const& type, std::string const& path) : Error(keyword, parser, type == file::source ? path : defaultSourcePath), Loggable_Error(type == file::log ? path : defaultLogPath)
{
}


stb::Log_Error::Log_Error(unsigned const &line, std::string const& sourcePath, std::string const& logPath) : Error(line, sourcePath), Loggable_Error(logPath)
{
}


stb::Log_Error::Log_Error(std::string const &keyword, char const &parser, std::string const& sourcePath, std::string const& logPath) : Error(keyword, parser, sourcePath), Loggable_Error(logPath)
{
}


void stb::Log_Error::log() const 
{
  std::string toLog = "[" + _date + "] : " + _reason + ".";
  File Log(_logPath);
  Log.insert(toLog, 1);
}



  /////////////////////////////////////////////////////////////////////////////////////



stb::Log_Detailed_Error::Log_Detailed_Error(std::string const& reason, std::string const &senderFunction, std::string const &senderFile, std::string const& logPath) : Detailed_Error(reason, senderFunction, senderFile), Loggable_Error(logPath)
{
}


stb::Log_Detailed_Error::Log_Detailed_Error(unsigned const &line, std::string const &senderFunction, std::string const &senderFile) : Detailed_Error(line, senderFunction, senderFile, defaultSourcePath), Loggable_Error(defaultLogPath)
{
}


stb::Log_Detailed_Error::Log_Detailed_Error(std::string const &keyword, std::string const &senderFunction, std::string const &senderFile, char const &parser) : Detailed_Error(keyword, senderFunction, senderFile, parser, defaultSourcePath), Loggable_Error(defaultLogPath)
{
}


stb::Log_Detailed_Error::Log_Detailed_Error(unsigned const& line, std::string const &senderFunction, std::string const &senderFile, file const& type, std::string const& path) : Detailed_Error(line, senderFunction, senderFile, type == file::source ? path : defaultSourcePath), Loggable_Error(type == file::log ? path : defaultLogPath)
{
}


stb::Log_Detailed_Error::Log_Detailed_Error(std::string const& keyword, std::string const &senderFunction, std::string const &senderFile, char const &parser, file const& type, std::string const& path) : Detailed_Error(keyword, senderFunction, senderFile, parser, type == file::source ? path : defaultSourcePath), Loggable_Error(type == file::log ? path : defaultLogPath)
{
}


stb::Log_Detailed_Error::Log_Detailed_Error(unsigned const &line, std::string const &senderFunction, std::string const &senderFile, std::string const& sourcePath, std::string const& logPath) : Detailed_Error(line, senderFunction, senderFile, sourcePath), Loggable_Error(logPath)
{
}


stb::Log_Detailed_Error::Log_Detailed_Error(std::string const &keyword, std::string const &senderFunction, std::string const &senderFile, char const &parser, std::string const& sourcePath, std::string const& logPath) : Detailed_Error(keyword, senderFunction, senderFile, parser, sourcePath), Loggable_Error(logPath)
{
}


void stb::Log_Detailed_Error::log() const 
{
  std::string toLog = "[" + _date + "] : " + _reason + ". Sent from function : " + _senderFunction + ", from file : " + _senderFile + ".";
  File Log(_logPath);
  Log.insert(toLog, 1);
}
