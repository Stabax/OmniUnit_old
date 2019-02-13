//constants_for_units.hh

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

#ifndef OMNIUNIT_CONSTANTS_FOR_UNITS_HH_
#define OMNIUNIT_CONSTANTS_FOR_UNITS_HH_


namespace omni
{


inline constexpr double one = 1.;
inline constexpr double two = 2.;
inline constexpr double four = 4.;
inline constexpr double five = 5.;
inline constexpr double nine = 9.;
inline constexpr double sixty = 60.;
inline constexpr double degDef = 180.;
inline constexpr double gradDef = 200.;
inline constexpr double piE36 = 3141592653589793238462643383279502884.;
inline constexpr double tauE36 = 2 * piE36;
inline constexpr double distanceTraveledByLightPerSec = 299792458.; // m
inline constexpr double secondsPerHour = 3600; // s
inline constexpr double secondsPerDay = 3600 * 24.; // s
inline constexpr double secondsPerWeek = 3600 * 24. * 7.; // s
inline constexpr double monthsPerYear = 12.; // mon
inline constexpr double secondsPerYearE2 = 36525. * 24. *3600.; // s
inline constexpr double distanceSunEarth = 149597870700.; //m
inline constexpr double parsecDef = 648000.;
inline constexpr double atomic_massDefE9 = 1660538921.; //kg * 10^-27
inline constexpr double evPerC2DefE8 = 178266184.; //kg * 10^-36
inline constexpr double solar_massDefE4 = 19884.; //kg * 10^30
inline constexpr double avogadroE9 = 6022140857.; //10^23 mol-1
inline constexpr double celsiusConstant = 273.15;
inline constexpr double fahrenheitConstant = 459.67;
inline constexpr double inchE2 = 254.; //cm
inline constexpr double linkE4 = 201168; //cm
inline constexpr double footE2 = 3048; //cm
inline constexpr double yardE2 = 9144; //cm
inline constexpr double rodE4 = 50292; //m
inline constexpr double chainE4 = 201168; //m
inline constexpr double mileE3 = 1609344.; //m
inline constexpr double leagueE3 = 4828032; //m
inline constexpr double nauticmileDef = 1852; //m
inline constexpr double fathomE4 = 18288; //m
inline constexpr double picaE4 = 42333; //mm
inline constexpr double pointE6 = 88194; //mm
inline constexpr double cableE3 = 219456; //m
inline constexpr double poundE8 = 45359237; //kg
inline constexpr double ounceE10 = 283495231; // kg
inline constexpr double longtonDef = 1016; //kg
inline constexpr double shorttonE1 = 9072; //kg
inline constexpr double CoulombE9 = 1602176565; //10^-19 C
inline constexpr double calorieE4 = 41855; // J
inline constexpr double btuDef = 1055; // J
inline constexpr double tonTNTE3 = 4184; // 10^9 J
inline constexpr double boeE7 = 61178632; // 10^9 J
inline constexpr double tecE5 = 2930760; // 10^9 J
inline constexpr double tepE3 = 41868; // 10^9 J
inline constexpr double gE5 = 980665;
inline constexpr double poundforceE13 = 44482216152605; // N
inline constexpr double hpE1 = 7355.; // W
inline constexpr double mhpE1 = 7457.; // W



typedef Ratio<piE36, E36> pi;
typedef Ratio<tauE36, E36> tau;
typedef Ratio<secondsPerYearE2, E2> secondsPerYear;
typedef Ratio_over_Ratio<Ratio<parsecDef, E0>, pi>::type parsecDefinition;
typedef Ratio_over_value<Ratio<atomic_massDefE9, E9>, E27>::type atomic_massDefinition;
typedef Ratio_over_value<Ratio<evPerC2DefE8, E8>, E36>::type evPerC2Definition;
typedef Ratio_times_value<Ratio<solar_massDefE4, E4>, E30>::type solar_massDefinition;
typedef Ratio_times_value<Ratio<avogadroE9, E9>, E23>::type avogadro;
typedef Ratio_invert<avogadro>::type unitaryQuantityDefinition;
typedef Ratio<nine, five> fahrenheitRatio;



} //namespace omni

#endif //OMNIUNIT_CONSTANTS_FOR_UNITS_HH_
