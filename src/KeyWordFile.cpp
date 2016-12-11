//KeyWordFile.cpp

#include "KeyWordFile.hpp"


KeyWordFile::KeyWordFile() : File()
{
}


KeyWordFile::KeyWordFile(std::string const &filePath) : File(filePath)
{
}


KeyWordFile::~KeyWordFile()
{
}


unsigned KeyWordFile::findKeyword(std::string const &keyword , std::string const &parser)
{
  clearState();
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
	    if(text.substr(0, keyword.length() + parser.length()) == keyword+parser)
	    {
	      return (line);
	    }
	  }
	  return (0);
  }
  else
  {
    _state = state::close;
    throw(DException("close", "unsigned KeyWordFile::findKeyword(std::string const&, std::string const&)", __FILE__));
  }
}


bool KeyWordFile::keywordExist(std::string const &keyword, std::string const &parser)
{
  if(findKeyword(keyword, parser) != 0)
    return true;
  return false;
}


std::string KeyWordFile::readKeywordValue(std::string const &keyword, std::string const &parser)
{
  clearState();
  if(isOpen())
  {
    unsigned line = findKeyword(keyword , parser);
    _file->clear();
    _file->seekg(0, std::ios::beg);
    std::string text;
    if(line != 0)
    {
      text = readLine(line);
      return (text.erase(0, keyword.length() + parser.length()));    
	  }
	  else
	    return (std::string(""));
  }
  else
  {
    _state = state::close;
    throw(DException("close", "std::string KeyWordFile::readKeywordValue(std::string const&, std::string const&)", __FILE__));
  }
}


void KeyWordFile::writeKeywordValue(std::string const &keyword, std::string const &text, std::string const &parser)
{
  clearState();
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
  else
    _state = state::close;
}


void KeyWordFile::addKeyword(std::string const &keyword, std::string const &text, std::string const &parser)
{
  if(! keywordExist(keyword, parser))
    write(keyword + parser + text, 0);
}


void KeyWordFile::removeKeyword(std::string const &keyword, std::string const &parser)
{
  removeLine(findKeyword(keyword, parser));
}
