//force.hh

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

#ifndef OMNIUNIT_FORCE_HH_
#define OMNIUNIT_FORCE_HH_

#include "../omniunit.hh"
#include "constants_for_units.hh"


namespace omni
{



typedef Dimension<1,1,-2,0,0,0,0> Force;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctonewton = Unit<Force, Rep, yocto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptonewton = Unit<Force, Rep, zepto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attonewton = Unit<Force, Rep, atto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtonewton = Unit<Force, Rep, femto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using piconewton = Unit<Force, Rep, pico, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanonewton = Unit<Force, Rep, nano, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using micronewton = Unit<Force, Rep, micro, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millinewton = Unit<Force, Rep, milli, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centinewton = Unit<Force, Rep, centi, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decinewton = Unit<Force, Rep, deci, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using newton = Unit<Force, Rep, base, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decanewton = Unit<Force, Rep, deca, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectonewton = Unit<Force, Rep, hecto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilonewton = Unit<Force, Rep, kilo, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using meganewton = Unit<Force, Rep, mega, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using giganewton = Unit<Force, Rep, giga, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using teranewton = Unit<Force, Rep, tera, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petanewton = Unit<Force, Rep, peta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exanewton = Unit<Force, Rep, exa, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettanewton = Unit<Force, Rep, zetta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottanewton = Unit<Force, Rep, yotta, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using dyne = Unit<Force, Rep, Ratio<E0, E5>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gramforce = Unit<Force, Rep, Ratio<gE5, E8>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilogramforce = Unit<Force, Rep, Ratio<gE5, E5>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using tonforce = Unit<Force, Rep, typename Ratio_times_value<typename kilogramforce<Rep>::period, E3>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using poundforce = Unit<Force, Rep, Ratio<poundforceE13, E13>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using poundal = Unit<Force, Rep, typename Ratio_times_Ratio<Ratio<footE2, E4>, Ratio<poundE8, E8>>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kipforce = Unit<Force, Rep, typename Ratio_times_value<typename poundforce<Rep>::period, E3>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using shorttonforce = Unit<Force, Rep, typename Ratio_times_value<typename poundforce<Rep>::period, twoThousand>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using longtonforce = Unit<Force, Rep, typename Ratio_times_value<typename poundforce<Rep>::period, longtonforceDef>::type, zero>;



typedef yoctonewton<> Yoctonewton;
typedef zeptonewton<> Zeptonewton;
typedef attonewton<> Attonewton;
typedef femtonewton<>  Femtonewton;
typedef piconewton<> Piconewton;
typedef nanonewton<> Nanonewton;
typedef micronewton<> Micronewton;
typedef millinewton<> Millinewton;
typedef centinewton<> Centinewton;
typedef decinewton<> Decinewton;
typedef newton<> Newton;
typedef decanewton<> Decanewton;
typedef hectonewton<> Hectonewton;
typedef kilonewton<> Kilonewton;
typedef meganewton<> Meganewton;
typedef giganewton<> Giganewton;
typedef teranewton<> Teranewton;
typedef petanewton<> Petanewton;
typedef exanewton<> Exanewton;
typedef zettanewton<> Zettanewton;
typedef yottanewton<> Yottanewton;

typedef dyne<> Dyne;
typedef gramforce<> Gramforce;
typedef kilogramforce<> Kilogramforce;
typedef tonforce<> Tonforce;
typedef poundforce<> Poundforce;
typedef poundal<> Poundal;
typedef kipforce<> Kipforce;
typedef shorttonforce<> Shorttonforce;
typedef longtonforce<> LongtonForce;



namespace suffixes
{



constexpr yoctonewton<OMNI_LITTERAL_FLOATING> operator"" _yN(long double val){return val;}
constexpr zeptonewton<OMNI_LITTERAL_FLOATING> operator"" _zN(long double val){return val;}
constexpr attonewton<OMNI_LITTERAL_FLOATING> operator"" _aN(long double val){return val;}
constexpr femtonewton<OMNI_LITTERAL_FLOATING> operator"" _fN(long double val){return val;}
constexpr nanonewton<OMNI_LITTERAL_FLOATING> operator"" _nN(long double val){return val;}
constexpr micronewton<OMNI_LITTERAL_FLOATING> operator"" _uN(long double val){return val;}
constexpr millinewton<OMNI_LITTERAL_FLOATING> operator"" _mN(long double val){return val;}
constexpr centinewton<OMNI_LITTERAL_FLOATING> operator"" _cN(long double val){return val;}
constexpr decinewton<OMNI_LITTERAL_FLOATING> operator"" _dN(long double val){return val;}
constexpr newton<OMNI_LITTERAL_FLOATING> operator"" _N(long double val){return val;}
constexpr decanewton<OMNI_LITTERAL_FLOATING> operator"" _daN(long double val){return val;}
constexpr hectonewton<OMNI_LITTERAL_FLOATING> operator"" _hN(long double val){return val;}
constexpr kilonewton<OMNI_LITTERAL_FLOATING> operator"" _kN(long double val){return val;}
constexpr meganewton<OMNI_LITTERAL_FLOATING> operator"" _MN(long double val){return val;}
constexpr giganewton<OMNI_LITTERAL_FLOATING> operator"" _GN(long double val){return val;}
constexpr teranewton<OMNI_LITTERAL_FLOATING> operator"" _TN(long double val){return val;}
constexpr petanewton<OMNI_LITTERAL_FLOATING> operator"" _PN(long double val){return val;}
constexpr exanewton<OMNI_LITTERAL_FLOATING> operator"" _EN(long double val){return val;}
constexpr zettanewton<OMNI_LITTERAL_FLOATING> operator"" _ZN(long double val){return val;}
constexpr yottanewton<OMNI_LITTERAL_FLOATING> operator"" _YN(long double val){return val;}

constexpr dyne<OMNI_LITTERAL_FLOATING> operator"" _dyn(long double val){return val;}
constexpr gramforce<OMNI_LITTERAL_FLOATING> operator"" _gf(long double val){return val;}
constexpr kilogramforce<OMNI_LITTERAL_FLOATING> operator"" _kgf(long double val){return val;}
constexpr tonforce<OMNI_LITTERAL_FLOATING> operator"" _tonf(long double val){return val;}
constexpr poundforce<OMNI_LITTERAL_FLOATING> operator"" _lbf(long double val){return val;}
constexpr poundal<OMNI_LITTERAL_FLOATING> operator"" _pdl(long double val){return val;}
constexpr kipforce<OMNI_LITTERAL_FLOATING> operator"" _kipf(long double val){return val;}
constexpr shorttonforce<OMNI_LITTERAL_FLOATING> operator"" _stonf(long double val){return val;}
constexpr longtonforce<OMNI_LITTERAL_FLOATING> operator"" _ltonf(long double val){return val;}




constexpr yoctonewton<OMNI_LITTERAL_INTEGER> operator"" _yN(unsigned long long int val){return val;}
constexpr zeptonewton<OMNI_LITTERAL_INTEGER> operator"" _zN(unsigned long long int val){return val;}
constexpr attonewton<OMNI_LITTERAL_INTEGER> operator"" _aN(unsigned long long int val){return val;}
constexpr femtonewton<OMNI_LITTERAL_INTEGER> operator"" _fN(unsigned long long int val){return val;}
constexpr nanonewton<OMNI_LITTERAL_INTEGER> operator"" _nN(unsigned long long int val){return val;}
constexpr micronewton<OMNI_LITTERAL_INTEGER> operator"" _uN(unsigned long long int val){return val;}
constexpr millinewton<OMNI_LITTERAL_INTEGER> operator"" _mN(unsigned long long int val){return val;}
constexpr centinewton<OMNI_LITTERAL_INTEGER> operator"" _cN(unsigned long long int val){return val;}
constexpr decinewton<OMNI_LITTERAL_INTEGER> operator"" _dN(unsigned long long int val){return val;}
constexpr newton<OMNI_LITTERAL_INTEGER> operator"" _N(unsigned long long int val){return val;}
constexpr decanewton<OMNI_LITTERAL_INTEGER> operator"" _daN(unsigned long long int val){return val;}
constexpr hectonewton<OMNI_LITTERAL_INTEGER> operator"" _hN(unsigned long long int val){return val;}
constexpr kilonewton<OMNI_LITTERAL_INTEGER> operator"" _kN(unsigned long long int val){return val;}
constexpr meganewton<OMNI_LITTERAL_INTEGER> operator"" _MN(unsigned long long int val){return val;}
constexpr giganewton<OMNI_LITTERAL_INTEGER> operator"" _GN(unsigned long long int val){return val;}
constexpr teranewton<OMNI_LITTERAL_INTEGER> operator"" _TN(unsigned long long int val){return val;}
constexpr petanewton<OMNI_LITTERAL_INTEGER> operator"" _PN(unsigned long long int val){return val;}
constexpr exanewton<OMNI_LITTERAL_INTEGER> operator"" _EN(unsigned long long int val){return val;}
constexpr zettanewton<OMNI_LITTERAL_INTEGER> operator"" _ZN(unsigned long long int val){return val;}
constexpr yottanewton<OMNI_LITTERAL_INTEGER> operator"" _YN(unsigned long long int val){return val;}

constexpr dyne<OMNI_LITTERAL_INTEGER> operator"" _dyn(unsigned long long int val){return val;}
constexpr gramforce<OMNI_LITTERAL_INTEGER> operator"" _gf(unsigned long long int val){return val;}
constexpr kilogramforce<OMNI_LITTERAL_INTEGER> operator"" _kgf(unsigned long long int val){return val;}
constexpr tonforce<OMNI_LITTERAL_INTEGER> operator"" _tonf(unsigned long long int val){return val;}
constexpr poundforce<OMNI_LITTERAL_INTEGER> operator"" _lbf(unsigned long long int val){return val;}
constexpr poundal<OMNI_LITTERAL_INTEGER> operator"" _pdl(unsigned long long int val){return val;}
constexpr kipforce<OMNI_LITTERAL_INTEGER> operator"" _kipf(unsigned long long int val){return val;}
constexpr shorttonforce<OMNI_LITTERAL_INTEGER> operator"" _stonf(unsigned long long int val){return val;}
constexpr longtonforce<OMNI_LITTERAL_INTEGER> operator"" _ltonf(unsigned long long int val){return val;}




} //namespace suffixes



} //namespace omni



#endif //OMNIUNIT_FORCE_HH_
