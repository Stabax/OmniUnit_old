//File.cpp

#include "File.hh"
#include "Exception.hpp"


stb::File_Close::File_Close(std::string const &senderFunction, std::string const &senderFile, std::string const& logPath) noexcept : File_Exception(senderFunction, senderFile, logPath){}





stb::File::File(std::string const &filePath) : Basic_File(filePath), _lastReadLine(0)
{
}


void stb::File::beginRead()
{
    _file->clear();
    _file->seekg(0, std::ios::beg);
    _lastReadLine = 0;
}


unsigned stb::File::getLineCount()
{
  if(isOpen())
  {
    beginRead();  
    std::string line;
    unsigned lineCount = 0;
    
    for(; _file->good(); ++lineCount)
      std::getline(*_file, line);
      
    if(lineCount == 1 && line == "")
      --lineCount;
    return lineCount;
  }
  throw File_Close("unsigned stb::File::getLineCount()", __FILE__);
}


void stb::File::nextLine(std::string& txt)
{
  std::getline(*_file, txt);
  ++_lastReadLine;
  if(! _file->good())
  {
    throw File_End_Reached("void stb::File::nextLine(std::string&)", __FILE__);
  }    
}


std::string stb::File::readLine(unsigned line)
{
  if(line != 0)
  {
    if(isOpen())
	  {
	    if(_lastReadLine >= line)
	      beginRead();
	      
	    std::string text;
	    while(_lastReadLine != line) //c'est la méthode nextLine qui incrémente _lastReadLine
	      nextLine(text);
	    return (text);
	  }
    else
	    throw File_Close("std::string stb::File::readLine(unsigned)", __FILE__);
  }
  else
    throw File_Invalid_Argument("std::string stb::File::readLine(unsigned)", __FILE__);
}


std::vector<std::string> stb::File::readLine(unsigned line, unsigned nbLines)
{
  if(isOpen())
  {
    unsigned lastLine = line + nbLines;
    unsigned currentLine = line;
    std::vector<std::string> vec(nbLines);
    try
    {
      std::string text;
      for(; currentLine < lastLine; ++currentLine)
      {
        text = readLine(currentLine); //c'est fait en deux étapes pour être sûr que le vecteur ne soit pas dans un état invalide lors d'une levée d'exception
        vec.at(currentLine - line) = text;
      }
    }
    catch(File_End_Reached const& e)
    {
      vec.resize(currentLine - line);
    }
    return vec;
  }
  else
    throw File_Close("std::vector<std::string> stb::File::readLine(unsigned, unsigned)", __FILE__);
}


std::vector<std::string> stb::File::readUntilEnd(unsigned line)
{
  if(isOpen())
  {
    std::vector<std::string> vec(1);
    size_t size = vec.size();
    
    unsigned currentLine = line;
    try
    {
      std::string text;
      for(;; ++currentLine)
      {
        if(size <= (currentLine - line) )
          vec.resize(size*=2); //augmentation exponentielle de la taille du vecteur, plutot qu'un ajout ligne par ligne (plus efficace)
        text = readLine(currentLine); //c'est fait en deux étapes pour être sûr que le vecteur ne soit pas dans un état invalide lors d'une levée d'exception
        vec.at(currentLine - line) = text;
      }
    }
    catch(File_End_Reached const& e)
    {
      vec.resize(currentLine - line);
    }
    return vec;
  }
  else
    throw File_Close("std::vector<std::string> stb::File::readLine(unsigned, unsigned)", __FILE__);
}

void stb::File::removeLine(unsigned line, unsigned nbLines)
{
  if(isOpen())
  {
    if(line != 0)
	  {
	    if(line <= getLineCount())
	    {
	      std::vector<std::string> fileContent = readUntilEnd(1);
	      size_t oldFileSize = fileContent.size();
	      
	      fileContent.erase(fileContent.begin() + static_cast<int>(line), fileContent.begin() + static_cast<int>(line + nbLines));
	      size_t newFileSize = fileContent.size();
	      
	      close();
	      remove();
	      create(); //IL FAUT TROUVER UN MOYEN DE RECUPERER MODE_T DU FICHIER POUR LE RECREER AVEC LES MEMES DROITS 
	      open();
	      
	      if(_lastReadLine > line)
	        _lastReadLine -= (oldFileSize - newFileSize);
	      
	      for(unsigned counter = 1; counter <= newFileSize; counter++)
		      *_file << fileContent.at(counter - 1) << '\n';
	    }
	  }
	  else
      throw File_Invalid_Argument("std::string stb::File::removeLine(unsigned, unsigned)", __FILE__);
  }
}


void stb::File::write(std::string const &text, unsigned n)
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


void stb::File::write(std::vector<std::string> const &text, unsigned n)
{
  size_t textSize = text.size();
  if(n == 0 || n >= getLineCount())
    for(unsigned counter = 0; counter < textSize; counter++)
      write(text[counter], 0);
  else
    for(unsigned counter = 0; counter < textSize; counter++)
      write(text[counter], n + counter);
}


void stb::File::insert(std::string const &text, unsigned n)
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


void stb::File::insert(std::vector<std::string> const &text, unsigned n)
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
