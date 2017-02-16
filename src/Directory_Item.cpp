//Directory_Item.cpp

#include "Directory_Item.hpp"
#include "general_exceptions.hpp"


Directory_Item::Directory_Item(std::string const& path) : _path(path)
{
}


Directory_Item::~Directory_Item()
{
}


std::string Directory_Item::extractDirPath(std::string const &path)
{
  size_t slash = path.find_last_of("/");
  if(slash == std::string::npos)
    return ("");
  else
    return (path.substr(0, slash));
}


bool Directory_Item::isPathSet() const
{
  if(_path != "")
    return true;
  return false;
}


std::string Directory_Item::getPath() const
{
  return _path;
}


bool Directory_Item::setPath(std::string const& path)
{
  if(! isOpen())
  {
    _path = path;
    return true;
  }
  return false;
}


std::string Directory_Item::extractDirPath() const
{
  if(isPathSet())
    return extractDirPath(_path);
  return "";
}

