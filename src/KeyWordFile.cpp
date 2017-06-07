//KeyWordFile.cpp

#include <algorithm>

#include "KeyWordFile.hh"
#include "Exception.hpp"


stb::KeyWordFile::KeyWordFile(std::string const &filePath) : File(filePath)
{
}


std::string stb::KeyWordFile::removeSpaces(std::string const& line, char parser)
{
  std::string toReturn = "";
  unsigned size = line.length();
  for(unsigned count = 0; count < size; ++count)
  {
    if((line[count] == ' ' && toReturn == "") ||
    (line[count] == ' ' && line[count+1] == ' ') ||
    (line[count] == ' ' && (line[count+1] == parser || line[count-1] == parser)) ||
    (line[count] == ' ' && count == size-1))
    {}
    else
      toReturn += line[count];
  }
  return toReturn;
}


unsigned stb::KeyWordFile::findKeyword(std::string const &keyword , char const &parser)
{
  if(isOpen())
  {
    _file->seekg(0, std::ios::beg);
    std::string text;
    
    for(unsigned line = 0; _file->rdstate() == std::fstream::goodbit; ++line)
	  {
	    std::getline(*_file, text);
	    
	    if(text.find_first_of(parser) != text.find_last_of(parser) &&
	    text.find_first_of(parser) != std::string::npos)
	    {
	      text = removeSpaces(text, parser);
	      if(text.substr(0, keyword.length() + 1) == keyword+parser) //+1 pour le parser
	        return (line);
	    }
	  }
	  return (0);
  }
  else
    throw File_Close("unsigned stb::KeyWordFile::findKeyword(std::string const&, char const&)", __FILE__);
}


bool stb::KeyWordFile::keywordExist(std::string const &keyword, char const &parser)
{
  if(findKeyword(keyword, parser) != 0)
    return true;
  return false;
}


std::string stb::KeyWordFile::readKeywordValue(std::string const &keyword, char const &parser)
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
    throw File_Close("std::string stb::KeyWordFile::readKeywordValue(std::string const&, char const&)", __FILE__);
}


void stb::KeyWordFile::writeKeywordValue(std::string const &keyword, std::string const &text, char const &parser)
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


void stb::KeyWordFile::addKeyword(std::string const &keyword, char const &parser, std::string const &text)
{
  if(! keywordExist(keyword, parser))
    write(keyword + parser + text, 0);
}


void stb::KeyWordFile::removeKeyword(std::string const &keyword, char const &parser)
{
  removeLine(findKeyword(keyword, parser));
}


std::vector<std::string> stb::KeyWordFile::readOpt(std::string const &keyword, char const &parser)
{
  std::vector<std::string> list;
  unsigned line = findKeyword(keyword, parser);
  if(line != 0)
  {
    std::string content = readLine(line);
    content.substr(0, content.find_first_of("\\"));
    /////////.......................
  }
  
  return list;
}

/*
void stb::KeyWordFile::addOpt(std::string const &keyword, char const &parser, std::string const& opt)
{

}


void stb::KeyWordFile::removeOpt(std::string const &keyword, char const &parser, std::string const& opt)
{

}
*/
