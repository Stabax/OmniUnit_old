//length.hh

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

#ifndef LENGTH_HH_
#define LENGTH_HH_

#include"constants_for_units.hh"

namespace stb
{



namespace omni
{



typedef Dimension<1, 0, 0, 0, 0, 0, 0, 0, 0> Length;



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
using lightsecond = Unit<Length, Rep, Ratio<distanceTraveledByLightIn1Sec, E10>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using lightminute = Unit<Length, Rep, typename Ratio_multiply<
typename lightsecond<Rep>::period, Ratio<secondsIn1Min, E0>>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using lightyear = Unit<Length, Rep, typename Ratio_multiply<
typename lightsecond<Rep>::period, secondsIn1Year>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using parsec = Unit<Length, Rep, typename Ratio_multiply<
typename astronomical_unit<Rep>::period, parsecDefinition>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kiloparsec = Unit<Length, Rep, typename Ratio_multiply<
typename parsec<Rep>::period, kilo>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megaparsec = Unit<Length, Rep, typename Ratio_multiply<
typename parsec<Rep>::period, mega>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigaparsec = Unit<Length, Rep, typename Ratio_multiply<
typename parsec<Rep>::period, giga>::type, zero>;



namespace def
{



typedef zeptometer<> zeptometer;
typedef femtometer<>  femtometer;
typedef picometer<> picometer;
typedef nanometer<> nanometer;
typedef micrometer<> micrometer;
typedef millimeter<> millimeter;
typedef centimeter<> centimeter;
typedef decimeter<> decimeter;
typedef meter<> meter;
typedef decameter<> decameter;
typedef hectometer<> hectometer;
typedef kilometer<> kilometer;
typedef megameter<> megameter;
typedef gigameter<> gigameter;
typedef terameter<> terameter;
typedef petameter<> petameter;
typedef exameter<> exameter;
typedef zettameter<> zettameter;
typedef yottameter<> yottameter;

typedef angstrom<> angstrom;
typedef astronomical_unit<> astronomical_unit;
typedef lightsecond<> lightsecond;
typedef lightminute<> lightminute;
typedef lightyear<> lightyear;
typedef parsec<> parsec;
typedef kiloparsec<> kiloparsec;
typedef megaparsec<> megaparsec;
typedef gigaparsec<> gigaparsec;



} // namespace default



} //namespace omni



} //namespace stb

#endif //LENGTH_HH_
