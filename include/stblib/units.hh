//units.hh

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

#ifndef UNITS_HH_
#define UNITS_HH_

#include "Unit.hh"

namespace stb
{



//=============================================================================
//=============================================================================
// Useful constants ===========================================================
//=============================================================================
//=============================================================================



static constexpr double piE36 = 3141592653589793238462643383279502884.;
static constexpr double distanceTraveledByLightIn1Sec = 299792458; // m
static constexpr double secondsIn1Min = 60.; // s
static constexpr double secondsIn1Hour = 3600.; // s
static constexpr double secondsIn1Day = 3600. * 24.; // s
static constexpr double secondsIn1Week = 3600 * 24. * 7.; // s
static constexpr double monthsIn1Year = 12.; // s
static constexpr double secondsIn1YearE2 = 36525. * 24. *3600.; // s
static constexpr double distanceSunEarth = 149597870700.; //m
static constexpr double parsecDef = 648000.;
static constexpr double atomic_massDefE9 = 1660538921.; //kg * 10^-27
static constexpr double evPerC2DefE8     =  178266191.; //kg * 10^-36
static constexpr double solar_massDefE4     =  19884.; //kg * 10^30

typedef ratio<piE36, E36> pi;
typedef ratio<secondsIn1YearE2, E2> secondsIn1Year;
typedef ratio_divide<ratio<parsecDef, E0>, pi>::type parsecDefinition;
typedef ratio_multiply<ratio<atomic_massDefE9, E9>, ratio<E0, E27>>::type atomic_massDefinition;
typedef ratio_multiply<ratio<evPerC2DefE8, E8>, ratio<E0, E36>>::type evPerC2Definition;
typedef ratio_multiply<ratio<solar_massDefE4, E4>, ratio<E30, E0>>::type solar_massDefinition;
typedef ratio_divide<secondsIn1Year, ratio<monthsIn1Year, E0>>::type secondsIn1Month;



//=============================================================================
//=============================================================================
// Length =====================================================================
//=============================================================================
//=============================================================================



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
using angstrom = Unit<Length, Rep, ratio<E0, E10>>;

template <typename Rep>
using astronomical_unit = Unit<Length, Rep, ratio<distanceSunEarth, E0>>;

template <typename Rep>
using lightsecond = Unit<Length, Rep, ratio<distanceTraveledByLightIn1Sec, E10>>;

template <typename Rep>
using lightminute = Unit<Length, Rep, typename ratio_multiply<
typename lightsecond<Rep>::period, ratio<secondsIn1Min, E0>>::type>;

template <typename Rep>
using lightyear = Unit<Length, Rep, typename ratio_multiply<
typename lightsecond<Rep>::period, secondsIn1Year>::type>;

template <typename Rep>
using parsec = Unit<Length, Rep, typename ratio_multiply<
typename astronomical_unit<Rep>::period, parsecDefinition>::type>;

template <typename Rep>
using kiloparsec = Unit<Length, Rep, typename ratio_multiply<
typename parsec<Rep>::period, kilo>::type>;

template <typename Rep>
using megaparsec = Unit<Length, Rep, typename ratio_multiply<
typename parsec<Rep>::period, mega>::type>;

template <typename Rep>
using gigaparsec = Unit<Length, Rep, typename ratio_multiply<
typename parsec<Rep>::period, giga>::type>;





//=============================================================================
//=============================================================================
// Mass =======================================================================
//=============================================================================
//=============================================================================



typedef Dimension<0, 1, 0, 0, 0, 0, 0> Mass;





template <typename Rep>
using zeptogram = Unit<Mass, Rep, yocto>;

template <typename Rep>
using attogram = Unit<Mass, Rep, zepto>;

template <typename Rep>
using femtogram = Unit<Mass, Rep, atto>;

template <typename Rep>
using picogram = Unit<Mass, Rep, femto>;

template <typename Rep>
using nanogram = Unit<Mass, Rep, pico>;

template <typename Rep>
using microgram = Unit<Mass, Rep, nano>;

template <typename Rep>
using milligram = Unit<Mass, Rep, micro>;

template <typename Rep>
using centigram = Unit<Mass, Rep, ratio<E0, E5>>;

template <typename Rep>
using decigram = Unit<Mass, Rep, ratio<E0, E4>>;

template <typename Rep>
using gram = Unit<Mass, Rep, milli>;

template <typename Rep>
using decagram = Unit<Mass, Rep, ratio<E0, E2>>;

template <typename Rep>
using hectogram = Unit<Mass, Rep, ratio<E0, E1>>;

template <typename Rep>
using kilogram = Unit<Mass, Rep, base>;

template <typename Rep>
using megagram = Unit<Mass, Rep, kilo>;

template <typename Rep>
using gigagram = Unit<Mass, Rep, mega>;

template <typename Rep>
using teragram = Unit<Mass, Rep, giga>;

template <typename Rep>
using petagram = Unit<Mass, Rep, tera>;

template <typename Rep>
using exagram = Unit<Mass, Rep, peta>;

template <typename Rep>
using zettagram = Unit<Mass, Rep, exa>;

template <typename Rep>
using yottagram = Unit<Mass, Rep, zetta>;





template <typename Rep>
using atomic_mass = Unit<Mass, Rep, typename ratio_multiply<
atomic_massDefinition, ratio<E0, E27>>::type>;

template <typename Rep>
using evPerC2 = Unit<Mass, Rep, evPerC2Definition>;

template <typename Rep>
using millievPerC2 = Unit<Mass, Rep, typename ratio_multiply<
typename evPerC2<Rep>::period, milli>::type>;

template <typename Rep>
using microevPerC2 = Unit<Mass, Rep, typename ratio_multiply<
typename evPerC2<Rep>::period, micro>::type>;

template <typename Rep>
using nanoevPerC2 = Unit<Mass, Rep, typename ratio_multiply<
typename evPerC2<Rep>::period, nano>::type>;

template <typename Rep>
using kiloevPerC2 = Unit<Mass, Rep, typename ratio_multiply<
typename evPerC2<Rep>::period, kilo>::type>;

template <typename Rep>
using megaevPerC2 = Unit<Mass, Rep, typename ratio_multiply<
typename evPerC2<Rep>::period, mega>::type>;

template <typename Rep>
using gigaevPerC2 = Unit<Mass, Rep, typename ratio_multiply<
typename evPerC2<Rep>::period, giga>::type>;

template <typename Rep>
using teraevPerC2 = Unit<Mass, Rep, typename ratio_multiply<
typename evPerC2<Rep>::period, tera>::type>;

template <typename Rep>
using petaevPerC2 = Unit<Mass, Rep, typename ratio_multiply<
typename evPerC2<Rep>::period, peta>::type>;





template <typename Rep>
using solar_mass = Unit<Mass, Rep, solar_massDefinition>;





//=============================================================================
//=============================================================================
// Duration ===================================================================
//=============================================================================
//=============================================================================



typedef Dimension<0, 0, 1, 0, 0, 0, 0> Duration;



template <typename Rep>
using yoctosecond = Unit<Duration, Rep, yocto>;

template <typename Rep>
using zeptosecond = Unit<Duration, Rep, zepto>;

template <typename Rep>
using attosecond = Unit<Duration, Rep, atto>;

template <typename Rep>
using femtosecond = Unit<Duration, Rep, femto>;

template <typename Rep>
using picosecond = Unit<Duration, Rep, pico>;

template <typename Rep>
using nanosecond = Unit<Duration, Rep, nano>;

template <typename Rep>
using microsecond = Unit<Duration, Rep, micro>;

template <typename Rep>
using millisecond = Unit<Duration, Rep, milli>;

template <typename Rep>
using centisecond = Unit<Duration, Rep, centi>;

template <typename Rep>
using decisecond = Unit<Duration, Rep, deci>;

template <typename Rep>
using second = Unit<Duration, Rep, base>;

template <typename Rep>
using decasecond = Unit<Duration, Rep, deca>;

template <typename Rep>
using hectosecond = Unit<Duration, Rep, hecto>;

template <typename Rep>
using kilosecond = Unit<Duration, Rep, kilo>;

template <typename Rep>
using megasecond = Unit<Duration, Rep, mega>;

template <typename Rep>
using gigasecond = Unit<Duration, Rep, giga>;

template <typename Rep>
using terasecond = Unit<Duration, Rep, tera>;

template <typename Rep>
using petasecond = Unit<Duration, Rep, peta>;

template <typename Rep>
using exasecond = Unit<Duration, Rep, exa>;

template <typename Rep>
using zettasecond = Unit<Duration, Rep, zetta>;

template <typename Rep>
using yottasecond = Unit<Duration, Rep, yotta>;





template <typename Rep>
using minute = Unit<Duration, Rep, ratio<secondsIn1Min, E0>>;

template <typename Rep>
using hour = Unit<Duration, Rep, ratio<secondsIn1Hour, E0>>;

template <typename Rep>
using day = Unit<Duration, Rep, ratio<secondsIn1Day, E0>>;

template <typename Rep>
using week = Unit<Duration, Rep, ratio<secondsIn1Week, E0>>;

template <typename Rep>
using month = Unit<Duration, Rep, secondsIn1Month>;

template <typename Rep>
using year = Unit<Duration, Rep, secondsIn1Year>;

template <typename Rep>
using kiloyear = Unit<Duration, Rep, typename ratio_multiply<
typename year<Rep>::period, kilo>::type>;

template <typename Rep>
using megayear = Unit<Duration, Rep, typename ratio_multiply<
typename year<Rep>::period, mega>::type>;

template <typename Rep>
using gigayear = Unit<Duration, Rep, typename ratio_multiply<
typename year<Rep>::period, giga>::type>;





//=============================================================================
//=============================================================================
// ElectricCurrent ============================================================
//=============================================================================
//=============================================================================



typedef Dimension<0, 0, 0, 1, 0, 0, 0> ElectricCurrent;



template <typename Rep>
using yoctoampere = Unit<ElectricCurrent, Rep, yocto>;

template <typename Rep>
using zeptoampere = Unit<ElectricCurrent, Rep, zepto>;

template <typename Rep>
using attoampere = Unit<ElectricCurrent, Rep, atto>;

template <typename Rep>
using femtoampere = Unit<ElectricCurrent, Rep, femto>;

template <typename Rep>
using picoampere = Unit<ElectricCurrent, Rep, pico>;

template <typename Rep>
using nanoampere = Unit<ElectricCurrent, Rep, nano>;

template <typename Rep>
using microampere = Unit<ElectricCurrent, Rep, micro>;

template <typename Rep>
using milliampere = Unit<ElectricCurrent, Rep, milli>;

template <typename Rep>
using centiampere = Unit<ElectricCurrent, Rep, centi>;

template <typename Rep>
using deciampere = Unit<ElectricCurrent, Rep, deci>;

template <typename Rep>
using ampere = Unit<ElectricCurrent, Rep, base>;

template <typename Rep>
using decaampere = Unit<ElectricCurrent, Rep, deca>;

template <typename Rep>
using hectoampere = Unit<ElectricCurrent, Rep, hecto>;

template <typename Rep>
using kiloampere = Unit<ElectricCurrent, Rep, kilo>;

template <typename Rep>
using megaampere = Unit<ElectricCurrent, Rep, mega>;

template <typename Rep>
using gigaampere = Unit<ElectricCurrent, Rep, giga>;

template <typename Rep>
using teraampere = Unit<ElectricCurrent, Rep, tera>;

template <typename Rep>
using petaampere = Unit<ElectricCurrent, Rep, peta>;

template <typename Rep>
using exaampere = Unit<ElectricCurrent, Rep, exa>;

template <typename Rep>
using zettaampere = Unit<ElectricCurrent, Rep, zetta>;

template <typename Rep>
using yottaampere = Unit<ElectricCurrent, Rep, yotta>;





//=============================================================================
//=============================================================================
// Temperature ================================================================
//=============================================================================
//=============================================================================



typedef Dimension<0, 0, 0, 0, 1, 0, 0> Temperature;



template <typename Rep>
using yoctokelvin = Unit<Temperature, Rep, yocto>;

template <typename Rep>
using zeptokelvin = Unit<Temperature, Rep, zepto>;

template <typename Rep>
using attokelvin = Unit<Temperature, Rep, atto>;

template <typename Rep>
using femtokelvin = Unit<Temperature, Rep, femto>;

template <typename Rep>
using picokelvin = Unit<Temperature, Rep, pico>;

template <typename Rep>
using nanokelvin = Unit<Temperature, Rep, nano>;

template <typename Rep>
using microkelvin = Unit<Temperature, Rep, micro>;

template <typename Rep>
using millikelvin = Unit<Temperature, Rep, milli>;

template <typename Rep>
using centikelvin = Unit<Temperature, Rep, centi>;

template <typename Rep>
using decikelvin = Unit<Temperature, Rep, deci>;

template <typename Rep>
using kelvin = Unit<Temperature, Rep, base>;

template <typename Rep>
using decakelvin = Unit<Temperature, Rep, deca>;

template <typename Rep>
using hectokelvin = Unit<Temperature, Rep, hecto>;

template <typename Rep>
using kilokelvin = Unit<Temperature, Rep, kilo>;

template <typename Rep>
using megakelvin = Unit<Temperature, Rep, mega>;

template <typename Rep>
using gigakelvin = Unit<Temperature, Rep, giga>;

template <typename Rep>
using terakelvin = Unit<Temperature, Rep, tera>;

template <typename Rep>
using petakelvin = Unit<Temperature, Rep, peta>;

template <typename Rep>
using exakelvin = Unit<Temperature, Rep, exa>;

template <typename Rep>
using zettakelvin = Unit<Temperature, Rep, zetta>;

template <typename Rep>
using yottakelvin = Unit<Temperature, Rep, yotta>;





//=============================================================================
//=============================================================================
// Quantity ===================================================================
//=============================================================================
//=============================================================================



typedef Dimension<0, 0, 0, 0, 0, 1, 0> Quantity;



template <typename Rep>
using yoctomol = Unit<Quantity, Rep, yocto>;

template <typename Rep>
using zeptomol = Unit<Quantity, Rep, zepto>;

template <typename Rep>
using attomol = Unit<Quantity, Rep, atto>;

template <typename Rep>
using femtomol = Unit<Quantity, Rep, femto>;

template <typename Rep>
using picomol = Unit<Quantity, Rep, pico>;

template <typename Rep>
using nanomol = Unit<Quantity, Rep, nano>;

template <typename Rep>
using micromol = Unit<Quantity, Rep, micro>;

template <typename Rep>
using millimol = Unit<Quantity, Rep, milli>;

template <typename Rep>
using centimol = Unit<Quantity, Rep, centi>;

template <typename Rep>
using decimol = Unit<Quantity, Rep, deci>;

template <typename Rep>
using mol = Unit<Quantity, Rep, base>;

template <typename Rep>
using decamol = Unit<Quantity, Rep, deca>;

template <typename Rep>
using hectomol = Unit<Quantity, Rep, hecto>;

template <typename Rep>
using kilomol = Unit<Quantity, Rep, kilo>;

template <typename Rep>
using megamol = Unit<Quantity, Rep, mega>;

template <typename Rep>
using gigamol = Unit<Quantity, Rep, giga>;

template <typename Rep>
using teramol = Unit<Quantity, Rep, tera>;

template <typename Rep>
using petamol = Unit<Quantity, Rep, peta>;

template <typename Rep>
using examol = Unit<Quantity, Rep, exa>;

template <typename Rep>
using zettamol = Unit<Quantity, Rep, zetta>;

template <typename Rep>
using yottamol = Unit<Quantity, Rep, yotta>;





//=============================================================================
//=============================================================================
// Luminosity =================================================================
//=============================================================================
//=============================================================================



typedef Dimension<0, 0, 0, 0, 0, 0, 1> Luminosity;



template <typename Rep>
using yoctocandela = Unit<Luminosity, Rep, yocto>;

template <typename Rep>
using zeptocandela = Unit<Luminosity, Rep, zepto>;

template <typename Rep>
using attocandela = Unit<Luminosity, Rep, atto>;

template <typename Rep>
using femtocandela = Unit<Luminosity, Rep, femto>;

template <typename Rep>
using picocandela = Unit<Luminosity, Rep, pico>;

template <typename Rep>
using nanocandela = Unit<Luminosity, Rep, nano>;

template <typename Rep>
using microcandela = Unit<Luminosity, Rep, micro>;

template <typename Rep>
using millicandela = Unit<Luminosity, Rep, milli>;

template <typename Rep>
using centicandela = Unit<Luminosity, Rep, centi>;

template <typename Rep>
using decicandela = Unit<Luminosity, Rep, deci>;

template <typename Rep>
using candela = Unit<Luminosity, Rep, base>;

template <typename Rep>
using decacandela = Unit<Luminosity, Rep, deca>;

template <typename Rep>
using hectocandela = Unit<Luminosity, Rep, hecto>;

template <typename Rep>
using kilocandela = Unit<Luminosity, Rep, kilo>;

template <typename Rep>
using megacandela = Unit<Luminosity, Rep, mega>;

template <typename Rep>
using gigacandela = Unit<Luminosity, Rep, giga>;

template <typename Rep>
using teracandela = Unit<Luminosity, Rep, tera>;

template <typename Rep>
using petacandela = Unit<Luminosity, Rep, peta>;

template <typename Rep>
using exacandela = Unit<Luminosity, Rep, exa>;

template <typename Rep>
using zettacandela = Unit<Luminosity, Rep, zetta>;

template <typename Rep>
using yottacandela = Unit<Luminosity, Rep, yotta>;



} //namespace stb

#endif //UNITS_HH_
