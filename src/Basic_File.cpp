//Basic_File.cpp

#include "Basic_File.hpp"
#include "general_exceptions.hpp"


Basic_File::Basic_File() : Directory_Item(""), _file(nullptr)
{
}


Basic_File::Basic_File(std::string const &path, mode_t mode) : Directory_Item(path), _file(newFile(_path, mode))
{
}


Basic_File::~Basic_File()
{
  if(_file != nullptr)
  {
    _file->close();
    delete _file;
    _file = nullptr;
  }
}


bool Basic_File::exist(std::string const &path)
{
  std::fstream tmpFile(path.c_str());
  if(tmpFile)
    return true;
  else
    return false;
}


bool Basic_File::create(std::string const& path, mode_t mode)
{
  if(! exist(path))
  {
    std::fstream tmpFile(path.c_str(), std::fstream::out | std::fstream::in | std::fstream::trunc);
    if(tmpFile)
    {
      tmpFile.close();
      mode+=0;
      //_chmod(path.c_str(), mode);
      return true;
    }
    return false;
  }
  return true;
}


bool Basic_File::createAll(std::string const& path, mode_t mode)
{
  Directory::createAll(extractDirPath(path), mode);
  return create(path, mode);
}


std::fstream* Basic_File::newFile(std::string const& path, mode_t mode)
{
  if(create(path, mode))
    return new std::fstream(path.c_str(), std::fstream::out | std::fstream::in); //on ne met ni ate ni trunc pour lire le fichier au début (ni app car ça ne va pas avec fstream, mais avec ofstream seulement)
  throw DException("Unable to open file : " + path , "bool Basic_File::newFile(std::string const&, mode_t)", __FILE__);
}


int Basic_File::getState() const
{
  return _file->rdstate();
}


std::string Basic_File::getStateStr() const
{
  if(_file->good())
    return "no problem";
  else if(_file->eof())
    return "end of file reached";
  else if(_file->bad())
    return "reading/writing error";
  else if(_file->fail()) //on teste fail() seul en dernier car il peut être true pour plusieurs raison
    return "Logical error on i/o operation";
  else
    return "unknown error";
}


bool Basic_File::exist() const
{
  if(isPathSet())
    return(exist(_path));
  return false;
}


bool Basic_File::isOpen() const
{
  if(_file == nullptr || ! _file->is_open())
    return false;
  else
    return true;
}


bool Basic_File::create(mode_t mode) const
{
  if(isPathSet())
      return create(_path, mode);
  return false;
}


bool Basic_File::createAll(mode_t mode) const
{
  if(isPathSet())
      return createAll(_path, mode);
  return false;
}


bool Basic_File::open(mode_t mode)
{
  if(! isOpen())
  {
    if(isPathSet())
	  {	      	          
      _file = newFile(_path, mode); //in et out pour pouvoir écrire et lire, app pour écrire à la fin par défaut
      if(! *_file)
	    {
        delete _file;
        _file = nullptr;
		  }
		  else
		    return true;	  
	  }
  }
  return false;
}


bool Basic_File::open(std::string const& path, mode_t mode)
{
  if(setPath(path))
    return open(mode);
  return false;
}


bool Basic_File::close()
{
  if(isOpen())
  {
    _file->clear();
    _file->close();
    if(_file->rdstate() == std::fstream::goodbit)
	  {
	    delete _file;
	    _file = nullptr;
	    return true;
	  }
	}
	return false;
}


bool Basic_File::rename(std::string const &name)
{
  if(! isOpen())
  {
    if(isPathSet())
    {
      if(name.find_first_of("/") == std::string::npos && name != "")
      {
	      std::string dirPath = extractDirPath();
	      if(dirPath != "")
	        dirPath += '/';
        if(exist() && ! exist(dirPath + name))
	      {
	        if(std::rename(_path.c_str(), (dirPath + name).c_str()) == 0)
	        {
	          _path = dirPath + name;
	          return true;
	        }
	      }
      }
    }
  }
  return false;	        
}


bool Basic_File::move(std::string const &dir)
{
  if(! isOpen())
  {
    if(isPathSet())
	  {
      if(dir.find_last_of("/") != dir.length() - 1)
      {	      
        std::string fileName(_path.substr(extractDirPath().length(), _path.length()));
        if(exist() && ! exist(dir + '/' + fileName))
        {
          if(std::rename(_path.c_str(), (dir + '/' + fileName).c_str()) == 0)
          {
            _path = dir + '/' + fileName;
            return true;
          }
        }
	    }    
	  }
  }
  return false;
}


bool Basic_File::remove() const
{
  if(! isOpen())
  {
    if(isPathSet())
	  {
	    if(std::remove(_path.c_str()) == 0)
	      return true;
	  }
  }
  return false;
}
