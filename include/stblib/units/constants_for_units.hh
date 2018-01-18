//constants_for_units.hh

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

#ifndef CONSTANTS_FOR_UNITS_HH_
#define CONSTANTS_FOR_UNITS_HH_

#include "../ratio.hh"

namespace stb
{



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



}

#endif //CONSTANTS_FOR_UNITS_HH_
