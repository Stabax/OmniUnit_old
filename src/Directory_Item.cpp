//Directory_Item.cpp

#include "Directory_Item.hpp"

Directory_Item::Directory_Item(std::string const& path) : _path(path)
{
}

Directory_Item::~Directory_Item()
{
}

bool Directory_Item::isPathSet() const
{
  if(_path != "")
    return true;
  else
    return false;
}

std::string Directory_Item::getPath() const
{
  return (_path);
}

void Directory_Item::setPath(std::string const& path)
{
  if(! isPathSet())
    _path = path;
}
