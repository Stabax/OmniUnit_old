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

#include "../Unit.hh"
#include"constants_for_units.hh"

namespace stb
{



  typedef Dimension<0, 0, 0, 0, 0, 1, 0> Quantity;



  template <typename Rep>
  using yoctomol = Unit<Quantity, Rep, yocto>;

  template <typename Rep>
  using zeptomol = Unit<Quantity, Rep, zepto>;

  template <typename Rep>
  using attomol = Unit<Quantity, Rep, atto>;

  template <typename Rep>
  using femtomol = Unit<Quantity, Rep, femto>;

  template <typename Rep>
  using picomol = Unit<Quantity, Rep, pico>;

  template <typename Rep>
  using nanomol = Unit<Quantity, Rep, nano>;

  template <typename Rep>
  using micromol = Unit<Quantity, Rep, micro>;

  template <typename Rep>
  using millimol = Unit<Quantity, Rep, milli>;

  template <typename Rep>
  using centimol = Unit<Quantity, Rep, centi>;

  template <typename Rep>
  using decimol = Unit<Quantity, Rep, deci>;

  template <typename Rep>
  using mol = Unit<Quantity, Rep, base>;

  template <typename Rep>
  using decamol = Unit<Quantity, Rep, deca>;

  template <typename Rep>
  using hectomol = Unit<Quantity, Rep, hecto>;

  template <typename Rep>
  using kilomol = Unit<Quantity, Rep, kilo>;

  template <typename Rep>
  using megamol = Unit<Quantity, Rep, mega>;

  template <typename Rep>
  using gigamol = Unit<Quantity, Rep, giga>;

  template <typename Rep>
  using teramol = Unit<Quantity, Rep, tera>;

  template <typename Rep>
  using petamol = Unit<Quantity, Rep, peta>;

  template <typename Rep>
  using examol = Unit<Quantity, Rep, exa>;

  template <typename Rep>
  using zettamol = Unit<Quantity, Rep, zetta>;

  template <typename Rep>
  using yottamol = Unit<Quantity, Rep, yotta>;



}

#endif //QUANTITY_HH_
