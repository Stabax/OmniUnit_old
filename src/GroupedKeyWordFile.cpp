//GroupedKeyWordFile.cpp

#include "GroupedKeyWordFile.hh"
#include "Exception.hpp"

#include <utility>

stb::GroupedKeyWordFile::GroupedKeyWordFile(std::string const &filePath) : KeyWordFile(filePath)
{
}


unsigned stb::GroupedKeyWordFile::BegEndGoup(std::vector<std::string> const &group, bool isBeg)
{
  if(isOpen())
  {
    unsigned size = group.size();
    std::vector<std::pair<unsigned, unsigned>> limitOfGroup(size);

    if(groupExist(group.at(0)))
    {
      limitOfGroup.at(0).first = findBegGroup(group.at(0));
      limitOfGroup.at(0).second = findEndGroup(group.at(0));
    
      for(unsigned count = 1; count < size; count++)
      {
        unsigned beg = findBegGroup(group.at(count));
        unsigned end = findEndGroup(group.at(count));
        
        if(beg > limitOfGroup.at(count-1).first && end < limitOfGroup.at(count-1).second)
        {
          limitOfGroup.at(count).first = beg;
          limitOfGroup.at(count).second = end;
        }
        else
          return 0;
      }
      if(isBeg)
        return limitOfGroup.at(size - 1).first;
      return limitOfGroup.at(size - 1).second;
    }
    else
      return 0;
  }
  throw File_Close("unsigned stb::GroupedKeyWordFile::BegEndGroup(std::vector<std::string> const&, bool)", __FILE__);
}


unsigned stb::GroupedKeyWordFile::findBegGroup(std::string const &group)
{
  if(isOpen())
    return (findKeyword(group, '{'));
  throw File_Close("unsigned stb::GroupedKeyWordFile::findBegGroup(std::string const&)", __FILE__);
}


unsigned stb::GroupedKeyWordFile::findBegGroup(std::vector<std::string> const &group)
{
  return BegEndGoup(group, true);
}


unsigned stb::GroupedKeyWordFile::findEndGroup(std::string const &group)
{
  if(isOpen())
  {
    unsigned beg = findBegGroup(group);
    if(beg == 0)
      return(0); //TESTER SI END > BEG !!!!!!!
    std::string lineContent;
    for(unsigned counter = 1; _file->rdstate() == std::fstream::goodbit; counter++) //A CHANGER (une boucle sur readLine c'est pas ouf...)
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


unsigned stb::GroupedKeyWordFile::findEndGroup(std::vector<std::string> const &group)
{
  return BegEndGoup(group, false);
}






  




