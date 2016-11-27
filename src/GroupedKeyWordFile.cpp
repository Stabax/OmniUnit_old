//GroupedKeyWordFile.cpp

#include "GroupedKeyWordFile.hpp"

GroupedKeyWordFile::GroupedKeyWordFile(std::string const &filePath) : KeyWordFile(filePath)
{
}

GroupedKeyWordFile::~GroupedKeyWordFile()
{
}

unsigned GroupedKeyWordFile::findBegGroup(std::string const &group)
{
  if(isOpen())
  {
    return (findKeyword(group, "{"));
  }
  else
  {
    _state = state::close;
    throw(DException("close", "unsigned GroupedKeyWordFile::findBegGroup(std::string const&)", __FILE__));
  }
}

unsigned GroupedKeyWordFile::findEndGroup(std::string const &group)
{
  clearState();
  if(isOpen())
  {
    unsigned beg = findBegGroup(group);
    if(beg == 0)
      return(0);
    std::string lineContent;
    for(unsigned counter = 1; _file->rdstate() == std::fstream::goodbit && _state == state::good; counter++)
    {
      lineContent = readLine(beg + counter);
      if(lineContent[0] == '}' && lineContent.size() == 1)
        return (beg + counter);
    }
    return (0);
  }
  else
  {
    _state = state::close;
    throw(DException("close", "unsigned GroupedKeyWordFile::findEndGroup(std::string const&)", __FILE__));
  }
}

bool GroupedKeyWordFile::groupExist(std::string const &group)
{
  if(findBegGroup(group) != 0 && findEndGroup(group) != 0)
    return true;
  return false;
}
unsigned GroupedKeyWordFile::findGKeyword(std::string const &group, std::string const &keyword, std::string const &parser)
{
  clearState();
  if(isOpen())
  {
    if(groupExist(group))
    {
      unsigned counter = findBegGroup(group) + 1;
      unsigned end = findEndGroup(group);
      std::string lineContent;
      size_t keywordSize = keyword.size();
      size_t parserSize = parser.size();
      while(counter < end)
      {
        lineContent = readLine(counter);
        if(lineContent.substr(0, keywordSize + parserSize) == keyword+parser)
	        return (counter);
	      counter++;
      }
      return (0);
    }
    else
      return (0);
  }
  else
  {
    _state = state::close;
    throw(DException("close", "unsigned GroupedKeyWordFile::findGKeyword(std::string const&, std::string const&, std::string const&)", __FILE__));
  }
}

bool GroupedKeyWordFile::gKeywordExist(std::string const &group, std::string const &keyword, std::string const &parser)
{
  if(groupExist(group))
  {
    if(findGKeyword(keyword, parser) != 0)
      return true;
  }
  return false;
}
  
std::string GroupedKeyWordFile::readGKeywordValue(std::string const &group, std::string const &keyword, std::string const &parser)
{
  clearState();
  if(isOpen())
  {
    if(groupExist(group))
	  {
	    unsigned line = findGKeyword(group, keyword, parser);
	    if(line != 0)
	    {
	      std::string content = readLine(line);
	      return content.substr(keyword.size() + parser.size(), content.size());
	    }
	    else
	      return ("");
	  }
    else
	    return ("");
  }
  else
  {
    _state = state::close;
    throw(DException("close", "std::string GroupedKeyWordFile::readGKeywordValue(std::string const&, std::string const&, std::string const&)", __FILE__));
  }
}

void GroupedKeyWordFile::writeGKeywordValue(std::string const &group, std::string const &keyword, std::string const &text, std::string const &parser)
{
  clearState();
  if(isOpen())
  {
    if(groupExist(group))
	  {
	    unsigned line = findGKeyword(group, keyword, parser);
	    removeLine(line);
	    insert(keyword + parser + text, line);
	  }
    else
	    _state = state::fail;
  }
  else
    _state = state::close;
}

void GroupedKeyWordFile::addGKeyword(std::string const &group, std::string const &keyword, std::string const &text, std::string const &parser)
{
  if(! gKeywordExist(group, keyword, parser))
    insert(keyword + parser + text, findEndGroup(group));
}

void GroupedKeyWordFile::removeGKeyword(std::string const &group, std::string const &keyword, std::string const &parser)
{
  removeLine(findGKeyword(group, keyword, parser));
}

void GroupedKeyWordFile::addGroup(std::string const &name)
{
  if(! groupExist(name))
  {
    write(name + "{", 0);
    write("}", 0);
  }
}

void GroupedKeyWordFile::removeGroup(std::string const &name)
{
  removeLine(findBegGroup(name), findEndGroup(name) - findBegGroup(name) + 1);
}

