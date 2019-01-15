//length.hh

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

#ifndef LENGTH_HH_
#define LENGTH_HH_

#include"constants_for_units.hh"


namespace omni
{



typedef Dimension<1,0,0,0,0,0,0> Length;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctometer = Unit<Length, Rep, yocto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptometer = Unit<Length, Rep, zepto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attometer = Unit<Length, Rep, atto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtometer = Unit<Length, Rep, femto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picometer = Unit<Length, Rep, pico, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanometer = Unit<Length, Rep, nano, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using micrometer = Unit<Length, Rep, micro, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millimeter = Unit<Length, Rep, milli, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centimeter = Unit<Length, Rep, centi, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decimeter = Unit<Length, Rep, deci, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using meter = Unit<Length, Rep, base, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decameter = Unit<Length, Rep, deca, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectometer = Unit<Length, Rep, hecto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilometer = Unit<Length, Rep, kilo, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megameter = Unit<Length, Rep, mega, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigameter = Unit<Length, Rep, giga, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using terameter = Unit<Length, Rep, tera, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petameter = Unit<Length, Rep, peta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exameter = Unit<Length, Rep, exa, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettameter = Unit<Length, Rep, zetta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottameter = Unit<Length, Rep, yotta, zero>;





template <typename Rep = OMNI_DEFAULT_TYPE>
using angstrom = Unit<Length, Rep, Ratio<E0, E10>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using astronomical_unit = Unit<Length, Rep, Ratio<distanceSunEarth, E0>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using lightsecond = Unit<Length, Rep, Ratio<distanceTraveledByLightPerSec, E10>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using lightminute = Unit<Length, Rep, typename Ratio_times_Ratio<
typename lightsecond<Rep>::period, Ratio<secondsPerMin, E0>>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using lightyear = Unit<Length, Rep, typename Ratio_times_Ratio<
typename lightsecond<Rep>::period, secondsPerYear>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using parsec = Unit<Length, Rep, typename Ratio_times_Ratio<
typename astronomical_unit<Rep>::period, parsecDefinition>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kiloparsec = Unit<Length, Rep, typename Ratio_times_Ratio<
typename parsec<Rep>::period, kilo>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megaparsec = Unit<Length, Rep, typename Ratio_times_Ratio<
typename parsec<Rep>::period, mega>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigaparsec = Unit<Length, Rep, typename Ratio_times_Ratio<
typename parsec<Rep>::period, giga>::type, zero>;




typedef yoctometer<> Yoctometer;
typedef zeptometer<> Zeptometer;
typedef attometer<> Attometer;
typedef femtometer<>  Femtometer;
typedef picometer<> Picometer;
typedef nanometer<> Nanometer;
typedef micrometer<> Micrometer;
typedef millimeter<> Millimeter;
typedef centimeter<> Centimeter;
typedef decimeter<> Decimeter;
typedef meter<> Meter;
typedef decameter<> Decameter;
typedef hectometer<> Hectometer;
typedef kilometer<> Kilometer;
typedef megameter<> Megameter;
typedef gigameter<> Gigameter;
typedef terameter<> Terameter;
typedef petameter<> Petameter;
typedef exameter<> Exameter;
typedef zettameter<> Zettameter;
typedef yottameter<> Yottameter;

typedef angstrom<> Angstrom;
typedef astronomical_unit<> Astronomical_unit;
typedef lightsecond<> Lightsecond;
typedef lightminute<> Lightminute;
typedef lightyear<> Lightyear;
typedef parsec<> Parsec;
typedef kiloparsec<> Kiloparsec;
typedef megaparsec<> Megaparsec;
typedef gigaparsec<> Gigaparsec;



namespace suffixes
{



constexpr Yoctometer operator"" _ym(long double val){return val;}
constexpr Zeptometer operator"" _zm(long double val){return val;}
constexpr Attometer operator"" _am(long double val){return val;}
constexpr Femtometer operator"" _fm(long double val){return val;}
constexpr Nanometer operator"" _nm(long double val){return val;}
constexpr Micrometer operator"" _um(long double val){return val;}
constexpr Millimeter operator"" _mm(long double val){return val;}
constexpr Centimeter operator"" _cm(long double val){return val;}
constexpr Decimeter operator"" _dm(long double val){return val;}
constexpr Meter operator"" _m(long double val){return val;}
constexpr Decameter operator"" _dam(long double val){return val;}
constexpr Hectometer operator"" _hm(long double val){return val;}
constexpr Kilometer operator"" _km(long double val){return val;}
constexpr Megameter operator"" _Mm(long double val){return val;}
constexpr Gigameter operator"" _Gm(long double val){return val;}
constexpr Terameter operator"" _Tm(long double val){return val;}
constexpr Petameter operator"" _Pm(long double val){return val;}
constexpr Exameter operator"" _Em(long double val){return val;}
constexpr Zettameter operator"" _Zm(long double val){return val;}
constexpr Yottameter operator"" _Ym(long double val){return val;}

constexpr Angstrom operator"" _a(long double val){return val;}
constexpr Astronomical_unit operator"" _AU(long double val){return val;}
constexpr Lightsecond operator"" _ls(long double val){return val;}
constexpr Lightminute operator"" _lmin(long double val){return val;}
constexpr Lightyear operator"" _ly(long double val){return val;}
constexpr Parsec operator"" _pc(long double val){return val;}
constexpr Kiloparsec operator"" _kpc(long double val){return val;}
constexpr Megaparsec operator"" _Mpc(long double val){return val;}
constexpr Gigaparsec operator"" _Gpc(long double val){return val;}



constexpr Yoctometer operator"" _ym(unsigned long long int val){return val;}
constexpr Zeptometer operator"" _zm(unsigned long long int val){return val;}
constexpr Attometer operator"" _am(unsigned long long int val){return val;}
constexpr Femtometer operator"" _fm(unsigned long long int val){return val;}
constexpr Nanometer operator"" _nm(unsigned long long int val){return val;}
constexpr Micrometer operator"" _um(unsigned long long int val){return val;}
constexpr Millimeter operator"" _mm(unsigned long long int val){return val;}
constexpr Centimeter operator"" _cm(unsigned long long int val){return val;}
constexpr Decimeter operator"" _dm(unsigned long long int val){return val;}
constexpr Meter operator"" _m(unsigned long long int val){return val;}
constexpr Decameter operator"" _dam(unsigned long long int val){return val;}
constexpr Hectometer operator"" _hm(unsigned long long int val){return val;}
constexpr Kilometer operator"" _km(unsigned long long int val){return val;}
constexpr Megameter operator"" _Mm(unsigned long long int val){return val;}
constexpr Gigameter operator"" _Gm(unsigned long long int val){return val;}
constexpr Terameter operator"" _Tm(unsigned long long int val){return val;}
constexpr Petameter operator"" _Pm(unsigned long long int val){return val;}
constexpr Exameter operator"" _Em(unsigned long long int val){return val;}
constexpr Zettameter operator"" _Zm(unsigned long long int val){return val;}
constexpr Yottameter operator"" _Ym(unsigned long long int val){return val;}

constexpr Angstrom operator"" _a(unsigned long long int val){return val;}
constexpr Astronomical_unit operator"" _AU(unsigned long long int val){return val;}
constexpr Lightsecond operator"" _ls(unsigned long long int val){return val;}
constexpr Lightminute operator"" _lmin(unsigned long long int val){return val;}
constexpr Lightyear operator"" _ly(unsigned long long int val){return val;}
constexpr Parsec operator"" _pc(unsigned long long int val){return val;}
constexpr Kiloparsec operator"" _kpc(unsigned long long int val){return val;}
constexpr Megaparsec operator"" _Mpc(unsigned long long int val){return val;}
constexpr Gigaparsec operator"" _Gpc(unsigned long long int val){return val;}

} //namespaxe suffixies



} //namespace omni


#endif //LENGTH_HH_
