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



#ifndef OMNIUNIT_MASS_HH_
#define OMNIUNIT_MASS_HH_

#include "../omniunit.hh"
#include"constants_for_units.hh"


namespace omni
{



typedef Dimension<0,1,0,0,0,0,0> Mass;





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

template <typename Rep = OMNI_DEFAULT_TYPE>
using pound = Unit<Mass, Rep, Ratio<poundE8, E8>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using ounce = Unit<Mass, Rep, Ratio<ounceE10, E10>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using longton = Unit<Mass, Rep, Ratio<longtonDef, E0>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using shortton = Unit<Mass, Rep, Ratio<shorttonE1, E1>, zero>;



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
typedef pound<> Pound;
typedef ounce<> Ounce;
typedef longton<> Longton;
typedef shortton<> Shortton;



namespace suffixes
{



constexpr zeptogram<OMNI_LITTERAL_FLOATING> operator"" _zg(long double val){return val;}
constexpr attogram<OMNI_LITTERAL_FLOATING> operator"" _ag(long double val){return val;}
constexpr femtogram<OMNI_LITTERAL_FLOATING> operator"" _fg(long double val){return val;}
constexpr nanogram<OMNI_LITTERAL_FLOATING> operator"" _ng(long double val){return val;}
constexpr microgram<OMNI_LITTERAL_FLOATING> operator"" _ug(long double val){return val;}
constexpr milligram<OMNI_LITTERAL_FLOATING> operator"" _mg(long double val){return val;}
constexpr centigram<OMNI_LITTERAL_FLOATING> operator"" _cg(long double val){return val;}
constexpr decigram<OMNI_LITTERAL_FLOATING> operator"" _dg(long double val){return val;}
constexpr gram<OMNI_LITTERAL_FLOATING> operator"" _g(long double val){return val;}
constexpr decagram<OMNI_LITTERAL_FLOATING> operator"" _dag(long double val){return val;}
constexpr hectogram<OMNI_LITTERAL_FLOATING> operator"" _hg(long double val){return val;}
constexpr kilogram<OMNI_LITTERAL_FLOATING> operator"" _kg(long double val){return val;}
constexpr megagram<OMNI_LITTERAL_FLOATING> operator"" _Mg(long double val){return val;}
constexpr gigagram<OMNI_LITTERAL_FLOATING> operator"" _Gg(long double val){return val;}
constexpr teragram<OMNI_LITTERAL_FLOATING> operator"" _Tg(long double val){return val;}
constexpr petagram<OMNI_LITTERAL_FLOATING> operator"" _Pg(long double val){return val;}
constexpr exagram<OMNI_LITTERAL_FLOATING> operator"" _Eg(long double val){return val;}
constexpr zettagram<OMNI_LITTERAL_FLOATING> operator"" _Zg(long double val){return val;}
constexpr yottagram<OMNI_LITTERAL_FLOATING> operator"" _Yg(long double val){return val;}

constexpr atomic_mass<OMNI_LITTERAL_FLOATING> operator"" _u(long double val){return val;}
constexpr evPerC2<OMNI_LITTERAL_FLOATING> operator"" _eVc2(long double val){return val;}
constexpr millievPerC2<OMNI_LITTERAL_FLOATING> operator"" _meVc2(long double val){return val;}
constexpr microevPerC2<OMNI_LITTERAL_FLOATING> operator"" _ueVc2(long double val){return val;}
constexpr kiloevPerC2<OMNI_LITTERAL_FLOATING> operator"" _keVc2(long double val){return val;}
constexpr megaevPerC2<OMNI_LITTERAL_FLOATING> operator"" _MeVc2(long double val){return val;}
constexpr gigaevPerC2<OMNI_LITTERAL_FLOATING> operator"" _GeVc2(long double val){return val;}
constexpr teraevPerC2<OMNI_LITTERAL_FLOATING> operator"" _TeVc2(long double val){return val;}
constexpr ton<OMNI_LITTERAL_FLOATING> operator"" _ton(long double val){return val;}
constexpr solar_mass<OMNI_LITTERAL_FLOATING> operator"" _SM(long double val){return val;}
constexpr pound<OMNI_LITTERAL_FLOATING> operator"" _lb(long double val){return val;}
constexpr ounce<OMNI_LITTERAL_FLOATING> operator"" _oz(long double val){return val;}
constexpr longton<OMNI_LITTERAL_FLOATING> operator"" _lton(long double val){return val;}
constexpr shortton<OMNI_LITTERAL_FLOATING> operator"" _ston(long double val){return val;}



constexpr zeptogram<OMNI_LITTERAL_INTEGER> operator"" _zg(unsigned long long int val){return val;}
constexpr attogram<OMNI_LITTERAL_INTEGER> operator"" _ag(unsigned long long int val){return val;}
constexpr femtogram<OMNI_LITTERAL_INTEGER> operator"" _fg(unsigned long long int val){return val;}
constexpr nanogram<OMNI_LITTERAL_INTEGER> operator"" _ng(unsigned long long int val){return val;}
constexpr microgram<OMNI_LITTERAL_INTEGER> operator"" _ug(unsigned long long int val){return val;}
constexpr milligram<OMNI_LITTERAL_INTEGER> operator"" _mg(unsigned long long int val){return val;}
constexpr centigram<OMNI_LITTERAL_INTEGER> operator"" _cg(unsigned long long int val){return val;}
constexpr decigram<OMNI_LITTERAL_INTEGER> operator"" _dg(unsigned long long int val){return val;}
constexpr gram<OMNI_LITTERAL_INTEGER> operator"" _g(unsigned long long int val){return val;}
constexpr decagram<OMNI_LITTERAL_INTEGER> operator"" _dag(unsigned long long int val){return val;}
constexpr hectogram<OMNI_LITTERAL_INTEGER> operator"" _hg(unsigned long long int val){return val;}
constexpr kilogram<OMNI_LITTERAL_INTEGER> operator"" _kg(unsigned long long int val){return val;}
constexpr megagram<OMNI_LITTERAL_INTEGER> operator"" _Mg(unsigned long long int val){return val;}
constexpr gigagram<OMNI_LITTERAL_INTEGER> operator"" _Gg(unsigned long long int val){return val;}
constexpr teragram<OMNI_LITTERAL_INTEGER> operator"" _Tg(unsigned long long int val){return val;}
constexpr petagram<OMNI_LITTERAL_INTEGER> operator"" _Pg(unsigned long long int val){return val;}
constexpr exagram<OMNI_LITTERAL_INTEGER> operator"" _Eg(unsigned long long int val){return val;}
constexpr zettagram<OMNI_LITTERAL_INTEGER> operator"" _Zg(unsigned long long int val){return val;}
constexpr yottagram<OMNI_LITTERAL_INTEGER> operator"" _Yg(unsigned long long int val){return val;}

constexpr atomic_mass<OMNI_LITTERAL_INTEGER> operator"" _u(unsigned long long int val){return val;}
constexpr evPerC2<OMNI_LITTERAL_INTEGER> operator"" _eVc2(unsigned long long int val){return val;}
constexpr millievPerC2<OMNI_LITTERAL_INTEGER> operator"" _meVc2(unsigned long long int val){return val;}
constexpr microevPerC2<OMNI_LITTERAL_INTEGER> operator"" _ueVc2(unsigned long long int val){return val;}
constexpr kiloevPerC2<OMNI_LITTERAL_INTEGER> operator"" _keVc2(unsigned long long int val){return val;}
constexpr megaevPerC2<OMNI_LITTERAL_INTEGER> operator"" _MeVc2(unsigned long long int val){return val;}
constexpr gigaevPerC2<OMNI_LITTERAL_INTEGER> operator"" _GeVc2(unsigned long long int val){return val;}
constexpr teraevPerC2<OMNI_LITTERAL_INTEGER> operator"" _TeVc2(unsigned long long int val){return val;}

constexpr ton<OMNI_LITTERAL_INTEGER> operator"" _ton(unsigned long long int val){return val;}
constexpr solar_mass<OMNI_LITTERAL_INTEGER> operator"" _SM(unsigned long long int val){return val;}
constexpr pound<OMNI_LITTERAL_INTEGER> operator"" _lb(unsigned long long int val){return val;}
constexpr ounce<OMNI_LITTERAL_INTEGER> operator"" _oz(unsigned long long int val){return val;}
constexpr longton<OMNI_LITTERAL_INTEGER> operator"" _lton(unsigned long long int val){return val;}
constexpr shortton<OMNI_LITTERAL_INTEGER> operator"" _ston(unsigned long long int val){return val;}



} //namespaxe suffixes



} //namespace omni


#endif //OMNIUNIT_MASS_HH_
