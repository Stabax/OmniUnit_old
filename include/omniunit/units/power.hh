//power.hh

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

#ifndef OMNIUNIT_POWER_HH_
#define OMNIUNIT_POWER_HH_

#include "../omniunit.hh"
#include "constants_for_units.hh"


namespace omni
{



typedef Dimension<2,1,-3,0,0,0,0> Power;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctowatt = Unit<Power, Rep, yocto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptowatt = Unit<Power, Rep, zepto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attowatt = Unit<Power, Rep, atto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtowatt = Unit<Power, Rep, femto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picowatt = Unit<Power, Rep, pico, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanowatt = Unit<Power, Rep, nano, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microwatt = Unit<Power, Rep, micro, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using milliwatt = Unit<Power, Rep, milli, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centiwatt = Unit<Power, Rep, centi, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using deciwatt = Unit<Power, Rep, deci, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using watt = Unit<Power, Rep, base, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decawatt = Unit<Power, Rep, deca, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectowatt = Unit<Power, Rep, hecto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilowatt = Unit<Power, Rep, kilo, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megawatt = Unit<Power, Rep, mega, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigawatt = Unit<Power, Rep, giga, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using terawatt = Unit<Power, Rep, tera, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petawatt = Unit<Power, Rep, peta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exawatt = Unit<Power, Rep, exa, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettawatt = Unit<Power, Rep, zetta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottawatt = Unit<Power, Rep, yotta, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using horsepower = Unit<Power, Rep, Ratio<hpE1, E1>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using mechanicalhorsepower = Unit<Power, Rep, Ratio<mhpE1, E1>, zero>;



typedef yoctowatt<> Yoctowatt;
typedef zeptowatt<> Zeptowatt;
typedef attowatt<> Attowatt;
typedef femtowatt<>  Femtowatt;
typedef picowatt<> Picowatt;
typedef nanowatt<> Nanowatt;
typedef microwatt<> Microwatt;
typedef milliwatt<> Milliwatt;
typedef centiwatt<> Centiwatt;
typedef deciwatt<> Deciwatt;
typedef watt<> Watt;
typedef decawatt<> Decawatt;
typedef hectowatt<> Hectowatt;
typedef kilowatt<> Kilowatt;
typedef megawatt<> Megawatt;
typedef gigawatt<> Gigawatt;
typedef terawatt<> Terawatt;
typedef petawatt<> Petawatt;
typedef exawatt<> Exawatt;
typedef zettawatt<> Zettawatt;
typedef yottawatt<> Yottawatt;

typedef horsepower<> Horsepower;
typedef mechanicalhorsepower<> Mechanicalhorsepower;


namespace suffixes
{



constexpr yoctowatt<OMNI_LITTERAL_FLOATING> operator"" _yW(long double val){return val;}
constexpr zeptowatt<OMNI_LITTERAL_FLOATING> operator"" _zW(long double val){return val;}
constexpr attowatt<OMNI_LITTERAL_FLOATING> operator"" _aW(long double val){return val;}
constexpr femtowatt<OMNI_LITTERAL_FLOATING> operator"" _fW(long double val){return val;}
constexpr nanowatt<OMNI_LITTERAL_FLOATING> operator"" _nW(long double val){return val;}
constexpr microwatt<OMNI_LITTERAL_FLOATING> operator"" _uW(long double val){return val;}
constexpr milliwatt<OMNI_LITTERAL_FLOATING> operator"" _mW(long double val){return val;}
constexpr centiwatt<OMNI_LITTERAL_FLOATING> operator"" _cW(long double val){return val;}
constexpr deciwatt<OMNI_LITTERAL_FLOATING> operator"" _dW(long double val){return val;}
constexpr watt<OMNI_LITTERAL_FLOATING> operator"" _W(long double val){return val;}
constexpr decawatt<OMNI_LITTERAL_FLOATING> operator"" _daW(long double val){return val;}
constexpr hectowatt<OMNI_LITTERAL_FLOATING> operator"" _hW(long double val){return val;}
constexpr kilowatt<OMNI_LITTERAL_FLOATING> operator"" _kW(long double val){return val;}
constexpr megawatt<OMNI_LITTERAL_FLOATING> operator"" _MW(long double val){return val;}
constexpr gigawatt<OMNI_LITTERAL_FLOATING> operator"" _GW(long double val){return val;}
constexpr terawatt<OMNI_LITTERAL_FLOATING> operator"" _TW(long double val){return val;}
constexpr petawatt<OMNI_LITTERAL_FLOATING> operator"" _PW(long double val){return val;}
constexpr exawatt<OMNI_LITTERAL_FLOATING> operator"" _EW(long double val){return val;}
constexpr zettawatt<OMNI_LITTERAL_FLOATING> operator"" _ZW(long double val){return val;}
constexpr yottawatt<OMNI_LITTERAL_FLOATING> operator"" _YW(long double val){return val;}

constexpr horsepower<OMNI_LITTERAL_FLOATING> operator""_hp (long double val) {return val;}
constexpr mechanicalhorsepower<OMNI_LITTERAL_FLOATING> operator""_mhp (long double val) {return val;}



constexpr yoctowatt<OMNI_LITTERAL_INTEGER> operator"" _yW(unsigned long long int val){return val;}
constexpr zeptowatt<OMNI_LITTERAL_INTEGER> operator"" _zW(unsigned long long int val){return val;}
constexpr attowatt<OMNI_LITTERAL_INTEGER> operator"" _aW(unsigned long long int val){return val;}
constexpr femtowatt<OMNI_LITTERAL_INTEGER> operator"" _fW(unsigned long long int val){return val;}
constexpr nanowatt<OMNI_LITTERAL_INTEGER> operator"" _nW(unsigned long long int val){return val;}
constexpr microwatt<OMNI_LITTERAL_INTEGER> operator"" _uW(unsigned long long int val){return val;}
constexpr milliwatt<OMNI_LITTERAL_INTEGER> operator"" _mW(unsigned long long int val){return val;}
constexpr centiwatt<OMNI_LITTERAL_INTEGER> operator"" _cW(unsigned long long int val){return val;}
constexpr deciwatt<OMNI_LITTERAL_INTEGER> operator"" _dW(unsigned long long int val){return val;}
constexpr watt<OMNI_LITTERAL_INTEGER> operator"" _W(unsigned long long int val){return val;}
constexpr decawatt<OMNI_LITTERAL_INTEGER> operator"" _daW(unsigned long long int val){return val;}
constexpr hectowatt<OMNI_LITTERAL_INTEGER> operator"" _hW(unsigned long long int val){return val;}
constexpr kilowatt<OMNI_LITTERAL_INTEGER> operator"" _kW(unsigned long long int val){return val;}
constexpr megawatt<OMNI_LITTERAL_INTEGER> operator"" _MW(unsigned long long int val){return val;}
constexpr gigawatt<OMNI_LITTERAL_INTEGER> operator"" _GW(unsigned long long int val){return val;}
constexpr terawatt<OMNI_LITTERAL_INTEGER> operator"" _TW(unsigned long long int val){return val;}
constexpr petawatt<OMNI_LITTERAL_INTEGER> operator"" _PW(unsigned long long int val){return val;}
constexpr exawatt<OMNI_LITTERAL_INTEGER> operator"" _EW(unsigned long long int val){return val;}
constexpr zettawatt<OMNI_LITTERAL_INTEGER> operator"" _ZW(unsigned long long int val){return val;}
constexpr yottawatt<OMNI_LITTERAL_INTEGER> operator"" _YW(unsigned long long int val){return val;}

constexpr horsepower<OMNI_LITTERAL_INTEGER> operator""_hp (unsigned long long int val) {return val;}
constexpr mechanicalhorsepower<OMNI_LITTERAL_INTEGER> operator""_mhp (unsigned long long int val) {return val;}



} //namespace suffixes



} //namespace omni



#endif //OMNIUNIT_POWER_HH_
