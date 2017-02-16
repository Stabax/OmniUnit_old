//GroupedKeyWordFile.cpp

#include "GroupedKeyWordFile.hpp"
#include "general_exceptions.hpp"


GroupedKeyWordFile::GroupedKeyWordFile() : KeyWordFile()
{
}


GroupedKeyWordFile::GroupedKeyWordFile(std::string const &filePath) : KeyWordFile(filePath)
{
}


GroupedKeyWordFile::~GroupedKeyWordFile()
{
}


unsigned GroupedKeyWordFile::findBegGroup(std::string const &group)
{
  if(isOpen())
    return (findKeyword(group, '{'));
  throw(DException("File -> " + _path + " is close.", "unsigned GroupedKeyWordFile::findBegGroup(std::string const&)", __FILE__));
}


unsigned GroupedKeyWordFile::findEndGroup(std::string const &group)
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
    throw(DException("File -> " + _path + " is close.", "unsigned GroupedKeyWordFile::findEndGroup(std::string const&)", __FILE__));
}


bool GroupedKeyWordFile::groupExist(std::string const &group)
{
  if(findBegGroup(group) != 0 && findEndGroup(group) != 0)
    return true;
  return false;
}


unsigned GroupedKeyWordFile::findGKeyword(std::string const &group, std::string const &keyword, char const &parser)
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
    throw(DException("File -> " + _path + " is close.", "unsigned GroupedKeyWordFile::findGKeyword(std::string const&, std::string const&, char const&)", __FILE__));
}


bool GroupedKeyWordFile::gKeywordExist(std::string const &group, std::string const &keyword, char const &parser)
{
  if(findGKeyword(group, keyword, parser) != 0)
    return true;
  return false;
}

  
std::string GroupedKeyWordFile::readGKeywordValue(std::string const &group, std::string const &keyword, char const &parser)
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
    throw(DException("File -> " + _path + " is close.", "std::string GroupedKeyWordFile::readGKeywordValue(std::string const&, std::string const&, char const&)", __FILE__));
}


void GroupedKeyWordFile::writeGKeywordValue(std::string const &group, std::string const &keyword, std::string const &text, char const &parser)
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


void GroupedKeyWordFile::addGKeyword(std::string const &group, std::string const &keyword, std::string const &text, char const &parser)
{
  if(! gKeywordExist(group, keyword, parser))
    insert(keyword + parser + text, findEndGroup(group));
}


void GroupedKeyWordFile::removeGKeyword(std::string const &group, std::string const &keyword, char const &parser)
{
  removeLine(findGKeyword(group, keyword, parser));
}


void GroupedKeyWordFile::addGroup(std::string const &name)
{
  if(! groupExist(name))
  {
    write(name + "{", 0);
    write("}" + name, 0);
  }
}


void GroupedKeyWordFile::removeGroup(std::string const &name)
{
  removeLine(findBegGroup(name), findEndGroup(name) - findBegGroup(name) + 1);
}
