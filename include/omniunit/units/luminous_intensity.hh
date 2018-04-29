//luminous_intensity.hh

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

#ifndef LUMINOUS_INTENSITY_HH_
#define LUMINOUS_INTENSITY_HH_

#include "constants_for_units.hh"

namespace stb
{



namespace omni
{



typedef Dimension<0, 0, 0, 0, 0, 0, 1, 0, 0> LuminousIntensity;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctocandela = Unit<LuminousIntensity, Rep, yocto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptocandela = Unit<LuminousIntensity, Rep, zepto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attocandela = Unit<LuminousIntensity, Rep, atto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtocandela = Unit<LuminousIntensity, Rep, femto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picocandela = Unit<LuminousIntensity, Rep, pico>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanocandela = Unit<LuminousIntensity, Rep, nano>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microcandela = Unit<LuminousIntensity, Rep, micro>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millicandela = Unit<LuminousIntensity, Rep, milli>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centicandela = Unit<LuminousIntensity, Rep, centi>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decicandela = Unit<LuminousIntensity, Rep, deci>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using candela = Unit<LuminousIntensity, Rep, base>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decacandela = Unit<LuminousIntensity, Rep, deca>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectocandela = Unit<LuminousIntensity, Rep, hecto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilocandela = Unit<LuminousIntensity, Rep, kilo>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megacandela = Unit<LuminousIntensity, Rep, mega>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigacandela = Unit<LuminousIntensity, Rep, giga>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using teracandela = Unit<LuminousIntensity, Rep, tera>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petacandela = Unit<LuminousIntensity, Rep, peta>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exacandela = Unit<LuminousIntensity, Rep, exa>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettacandela = Unit<LuminousIntensity, Rep, zetta>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottacandela = Unit<LuminousIntensity, Rep, yotta>;




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



} // namespace default



} //namespace omni



} //namespace stb

#endif //LUMINOUS_INTENSITY_HH_
