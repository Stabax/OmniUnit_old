//temperature.hh

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

#ifndef TEMPERATURE_HH_
#define TEMPERATURE_HH_

#include"constants_for_units.hh"

namespace stb
{



namespace omni
{



typedef Dimension<0, 0, 0, 0, 1, 0, 0> Temperature;



template <typename Rep>
using yoctokelvin = Unit<Temperature, Rep, yocto>;

template <typename Rep>
using zeptokelvin = Unit<Temperature, Rep, zepto>;

template <typename Rep>
using attokelvin = Unit<Temperature, Rep, atto>;

template <typename Rep>
using femtokelvin = Unit<Temperature, Rep, femto>;

template <typename Rep>
using picokelvin = Unit<Temperature, Rep, pico>;

template <typename Rep>
using nanokelvin = Unit<Temperature, Rep, nano>;

template <typename Rep>
using microkelvin = Unit<Temperature, Rep, micro>;

template <typename Rep>
using millikelvin = Unit<Temperature, Rep, milli>;

template <typename Rep>
using centikelvin = Unit<Temperature, Rep, centi>;

template <typename Rep>
using decikelvin = Unit<Temperature, Rep, deci>;

template <typename Rep>
using kelvin = Unit<Temperature, Rep, base>;

template <typename Rep>
using decakelvin = Unit<Temperature, Rep, deca>;

template <typename Rep>
using hectokelvin = Unit<Temperature, Rep, hecto>;

template <typename Rep>
using kilokelvin = Unit<Temperature, Rep, kilo>;

template <typename Rep>
using megakelvin = Unit<Temperature, Rep, mega>;

template <typename Rep>
using gigakelvin = Unit<Temperature, Rep, giga>;

template <typename Rep>
using terakelvin = Unit<Temperature, Rep, tera>;

template <typename Rep>
using petakelvin = Unit<Temperature, Rep, peta>;

template <typename Rep>
using exakelvin = Unit<Temperature, Rep, exa>;

template <typename Rep>
using zettakelvin = Unit<Temperature, Rep, zetta>;

template <typename Rep>
using yottakelvin = Unit<Temperature, Rep, yotta>;



} //namespace omni



} //namespace stb

#endif //TEMPERATURE_HH_
