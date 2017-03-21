//Hasher.cpp

#include <vector>

#include "Hasher.hh"


stb::Hasher::Hasher(std::string salt) : m_salt(salt)
{
}


std::string stb::Hasher::getSalt() const
{
  return (m_salt);
}

void stb::Hasher::setSalt(std::string salt)
{
  if(m_salt != "")
    ;
  else
    m_salt = salt;
}

void stb::Hasher::salting(std::string &text) const
{
  if(text.size() < m_salt.size())
  {
    text += m_salt;
  }
  size_t size = text.size();
  for(unsigned counter = 0; counter < size; counter++)
  {
    //A REMPLIR
  }
}

//void Hasher::salting(std::vector<std::string> &text) const
//{
  //A REMPLIR
//}

std::string stb::Hasher::hashTotalSize(std::string text) const
{
  return (toBase(text.length(), 16));
}

std::string stb::Hasher::hashTotalSize(std::vector<std::string> text) const
{
  size_t size = text.size();
  size_t textLength = 0;
  for(unsigned counter = 0; counter < size; counter++)
    textLength += text[counter].length();
  return (toBase(textLength, 16));
}

std::string stb::Hasher::hashLineSize(std::string text) const
{
  return (toBase(text.length(), 16));
}

std::string stb::Hasher::hashLineSize(std::vector<std::string> text) const
{
  std::string toHash;
  size_t size = text.size();
  for(unsigned counter = 0; counter < size; counter++)
    toHash += toBase(text[counter].length(), 16);
  return (toHash);
}

std::string stb::Hasher::hashTotalChar(std::string text) const
{
  size_t size = text.size();
  unsigned toHash = 0;
  for(unsigned counter = 0; counter < size; counter++)
    toHash += static_cast<unsigned>(text[counter]);
  return (toBase(toHash, 16));
}

std::string stb::Hasher::hashTotalChar(std::vector<std::string> text) const
{
  size_t size = text.size();
  unsigned toHash = 0;
  for(unsigned counter = 0; counter < size; counter++)
  {
    size_t stringSize = text[counter].size();
    for(unsigned counter2 = 0; counter2 < stringSize; counter2++)
      toHash += static_cast<unsigned>(text[counter][counter2]);
  }
  return (toBase(toHash, 16));
}

std::string stb::Hasher::hashLineChar(std::string text) const
{
  size_t size = text.size();
  unsigned toHash = 0;
  for(unsigned counter = 0; counter < size; counter++)
    toHash += static_cast<unsigned>(text[counter]);
  return (toBase(toHash, 16));
}

std::string stb::Hasher::hashLineChar(std::vector<std::string> text) const
{
  size_t size = text.size();
  std::string toReturn;
  for(unsigned counter = 0; counter < size; counter++)
  {
    size_t stringSize = text[counter].size();
    for(unsigned counter2 = 0; counter2 < stringSize; counter2++)
      toReturn += toBase(text[counter][counter2], 16);
  }
  return (toReturn);
}

