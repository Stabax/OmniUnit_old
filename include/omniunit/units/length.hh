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
typename lightsecond<Rep>::period, Ratio<sixty, E0>>::type, zero>;

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



template <typename Rep = OMNI_DEFAULT_TYPE>
using inch = Unit<Length, Rep, typename Ratio_times_Ratio<Ratio<inchE2, E2>, centi>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using link = Unit<Length, Rep, typename Ratio_times_Ratio<Ratio<linkE4, E4>, centi>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using foot = Unit<Length, Rep, typename Ratio_times_Ratio<Ratio<footE2, E2>, centi>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yard = Unit<Length, Rep, typename Ratio_times_Ratio<Ratio<yardE2, E2>, centi>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using rod = Unit<Length, Rep, Ratio<rodE4, E4>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using chain = Unit<Length, Rep, Ratio<chainE4, E4>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using mile = Unit<Length, Rep, Ratio<mileE3, E3>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using league = Unit<Length, Rep, Ratio<leagueE3, E3>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nauticmile = Unit<Length, Rep, Ratio<nauticmileDef, E0>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using fathom = Unit<Length, Rep, Ratio<fathomE4, E4>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using pica = Unit<Length, Rep, typename Ratio_times_Ratio<Ratio<picaE4, E4>, milli>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using point = Unit<Length, Rep, typename Ratio_times_Ratio<Ratio<pointE6, E6>, milli>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using cable = Unit<Length, Rep, Ratio<cableE3, E3>, zero>;



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

typedef inch<> Inch;
typedef link<> Link;
typedef foot<> Foot;
typedef yard<> Yard;
typedef rod<> Rod;
typedef chain<> Chain;
typedef mile<> Mile;
typedef league<>  League;
typedef nauticmile<> Nauticmile;
typedef fathom<> Fathom;
typedef pica<> Pica;
typedef point<> Point;
typedef cable<> Cable;



