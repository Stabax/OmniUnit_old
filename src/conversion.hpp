//conversion.hpp

#ifndef CONVERSION_H_
#define CONVERSION_H_

#include <iomanip>
#include <sstream>

template <typename returnType = int>
returnType toNumber(std::string txt)
{
  std::istringstream converter(txt);
  returnType value;
  converter >> value;
  return value;
}

template <typename argType> //ne fonctionne qu'avec les bases 8, 10 et 16
std::string toBase(argType number, int base)
{
  std::ostringstream converter;
  converter << std::setbase(base) << number;
  return converter.str();
}

#endif //CONVERSION_H_
