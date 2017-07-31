//Directory.cpp

#include "Directory.hh"


stb::Directory_Exception::Directory_Exception(std::string const &reason, std::string const &senderFunction, std::string const &senderFile, std::string const& logPath) noexcept : Exception(reason, senderFunction, senderFile, logPath){}


stb::Directory::Directory(std::string const& path) : Directory_Item(path), _dir(nullptr)
{
}


stb::Directory::~Directory()
{
  closedir(_dir); //s'occupe aussi de delete _dir
  _dir = nullptr;
}


bool stb::Directory::exist(std::string const& path)
{
  bool exist;
  const char* currentDir = getDirPath();
  if(chdir(path.c_str()) == 0)
    exist = true;
  else
    exist = false;
  if(chdir(currentDir) == 0)
    return (exist);
  throw Directory_Exception("Unable to access directory", "bool stb::Directory::exist(std::string const&)", __FILE__);
}


char* stb::Directory::getDirPath()
{
  char* path = getcwd(nullptr, PATH_MAX);
  if(path == nullptr)
  {
    if(errno == ERANGE || errno == ENAMETOOLONG)
      throw Directory_Exception("Directory Path exeeds PATH_MAX macro", "char* stb::Directory::getDirPath()", __FILE__);
    else if(errno == EACCES)
      throw Directory_Exception("Permission to work with directory DENIED", "char* stb::Directory::getDirPath()", __FILE__);
    else if(errno == ENOENT)
      throw Directory_Exception("Directory is unlinked", "char* stb::Directory::getDirPath()", __FILE__);
    else
      throw Directory_Exception("Unknown issue", "char* stb::Directory::getDirPath()", __FILE__);
  }
  return path;

}


std::string stb::Directory::firstDir(std::string const& path)
{
    return (path.substr(0, path.find_first_of("/\\")));
  return ("");
}


bool stb::Directory::create(std::string const& name, mode_t mode)
{
  mode += 0; //permet de compiler sous windows
  
  if(mkdir(name.c_str(), mode) == -1)
    return false;
  return true;
}


bool stb::Directory::createAll(std::string const& name, mode_t mode)
{
  mode += 0; //permet de compiler sous windows
  
  std::string path2(name);
  std::string toCreate = ""; 
  while(path2.find_first_of("/\\") != std::string::npos)
  {
    toCreate += firstDir(path2);
    if(! exist(toCreate))
      if(! create(toCreate, mode))
        return false;
    path2 = path2.substr(path2.find_first_of("/\\") + 1, path2.size());
    toCreate += '/';
  }
  return create(name, mode);
}


bool stb::Directory::exist() const
{
  return (exist(_path));
}


bool stb::Directory::isOpen() const
{
  if(_dir == nullptr)
    return false;
  return true;
}


void stb::Directory::open()
{
  if(exist())
    _dir = opendir(_path.c_str());
}


void stb::Directory::close()
{
  closedir(_dir);
}


bool stb::Directory::create(mode_t mode)
{
 return create(_path, mode);
}


bool stb::Directory::createAll(mode_t mode)
{
  return createAll(_path, mode);
}


std::vector<std::string> stb::Directory::getContent()
{
  std::vector<std::string> content;
  struct dirent *fileInfo = nullptr;
  rewinddir(_dir);
  
  while((fileInfo = readdir(_dir)) != nullptr)
    content.push_back(fileInfo -> d_name);

  return content;
}


std::vector<long> stb::Directory::getId()
{
  std::vector<long> id;
  rewinddir(_dir);
  
  while(readdir(_dir) != nullptr)
  {
    id.push_back(telldir(_dir));   
  }
  
  return id;
}
