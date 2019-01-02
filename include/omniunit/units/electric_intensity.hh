//intensity.hh

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

#ifndef INTENSITY_HH_
#define INTENSITY_HH_

#include "constants_for_units.hh"


namespace omni
{



typedef Dimension<0, 0, 0, 1, 0, 0, 0, 0, 0> ElectricIntensity;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctoampere = Unit<ElectricIntensity, Rep, yocto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptoampere = Unit<ElectricIntensity, Rep, zepto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attoampere = Unit<ElectricIntensity, Rep, atto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtoampere = Unit<ElectricIntensity, Rep, femto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picoampere = Unit<ElectricIntensity, Rep, pico, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanoampere = Unit<ElectricIntensity, Rep, nano, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microampere = Unit<ElectricIntensity, Rep, micro, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using milliampere = Unit<ElectricIntensity, Rep, milli, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centiampere = Unit<ElectricIntensity, Rep, centi, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using deciampere = Unit<ElectricIntensity, Rep, deci, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using ampere = Unit<ElectricIntensity, Rep, base, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decaampere = Unit<ElectricIntensity, Rep, deca, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectoampere = Unit<ElectricIntensity, Rep, hecto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kiloampere = Unit<ElectricIntensity, Rep, kilo, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megaampere = Unit<ElectricIntensity, Rep, mega, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigaampere = Unit<ElectricIntensity, Rep, giga, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using teraampere = Unit<ElectricIntensity, Rep, tera, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petaampere = Unit<ElectricIntensity, Rep, peta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exaampere = Unit<ElectricIntensity, Rep, exa, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettaampere = Unit<ElectricIntensity, Rep, zetta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottaampere = Unit<ElectricIntensity, Rep, yotta, zero>;



namespace def
{



typedef zeptoampere<> zeptoampere;
typedef femtoampere<>  femtoampere;
typedef picoampere<> picoampere;
typedef nanoampere<> nanoampere;
typedef microampere<> microampere;
typedef milliampere<> milliampere;
typedef centiampere<> centiampere;
typedef deciampere<> deciampere;
typedef ampere<> ampere;
typedef decaampere<> decaampere;
typedef hectoampere<> hectoampere;
typedef kiloampere<> kiloampere;
typedef megaampere<> megaampere;
typedef gigaampere<> gigaampere;
typedef teraampere<> teraampere;
typedef petaampere<> petaampere;
typedef exaampere<> exaampere;
typedef zettaampere<> zettaampere;
typedef yottaampere<> yottaampere;



} // namespace default



} //namespace omni


#endif //INTENSITY_HH_
