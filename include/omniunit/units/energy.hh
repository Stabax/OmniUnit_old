//energy.hh

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

#ifndef ENERGY_HH_
#define ENERGY_HH_

#include "constants_for_units.hh"

namespace omni
{



typedef Dimension<2,1,-2,0,0,0,0> Energy;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctojoule = Unit<Energy, Rep, yocto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptojoule = Unit<Energy, Rep, zepto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attojoule = Unit<Energy, Rep, atto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtojoule = Unit<Energy, Rep, femto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picojoule = Unit<Energy, Rep, pico, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanojoule = Unit<Energy, Rep, nano, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microjoule = Unit<Energy, Rep, micro, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millijoule = Unit<Energy, Rep, milli, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centijoule = Unit<Energy, Rep, centi, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decijoule = Unit<Energy, Rep, deci, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using joule = Unit<Energy, Rep, base, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decajoule = Unit<Energy, Rep, deca, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectojoule = Unit<Energy, Rep, hecto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilojoule = Unit<Energy, Rep, kilo, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megajoule = Unit<Energy, Rep, mega, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigajoule = Unit<Energy, Rep, giga, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using terajoule = Unit<Energy, Rep, tera, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petajoule = Unit<Energy, Rep, peta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exajoule = Unit<Energy, Rep, exa, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettajoule = Unit<Energy, Rep, zetta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottajoule = Unit<Energy, Rep, yotta, zero>;



typedef yoctojoule<> Yoctojoule;
typedef zeptojoule<> Zeptojoule;
typedef attojoule<> Attojoule;
typedef femtojoule<>  Femtojoule;
typedef picojoule<> Picojoule;
typedef nanojoule<> Nanojoule;
typedef microjoule<> Microjoule;
typedef millijoule<> Millijoule;
typedef centijoule<> Centijoule;
typedef decijoule<> Decijoule;
typedef joule<> Ampere;
typedef decajoule<> Decajoule;
typedef hectojoule<> Hectojoule;
typedef kilojoule<> Kilojoule;
typedef megajoule<> Megajoule;
typedef gigajoule<> Gigajoule;
typedef terajoule<> Terajoule;
typedef petajoule<> Petajoule;
typedef exajoule<> Exajoule;
typedef zettajoule<> Zettajoule;
typedef yottajoule<> Yottajoule;



namespace suffixes
{



constexpr yoctojoule<OMNI_LITTERAL_FLOATING> operator"" _y(long double val){return val;}
constexpr zeptojoule<OMNI_LITTERAL_FLOATING> operator"" _zJ(long double val){return val;}
constexpr attojoule<OMNI_LITTERAL_FLOATING> operator"" _aJ(long double val){return val;}
constexpr femtojoule<OMNI_LITTERAL_FLOATING> operator"" _fJ(long double val){return val;}
constexpr nanojoule<OMNI_LITTERAL_FLOATING> operator"" _nJ(long double val){return val;}
constexpr microjoule<OMNI_LITTERAL_FLOATING> operator"" _uJ(long double val){return val;}
constexpr millijoule<OMNI_LITTERAL_FLOATING> operator"" _mJ(long double val){return val;}
constexpr centijoule<OMNI_LITTERAL_FLOATING> operator"" _cJ(long double val){return val;}
constexpr decijoule<OMNI_LITTERAL_FLOATING> operator"" _dJ(long double val){return val;}
constexpr joule<OMNI_LITTERAL_FLOATING> operator"" _J(long double val){return val;}
constexpr decajoule<OMNI_LITTERAL_FLOATING> operator"" _daJ(long double val){return val;}
constexpr hectojoule<OMNI_LITTERAL_FLOATING> operator"" _hJ(long double val){return val;}
constexpr kilojoule<OMNI_LITTERAL_FLOATING> operator"" _kJ(long double val){return val;}
constexpr megajoule<OMNI_LITTERAL_FLOATING> operator"" _MJ(long double val){return val;}
constexpr gigajoule<OMNI_LITTERAL_FLOATING> operator"" _GJ(long double val){return val;}
constexpr terajoule<OMNI_LITTERAL_FLOATING> operator"" _TJ(long double val){return val;}
constexpr petajoule<OMNI_LITTERAL_FLOATING> operator"" _PJ(long double val){return val;}
constexpr exajoule<OMNI_LITTERAL_FLOATING> operator"" _EJ(long double val){return val;}
constexpr zettajoule<OMNI_LITTERAL_FLOATING> operator"" _ZJ(long double val){return val;}
constexpr yottajoule<OMNI_LITTERAL_FLOATING> operator"" _YJ(long double val){return val;}



constexpr yoctojoule<OMNI_LITTERAL_INTEGER> operator"" _yJ(unsigned long long int val){return val;}
constexpr zeptojoule<OMNI_LITTERAL_INTEGER> operator"" _zJ(unsigned long long int val){return val;}
constexpr attojoule<OMNI_LITTERAL_INTEGER> operator"" _aJ(unsigned long long int val){return val;}
constexpr femtojoule<OMNI_LITTERAL_INTEGER> operator"" _fJ(unsigned long long int val){return val;}
constexpr nanojoule<OMNI_LITTERAL_INTEGER> operator"" _nJ(unsigned long long int val){return val;}
constexpr microjoule<OMNI_LITTERAL_INTEGER> operator"" _uJ(unsigned long long int val){return val;}
constexpr millijoule<OMNI_LITTERAL_INTEGER> operator"" _mJ(unsigned long long int val){return val;}
constexpr centijoule<OMNI_LITTERAL_INTEGER> operator"" _cJ(unsigned long long int val){return val;}
constexpr decijoule<OMNI_LITTERAL_INTEGER> operator"" _dJ(unsigned long long int val){return val;}
constexpr joule<OMNI_LITTERAL_INTEGER> operator"" _J(unsigned long long int val){return val;}
constexpr decajoule<OMNI_LITTERAL_INTEGER> operator"" _daJ(unsigned long long int val){return val;}
constexpr hectojoule<OMNI_LITTERAL_INTEGER> operator"" _hJ(unsigned long long int val){return val;}
constexpr kilojoule<OMNI_LITTERAL_INTEGER> operator"" _kJ(unsigned long long int val){return val;}
constexpr megajoule<OMNI_LITTERAL_INTEGER> operator"" _MJ(unsigned long long int val){return val;}
constexpr gigajoule<OMNI_LITTERAL_INTEGER> operator"" _GJ(unsigned long long int val){return val;}
constexpr terajoule<OMNI_LITTERAL_INTEGER> operator"" _TJ(unsigned long long int val){return val;}
constexpr petajoule<OMNI_LITTERAL_INTEGER> operator"" _PJ(unsigned long long int val){return val;}
constexpr exajoule<OMNI_LITTERAL_INTEGER> operator"" _EJ(unsigned long long int val){return val;}
constexpr zettajoule<OMNI_LITTERAL_INTEGER> operator"" _ZJ(unsigned long long int val){return val;}
constexpr yottajoule<OMNI_LITTERAL_INTEGER> operator"" _YJ(unsigned long long int val){return val;}



} //namespace suffixes



} //namespace omni

#endif //ENERGY_HH_