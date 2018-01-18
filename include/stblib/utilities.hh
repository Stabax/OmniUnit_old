//utilities.hh

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

#ifndef UTILITIES_HH_
#define UTILITIES_HH_

namespace stb
{



  //modulo at compile time which can handle floating point.
  template <typename T, typename U>
  constexpr typename std::common_type<
  typename std::enable_if<std::is_arithmetic<T>::value, T>::type,
  typename std::enable_if<std::is_arithmetic<U>::value, U>::type>::type
  modulo(T const& a, U const& b)
  {
    //static_assert(b < 0 || b > 0, "Division by 0.");
    typedef typename std::common_type<T, U>::type common;
    common a2 = static_cast<common>(a);
    common b2 = static_cast<common>(b);
    return a2 - (static_cast<common>(std::floor(a2/b2)) * b2);
  }


  //there is a standard gcd in c++17. It's too recent.
  template <typename T, typename U>
  constexpr typename std::common_type<
  typename std::enable_if<std::is_arithmetic<T>::value, T>::type,
  typename std::enable_if<std::is_arithmetic<U>::value, U>::type>::type
  gcd(T const& a, U const& b)
  {
    typedef typename std::common_type<T, U>::type common;
    common a2 = static_cast<common>(a);
    common b2 = static_cast<common>(b);

    double tempo = 0;
    while (b2 > 0)
    {
      tempo = modulo(a2, b2);
      a2 = b2;
      b2 = tempo;
    }
    return a2;
  }


  template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
  constexpr bool is_positive_integer(T const& number)
  {
    T res = number - static_cast<T>(std::floor(number));
    return (res >=0 && res <=0 && number >= 0) ? true : false;
  }



} //namespace stb

#endif //UTILITIES_HH_
