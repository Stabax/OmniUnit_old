//ratio.hh

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

#ifndef RATIO_HH_
#define RATIO_HH_

#include <limits>
#include <cmath>

namespace stb
{



//=============================================================================
//=============================================================================
// MODULO =====================================================================
//=============================================================================
//=============================================================================



inline constexpr double gcd(double a, double b)
{
  double r = 0;

  while (b > 0) {
    r = std::remainder(a, b);
    a = b;
    b = r;
  }
  return a;
}



//=============================================================================
//=============================================================================
// RATIO DEFINITION ===========================================================
//=============================================================================
//=============================================================================



template<double const& _Num, double const& _Den = 1>
class ratio
{
  static constexpr double one = 1;
public:
  static_assert(_Den > 0 || _Den < 0, "denominator cannot be zero.");

  static constexpr double num = _Num / gcd(_Num, _Den);
  static constexpr double den = _Den / gcd(_Num, _Den);
  static constexpr double value = num / den;
  typedef ratio<num, den> type;
};



//=============================================================================
//=============================================================================
// RATIO ARITHMETIC ===========================================================
//=============================================================================
//=============================================================================



template <typename ratio1, typename ratio2>
class ratio_multiply
{
  static constexpr double gcd = gcd(ratio1::num * ratio2::num, ratio1::den * ratio2::den);
  static constexpr double num = (ratio1::num * ratio2::num) / gcd;
  static constexpr double den = (ratio1::den * ratio2::den) / gcd;
public:
  typedef ratio<num, den> type;
};


template <typename ratio1, typename ratio2>
class ratio_divide
{
  static_assert(ratio2::num > 0 || ratio2::num < 0, "denominator cannot be zero.");
  static constexpr double gcd = gcd(ratio1::num * ratio2::den, ratio1::den * ratio2::num);
  static constexpr double num = (ratio1::num * ratio2::den) / gcd;
  static constexpr double den = (ratio1::den * ratio2::num) /gcd;
public:
  typedef ratio<num, den> type;
};



//=============================================================================
//=============================================================================
// STATIC CONSTEXPR DOUBLE ====================================================
//=============================================================================
//=============================================================================



static constexpr double E0  = 1.;
static constexpr double E1  = 10.;
static constexpr double E2  = 100.;
static constexpr double E3  = 1000.;
static constexpr double E4  = 10000.;
static constexpr double E5  = 100000.;
static constexpr double E6  = 1000000.;
static constexpr double E7  = 10000000.;
static constexpr double E8  = 100000000.;
static constexpr double E9  = 1000000000.;
static constexpr double E10 = 10000000000.;
static constexpr double E11 = 100000000000.;
static constexpr double E12 = 1000000000000.;
static constexpr double E13 = 10000000000000.;
static constexpr double E14 = 100000000000000.;
static constexpr double E15 = 1000000000000000.;
static constexpr double E16 = 10000000000000000.;
static constexpr double E17 = 100000000000000000.;
static constexpr double E18 = 1000000000000000000.;
static constexpr double E19 = 10000000000000000000.;
static constexpr double E20 = 100000000000000000000.;
static constexpr double E21 = 1000000000000000000000.;
static constexpr double E22 = 10000000000000000000000.;
static constexpr double E23 = 100000000000000000000000.;
static constexpr double E24 = 1000000000000000000000000.;
static constexpr double E25 = 10000000000000000000000000.;
static constexpr double E26 = 100000000000000000000000000.;
static constexpr double E27 = 1000000000000000000000000000.;
static constexpr double E28 = 10000000000000000000000000000.;
static constexpr double E29 = 100000000000000000000000000000.;
static constexpr double E30 = 1000000000000000000000000000000.;
static constexpr double E31 = 10000000000000000000000000000000.;
static constexpr double E32 = 100000000000000000000000000000000.;
static constexpr double E33 = 1000000000000000000000000000000000.;
static constexpr double E34 = 10000000000000000000000000000000000.;
static constexpr double E35 = 100000000000000000000000000000000000.;
static constexpr double E36 = 1000000000000000000000000000000000000.;
static constexpr double E37 = 10000000000000000000000000000000000000.;
static constexpr double E38 = 100000000000000000000000000000000000000.;
static constexpr double E39 = 1000000000000000000000000000000000000000.;
static constexpr double E40 = 10000000000000000000000000000000000000000.;



//=============================================================================
//=============================================================================
// RATIO TYPEDEF ==============================================================
//=============================================================================
//=============================================================================



typedef ratio<E0, E24> yocto;
typedef ratio<E0, E21> zepto;
typedef ratio<E0, E18> atto;
typedef ratio<E0, E15> femto;
typedef ratio<E0, E12> pico;
typedef ratio<E0, E9> nano;
typedef ratio<E0, E6> micro;
typedef ratio<E0, E3> milli;
typedef ratio<E0, E2> centi;
typedef ratio<E0, E1> deci;
typedef ratio<E0, E0> basic_unit;
typedef ratio<E1, E0> deca;
typedef ratio<E2, E0> hecto;
typedef ratio<E3, E0> kilo;
typedef ratio<E6, E0> mega;
typedef ratio<E9, E0> giga;
typedef ratio<E12, E0> tera;
typedef ratio<E15, E0> peta;
typedef ratio<E18, E0> exa;
typedef ratio<E21, E0> zetta;
typedef ratio<E24, E0> yotta;



}

#endif //RATIO_HH_
