//Basic_File.cpp

#include "Basic_File.hpp"


Basic_File::Basic_File() : Directory_Item(""), _file(nullptr), _state(state::good)
{
}


Basic_File::Basic_File(std::string const &path) : Directory_Item(path), _file(new std::fstream(_path.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::app)), _state(_file == nullptr ?state::fail : state::good)
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
 
  std::fstream tmpFile(path.c_str(), std::ios_base::out); //std::ios_base::out OU std::ios_base::trunc SEULS pour qu'un fichier soit créé
  if(tmpFile)
  {
    tmpFile.close();
    chmod(path.c_str(), mode);
    return true;
  }
  return false;
}


bool Basic_File::createAll(std::string const& path, mode_t mode)
{
  if(! Directory::exist(extractDirPath(path)))
  {
    Directory::createAll(extractDirPath(path), mode);
  }
  std::fstream tmpFile(path.c_str(), std::ios_base::out); //std::ios_base::out OU std::ios_base::trunc SEULS pour qu'un fichier soit créé
  if(tmpFile)
  {
    tmpFile.close();
    chmod(path.c_str(), mode);
    return true;
  }
  return false;
}


std::string Basic_File::getStateStr() const
{
  if(_state == fstate::good)
    return "GOOD";
  else if(_state == fstate::badarg)
    return "BAD_ARG";
  else if(_state == fstate::open)
   return "OPEN: must be close";
  else if(_state == fstate::close)
    return "CLOSE: must be open";
  else if(_state == state::nopath)
    return "NO_PATH";
  else
    return "FAIL";
}


Basic_File::state Basic_File::getState() const
{
  return _state;
}


int Basic_File::rdstate() const
{
  return _file->rdstate();
}


void Basic_File::clearState()
{
  _state = state::good;
}


bool Basic_File::exist() const
{
  if(isPathSet())
  {
    return(exist(_path));
  }
  throw(DException("no_path", "bool Basic_File::exist()", __FILE__));
}


bool Basic_File::isOpen() const
{
  if(_file == nullptr || ! _file->is_open())
    return false;
  else
    return true;
}


bool Basic_File::isGood() const
{
  if(_state == state::good)
    return true;
  return false;
}


bool Basic_File::create(mode_t mode)
{
  clearState();
  if(isPathSet())
    if(! exist())
      return create(_path, mode);
    else
      _state = state::fail;
  else
    _state = state::nopath;
  return false;
}


bool Basic_File::createAll(mode_t mode)
{
  clearState();
  if(isPathSet())
    if(! exist())
      return createAll(_path, mode);
    else
      _state = state::fail;
  else
    _state = state::nopath;
  return false;
}


void Basic_File::open()
{
  clearState();
  if(! isOpen())
  {
    if(isPathSet())
	  {
	    if(! exist())
	      create();	
	          
      _file = new std::fstream(_path.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::app); //in et out pour pouvoir écrire et lire, app pour écrire à la fin par défaut
      if(_file->rdstate() == std::fstream::goodbit)
	      ;
      else
	    {
	      _state = state::fail;
	      delete _file;
	      _file = nullptr;
		    }
		  
	  }
    else
	    _state = state::nopath;
  }
  else
    _state = state::open;
}


void Basic_File::open(std::string const& path)
{
  setPath(path);
  open();
}


void Basic_File::close()
{
  clearState();
  if(isOpen())
  {
    _file->clear();
    _file->close();
    if(_file->rdstate() == std::fstream::goodbit)
	  {
	    delete _file;
	    _file = nullptr;
	  }
    else
	    _state = state::fail;
  }
  else
    _state = state::close;
}


void Basic_File::rename(std::string const &name)
{
  clearState();
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
	          _path = dirPath + name;
	        else
	          _state = state::fail;
	      }
        else
	        _state = state::fail;
      }
      else
        _state = state::badarg;
    }
    else
      _state = state::nopath;
  }
  else
    _state = state::open;
}


void Basic_File::move(std::string const &dir)
{
  clearState();
  if(! isOpen())
  {
    if(isPathSet())
	  {
      if(dir.find_last_of("/") != dir.length() - 1)
      {	      
        size_t character = _path.find_last_of("/");
        if(character == std::string::npos)
	        character = 0;
        std::string fileName(_path.substr(character, _path.length()));
        if(exist() && ! exist(dir + '/' + fileName))
	      {
	        if(! Directory::exist(dir.c_str()))
	        {
	          Directory Dir(dir.c_str());
	          Dir.create(m777);
	        }
	        if(std::rename(_path.c_str(), (dir + '/' + fileName).c_str()) == 0)
	          _path = dir + '/' + fileName;
	        else
	          _state = state::fail;
	      }
        else
	        _state = state::fail;
	    }
      else
        _state = state::badarg;    
	  }
    else
	    _state = state::nopath;
  }
  else
    _state = state::open;
}


void Basic_File::remove()
{
  clearState();
  if(! isOpen())
  {
    if(isPathSet())
	  {
	    if(std::remove(_path.c_str()) == 0)
	      ;
	    else
	      _state = state::fail;
	  }
    else
	    _state = state::nopath;
  }
  else
    _state = state::open;
}
