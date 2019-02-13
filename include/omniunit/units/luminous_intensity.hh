//luminous_intensity.hh

/*
Copyright (c) 2019, Denis Tosetto All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

  Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.

  Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

  Neither the name of Denis Tosetto nor the names
  of its contributors may be used to endorse or promote products derived
  from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef OMNIUNIT_LUMINOUS_INTENSITY_HH_
#define OMNIUNIT_LUMINOUS_INTENSITY_HH_

#include "../omniunit.hh"
#include "constants_for_units.hh"


namespace omni
{



typedef Dimension<0,0,0,0,0,0,1> LuminousIntensity;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctocandela = Unit<LuminousIntensity, Rep, yocto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptocandela = Unit<LuminousIntensity, Rep, zepto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attocandela = Unit<LuminousIntensity, Rep, atto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtocandela = Unit<LuminousIntensity, Rep, femto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picocandela = Unit<LuminousIntensity, Rep, pico, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanocandela = Unit<LuminousIntensity, Rep, nano, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microcandela = Unit<LuminousIntensity, Rep, micro, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millicandela = Unit<LuminousIntensity, Rep, milli, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centicandela = Unit<LuminousIntensity, Rep, centi, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decicandela = Unit<LuminousIntensity, Rep, deci, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using candela = Unit<LuminousIntensity, Rep, base, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decacandela = Unit<LuminousIntensity, Rep, deca, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectocandela = Unit<LuminousIntensity, Rep, hecto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilocandela = Unit<LuminousIntensity, Rep, kilo, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megacandela = Unit<LuminousIntensity, Rep, mega, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigacandela = Unit<LuminousIntensity, Rep, giga, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using teracandela = Unit<LuminousIntensity, Rep, tera, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petacandela = Unit<LuminousIntensity, Rep, peta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exacandela = Unit<LuminousIntensity, Rep, exa, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettacandela = Unit<LuminousIntensity, Rep, zetta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottacandela = Unit<LuminousIntensity, Rep, yotta, zero>;



typedef yoctocandela<> Yoctocandela;
typedef zeptocandela<> Zeptocandela;
typedef attocandela<> Attocandela;
typedef femtocandela<>  Femtocandela;
typedef picocandela<> Picocandela;
typedef nanocandela<> Nanocandela;
typedef microcandela<> Microcandela;
typedef millicandela<> Millicandela;
typedef centicandela<> Centicandela;
typedef decicandela<> Decicandela;
typedef candela<> Candela;
typedef decacandela<> Decacandela;
typedef hectocandela<> Hectocandela;
typedef kilocandela<> Kilocandela;
typedef megacandela<> Megacandela;
typedef gigacandela<> Gigacandela;
typedef teracandela<> Teracandela;
typedef petacandela<> Petacandela;
typedef exacandela<> Exacandela;
typedef zettacandela<> Zettacandela;
typedef yottacandela<> Yottacandela;



namespace suffixes
{



constexpr yoctocandela<OMNI_LITTERAL_FLOATING> operator"" _ycd(long double val){return val;}
constexpr zeptocandela<OMNI_LITTERAL_FLOATING> operator"" _zcd(long double val){return val;}
constexpr attocandela<OMNI_LITTERAL_FLOATING> operator"" _acd(long double val){return val;}
constexpr femtocandela<OMNI_LITTERAL_FLOATING> operator"" _fcd(long double val){return val;}
constexpr nanocandela<OMNI_LITTERAL_FLOATING> operator"" _ncd(long double val){return val;}
constexpr microcandela<OMNI_LITTERAL_FLOATING> operator"" _ucd(long double val){return val;}
constexpr millicandela<OMNI_LITTERAL_FLOATING> operator"" _mcd(long double val){return val;}
constexpr centicandela<OMNI_LITTERAL_FLOATING> operator"" _ccd(long double val){return val;}
constexpr decicandela<OMNI_LITTERAL_FLOATING> operator"" _dcd(long double val){return val;}
constexpr candela<OMNI_LITTERAL_FLOATING> operator"" _cd(long double val){return val;}
constexpr decacandela<OMNI_LITTERAL_FLOATING> operator"" _dacd(long double val){return val;}
constexpr hectocandela<OMNI_LITTERAL_FLOATING> operator"" _hcd(long double val){return val;}
constexpr kilocandela<OMNI_LITTERAL_FLOATING> operator"" _kcd(long double val){return val;}
constexpr megacandela<OMNI_LITTERAL_FLOATING> operator"" _Mcd(long double val){return val;}
constexpr gigacandela<OMNI_LITTERAL_FLOATING> operator"" _Gcd(long double val){return val;}
constexpr teracandela<OMNI_LITTERAL_FLOATING> operator"" _Tcd(long double val){return val;}
constexpr petacandela<OMNI_LITTERAL_FLOATING> operator"" _Pcd(long double val){return val;}
constexpr exacandela<OMNI_LITTERAL_FLOATING> operator"" _Ecd(long double val){return val;}
constexpr zettacandela<OMNI_LITTERAL_FLOATING> operator"" _Zcd(long double val){return val;}
constexpr yottacandela<OMNI_LITTERAL_FLOATING> operator"" _Ycd(long double val){return val;}



constexpr yoctocandela<OMNI_LITTERAL_INTEGER> operator"" _ycd(unsigned long long int val){return val;}
constexpr zeptocandela<OMNI_LITTERAL_INTEGER> operator"" _zcd(unsigned long long int val){return val;}
constexpr attocandela<OMNI_LITTERAL_INTEGER> operator"" _acd(unsigned long long int val){return val;}
constexpr femtocandela<OMNI_LITTERAL_INTEGER> operator"" _fcd(unsigned long long int val){return val;}
constexpr nanocandela<OMNI_LITTERAL_INTEGER> operator"" _ncd(unsigned long long int val){return val;}
constexpr microcandela<OMNI_LITTERAL_INTEGER> operator"" _ucd(unsigned long long int val){return val;}
constexpr millicandela<OMNI_LITTERAL_INTEGER> operator"" _mcd(unsigned long long int val){return val;}
constexpr centicandela<OMNI_LITTERAL_INTEGER> operator"" _ccd(unsigned long long int val){return val;}
constexpr decicandela<OMNI_LITTERAL_INTEGER> operator"" _dcd(unsigned long long int val){return val;}
constexpr candela<OMNI_LITTERAL_INTEGER> operator"" _cd(unsigned long long int val){return val;}
constexpr decacandela<OMNI_LITTERAL_INTEGER> operator"" _dacd(unsigned long long int val){return val;}
constexpr hectocandela<OMNI_LITTERAL_INTEGER> operator"" _hcd(unsigned long long int val){return val;}
constexpr kilocandela<OMNI_LITTERAL_INTEGER> operator"" _kcd(unsigned long long int val){return val;}
constexpr megacandela<OMNI_LITTERAL_INTEGER> operator"" _Mcd(unsigned long long int val){return val;}
constexpr gigacandela<OMNI_LITTERAL_INTEGER> operator"" _Gcd(unsigned long long int val){return val;}
constexpr teracandela<OMNI_LITTERAL_INTEGER> operator"" _Tcd(unsigned long long int val){return val;}
constexpr petacandela<OMNI_LITTERAL_INTEGER> operator"" _Pcd(unsigned long long int val){return val;}
constexpr exacandela<OMNI_LITTERAL_INTEGER> operator"" _Ecd(unsigned long long int val){return val;}
constexpr zettacandela<OMNI_LITTERAL_INTEGER> operator"" _Zcd(unsigned long long int val){return val;}
constexpr yottacandela<OMNI_LITTERAL_INTEGER> operator"" _Ycd(unsigned long long int val){return val;}



} //namespaxe suffixes



} //namespace omni


#endif //OMNIUNIT_LUMINOUS_INTENSITY_HH_
