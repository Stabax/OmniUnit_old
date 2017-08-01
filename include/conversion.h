//conversion.h

/*
*Ce header contient des fonctions de conversion et de test.
*/


#ifndef CONVERSION_H_
#define CONVERSION_H_

#include <iomanip>
#include <sstream>
#include <typeinfo>

#include "Exception.hpp"


namespace stb
{

  template <typename returnType = int>
  returnType toNumber(std::string txt)
  {
    std::istringstream converter(txt);
    returnType value;
    converter >> value;
    if(converter.eof())
      return value;
    throw Exception("Cannot convert letter to number", "template <typename returnType> returnType toNumber(std::string)", __FILE__);
  }

  template <typename argType> //ne fonctionne qu'avec les bases 8, 10 et 16
  std::string toBase(argType number, int base)
  {
    std::ostringstream converter;
    converter << std::setbase(base) << number;
    return converter.str();
  }

  template <typename A, typename B>
  bool isSameType(A a, B b)
  {
    return (typeid(a) == typeid(b));
  }
  template <typename A, typename B>
  bool isSameType()
  {
    return (typeid(A) == typeid(B));
  }

}//namespace

#endif //CONVERSION_H_
