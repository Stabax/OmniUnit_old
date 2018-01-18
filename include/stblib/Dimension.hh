//Dimension.hh

/*
Copyright (c) 1998, Regents of the University of California All rights
reserved. Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
    Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
    Neither the name of the University of California, Berkeley nor the names
    of its contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef DIMENSION_HH_
#define DIMENSION_HH_

namespace stb
{
  template<int _length, int _mass, int _time, int _current,
  int _temperature, int _quantity, int _luminosity>
  struct Dimension
  {
    static constexpr int length = _length;
    static constexpr int mass = _mass;
    static constexpr int time = _time;
    static constexpr int current = _current;
    static constexpr int temperature = _temperature;
    static constexpr int quantity = _quantity;
    static constexpr int luminosity = _luminosity;
  };


  template<typename falseType>
  struct is_Dimension : std::false_type
  {
  };


  template<int length, int mass, int time, int current,
  int temperature, int quantity, int luminosity>
  struct is_Dimension<Dimension<length, mass, time, current,
  temperature, quantity, luminosity>> : public std::true_type
  {
  };


  template <typename dim1, typename dim2>
  struct Dimension_multiply
  {
    static_assert(is_Dimension<dim1>::value && is_Dimension<dim2>::value,
    "Bad type, need a stb::Dimension.");

    typedef Dimension<
    dim1::length + dim2::length,
    dim1::mass + dim2::mass,
    dim1::time + dim2::time,
    dim1::current + dim2::current,
    dim1::temperature + dim2::temperature,
    dim1::quantity + dim2::quantity,
    dim1::luminosity + dim2::luminosity
    > type;
  };


  template <typename dim1, typename dim2>
  struct Dimension_divide
  {
    static_assert(is_Dimension<dim1>::value && is_Dimension<dim2>::value,
    "Bad type, need a stb::Dimension.");

    typedef Dimension<
    dim1::length - dim2::length,
    dim1::mass - dim2::mass,
    dim1::time - dim2::time,
    dim1::current - dim2::current,
    dim1::temperature - dim2::temperature,
    dim1::quantity - dim2::quantity,
    dim1::luminosity - dim2::luminosity> type;
  };


  //it is useless to make this function part of the class Dimension (static constexpr)
  //because std::string is not a litteral : the function cannot be interpreted at
  //compile time, so class Dimension could neither.
  template<typename dimension>
  typename std::enable_if<is_Dimension<dimension>::value, std::string>::type dimension_str()
  {
    std::string dim = "";

    if(dimension::length != 0)
      dim += ("[L" + std::to_string(dimension::length) + "]");
    if(dimension::mass != 0)
      dim += ("[M" + std::to_string(dimension::mass) + "]");
    if(dimension::time != 0)
      dim += ("[Tm" + std::to_string(dimension::time) + "]");
    if(dimension::current != 0)
      dim += ("[I" + std::to_string(dimension::current) + "]");
    if(dimension::temperature != 0)
      dim += ("[Tp" + std::to_string(dimension::temperature) + "]");
    if(dimension::quantity != 0)
      dim += ("[N" + std::to_string(dimension::quantity) + "]");
    if(dimension::luminosity != 0)
      dim += ("[J" + std::to_string(dimension::luminosity) + "]");
    if(dim.length() == 0)
      dim = "[/]";

    return dim;
  }



} //namespace stb

#endif //DIMENSION_HH_
