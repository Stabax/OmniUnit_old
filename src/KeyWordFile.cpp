//KeyWordFile.cpp

#include "KeyWordFile.hpp"
#include "general_exceptions.hpp"


KeyWordFile::KeyWordFile() : File()
{
}


KeyWordFile::KeyWordFile(std::string const &filePath) : File(filePath)
{
}


KeyWordFile::~KeyWordFile()
{
}


unsigned KeyWordFile::findKeyword(std::string const &keyword , char const &parser)
{
  if(isOpen())
  {
    _file->clear();
    _file->seekg(0, std::ios::beg);
    std::string text;
    unsigned line = 0;
    while(_file->rdstate() == std::fstream::goodbit)
	  {
	    std::getline(*_file, text);
	    line++;
	    if(text.substr(0, keyword.length() + 1) == keyword+parser) //+1 pour le parser
	    {
	      return (line);
	    }
	  }
	  return (0);
  }
  else
    throw(DException("File -> " + _path + " is close.", "unsigned KeyWordFile::findKeyword(std::string const&, char const&)", __FILE__));
}


bool KeyWordFile::keywordExist(std::string const &keyword, char const &parser)
{
  if(findKeyword(keyword, parser) != 0)
    return true;
  return false;
}


std::string KeyWordFile::readKeywordValue(std::string const &keyword, char const &parser)
{
  if(isOpen())
  {
    unsigned line = findKeyword(keyword , parser);
    _file->clear();
    _file->seekg(0, std::ios::beg);
    std::string text;
    if(line != 0)
    {
      text = readLine(line);
      return (text.erase(0, keyword.length() + 1));    //+1 pour le parser
	  }
	  else
	    return (std::string(""));
  }
  else
    throw(DException("File -> " + _path + " is close.", "std::string KeyWordFile::readKeywordValue(std::string const&, char const&)", __FILE__));
}


void KeyWordFile::writeKeywordValue(std::string const &keyword, std::string const &text, char const &parser)
{
  if(isOpen())
  {
    _file->clear();
    unsigned line = findKeyword(keyword, parser);
    if(line != 0)
    {
      std::vector<std::string> fileContent = readLine(line + 1, getLineCount());
      removeLine(line, getLineCount());
      write(keyword + parser + text, 0);
      write(fileContent, 0);
    }
  }
}


void KeyWordFile::addKeyword(std::string const &keyword, std::string const &text, char const &parser)
{
  if(! keywordExist(keyword, parser))
    write(keyword + parser + text, 0);
}


void KeyWordFile::removeKeyword(std::string const &keyword, char const &parser)
{
  removeLine(findKeyword(keyword, parser));
}
