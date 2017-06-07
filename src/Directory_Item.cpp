//Directory_Item.cpp

#include "Directory_Item.hpp"


stb::Directory_Item::Directory_Item(std::string const& path, stb::access acc) : _path(path), _readOnly(acc == stb::access::r)
{
}


stb::Directory_Item::~Directory_Item()
{
}


std::string stb::Directory_Item::extractDirPath(std::string const &path)
{
  size_t slash = path.find_last_of("/");
  if(slash == std::string::npos)
    return ("");
  else
    return (path.substr(0, slash));
}


std::string stb::Directory_Item::getPath() const
{
  return _path;
}


std::string stb::Directory_Item::extractDirPath() const
{
  return extractDirPath(_path);
}

