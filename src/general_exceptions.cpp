//general_exceptions.cpp

#include "general_exceptions.hpp"


Exception::Exception(std::string const& reason) noexcept : Failure(reason)
{
}


Exception::~Exception()
{
}


const char* Exception::what() const noexcept
{
  return _reason.c_str();
}


/////////////////////////////////////////////////////////////////////////////

Detailed_Exception::Detailed_Exception(std::string const& reason, std::string const &senderFunction, std::string const &senderFile) noexcept : Failure(reason), Exception(_reason), Detailed_Failure(_reason, senderFunction, senderFile)
{
}


Detailed_Exception::~Detailed_Exception()
{
}


/////////////////////////////////////////////////////////////////////////////

std::string Loaded_Exception::defaultSourceFilePath = "exception.src";


Loaded_Exception::Loaded_Exception(unsigned const &line) noexcept : Failure(loadException(defaultSourceFilePath, line)), Exception(_reason)
{
}


Loaded_Exception::Loaded_Exception(std::string const &keyword, char const &parser) noexcept : Failure(loadKWException(defaultSourceFilePath, keyword, parser)), Exception(_reason)
{
}


Loaded_Exception::Loaded_Exception(std::string const& group, std::string const &keyword, char const &parser) noexcept : Failure(loadGKWException(defaultSourceFilePath, group, keyword, parser)), Exception(_reason)
{
}


Loaded_Exception::Loaded_Exception(File& sourceFile, unsigned const &line) noexcept : Failure(sourceFile.readLine(line)), Exception(_reason)
{
}


Loaded_Exception::Loaded_Exception(KWFile& sourceFile, std::string const& keyword, char const& parser) noexcept : Failure(sourceFile.readKeywordValue(keyword, parser)), Exception(_reason)
{
}


Loaded_Exception::Loaded_Exception(GFile& sourceFile, std::string const& group, std::string const& keyword, char const& parser) noexcept : Failure(sourceFile.readGKeywordValue(group, keyword, parser)), Exception(_reason)
{
}


Loaded_Exception::~Loaded_Exception()
{
}


void Loaded_Exception::setDefaultSourceFilePath(std::string const& path)
{
  defaultSourceFilePath = path;
}


std::string Loaded_Exception::loadException(std::string const& path, unsigned const& line)
{
  File sourceFile(path);
  return sourceFile.readLine(line);
}


std::string Loaded_Exception::loadKWException(std::string const &path, std::string const &keyword, char const &parser)
{
  KeyWordFile sourceFile(path);
  return sourceFile.readKeywordValue(keyword, parser);
}


std::string Loaded_Exception::loadGKWException(std::string const &path, std::string const& group, std::string const& keyword, char const &parser)
{
  GroupedKeyWordFile sourceFile(path);
  return sourceFile.readGKeywordValue(group, keyword, parser);
}


/////////////////////////////////////////////////////////////////////////////

Detailed_Loaded_Exception::Detailed_Loaded_Exception(unsigned const& line, std::string const &senderFunction, std::string const &senderFile) noexcept : Failure(loadException(defaultSourceFilePath, line)), Exception(_reason), Loaded_Exception(line), Detailed_Exception(_reason, senderFunction, senderFile)
{
}


Detailed_Loaded_Exception::Detailed_Loaded_Exception(std::string const& keyword, std::string const &senderFunction, std::string const &senderFile, char const &parser) noexcept : Failure(loadKWException(defaultSourceFilePath, keyword, parser)), Exception(_reason), Loaded_Exception(keyword, parser), Detailed_Exception(_reason, senderFunction, senderFile)
{
}


Detailed_Loaded_Exception::Detailed_Loaded_Exception(std::string const& group, std::string const& keyword, std::string const &senderFunction, std::string const &senderFile, char const &parser) noexcept : Failure(loadGKWException(defaultSourceFilePath, group, keyword, parser)), Exception(_reason), Loaded_Exception(group, keyword, parser), Detailed_Exception(_reason, senderFunction, senderFile)
{
}


Detailed_Loaded_Exception::Detailed_Loaded_Exception(File& sourceFile, unsigned const &line, std::string const &senderFunction, std::string const &senderFile) noexcept : Failure(sourceFile.readLine(line)), Exception(_reason), Loaded_Exception(sourceFile, line), Detailed_Exception(_reason, senderFunction, senderFile)
{
}


Detailed_Loaded_Exception::Detailed_Loaded_Exception(KWFile& sourceFile, std::string const &keyword, std::string const &senderFunction, std::string const &senderFile, char const &parser) noexcept  : Failure(sourceFile.readKeywordValue(keyword, parser)), Exception(_reason), Loaded_Exception(sourceFile, keyword, parser), Detailed_Exception(_reason, senderFunction, senderFile)
{
}


Detailed_Loaded_Exception::Detailed_Loaded_Exception(GFile& sourceFile, std::string const& group, std::string const& keyword, std::string const &senderFunction, std::string const &senderFile, char const &parser) noexcept: Failure(sourceFile.readGKeywordValue(group, keyword, parser)), Exception(_reason), Loaded_Exception(sourceFile, group, keyword, parser), Detailed_Exception(_reason, senderFunction, senderFile)
{
}


Detailed_Loaded_Exception::~Detailed_Loaded_Exception()
{
}
