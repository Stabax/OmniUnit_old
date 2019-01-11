//mass.hh

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



#ifndef MASS_HH_
#define MASS_HH_

#include"constants_for_units.hh"


namespace omni
{



typedef Dimension<0, 1, 0, 0, 0, 0, 0, 0, 0> Mass;





template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptogram = Unit<Mass, Rep, yocto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attogram = Unit<Mass, Rep, zepto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtogram = Unit<Mass, Rep, atto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picogram = Unit<Mass, Rep, femto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanogram = Unit<Mass, Rep, pico, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microgram = Unit<Mass, Rep, nano, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using milligram = Unit<Mass, Rep, micro, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centigram = Unit<Mass, Rep, Ratio<E0, E5>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decigram = Unit<Mass, Rep, Ratio<E0, E4>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gram = Unit<Mass, Rep, milli, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decagram = Unit<Mass, Rep, Ratio<E0, E2>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectogram = Unit<Mass, Rep, Ratio<E0, E1>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilogram = Unit<Mass, Rep, base, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megagram = Unit<Mass, Rep, kilo, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigagram = Unit<Mass, Rep, mega, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using teragram = Unit<Mass, Rep, giga, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petagram = Unit<Mass, Rep, tera, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exagram = Unit<Mass, Rep, peta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettagram = Unit<Mass, Rep, exa, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottagram = Unit<Mass, Rep, zetta, zero>;





template <typename Rep = OMNI_DEFAULT_TYPE>
using atomic_mass = Unit<Mass, Rep, atomic_massDefinition, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using evPerC2 = Unit<Mass, Rep, evPerC2Definition, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millievPerC2 = Unit<Mass, Rep, typename Ratio_times_Ratio<
typename evPerC2<Rep>::period, milli>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microevPerC2 = Unit<Mass, Rep, typename Ratio_times_Ratio<
typename evPerC2<Rep>::period, micro>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kiloevPerC2 = Unit<Mass, Rep, typename Ratio_times_Ratio<
typename evPerC2<Rep>::period, kilo>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megaevPerC2 = Unit<Mass, Rep, typename Ratio_times_Ratio<
typename evPerC2<Rep>::period, mega>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigaevPerC2 = Unit<Mass, Rep, typename Ratio_times_Ratio<
typename evPerC2<Rep>::period, giga>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using teraevPerC2 = Unit<Mass, Rep, typename Ratio_times_Ratio<
typename evPerC2<Rep>::period, tera>::type, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using ton = megagram<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using solar_mass = Unit<Mass, Rep, solar_massDefinition, zero>;



typedef zeptogram<> Zeptogram;
typedef attogram<> Attogram;
typedef femtogram<>  Femtogram;
typedef picogram<> Picogram;
typedef nanogram<> Nanogram;
typedef microgram<> Microgram;
typedef milligram<> Milligram;
typedef centigram<> Centigram;
typedef decigram<> Decigram;
typedef gram<> Gram;
typedef decagram<> Decagram;
typedef hectogram<> Hectogram;
typedef kilogram<> Kilogram;
typedef megagram<> Megagram;
typedef gigagram<> Gigagram;
typedef teragram<> Teragram;
typedef petagram<> Petagram;
typedef exagram<> Exagram;
typedef zettagram<> Zettagram;
typedef yottagram<> Yottagram;

typedef atomic_mass<> Atomic_mass;

typedef evPerC2<> EvPerC2;
typedef millievPerC2<> MillievPerC2;
typedef microevPerC2<> MicroevPerC2;
typedef kiloevPerC2<> KiloevPerC2;
typedef megaevPerC2<> MegaevPerC2;
typedef gigaevPerC2<> GigaevPerC2;
typedef teraevPerC2<> TeraevPerC2;

typedef ton<> Ton;
typedef solar_mass<> Solar_mass;



namespace suffixes
{



constexpr Zeptogram operator"" _zg(long double val){return val;}
constexpr Attogram operator"" _ag(long double val){return val;}
constexpr Femtogram operator"" _fg(long double val){return val;}
constexpr Nanogram operator"" _ng(long double val){return val;}
constexpr Microgram operator"" _ug(long double val){return val;}
constexpr Milligram operator"" _mg(long double val){return val;}
constexpr Centigram operator"" _cg(long double val){return val;}
constexpr Decigram operator"" _dg(long double val){return val;}
constexpr Gram operator"" _g(long double val){return val;}
constexpr Decagram operator"" _dag(long double val){return val;}
constexpr Hectogram operator"" _hg(long double val){return val;}
constexpr Kilogram operator"" _kg(long double val){return val;}
constexpr Megagram operator"" _Mg(long double val){return val;}
constexpr Gigagram operator"" _Gg(long double val){return val;}
constexpr Teragram operator"" _Tg(long double val){return val;}
constexpr Petagram operator"" _Pg(long double val){return val;}
constexpr Exagram operator"" _Eg(long double val){return val;}
constexpr Zettagram operator"" _Zg(long double val){return val;}
constexpr Yottagram operator"" _Yg(long double val){return val;}

constexpr Atomic_mass operator"" _u(long double val){return val;}
constexpr EvPerC2 operator"" _eVc2(long double val){return val;}
constexpr MillievPerC2 operator"" _meVc2(long double val){return val;}
constexpr MicroevPerC2 operator"" _ueVc2(long double val){return val;}
constexpr KiloevPerC2 operator"" _keVc2(long double val){return val;}
constexpr MegaevPerC2 operator"" _MeVc2(long double val){return val;}
constexpr GigaevPerC2 operator"" _GeVc2(long double val){return val;}
constexpr TeraevPerC2 operator"" _TeVc2(long double val){return val;}
constexpr Ton operator"" _ton(long double val){return val;}
constexpr Solar_mass operator"" _SM(long double val){return val;}



} //namespaxe suffixies



} //namespace omni


#endif //MASS_HH_
