//Ratio.hh

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

#ifndef Ratio_HH_
#define Ratio_HH_

#include <limits>
#include <cmath>
#include <Ratio>
#include "utilities.hh"

namespace stb
{
//=============================================================================
//=============================================================================
// Ratio DEFINITION ===========================================================
//=============================================================================
//=============================================================================



template<double const& _Num, double const& _Den>
struct Ratio
{
  static_assert(_Den > 0 || _Den < 0, "denominator cannot be zero.");
  static_assert(is_positive_integer(_Num), "numerator may not have decimals and may be positive");
  static_assert(is_positive_integer(_Den), "denominator may not have decimals and may be positive");

  static constexpr double num = _Num / gcd(_Num, _Den);
  static constexpr double den = _Den / gcd(_Num, _Den);
  static constexpr double value = num / den;
  typedef Ratio<num, den> type;
};


template<typename falseType>
struct is_stb_Ratio : std::false_type
{
};


template<double const& Num, double const& Den>
struct is_stb_Ratio<Ratio<Num, Den>> : public std::true_type
{
};



//=============================================================================
//=============================================================================
// Ratio ARITHMETIC ===========================================================
//=============================================================================
//=============================================================================



template <typename Ratio1, typename Ratio2>
class Ratio_multiply
{
  static constexpr double _gcd = gcd(Ratio1::num * Ratio2::num, Ratio1::den * Ratio2::den);
  static constexpr double num = (Ratio1::num * Ratio2::num) / _gcd;
  static constexpr double den = (Ratio1::den * Ratio2::den) / _gcd;
public:
  typedef Ratio<num, den> type;
};


template <typename Ratio1, typename Ratio2>
class Ratio_divide
{
  static_assert(Ratio2::num > 0 || Ratio2::num < 0, "denominator cannot be zero.");

  static constexpr double _gcd = gcd(Ratio1::num * Ratio2::den, Ratio1::den * Ratio2::num);
  static constexpr double num = (Ratio1::num * Ratio2::den) / _gcd;
  static constexpr double den = (Ratio1::den * Ratio2::num) /_gcd;
public:
  typedef Ratio<num, den> type;
};



//=============================================================================
//=============================================================================
// Ratio CONVERTER STD/STB ====================================================
//=============================================================================
//=============================================================================



template<typename falseType>
struct is_std_Ratio : std::false_type
{
};


template<intmax_t Num, intmax_t Den>
struct is_std_Ratio<std::ratio<Num, Den>> : public std::true_type
{
};


template<typename _stdRatio>
struct Ratio_std_to_stb
{
  static_assert(is_std_Ratio<_stdRatio>::value, "Need std::ratio in Ratio_converter_std_stb.");

  static constexpr double num = static_cast<double>(_stdRatio::num);
  static constexpr double den = static_cast<double>(_stdRatio::den);

  typedef Ratio<num, den> type;
};


template<typename _stbRatio>
struct Ratio_stb_to_std
{
  static_assert(is_stb_Ratio<_stbRatio>::value, "Need stb::Ratio in Ratio_converter_stb_std.");
  static_assert(_stbRatio::num < std::numeric_limits<intmax_t>::max(), "Too high numerator.");
  static_assert(_stbRatio::den < std::numeric_limits<intmax_t>::max(), "Too high denominator.");

  typedef std::ratio<static_cast<intmax_t>(_stbRatio::num), static_cast<intmax_t>(_stbRatio::den)> type;
};



//=============================================================================
//=============================================================================
// POWER OF TEN STATIC CONSTEXPR DEFINITION ===================================
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
static constexpr double E41 = 100000000000000000000000000000000000000000.;
static constexpr double E42 = 1000000000000000000000000000000000000000000.;
static constexpr double E43 = 10000000000000000000000000000000000000000000.;
static constexpr double E44 = 100000000000000000000000000000000000000000000.;
static constexpr double E45 = 1000000000000000000000000000000000000000000000.;
static constexpr double E46 = 10000000000000000000000000000000000000000000000.;
static constexpr double E47 = 100000000000000000000000000000000000000000000000.;
static constexpr double E48 = 1000000000000000000000000000000000000000000000000.;
static constexpr double E49 = 10000000000000000000000000000000000000000000000000.;
static constexpr double E50 = 100000000000000000000000000000000000000000000000000.;
static constexpr double E51 = 1000000000000000000000000000000000000000000000000000.;
static constexpr double E52 = 10000000000000000000000000000000000000000000000000000.;
static constexpr double E53 = 100000000000000000000000000000000000000000000000000000.;
static constexpr double E54 = 1000000000000000000000000000000000000000000000000000000.;
static constexpr double E55 = 10000000000000000000000000000000000000000000000000000000.;
static constexpr double E56 = 100000000000000000000000000000000000000000000000000000000.;
static constexpr double E57 = 1000000000000000000000000000000000000000000000000000000000.;
static constexpr double E58 = 10000000000000000000000000000000000000000000000000000000000.;
static constexpr double E59 = 100000000000000000000000000000000000000000000000000000000000.;
static constexpr double E60 = 1000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E61 = 10000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E62 = 100000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E63 = 1000000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E64 = 10000000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E65 = 100000000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E66 = 1000000000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E67 = 10000000000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E68 = 100000000000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E69 = 1000000000000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E70 = 10000000000000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E71 = 100000000000000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E72 = 1000000000000000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E73 = 10000000000000000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E74 = 100000000000000000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E75 = 1000000000000000000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E76 = 10000000000000000000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E77 = 100000000000000000000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E78 = 1000000000000000000000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E79 = 10000000000000000000000000000000000000000000000000000000000000000000000000000000.;
static constexpr double E80 = 100000000000000000000000000000000000000000000000000000000000000000000000000000000.;



//=============================================================================
//=============================================================================
// Ratio TYPEDEF ==============================================================
//=============================================================================
//=============================================================================



typedef Ratio<E0, E24> yocto;
typedef Ratio<E0, E21> zepto;
typedef Ratio<E0, E18> atto;
typedef Ratio<E0, E15> femto;
typedef Ratio<E0, E12> pico;
typedef Ratio<E0, E9> nano;
typedef Ratio<E0, E6> micro;
typedef Ratio<E0, E3> milli;
typedef Ratio<E0, E2> centi;
typedef Ratio<E0, E1> deci;
typedef Ratio<E0, E0> base;
typedef Ratio<E1, E0> deca;
typedef Ratio<E2, E0> hecto;
typedef Ratio<E3, E0> kilo;
typedef Ratio<E6, E0> mega;
typedef Ratio<E9, E0> giga;
typedef Ratio<E12, E0> tera;
typedef Ratio<E15, E0> peta;
typedef Ratio<E18, E0> exa;
typedef Ratio<E21, E0> zetta;
typedef Ratio<E24, E0> yotta;

}

#endif //Ratio_HH_
