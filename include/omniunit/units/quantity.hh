//quantity.hh

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

#ifndef QUANTITY_HH_
#define QUANTITY_HH_

#include"constants_for_units.hh"

namespace stb
{



namespace omni
{



typedef Dimension<0, 0, 0, 0, 0, 1, 0> Quantity;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctomol = Unit<Quantity, Rep, yocto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptomol = Unit<Quantity, Rep, zepto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attomol = Unit<Quantity, Rep, atto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtomol = Unit<Quantity, Rep, femto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picomol = Unit<Quantity, Rep, pico>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanomol = Unit<Quantity, Rep, nano>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using micromol = Unit<Quantity, Rep, micro>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millimol = Unit<Quantity, Rep, milli>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centimol = Unit<Quantity, Rep, centi>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decimol = Unit<Quantity, Rep, deci>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using mol = Unit<Quantity, Rep, base>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decamol = Unit<Quantity, Rep, deca>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectomol = Unit<Quantity, Rep, hecto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilomol = Unit<Quantity, Rep, kilo>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megamol = Unit<Quantity, Rep, mega>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigamol = Unit<Quantity, Rep, giga>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using teramol = Unit<Quantity, Rep, tera>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petamol = Unit<Quantity, Rep, peta>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using examol = Unit<Quantity, Rep, exa>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettamol = Unit<Quantity, Rep, zetta>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottamol = Unit<Quantity, Rep, yotta>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using rawQuantity = Unit<Quantity, Rep, rawQuantityDefinition>;



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

typedef rawQuantity<> rawQuantity;



} // namespace default



} //namespace omni



} //namespace stb

#endif //QUANTITY_HH_
