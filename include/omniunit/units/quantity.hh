//quantity.hh

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

#ifndef QUANTITY_HH_
#define QUANTITY_HH_

#include"constants_for_units.hh"


namespace omniunit
{



typedef Dimension<0, 0, 0, 0, 0, 1, 0, 0, 0> Quantity;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctomol = Unit<Quantity, Rep, yocto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptomol = Unit<Quantity, Rep, zepto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attomol = Unit<Quantity, Rep, atto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtomol = Unit<Quantity, Rep, femto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picomol = Unit<Quantity, Rep, pico, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanomol = Unit<Quantity, Rep, nano, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using micromol = Unit<Quantity, Rep, micro, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millimol = Unit<Quantity, Rep, milli, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centimol = Unit<Quantity, Rep, centi, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decimol = Unit<Quantity, Rep, deci, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using mol = Unit<Quantity, Rep, base, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decamol = Unit<Quantity, Rep, deca, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectomol = Unit<Quantity, Rep, hecto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilomol = Unit<Quantity, Rep, kilo, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megamol = Unit<Quantity, Rep, mega, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigamol = Unit<Quantity, Rep, giga, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using teramol = Unit<Quantity, Rep, tera, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petamol = Unit<Quantity, Rep, peta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using examol = Unit<Quantity, Rep, exa, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettamol = Unit<Quantity, Rep, zetta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottamol = Unit<Quantity, Rep, yotta, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using amount = Unit<Quantity, Rep, unitaryQuantityDefinition, zero>;



namespace def
{



typedef zeptomol<> zeptomol;
typedef femtomol<>  femtomol;
typedef picomol<> picomol;
typedef nanomol<> nanomol;
typedef micromol<> micromol;
typedef millimol<> millimol;
typedef centimol<> centimol;
typedef decimol<> decimol;
typedef mol<> mol;
typedef decamol<> decamol;
typedef hectomol<> hectomol;
typedef kilomol<> kilomol;
typedef megamol<> megamol;
typedef gigamol<> gigamol;
typedef teramol<> teramol;
typedef petamol<> petamol;
typedef examol<> examol;
typedef zettamol<> zettamol;
typedef yottamol<> yottamol;

typedef amount<> amount;



} // namespace default



} //namespace omniunit


#endif //QUANTITY_HH_
