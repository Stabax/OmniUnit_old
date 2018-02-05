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



typedef Dimension<1, 0, 0, 0, 0, 0, 0> Length;



template <typename Rep>
using yoctometer = Unit<Length, Rep, yocto>;

template <typename Rep>
using zeptometer = Unit<Length, Rep, zepto>;

template <typename Rep>
using attometer = Unit<Length, Rep, atto>;

template <typename Rep>
using femtometer = Unit<Length, Rep, femto>;

template <typename Rep>
using picometer = Unit<Length, Rep, pico>;

template <typename Rep>
using nanometer = Unit<Length, Rep, nano>;

template <typename Rep>
using micrometer = Unit<Length, Rep, micro>;

template <typename Rep>
using millimeter = Unit<Length, Rep, milli>;

template <typename Rep>
using centimeter = Unit<Length, Rep, centi>;

template <typename Rep>
using decimeter = Unit<Length, Rep, deci>;

template <typename Rep>
using meter = Unit<Length, Rep, base>;

template <typename Rep>
using decameter = Unit<Length, Rep, deca>;

template <typename Rep>
using hectometer = Unit<Length, Rep, hecto>;

template <typename Rep>
using kilometer = Unit<Length, Rep, kilo>;

template <typename Rep>
using megameter = Unit<Length, Rep, mega>;

template <typename Rep>
using gigameter = Unit<Length, Rep, giga>;

template <typename Rep>
using terameter = Unit<Length, Rep, tera>;

template <typename Rep>
using petameter = Unit<Length, Rep, peta>;

template <typename Rep>
using exameter = Unit<Length, Rep, exa>;

template <typename Rep>
using zettameter = Unit<Length, Rep, zetta>;

template <typename Rep>
using yottameter = Unit<Length, Rep, yotta>;





template <typename Rep>
using angstrom = Unit<Length, Rep, Ratio<E0, E10>>;

template <typename Rep>
using astronomical_unit = Unit<Length, Rep, Ratio<distanceSunEarth, E0>>;

template <typename Rep>
using lightsecond = Unit<Length, Rep, Ratio<distanceTraveledByLightIn1Sec, E10>>;

template <typename Rep>
using lightminute = Unit<Length, Rep, typename Ratio_multiply<
typename lightsecond<Rep>::period, Ratio<secondsIn1Min, E0>>::type>;

template <typename Rep>
using lightyear = Unit<Length, Rep, typename Ratio_multiply<
typename lightsecond<Rep>::period, secondsIn1Year>::type>;

template <typename Rep>
using parsec = Unit<Length, Rep, typename Ratio_multiply<
typename astronomical_unit<Rep>::period, parsecDefinition>::type>;

template <typename Rep>
using kiloparsec = Unit<Length, Rep, typename Ratio_multiply<
typename parsec<Rep>::period, kilo>::type>;

template <typename Rep>
using megaparsec = Unit<Length, Rep, typename Ratio_multiply<
typename parsec<Rep>::period, mega>::type>;

template <typename Rep>
using gigaparsec = Unit<Length, Rep, typename Ratio_multiply<
typename parsec<Rep>::period, giga>::type>;



} //namespace omni



} //namespace stb

#endif //LENGTH_HH_
