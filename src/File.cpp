//File.cpp

#include "File.hh"
#include "Exception.hpp"


stb::File_Close::File_Close(std::string const& senderFunction, std::string const& senderFile, std::string const& logPath) noexcept : File_Exception(senderFunction, senderFile, logPath){}





stb::File::File(std::string const& filePath) : Basic_File(filePath)
{
}


unsigned stb::File::getLineCount()
{
  if(isOpen())
  {
    _file->clear();
    _file->seekg(0, std::ios::beg);
    std::string line;
    unsigned lineCount = 0;
    while(_file->rdstate() == std::fstream::goodbit)
    {
      std::getline(*_file, line);
      lineCount++;
    }
    if(lineCount == 1 && line == "")
      lineCount--;
    return (lineCount);
  }
  throw File_Close("unsigned stb::File::getLineCount()", __FILE__);
}


std::string stb::File::readLine(unsigned line)
{
  if(line != 0)
  {
    if(isOpen())
	  {
	    _file->clear();
	    _file->seekg(0, std::ios::beg);
	    std::string text;
	    for(unsigned ligne = 1; ligne <= line; ligne++)
	      std::getline(*_file, text);
	    return (text);
	  }
    else
	    throw File_Close("std::string stb::File::readLine(unsigned const&)", __FILE__);
  }
  else
    throw File_Invalid_Argument("std::string stb::File::readLine(unsigned const&)", __FILE__);
}


std::vector<std::string> stb::File::readLine(unsigned line, unsigned n)
{
  std::vector<std::string> text(0);
  if(getLineCount() >= line)
  {
    if(isOpen())
    {
      if(n == 0 || n >= getLineCount())
        n = getLineCount() - line + 1;
      _file->clear();
      _file->seekg(0, std::ios::beg);
      std::string tmpLine;
      for(unsigned ligne = 1; ligne <= line; ligne++)
      {
        std::getline(*_file, tmpLine);
        if(ligne == line)
        {
          text.push_back(tmpLine);
          for(unsigned ligne2 = 1; ligne2 < n; ligne2++)
          {
            std::getline(*_file, tmpLine);
            text.push_back(tmpLine);
          }
        }
      }
      return (text);
    }
    else
      throw File_Close("std::vector<std::string> stb::File::readLine(unsigned const&, unsigned)", __FILE__);
  }
  else
    return text;  
}


void stb::File::removeLine(unsigned line, unsigned n)
{
  if(isOpen())
  {
    if(line != 0)
	  {
	    if(line <= getLineCount())
	    {
	      std::vector<std::string> fileContent = readLine(1, getLineCount());
	      close();
	      remove();
	      create(); //IL FAUT TROUVER UN MOYEN DE RECUPERER MODE_T DU FICHIER POUR LE RECREER AVEC LES MEMES DROITS 
	      open();
	      size_t fileSize = fileContent.size();
	      for(unsigned counter = 1; counter <= fileSize; counter++)
	        if(counter < line || counter >= line + n)
		        *_file << fileContent[counter - 1] << '\n';
	    }
	  }
  }
}


void stb::File::write(std::string const& text, unsigned n)
{
  if(isOpen())
  {
    if(n == 0 || n > getLineCount())
      n = getLineCount() + 1;
    removeLine(n, getLineCount());
    _file->clear();
	  _file->seekp(0, std::ios::end);
    *_file << text << '\n';
  }
}


void stb::File::write(std::vector<std::string> const& text, unsigned n)
{
  size_t textSize = text.size();
  if(n == 0 || n >= getLineCount())
    for(unsigned counter = 0; counter < textSize; counter++)
      write(text[counter], 0);
  else
    for(unsigned counter = 0; counter < textSize; counter++)
      write(text[counter], n + counter);
}


void stb::File::insert(std::string const& text, unsigned n)
{
  if(isOpen())
  {
    if(getLineCount() == 0)
    {
       write(text, n);
    }
    else if(n != 0 && n <= getLineCount())
	  {
	    std::vector<std::string> fileContent = readLine(n, getLineCount());
	    write(text, n);
	    write(fileContent, 0);
	  }
  }
}


void stb::File::insert(std::vector<std::string> const& text, unsigned n)
{
  size_t textSize = text.size();
  for(unsigned counter = 0; counter < textSize; counter++)
    insert(text[counter], n + counter);
}


bool stb::File::isSameContent(File &a)
{
  std::vector<std::string> aContent = a.readLine(1, 0);
  std::vector<std::string> thisContent = readLine(1, 0);

  if(aContent.size() != thisContent.size())
    return (false);
  else
  {
    size_t aContentSize = aContent.size();
    for(unsigned counter = 0; counter < aContentSize; counter++)
      if(aContent[counter] != thisContent[counter])
        return (false);
  }
  return (true);
}
