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



typedef Dimension<0, 0, 0, 0, 1, 0, 0, 0, 0> Temperature;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctokelvin = Unit<Temperature, Rep, yocto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptokelvin = Unit<Temperature, Rep, zepto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attokelvin = Unit<Temperature, Rep, atto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtokelvin = Unit<Temperature, Rep, femto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picokelvin = Unit<Temperature, Rep, pico>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanokelvin = Unit<Temperature, Rep, nano>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microkelvin = Unit<Temperature, Rep, micro>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millikelvin = Unit<Temperature, Rep, milli>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centikelvin = Unit<Temperature, Rep, centi>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decikelvin = Unit<Temperature, Rep, deci>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kelvin = Unit<Temperature, Rep, base>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decakelvin = Unit<Temperature, Rep, deca>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectokelvin = Unit<Temperature, Rep, hecto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilokelvin = Unit<Temperature, Rep, kilo>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megakelvin = Unit<Temperature, Rep, mega>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigakelvin = Unit<Temperature, Rep, giga>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using terakelvin = Unit<Temperature, Rep, tera>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petakelvin = Unit<Temperature, Rep, peta>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exakelvin = Unit<Temperature, Rep, exa>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettakelvin = Unit<Temperature, Rep, zetta>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottakelvin = Unit<Temperature, Rep, yotta>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctocelsius = Unit<Temperature, Rep, yocto, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptocelsius = Unit<Temperature, Rep, zepto, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attocelsius = Unit<Temperature, Rep, atto, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtocelsius = Unit<Temperature, Rep, femto, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picocelsius = Unit<Temperature, Rep, pico, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanocelsius = Unit<Temperature, Rep, nano, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microcelsius = Unit<Temperature, Rep, micro, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millicelsius = Unit<Temperature, Rep, milli, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centicelsius = Unit<Temperature, Rep, centi, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decicelsius = Unit<Temperature, Rep, deci, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using celsius = Unit<Temperature, Rep, base, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decacelsius = Unit<Temperature, Rep, deca, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectocelsius = Unit<Temperature, Rep, hecto, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilocelsius = Unit<Temperature, Rep, kilo, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megacelsius = Unit<Temperature, Rep, mega, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigacelsius = Unit<Temperature, Rep, giga, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using teracelsius = Unit<Temperature, Rep, tera, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petacelsius = Unit<Temperature, Rep, peta, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exacelsius = Unit<Temperature, Rep, exa, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettacelsius = Unit<Temperature, Rep, zetta, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottacelsius = Unit<Temperature, Rep, yotta, celsiusConstant>;



namespace def
{



typedef zeptokelvin<> zeptokelvin;
typedef femtokelvin<>  femtokelvin;
typedef picokelvin<> picokelvin;
typedef nanokelvin<> nanokelvin;
typedef microkelvin<> microkelvin;
typedef millikelvin<> millikelvin;
typedef centikelvin<> centikelvin;
typedef decikelvin<> decikelvin;
typedef kelvin<> kelvin;
typedef decakelvin<> decakelvin;
typedef hectokelvin<> hectokelvin;
typedef kilokelvin<> kilokelvin;
typedef megakelvin<> megakelvin;
typedef gigakelvin<> gigakelvin;
typedef terakelvin<> terakelvin;
typedef petakelvin<> petakelvin;
typedef exakelvin<> exakelvin;
typedef zettakelvin<> zettakelvin;
typedef yottakelvin<> yottakelvin;



typedef zeptocelsius<> zeptocelsius;
typedef femtocelsius<>  femtocelsius;
typedef picocelsius<> picocelsius;
typedef nanocelsius<> nanocelsius;
typedef microcelsius<> microcelsius;
typedef millicelsius<> millicelsius;
typedef centicelsius<> centicelsius;
typedef decicelsius<> decicelsius;
typedef celsius<> celsius;
typedef decacelsius<> decacelsius;
typedef hectocelsius<> hectocelsius;
typedef kilocelsius<> kilocelsius;
typedef megacelsius<> megacelsius;
typedef gigacelsius<> gigacelsius;
typedef teracelsius<> teracelsius;
typedef petacelsius<> petacelsius;
typedef exacelsius<> exacelsius;
typedef zettacelsius<> zettacelsius;
typedef yottacelsius<> yottacelsius;



} // namespace default



} //namespace omni



} //namespace stb

#endif //TEMPERATURE_HH_