namespace suffixes
{



constexpr yoctometer<OMNI_LITTERAL_FLOATING> operator"" _ym(long double val){return val;}
constexpr zeptometer<OMNI_LITTERAL_FLOATING> operator"" _zm(long double val){return val;}
constexpr attometer<OMNI_LITTERAL_FLOATING> operator"" _am(long double val){return val;}
constexpr femtometer<OMNI_LITTERAL_FLOATING> operator"" _fm(long double val){return val;}
constexpr nanometer<OMNI_LITTERAL_FLOATING> operator"" _nm(long double val){return val;}
constexpr micrometer<OMNI_LITTERAL_FLOATING> operator"" _um(long double val){return val;}
constexpr millimeter<OMNI_LITTERAL_FLOATING> operator"" _mm(long double val){return val;}
constexpr centimeter<OMNI_LITTERAL_FLOATING> operator"" _cm(long double val){return val;}
constexpr decimeter<OMNI_LITTERAL_FLOATING> operator"" _dm(long double val){return val;}
constexpr meter<OMNI_LITTERAL_FLOATING> operator"" _m(long double val){return val;}
constexpr decameter<OMNI_LITTERAL_FLOATING> operator"" _dam(long double val){return val;}
constexpr hectometer<OMNI_LITTERAL_FLOATING> operator"" _hm(long double val){return val;}
constexpr kilometer<OMNI_LITTERAL_FLOATING> operator"" _km(long double val){return val;}
constexpr megameter<OMNI_LITTERAL_FLOATING> operator"" _Mm(long double val){return val;}
constexpr gigameter<OMNI_LITTERAL_FLOATING> operator"" _Gm(long double val){return val;}
constexpr terameter<OMNI_LITTERAL_FLOATING> operator"" _Tm(long double val){return val;}
constexpr petameter<OMNI_LITTERAL_FLOATING> operator"" _Pm(long double val){return val;}
constexpr exameter<OMNI_LITTERAL_FLOATING> operator"" _Em(long double val){return val;}
constexpr zettameter<OMNI_LITTERAL_FLOATING> operator"" _Zm(long double val){return val;}
constexpr yottameter<OMNI_LITTERAL_FLOATING> operator"" _Ym(long double val){return val;}

constexpr angstrom<OMNI_LITTERAL_FLOATING> operator"" _a(long double val){return val;}
constexpr astronomical_unit<OMNI_LITTERAL_FLOATING> operator"" _au(long double val){return val;}
constexpr lightsecond<OMNI_LITTERAL_FLOATING> operator"" _ls(long double val){return val;}
constexpr lightminute<OMNI_LITTERAL_FLOATING> operator"" _lmin(long double val){return val;}
constexpr lightyear<OMNI_LITTERAL_FLOATING> operator"" _ly(long double val){return val;}
constexpr parsec<OMNI_LITTERAL_FLOATING> operator"" _pc(long double val){return val;}
constexpr kiloparsec<OMNI_LITTERAL_FLOATING> operator"" _kpc(long double val){return val;}
constexpr megaparsec<OMNI_LITTERAL_FLOATING> operator"" _Mpc(long double val){return val;}
constexpr gigaparsec<OMNI_LITTERAL_FLOATING> operator"" _Gpc(long double val){return val;}

constexpr inch<OMNI_LITTERAL_FLOATING> operator"" _in(long double val){return val;}
constexpr link<OMNI_LITTERAL_FLOATING> operator"" _lnk(long double val){return val;}
constexpr foot<OMNI_LITTERAL_FLOATING> operator"" _ft(long double val){return val;}
constexpr yard<OMNI_LITTERAL_FLOATING> operator"" _yd(long double val){return val;}
constexpr rod<OMNI_LITTERAL_FLOATING> operator"" _rod(long double val){return val;}
constexpr chain<OMNI_LITTERAL_FLOATING> operator"" _chn(long double val){return val;}
constexpr mile<OMNI_LITTERAL_FLOATING> operator"" _mi(long double val){return val;}
constexpr league<OMNI_LITTERAL_FLOATING> operator"" _lea(long double val){return val;}
constexpr nauticmile<OMNI_LITTERAL_FLOATING> operator"" _nmi(long double val){return val;}
constexpr fathom<OMNI_LITTERAL_FLOATING> operator"" _ftm(long double val){return val;}
constexpr pica<OMNI_LITTERAL_FLOATING> operator"" _pica(long double val){return val;}
constexpr point<OMNI_LITTERAL_FLOATING> operator"" _pt(long double val){return val;}
constexpr cable<OMNI_LITTERAL_FLOATING> operator"" _cb(long double val){return val;}




constexpr yoctometer<OMNI_LITTERAL_INTEGER> operator"" _ym(unsigned long long int val){return val;}
constexpr zeptometer<OMNI_LITTERAL_INTEGER> operator"" _zm(unsigned long long int val){return val;}
constexpr attometer<OMNI_LITTERAL_INTEGER> operator"" _am(unsigned long long int val){return val;}
constexpr femtometer<OMNI_LITTERAL_INTEGER> operator"" _fm(unsigned long long int val){return val;}
constexpr nanometer<OMNI_LITTERAL_INTEGER> operator"" _nm(unsigned long long int val){return val;}
constexpr micrometer<OMNI_LITTERAL_INTEGER> operator"" _um(unsigned long long int val){return val;}
constexpr millimeter<OMNI_LITTERAL_INTEGER> operator"" _mm(unsigned long long int val){return val;}
constexpr centimeter<OMNI_LITTERAL_INTEGER> operator"" _cm(unsigned long long int val){return val;}
constexpr decimeter<OMNI_LITTERAL_INTEGER> operator"" _dm(unsigned long long int val){return val;}
constexpr meter<OMNI_LITTERAL_INTEGER> operator"" _m(unsigned long long int val){return val;}
constexpr decameter<OMNI_LITTERAL_INTEGER> operator"" _dam(unsigned long long int val){return val;}
constexpr hectometer<OMNI_LITTERAL_INTEGER> operator"" _hm(unsigned long long int val){return val;}
constexpr kilometer<OMNI_LITTERAL_INTEGER> operator"" _km(unsigned long long int val){return val;}
constexpr megameter<OMNI_LITTERAL_INTEGER> operator"" _Mm(unsigned long long int val){return val;}
constexpr gigameter<OMNI_LITTERAL_INTEGER> operator"" _Gm(unsigned long long int val){return val;}
constexpr terameter<OMNI_LITTERAL_INTEGER> operator"" _Tm(unsigned long long int val){return val;}
constexpr petameter<OMNI_LITTERAL_INTEGER> operator"" _Pm(unsigned long long int val){return val;}
constexpr exameter<OMNI_LITTERAL_INTEGER> operator"" _Em(unsigned long long int val){return val;}
constexpr zettameter<OMNI_LITTERAL_INTEGER> operator"" _Zm(unsigned long long int val){return val;}
constexpr yottameter<OMNI_LITTERAL_INTEGER> operator"" _Ym(unsigned long long int val){return val;}

constexpr angstrom<OMNI_LITTERAL_INTEGER> operator"" _a(unsigned long long int val){return val;}
constexpr astronomical_unit<OMNI_LITTERAL_INTEGER> operator"" _au(unsigned long long int val){return val;}
constexpr lightsecond<OMNI_LITTERAL_INTEGER> operator"" _ls(unsigned long long int val){return val;}
constexpr lightminute<OMNI_LITTERAL_INTEGER> operator"" _lmin(unsigned long long int val){return val;}
constexpr lightyear<OMNI_LITTERAL_INTEGER> operator"" _ly(unsigned long long int val){return val;}
constexpr parsec<OMNI_LITTERAL_INTEGER> operator"" _pc(unsigned long long int val){return val;}
constexpr kiloparsec<OMNI_LITTERAL_INTEGER> operator"" _kpc(unsigned long long int val){return val;}
constexpr megaparsec<OMNI_LITTERAL_INTEGER> operator"" _Mpc(unsigned long long int val){return val;}
constexpr gigaparsec<OMNI_LITTERAL_INTEGER> operator"" _Gpc(unsigned long long int val){return val;}

constexpr inch<OMNI_LITTERAL_INTEGER> operator"" _in(unsigned long long int val){return val;}
constexpr link<OMNI_LITTERAL_INTEGER> operator"" _lnk(unsigned long long int val){return val;}
constexpr foot<OMNI_LITTERAL_INTEGER> operator"" _ftm(unsigned long long int val){return val;}
constexpr yard<OMNI_LITTERAL_INTEGER> operator"" _yd(unsigned long long int val){return val;}
constexpr rod<OMNI_LITTERAL_INTEGER> operator"" _rod(unsigned long long int val){return val;}
constexpr chain<OMNI_LITTERAL_INTEGER> operator"" _chn(unsigned long long int val){return val;}
constexpr mile<OMNI_LITTERAL_INTEGER> operator"" _mi(unsigned long long int val){return val;}
constexpr league<OMNI_LITTERAL_INTEGER> operator"" _lea(unsigned long long int val){return val;}
constexpr nauticmile<OMNI_LITTERAL_INTEGER> operator"" _nmi(unsigned long long int val){return val;}
constexpr fathom<OMNI_LITTERAL_INTEGER> operator"" _fh(unsigned long long int val){return val;}
constexpr pica<OMNI_LITTERAL_INTEGER> operator"" _pica(unsigned long long int val){return val;}
constexpr point<OMNI_LITTERAL_INTEGER> operator"" _pt(unsigned long long int val){return val;}
constexpr cable<OMNI_LITTERAL_INTEGER> operator"" _cb(unsigned long long int val){return val;}




} //namespaxe suffixes



} //namespace omni


#endif //LENGTH_HH_
