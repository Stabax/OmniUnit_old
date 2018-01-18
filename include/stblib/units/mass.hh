//mass.hh

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

#ifndef MASS_HH_
#define MASS_HH_

#include "../Unit.hh"
#include"constants_for_units.hh"

namespace stb
{



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


  
}

#endif //MASS_HH_
