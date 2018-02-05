//intensity.hh

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

#ifndef INTENSITY_HH_
#define INTENSITY_HH_

#include"constants_for_units.hh"

namespace stb
{



namespace omni
{



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



} //namespace omni



} //namespace stb

#endif //INTENSITY_HH_
