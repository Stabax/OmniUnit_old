//mass.hh

/*
Copyright (c) 2016, Denis Tosetto All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

  Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.

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



namespace def
{



typedef zeptogram<> zeptogram;
typedef femtogram<>  femtogram;
typedef picogram<> picogram;
typedef nanogram<> nanogram;
typedef microgram<> microgram;
typedef milligram<> milligram;
typedef centigram<> centigram;
typedef decigram<> decigram;
typedef gram<> gram;
typedef decagram<> decagram;
typedef hectogram<> hectogram;
typedef kilogram<> kilogram;
typedef megagram<> megagram;
typedef gigagram<> gigagram;
typedef teragram<> teragram;
typedef petagram<> petagram;
typedef exagram<> exagram;
typedef zettagram<> zettagram;
typedef yottagram<> yottagram;

typedef atomic_mass<> atomic_mass;

typedef evPerC2<> evPerC2;
typedef millievPerC2<> millievPerC2;
typedef microevPerC2<> microevPerC2;
typedef kiloevPerC2<> kiloevPerC2;
typedef megaevPerC2<> megaevPerC2;
typedef gigaevPerC2<> gigaevPerC2;
typedef teraevPerC2<> teraevPerC2;

typedef ton<> ton;
typedef solar_mass<> solar_mass;



} // namespace default



} //namespace omni


#endif //MASS_HH_
