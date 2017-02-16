//File.cpp

#include "File.hpp"
#include "general_exceptions.hpp"


File::File() : Basic_File()
{
}


File::File(std::string const &filePath) : Basic_File(filePath)
{
}


File::~File()
{
}


unsigned File::getLineCount()
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
  throw(DException("File -> " + _path + " is close.", "unsigned File::getLineCount()", __FILE__));
}


std::string File::readLine(unsigned const &line)
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
	    throw(DException("File -> " + _path + " is close.", "std::string File::readLine(unsigned const&)", __FILE__));
  }
  else
    throw(DException("Bad argument : line 0 doesn't exist.", "std::string File::readLine(unsigned const&)", __FILE__));
}


std::vector<std::string> File::readLine(unsigned const &line, unsigned n)
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
      throw(DException("File -> " + _path + " is close.", "std::vector<std::string> File::readLine(unsigned const&, unsigned)", __FILE__));
  }
  else
    return text;  
}


void File::removeLine(unsigned const &line, unsigned const &n)
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


void File::write(std::string const &text, unsigned n)
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


void File::write(std::vector<std::string> const &text, unsigned const &n)
{
  size_t textSize = text.size();
  if(n == 0 || n >= getLineCount())
    for(unsigned counter = 0; counter < textSize; counter++)
      write(text[counter], 0);
  else
    for(unsigned counter = 0; counter < textSize; counter++)
      write(text[counter], n + counter);
}


void File::insert(std::string const &text, unsigned const &n)
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


void File::insert(std::vector<std::string> const &text, unsigned const &n)
{
  size_t textSize = text.size();
  for(unsigned counter = 0; counter < textSize; counter++)
    insert(text[counter], n + counter);
}


bool File::isSameContent(File &a)
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
