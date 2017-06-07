//GroupedKeyWordFile.cpp

#include "GroupedKeyWordFile.hh"
#include "Exception.hpp"


stb::GroupedKeyWordFile::GroupedKeyWordFile(std::string const &filePath) : KeyWordFile(filePath)
{
}


unsigned stb::GroupedKeyWordFile::findBegGroup(std::string const &group)
{
  if(isOpen())
    return (findKeyword(group, '{'));
  throw File_Close("unsigned stb::GroupedKeyWordFile::findBegGroup(std::string const&)", __FILE__);
}


unsigned stb::GroupedKeyWordFile::findEndGroup(std::string const &group)
{
  if(isOpen())
  {
    unsigned beg = findBegGroup(group);
    if(beg == 0)
      return(0);
    std::string lineContent;
    for(unsigned counter = 1; _file->rdstate() == std::fstream::goodbit; counter++)
    {
      lineContent = readLine(beg + counter);
      if(lineContent == "}" + group)
        return (beg + counter);
    }
    return (0);
  }
  else
    throw File_Close("unsigned stb::GroupedKeyWordFile::findEndGroup(std::string const&)", __FILE__);
}


bool stb::GroupedKeyWordFile::groupExist(std::string const &group)
{
  if(findBegGroup(group) != 0 && findEndGroup(group) != 0)
    return true;
  return false;
}


unsigned stb::GroupedKeyWordFile::findGKeyword(std::string const &group, std::string const &keyword, char const &parser)
{
  if(isOpen())
  {
    if(groupExist(group))
    {
      unsigned counter = findBegGroup(group) + 1;
      unsigned end = findEndGroup(group);
      std::string lineContent;
      size_t keywordSize = keyword.size();
      while(counter < end)
      {
        lineContent = readLine(counter);
        if(lineContent.substr(0, keywordSize + 1) == keyword+parser) //+1 pour le parser
	        return (counter);
	      counter++;
      }
      return (0);
    }
    else
      return (0);
  }
  else
    throw File_Close("unsigned stb::GroupedKeyWordFile::findGKeyword(std::string const&, std::string const&, char const&)", __FILE__);
}


bool stb::GroupedKeyWordFile::gKeywordExist(std::string const &group, std::string const &keyword, char const &parser)
{
  if(findGKeyword(group, keyword, parser) != 0)
    return true;
  return false;
}

  
std::string stb::GroupedKeyWordFile::readGKeywordValue(std::string const &group, std::string const &keyword, char const &parser)
{
  if(isOpen())
  {
    if(groupExist(group))
	  {
	    unsigned line = findGKeyword(group, keyword, parser);
	    if(line != 0)
	    {
	      std::string content = readLine(line);
	      return content.substr(keyword.size() + 1, content.size());  //+1 pour le parser
	    }
	    else
	      return ("");
	  }
    else
	    return ("");
  }
  else
    throw File_Close("std::string stb::GroupedKeyWordFile::readGKeywordValue(std::string const&, std::string const&, char const&)", __FILE__);
}


void stb::GroupedKeyWordFile::writeGKeywordValue(std::string const &group, std::string const &keyword, std::string const &text, char const &parser)
{
  if(isOpen())
  {
    if(groupExist(group))
	  {
	    unsigned line = findGKeyword(group, keyword, parser);
	    removeLine(line);
	    insert(keyword + parser + text, line);
	  }
  }
}


void stb::GroupedKeyWordFile::addGKeyword(std::string const &group, std::string const &keyword, char const &parser, std::string const &text)
{
  if(! gKeywordExist(group, keyword, parser))
    insert(keyword + parser + text, findEndGroup(group));
}


void stb::GroupedKeyWordFile::removeGKeyword(std::string const &group, std::string const &keyword, char const &parser)
{
  removeLine(findGKeyword(group, keyword, parser));
}


void stb::GroupedKeyWordFile::addGroup(std::string const &name)
{
  if(! groupExist(name))
  {
    write(name + "{", 0);
    write("}" + name, 0);
  }
}


void stb::GroupedKeyWordFile::removeGroup(std::string const &name)
{
  removeLine(findBegGroup(name), findEndGroup(name) - findBegGroup(name) + 1);
}

/*
std::vector<std::string> stb::GroupedKeyWordFile::readGOpt(std::string const &group, std::string const &keyword, char const &parser)
{

}


void stb::GroupedKeyWordFile::addGOpt(std::string const &group, std::string const &keyword, char const &parser, std::string const& opt)
{

}


void stb::GroupedKeyWordFile::removeGOpt(std::string const &group, std::string const &keyword, char const &parser, std::string const& opt = "")
{

}
  */  

std::vector<std::string> stb::GroupedKeyWordFile::groupList()
{
  unsigned lineCount = getLineCount();
  std::vector<std::string> list;
  
  for(unsigned line = 0; line < lineCount; ++line)
  {
    std::string content = readLine(line);
    if(content.find_first_of("{") != std::string::npos)
    {
      std::string group = content.substr(0, content.find_first_of("{"));
      if(findEndGroup(group) != 0)
        list.push_back(group);
    }
  }

  return list;
}

