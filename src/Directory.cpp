//Directory.cpp

#include "Directory.hpp"

Directory::Directory(std::string const& path) : Directory_Item(path), _dir(nullptr)
{
}

Directory::~Directory()
{
  closedir(_dir); //s'occupe aussi de delete _dir
  _dir = nullptr;
}

bool Directory::exist(std::string path)
{
  bool exist;
  const char* currentDir = getDirPath();
  if(chdir(path.c_str()) == 0)
    exist = true;
  else
    exist = false;
  if(chdir(currentDir) == 0)
    return (exist);
  throw (std::string ("Unable to go to the main working directory: bool Directory::exist()."));
}

char* Directory::getDirPath()
{
  char* path = getcwd(nullptr, PATH_MAX);
  if(path == nullptr)
  {
    if(errno == ERANGE || errno == ENAMETOOLONG)
      throw(std::string("Path length of current working directory exceeds PATH_MAX macro : char* Directory::getDirPath()."));
    if(errno == EACCES)
      throw(std::string("Permission to get directory name DENIED : char* Directory::getDirPath()."));
    if(errno == EFAULT)
      throw(std::string("Segfault : char* Directory::getDirPath()."));
    if(errno == EINVAL)
      throw(std::string("invalid PATH_MAX macro : char* Directory::getDirPath()."));
    if(errno == ENOENT)
      throw(std::string("The current working directory is unlinked : char* Directory::getDirPath()."));
  }
  return path;

}

void Directory::open()
{
  if(isPathSet() && exist())
    _dir = opendir(_path.c_str());
}

void Directory::close()
{
  closedir(_dir);
}

std::string Directory::firstDir(const std::string path)
{
  if(path.find_first_of("/\\") != std::string::npos)
  {
    return (path.substr(0, path.find_first_of("/\\")));
  }
  return ("");
}

bool Directory::exist()
{
  return (exist(_path));
}


bool Directory::create(mode_t mode)
{
  std::string path2(_path);
  std::string toCreate; 
  while(path2.find_first_of("/\\") != std::string::npos)
  {
    toCreate = toCreate + firstDir(path2);
    if(! exist(toCreate.c_str()))
      if(mkdir(toCreate.c_str(), mode) == -1)
        return false;
    path2 = path2.substr(path2.find_first_of("/\\") + 1, path2.size());
    toCreate += '/';
  }
  mkdir(_path.c_str(), mode);
  mode += 0; //permet de compiler sous windows
  return true;
}

std::vector<std::string> Directory::getContent()
{
  std::vector<std::string> content;
  struct dirent *fileInfo = nullptr;
  rewinddir(_dir);
  
  while((fileInfo = readdir(_dir)) != nullptr)
    content.push_back(fileInfo -> d_name);

  return content;
}

std::vector<long> Directory::getId()
{
  std::vector<long> id;
  rewinddir(_dir);
  
  while(readdir(_dir) != nullptr)
  {
    id.push_back(telldir(_dir));   
  }
  
  return id;
}
