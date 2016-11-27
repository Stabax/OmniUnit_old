//Hasher.cpp

#include "Hasher.hpp"

Hasher::Hasher(std::string salt) : m_salt(salt)
{

}

Hasher::~Hasher()
{

}

std::string Hasher::getSalt() const
{
  return (m_salt);
}

void Hasher::setSalt(std::string salt)
{
  if(m_salt != "")
    ;
  else
    m_salt = salt;
}

void Hasher::salting(std::string &text) const
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

std::string Hasher::hashTotalSize(std::string text) const
{
  return (toBase(text.length(), 16));
}

std::string Hasher::hashTotalSize(std::vector<std::string> text) const
{
  size_t size = text.size();
  size_t textLength = 0;
  for(unsigned counter = 0; counter < size; counter++)
    textLength += text[counter].length();
  return (toBase(textLength, 16));
}

std::string Hasher::hashLineSize(std::string text) const
{
  return (toBase(text.length(), 16));
}

std::string Hasher::hashLineSize(std::vector<std::string> text) const
{
  std::string toHash;
  size_t size = text.size();
  for(unsigned counter = 0; counter < size; counter++)
    toHash += toBase(text[counter].length(), 16);
  return (toHash);
}

std::string Hasher::hashTotalChar(std::string text) const
{
  size_t size = text.size();
  unsigned toHash = 0;
  for(unsigned counter = 0; counter < size; counter++)
    toHash += static_cast<unsigned>(text[counter]);
  return (toBase(toHash, 16));
}

std::string Hasher::hashTotalChar(std::vector<std::string> text) const
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

std::string Hasher::hashLineChar(std::string text) const
{
  size_t size = text.size();
  unsigned toHash = 0;
  for(unsigned counter = 0; counter < size; counter++)
    toHash += static_cast<unsigned>(text[counter]);
  return (toBase(toHash, 16));
}

std::string Hasher::hashLineChar(std::vector<std::string> text) const
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

