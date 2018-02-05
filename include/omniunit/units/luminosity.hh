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



} //namespace omni



} //namespace stb

#endif //LUMINOSITY_HH_
