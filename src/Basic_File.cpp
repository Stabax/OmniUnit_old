//Basic_File.cpp

#include "Basic_File.hh"
#include "Directory.hh"



stb::File_Exception::File_Exception(std::string const& reason, std::string const& senderFunction, std::string const& senderFile, std::string const& logPath) noexcept : Exception(reason, senderFunction, senderFile, logPath){}


mode_t stb::Basic_File::defaultMode = m755;


stb::Basic_File::Basic_File(std::string const& path, mode_t mode) : Directory_Item(path), _file(newFile(_path, mode))
{
}


stb::Basic_File::~Basic_File()
{
  if(_file != nullptr)
  {
    _file->close();
    delete _file;
    _file = nullptr;
  }
}


bool stb::Basic_File::exist(std::string const& path)
{
  errno = 0;
  std::ifstream tmpFile(path.c_str()); //ifstream permet de tester les fichiers même en read-only
  
  if(errno == ENOENT)
    return false;
  else if(errno == EACCES)
    throw File_Exception("Permission to work with file DENIED", "stb::Basic_File::exist(std::string const&)", __FILE__);
  else
    return true;
}


void stb::Basic_File::create(std::string const& path, mode_t mode)
{
  if(! exist(path))
  {
    errno = 0;
    std::fstream tmpFile(path.c_str(), std::fstream::out | std::fstream::in | std::fstream::trunc);
    int err = errno;
    
    if(exist(path))
    {
      tmpFile.close();
      mode+=0;
      //_chmod(path.c_str(), mode);
      //TESTER CHMOD
    }
    else if(err == EROFS)
      throw Directory_Exception("Directory is read-only", "stb::Basic_File::create(std::string const&, mode_t)", __FILE__);
    else if(err == EACCES)
      throw Directory_Exception("Permission to work with directory DENIED", "stb::Basic_File::create(std::string const&, mode_t)", __FILE__);
    else
      throw File_Exception("Unknown issue", "stb::Basic_File::create(std::string const&, mode_t)", __FILE__);
  } 
  else
    throw File_Exception("File already exists", "stb::Basic_File::create(std::string const&, mode_t)", __FILE__);
}


void stb::Basic_File::createAll(std::string const& path, mode_t mode)
{
  Directory::createAll(extractDirPath(path), mode);
  create(path, mode);
}


std::fstream* stb::Basic_File::newFile(std::string const& path, mode_t mode)
{
  if(! exist(path))
    create(path, mode);

  errno = 0;
  std::fstream* file = new std::fstream(path.c_str(), std::fstream::out | std::fstream::in); //on ne met ni ate ni trunc pour lire le fichier au début (ni app car ça ne va pas avec fstream, mais avec ofstream seulement)
  if(file != nullptr)
    return file;
  else if(errno == EROFS)
      throw File_Exception("File is read-only", "std::fstream* stb::Basic_File::newFile(std::string const&, mode_t)", __FILE__);
  else if(errno == EACCES)
    throw File_Exception("Permission to work with file DENIED", "std::fstream* stb::Basic_File::newFile(std::string const&, mode_t)", __FILE__);
  else
    throw File_Exception("Unknown issue", "std::fstream* stb::Basic_File::newFile(std::string const&, mode_t)", __FILE__);
}


mode_t stb::Basic_File::getDefaultMode()
{
  return defaultMode;
}


void stb::Basic_File::setDefaultMode(mode_t mode)
{
  defaultMode = mode;
}


std::fstream::iostate stb::Basic_File::getState() const
{
  return _file->rdstate();
}


std::string stb::Basic_File::getStateStr() const
{
  if(_file->good())
    return "good";
  else if(_file->eof())
    return "end of file reached";
  else if(_file->bad())
    return "reading/writing error";
  else if(_file->fail()) //on teste fail() seul en dernier car il peut être true pour plusieurs raisons (dont quand eof() est vrai)
    return "Logical error on i/o operation";
  else
    return "unknown error";
}


bool stb::Basic_File::good() const
{
  return _file->good();
}


bool stb::Basic_File::eof() const
{
  return _file->eof();
}


bool stb::Basic_File::bad() const
{
  return _file->bad();
}


bool stb::Basic_File::fail() const
{
  return _file->fail();
}
    

bool stb::Basic_File::exist() const
{
  return(exist(_path));
}


bool stb::Basic_File::isOpen() const
{
  if(_file == nullptr || ! _file->is_open())
    return false;
  else
    return true;
}


void stb::Basic_File::create(mode_t mode) const
{
  create(_path, mode);
}


void stb::Basic_File::createAll(mode_t mode) const
{
  createAll(_path, mode);
}


void stb::Basic_File::open(mode_t mode)
{
  if(! isOpen())  	          
    _file = newFile(_path, mode);
    //Pas de test a faire, newFile lève déjà des exceptions
}


void stb::Basic_File::close()
{
  if(isOpen())
  {
    _file->clear();
    _file->close();
    if(_file->rdstate() == std::fstream::goodbit)
	  {
	    delete _file;
	    _file = nullptr;
	  }
	}
}


void stb::Basic_File::rename(std::string const& name)
{
  if(isOpen())
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
        }
      }
    }
    else
      throw File_Exception("Invalid argument", "stb::Basic_File::rename(std::string const&)", __FILE__);
  }
  else
    throw File_Exception("File is open and need to be close", "stb::Basic_File::rename(std::string const&)", __FILE__);
}


void stb::Basic_File::move(std::string const& dir)
{
  if(! isOpen())
  {
    if(dir.find_last_of("/") != dir.length() - 1)
    {	      
      std::string fileName(_path.substr(extractDirPath().length(), _path.length()));
      if(exist() && ! exist(dir + '/' + fileName))
      {
        if(std::rename(_path.c_str(), (dir + '/' + fileName).c_str()) == 0)
        {
          _path = dir + '/' + fileName;
        }
      }
    }    
  }
  throw File_Exception("File is open and need to be close", "stb::Basic_File::move(std::string const&)", __FILE__);
}


void stb::Basic_File::remove() const
{
  if(! isOpen())
  {
    if(std::remove(_path.c_str()) == 0)
    {}
  }
  else
    throw File_Exception("File is open and need to be close", "stb::Basic_File::rename(std::string const&)", __FILE__);
}
