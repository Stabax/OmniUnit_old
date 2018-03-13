//luminosity.hh

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

#ifndef LUMINOSITY_HH_
#define LUMINOSITY_HH_

#include"constants_for_units.hh"

namespace stb
{



namespace omni
{



typedef Dimension<0, 0, 0, 0, 0, 0, 1> Luminosity;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctocandela = Unit<Luminosity, Rep, yocto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptocandela = Unit<Luminosity, Rep, zepto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attocandela = Unit<Luminosity, Rep, atto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtocandela = Unit<Luminosity, Rep, femto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picocandela = Unit<Luminosity, Rep, pico>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanocandela = Unit<Luminosity, Rep, nano>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microcandela = Unit<Luminosity, Rep, micro>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millicandela = Unit<Luminosity, Rep, milli>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centicandela = Unit<Luminosity, Rep, centi>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decicandela = Unit<Luminosity, Rep, deci>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using candela = Unit<Luminosity, Rep, base>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decacandela = Unit<Luminosity, Rep, deca>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectocandela = Unit<Luminosity, Rep, hecto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilocandela = Unit<Luminosity, Rep, kilo>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megacandela = Unit<Luminosity, Rep, mega>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigacandela = Unit<Luminosity, Rep, giga>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using teracandela = Unit<Luminosity, Rep, tera>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petacandela = Unit<Luminosity, Rep, peta>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exacandela = Unit<Luminosity, Rep, exa>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettacandela = Unit<Luminosity, Rep, zetta>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottacandela = Unit<Luminosity, Rep, yotta>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctolumen = yoctocandela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptolumen = zeptocandela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attolumen = attocandela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtolumen = femtocandela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picolumen = picocandela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanolumen = nanocandela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microlumen = microcandela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millilumen = millicandela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centilumen = centicandela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decilumen = decicandela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using lumen = candela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decalumen = decacandela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectolumen = hectocandela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilolumen = kilocandela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megalumen = megacandela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigalumen = gigacandela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using teralumen = teracandela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petalumen = petacandela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exalumen = exacandela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettalumen = zettacandela<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottalumen = yottacandela<Rep>;



namespace def
{



typedef zeptocandela<> zeptocandela;
typedef femtocandela<>  femtocandela;
typedef picocandela<> picocandela;
typedef nanocandela<> nanocandela;
typedef microcandela<> microcandela;
typedef millicandela<> millicandela;
typedef centicandela<> centicandela;
typedef decicandela<> decicandela;
typedef candela<> candela;
typedef decacandela<> decacandela;
typedef hectocandela<> hectocandela;
typedef kilocandela<> kilocandela;
typedef megacandela<> megacandela;
typedef gigacandela<> gigacandela;
typedef teracandela<> teracandela;
typedef petacandela<> petacandela;
typedef exacandela<> exacandela;
typedef zettacandela<> zettacandela;
typedef yottacandela<> yottacandela;

typedef zeptolumen<> zeptolumen;
typedef femtolumen<>  femtolumen;
typedef picolumen<> picolumen;
typedef nanolumen<> nanolumen;
typedef microlumen<> microlumen;
typedef millilumen<> millilumen;
typedef centilumen<> centilumen;
typedef decilumen<> decilumen;
typedef lumen<> lumen;
typedef decalumen<> decalumen;
typedef hectolumen<> hectolumen;
typedef kilolumen<> kilolumen;
typedef megalumen<> megalumen;
typedef gigalumen<> gigalumen;
typedef teralumen<> teralumen;
typedef petalumen<> petalumen;
typedef exalumen<> exalumen;
typedef zettalumen<> zettalumen;
typedef yottalumen<> yottalumen;



} // namespace default



} //namespace omni



} //namespace stb

#endif //LUMINOSITY_HH_
