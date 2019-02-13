//electric_intensity.hh

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

#ifndef OMNIUNIT_INTENSITY_HH_
#define OMNIUNIT_INTENSITY_HH_

#include "../omniunit.hh"
#include "constants_for_units.hh"


namespace omni
{



typedef Dimension<0,0,0,1,0,0,0> ElectricIntensity;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctoampere = Unit<ElectricIntensity, Rep, yocto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptoampere = Unit<ElectricIntensity, Rep, zepto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attoampere = Unit<ElectricIntensity, Rep, atto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtoampere = Unit<ElectricIntensity, Rep, femto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picoampere = Unit<ElectricIntensity, Rep, pico, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanoampere = Unit<ElectricIntensity, Rep, nano, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microampere = Unit<ElectricIntensity, Rep, micro, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using milliampere = Unit<ElectricIntensity, Rep, milli, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centiampere = Unit<ElectricIntensity, Rep, centi, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using deciampere = Unit<ElectricIntensity, Rep, deci, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using ampere = Unit<ElectricIntensity, Rep, base, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decaampere = Unit<ElectricIntensity, Rep, deca, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectoampere = Unit<ElectricIntensity, Rep, hecto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kiloampere = Unit<ElectricIntensity, Rep, kilo, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megaampere = Unit<ElectricIntensity, Rep, mega, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigaampere = Unit<ElectricIntensity, Rep, giga, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using teraampere = Unit<ElectricIntensity, Rep, tera, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petaampere = Unit<ElectricIntensity, Rep, peta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exaampere = Unit<ElectricIntensity, Rep, exa, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettaampere = Unit<ElectricIntensity, Rep, zetta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottaampere = Unit<ElectricIntensity, Rep, yotta, zero>;



typedef yoctoampere<> Yoctoampere;
typedef zeptoampere<> Zeptoampere;
typedef attoampere<> Attoampere;
typedef femtoampere<>  Femtoampere;
typedef picoampere<> Picoampere;
typedef nanoampere<> Nanoampere;
typedef microampere<> Microampere;
typedef milliampere<> Milliampere;
typedef centiampere<> Centiampere;
typedef deciampere<> Deciampere;
typedef ampere<> Ampere;
typedef decaampere<> Decaampere;
typedef hectoampere<> Hectoampere;
typedef kiloampere<> Kiloampere;
typedef megaampere<> Megaampere;
typedef gigaampere<> Gigaampere;
typedef teraampere<> Teraampere;
typedef petaampere<> Petaampere;
typedef exaampere<> Exaampere;
typedef zettaampere<> Zettaampere;
typedef yottaampere<> Yottaampere;



namespace suffixes
{



constexpr yoctoampere<OMNI_LITTERAL_FLOATING> operator"" _yA(long double val){return val;}
constexpr zeptoampere<OMNI_LITTERAL_FLOATING> operator"" _zA(long double val){return val;}
constexpr attoampere<OMNI_LITTERAL_FLOATING> operator"" _aA(long double val){return val;}
constexpr femtoampere<OMNI_LITTERAL_FLOATING> operator"" _fA(long double val){return val;}
constexpr nanoampere<OMNI_LITTERAL_FLOATING> operator"" _nA(long double val){return val;}
constexpr microampere<OMNI_LITTERAL_FLOATING> operator"" _uA(long double val){return val;}
constexpr milliampere<OMNI_LITTERAL_FLOATING> operator"" _mA(long double val){return val;}
constexpr centiampere<OMNI_LITTERAL_FLOATING> operator"" _cA(long double val){return val;}
constexpr deciampere<OMNI_LITTERAL_FLOATING> operator"" _dA(long double val){return val;}
constexpr ampere<OMNI_LITTERAL_FLOATING> operator"" _A(long double val){return val;}
constexpr decaampere<OMNI_LITTERAL_FLOATING> operator"" _daA(long double val){return val;}
constexpr hectoampere<OMNI_LITTERAL_FLOATING> operator"" _hA(long double val){return val;}
constexpr kiloampere<OMNI_LITTERAL_FLOATING> operator"" _kA(long double val){return val;}
constexpr megaampere<OMNI_LITTERAL_FLOATING> operator"" _MA(long double val){return val;}
constexpr gigaampere<OMNI_LITTERAL_FLOATING> operator"" _GA(long double val){return val;}
constexpr teraampere<OMNI_LITTERAL_FLOATING> operator"" _TA(long double val){return val;}
constexpr petaampere<OMNI_LITTERAL_FLOATING> operator"" _PA(long double val){return val;}
constexpr exaampere<OMNI_LITTERAL_FLOATING> operator"" _EA(long double val){return val;}
constexpr zettaampere<OMNI_LITTERAL_FLOATING> operator"" _ZA(long double val){return val;}
constexpr yottaampere<OMNI_LITTERAL_FLOATING> operator"" _YA(long double val){return val;}

constexpr yoctoampere<OMNI_LITTERAL_INTEGER> operator"" _yA(unsigned long long int val){return val;}
constexpr zeptoampere<OMNI_LITTERAL_INTEGER> operator"" _zA(unsigned long long int val){return val;}
constexpr attoampere<OMNI_LITTERAL_INTEGER> operator"" _aA(unsigned long long int val){return val;}
constexpr femtoampere<OMNI_LITTERAL_INTEGER> operator"" _fA(unsigned long long int val){return val;}
constexpr nanoampere<OMNI_LITTERAL_INTEGER> operator"" _nA(unsigned long long int val){return val;}
constexpr microampere<OMNI_LITTERAL_INTEGER> operator"" _uA(unsigned long long int val){return val;}
constexpr milliampere<OMNI_LITTERAL_INTEGER> operator"" _mA(unsigned long long int val){return val;}
constexpr centiampere<OMNI_LITTERAL_INTEGER> operator"" _cA(unsigned long long int val){return val;}
constexpr deciampere<OMNI_LITTERAL_INTEGER> operator"" _dA(unsigned long long int val){return val;}
constexpr ampere<OMNI_LITTERAL_INTEGER> operator"" _A(unsigned long long int val){return val;}
constexpr decaampere<OMNI_LITTERAL_INTEGER> operator"" _daA(unsigned long long int val){return val;}
constexpr hectoampere<OMNI_LITTERAL_INTEGER> operator"" _hA(unsigned long long int val){return val;}
constexpr kiloampere<OMNI_LITTERAL_INTEGER> operator"" _kA(unsigned long long int val){return val;}
constexpr megaampere<OMNI_LITTERAL_INTEGER> operator"" _MA(unsigned long long int val){return val;}
constexpr gigaampere<OMNI_LITTERAL_INTEGER> operator"" _GA(unsigned long long int val){return val;}
constexpr teraampere<OMNI_LITTERAL_INTEGER> operator"" _TA(unsigned long long int val){return val;}
constexpr petaampere<OMNI_LITTERAL_INTEGER> operator"" _PA(unsigned long long int val){return val;}
constexpr exaampere<OMNI_LITTERAL_INTEGER> operator"" _EA(unsigned long long int val){return val;}
constexpr zettaampere<OMNI_LITTERAL_INTEGER> operator"" _ZA(unsigned long long int val){return val;}
constexpr yottaampere<OMNI_LITTERAL_INTEGER> operator"" _YA(unsigned long long int val){return val;}



} //namespace suffixes



} //namespace omni



#endif //OMNIUNIT_INTENSITY_HH_
