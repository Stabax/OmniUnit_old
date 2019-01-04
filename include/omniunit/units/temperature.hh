//temperature.hh

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

#ifndef TEMPERATURE_HH_
#define TEMPERATURE_HH_

#include"constants_for_units.hh"


namespace omni
{



typedef Dimension<0, 0, 0, 0, 1, 0, 0, 0, 0> Temperature;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctokelvin = Unit<Temperature, Rep, yocto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptokelvin = Unit<Temperature, Rep, zepto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attokelvin = Unit<Temperature, Rep, atto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtokelvin = Unit<Temperature, Rep, femto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picokelvin = Unit<Temperature, Rep, pico, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanokelvin = Unit<Temperature, Rep, nano, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microkelvin = Unit<Temperature, Rep, micro, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millikelvin = Unit<Temperature, Rep, milli, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centikelvin = Unit<Temperature, Rep, centi, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decikelvin = Unit<Temperature, Rep, deci, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kelvin = Unit<Temperature, Rep, base, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decakelvin = Unit<Temperature, Rep, deca, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectokelvin = Unit<Temperature, Rep, hecto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilokelvin = Unit<Temperature, Rep, kilo, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megakelvin = Unit<Temperature, Rep, mega, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigakelvin = Unit<Temperature, Rep, giga, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using terakelvin = Unit<Temperature, Rep, tera, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petakelvin = Unit<Temperature, Rep, peta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exakelvin = Unit<Temperature, Rep, exa, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettakelvin = Unit<Temperature, Rep, zetta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottakelvin = Unit<Temperature, Rep, yotta, zero>;



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



typedef zeptokelvin<> Zeptokelvin;
typedef femtokelvin<>  Femtokelvin;
typedef picokelvin<> Picokelvin;
typedef nanokelvin<> Nanokelvin;
typedef microkelvin<> Microkelvin;
typedef millikelvin<> Millikelvin;
typedef centikelvin<> Centikelvin;
typedef decikelvin<> Decikelvin;
typedef kelvin<> Kelvin;
typedef decakelvin<> Decakelvin;
typedef hectokelvin<> Hectokelvin;
typedef kilokelvin<> Kilokelvin;
typedef megakelvin<> Megakelvin;
typedef gigakelvin<> Gigakelvin;
typedef terakelvin<> Terakelvin;
typedef petakelvin<> Petakelvin;
typedef exakelvin<> Exakelvin;
typedef zettakelvin<> Zettakelvin;
typedef yottakelvin<> Yottakelvin;



typedef zeptocelsius<> Zeptocelsius;
typedef femtocelsius<>  Femtocelsius;
typedef picocelsius<> Picocelsius;
typedef nanocelsius<> Nanocelsius;
typedef microcelsius<> Microcelsius;
typedef millicelsius<> Millicelsius;
typedef centicelsius<> Centicelsius;
typedef decicelsius<> Decicelsius;
typedef celsius<> Celsius;
typedef decacelsius<> Decacelsius;
typedef hectocelsius<> Hectocelsius;
typedef kilocelsius<> Kilocelsius;
typedef megacelsius<> Megacelsius;
typedef gigacelsius<> Gigacelsius;
typedef teracelsius<> Teracelsius;
typedef petacelsius<> Petacelsius;
typedef exacelsius<> Exacelsius;
typedef zettacelsius<> Zettacelsius;
typedef yottacelsius<> Yottacelsius;




} //namespace omni


#endif //TEMPERATURE_HH_
