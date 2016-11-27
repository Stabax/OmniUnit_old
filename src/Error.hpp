//Error.hpp

/*
*
*
*
*/

//Error et Detailed_Exception devraient dériver d'une classe commune


#ifndef ERROR_H_
#define ERROR_H_

#include "Failure.hpp"
#include "GroupedKeyWordFile.hpp"

/*
class Error : public Failure
{
  //fonctions amies

public:
  //constructeurs
  Error();
  Error(std::string const &error, std::string const &eLogFilePath = errorLogFilePath);
  Error(std::string const &error, std::string const &senderFunction, std::string const &eLogFilePath = errorLogFilePath);
  Error(std::string const &error, int const &severity, std::string const &eLogFilePath = errorLogFilePath);
  Error(std::string const &error, std::string const &senderFunction, int const &severity, std::string const &eLogFilePath = errorLogFilePath);
  Error(File &source, int const &line, std::string const &eLogFilePath = errorLogFilePath);
  Error(KWFile &source, std::string const &keyword, std::string const &eLogFilePath = errorLogFilePath);
  Error(GFile &source, std::string const &group, std::string const &keyword, std::string const &eLogFilePath = errorLogFilePath);
  Error(GFile &source, std::string const &group, std::string const &eLogFilePath = errorLogFilePath);

  //destructeur
  virtual ~Error();

  //méthodes statiques
  static void setErrorLogFilePath(std::string const &path);
  static void setShowErrorDetails(bool const &value);

  //accesseurs
  int getSeverity();

  //mutateurs
  void setError(std::string const &error);
  void setSenderFunction(std::string const &senderFunction);
  void setSeverity(int const &severity);
  void setSourceFile(File &source, int const &line);
  void setSourceFile(KWFile &source, std::string const &keyword);
  void setSourceFile(GFile &source, std::string const &group, std::string const &keyword);
  void setSourceFile(GFile &source, std::string const &group);
  void setLogFilePath(std::string const &Path);
  void showDetails(bool const &showDetails);

  //méthodes
  virtual void log() const;
  virtual void display() const;

  //opérateurs méthodes ( =, (), [], -> )

protected:
  //attributs
  int m_severity;
  bool m_showDetails;

  static std::string errorLogFilePath;
  static bool showErrorDetails;
  
};
//opérateurs non méthodes (+, ++, -, --, +=, -=, /=, *=, %=, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )
*/
#endif //ERROR_H_
