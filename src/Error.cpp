//Error.cpp

#include "Error.hpp"
/*
std::string Error::errorLogFilePath = "error.log";
bool Error::showErrorDetails = true;

Error::Error() : Failure(errorLogFilePath), m_severity(-1), m_showDetails(showErrorDetails)
{
}

Error::Error(std::string const &error, std::string const &path) : Failure(error, path), m_severity(-1), m_showDetails(showErrorDetails)
{
}

Error::Error(std::string const &error, std::string const &senderFunction, std::string const &path) : Failure(error, senderFunction, path), m_severity(-1), m_showDetails(showErrorDetails)
{
}

Error::Error(std::string const &error, int const &severity, std::string const &path) : Failure(error, path), m_severity(severity), m_showDetails(showErrorDetails)
{
}

Error::Error(std::string const &error, std::string const &senderFunction, int const &severity, std::string const &path) : Failure(error, senderFunction, path), m_severity(severity), m_showDetails(showErrorDetails)
{
}

Error::Error(File &source, int const &line, std::string const &path) : Failure(source.readLine(line), path), m_severity(-1), m_showDetails(showErrorDetails)
{
}

Error::Error(KWFile &source, std::string const &keyword, std::string const &path) : Failure(source.readKeywordValue(keyword), path), m_severity(-1), m_showDetails(showErrorDetails)
{
}

Error::Error(GFile &source, std::string const &group, std::string const &keyword, std::string const &path) : Failure(source.readGKeywordValue(group, keyword), path), m_severity(-1), m_showDetails(showErrorDetails)
{
}

Error::Error(GFile &source, std::string const &group, std::string const &path) : Failure(source.readGKeywordValue(group, "ERROR"), path), m_severity(toNumber(source.readGKeywordValue(group, "SEVERITY"))), m_showDetails(showErrorDetails)
{
}

Error::Error::~Error()
{
}

void Error::setError(std::string const &error)
{
  m_fail = error;
}

void Error::setSenderFunction(std::string const &senderFunction)
{
  m_senderFunction = senderFunction;
}

void Error::setSeverity(int const &severity)
{
  m_severity = severity;
}

void Error::setSourceFile(File &source, int const &line)
{
}

void Error::setSourceFile(KWFile &source, std::string const &keyword)
{
}

void Error::setSourceFile(GFile &source, std::string const &group, std::string const &keyword)
{
}

void Error::setSourceFile(GFile &source, std::string const &group)
{
}

void Error::setLogFilePath(std::string const &path)
{
  m_logFilePath = path;
}

void Error::showDetails(bool const &showDetails)
{
  m_showDetails = showDetails;
}

void Error::log() const
{
}

void Error::display() const
{
}
*/
