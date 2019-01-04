//utility.hh

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



#ifndef OMNIUNIT_UTILITY_HH_
#define OMNIUNIT_UTILITY_HH_


#include <cmath>
#include <limits>
#include <ratio>
#include <string>



namespace omni
{



//=============================================================================
//=============================================================================
//=============================================================================
//=== UTILITY FUNCTIONS =======================================================
//=============================================================================
//=============================================================================
//=============================================================================



//modulo at compile time (if parameters are constexpr) which can handle floating points.
template <typename T, typename U>
constexpr typename std::common_type<T, U>::type
modulo(T const& a, U const& b)
{
  static_assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value, "Arguments should be arithmetic values.");
  typedef typename std::common_type<T, U>::type common;
  common a2 = static_cast<common>(a);
  common b2 = static_cast<common>(b);
  return a2 - (static_cast<common>(std::floor(a2/b2)) * b2);
}


//there is a standard gcd in c++17, but it handles only integers.
template <typename T, typename U>
constexpr typename std::common_type<T, U>::type
gcd(T const& a, U const& b)
{
  static_assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value, "Arguments should be arithmetic values.");

  typedef typename std::common_type<T, U>::type common;
  common a2 = static_cast<common>(a);
  common b2 = static_cast<common>(b);

  double temp = 0;
  while (std::abs(b2) > std::numeric_limits<common>::epsilon())
  {
    temp = modulo(a2, b2);
    a2 = b2;
    b2 = temp;
  }
  return a2;
}


//test if a double has no decimals and is positive
template <typename T>
constexpr bool is_positive_integer(T const& number)
{
  static_assert(std::is_arithmetic<T>::value, "Arguments should be arithmetic values.");
  T res = number - static_cast<T>(std::floor(number));
  return (std::abs(res) <= std::numeric_limits<T>::epsilon() && number >= 0) ? true : false;
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== STATIC CONSTEXPR POWER OF TEN DEFINITION ================================
//=============================================================================
//=============================================================================
//=============================================================================



constexpr double zero = 0.;

constexpr double E0  = 1.;
constexpr double E1  = 10.;
constexpr double E2  = 100.;
constexpr double E3  = 1000.;
constexpr double E4  = 10000.;
constexpr double E5  = 100000.;
constexpr double E6  = 1000000.;
constexpr double E7  = 10000000.;
constexpr double E8  = 100000000.;
constexpr double E9  = 1000000000.;
constexpr double E10 = 10000000000.;
constexpr double E11 = 100000000000.;
constexpr double E12 = 1000000000000.;
constexpr double E13 = 10000000000000.;
constexpr double E14 = 100000000000000.;
constexpr double E15 = 1000000000000000.;
constexpr double E16 = 10000000000000000.;
constexpr double E17 = 100000000000000000.;
constexpr double E18 = 1000000000000000000.;
constexpr double E19 = 10000000000000000000.;
constexpr double E20 = 100000000000000000000.;
constexpr double E21 = 1000000000000000000000.;
constexpr double E22 = 10000000000000000000000.;
constexpr double E23 = 100000000000000000000000.;
constexpr double E24 = 1000000000000000000000000.;
constexpr double E25 = 10000000000000000000000000.;
constexpr double E26 = 100000000000000000000000000.;
constexpr double E27 = 1000000000000000000000000000.;
constexpr double E28 = 10000000000000000000000000000.;
constexpr double E29 = 100000000000000000000000000000.;
constexpr double E30 = 1000000000000000000000000000000.;
constexpr double E31 = 10000000000000000000000000000000.;
constexpr double E32 = 100000000000000000000000000000000.;
constexpr double E33 = 1000000000000000000000000000000000.;
constexpr double E34 = 10000000000000000000000000000000000.;
constexpr double E35 = 100000000000000000000000000000000000.;
constexpr double E36 = 1000000000000000000000000000000000000.;
constexpr double E37 = 10000000000000000000000000000000000000.;
constexpr double E38 = 100000000000000000000000000000000000000.;
constexpr double E39 = 1000000000000000000000000000000000000000.;
constexpr double E40 = 10000000000000000000000000000000000000000.;
constexpr double E41 = 100000000000000000000000000000000000000000.;
constexpr double E42 = 1000000000000000000000000000000000000000000.;
constexpr double E43 = 10000000000000000000000000000000000000000000.;
constexpr double E44 = 100000000000000000000000000000000000000000000.;
constexpr double E45 = 1000000000000000000000000000000000000000000000.;
constexpr double E46 = 10000000000000000000000000000000000000000000000.;
constexpr double E47 = 100000000000000000000000000000000000000000000000.;
constexpr double E48 = 1000000000000000000000000000000000000000000000000.;
constexpr double E49 = 10000000000000000000000000000000000000000000000000.;
constexpr double E50 = 100000000000000000000000000000000000000000000000000.;
constexpr double E51 = 1000000000000000000000000000000000000000000000000000.;
constexpr double E52 = 10000000000000000000000000000000000000000000000000000.;
constexpr double E53 = 100000000000000000000000000000000000000000000000000000.;
constexpr double E54 = 1000000000000000000000000000000000000000000000000000000.;
constexpr double E55 = 10000000000000000000000000000000000000000000000000000000.;
constexpr double E56 = 100000000000000000000000000000000000000000000000000000000.;
constexpr double E57 = 1000000000000000000000000000000000000000000000000000000000.;
constexpr double E58 = 10000000000000000000000000000000000000000000000000000000000.;
constexpr double E59 = 100000000000000000000000000000000000000000000000000000000000.;
constexpr double E60 = 1000000000000000000000000000000000000000000000000000000000000.;
constexpr double E61 = 10000000000000000000000000000000000000000000000000000000000000.;
constexpr double E62 = 100000000000000000000000000000000000000000000000000000000000000.;
constexpr double E63 = 1000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E64 = 10000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E65 = 100000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E66 = 1000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E67 = 10000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E68 = 100000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E69 = 1000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E70 = 10000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E71 = 100000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E72 = 1000000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E73 = 10000000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E74 = 100000000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E75 = 1000000000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E76 = 10000000000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E77 = 100000000000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E78 = 1000000000000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E79 = 10000000000000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E80 = 100000000000000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E81 = 1000000000000000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E82 = 10000000000000000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E83 = 100000000000000000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E84 = 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E85 = 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E86 = 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E87 = 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E88 = 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E89 = 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.;
constexpr double E90 = 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.;



//=============================================================================
//=============================================================================
//=============================================================================
//=== RATIO DEFINITION ========================================================
//=============================================================================
//=============================================================================
//=============================================================================



template<double const& _Num, double const& _Den>
struct Ratio
{
  static_assert(std::abs(_Den) > std::numeric_limits<double>::epsilon(), "Denominator cannot be zero.");
  static_assert(is_positive_integer(_Num), "Numerator may not have decimals and may be positive.");
  static_assert(is_positive_integer(_Den), "Denominator may not have decimals and may be positive.");

  static constexpr double num = _Num / gcd(_Num, _Den);
  static constexpr double den = _Den / gcd(_Num, _Den);
  static constexpr double value = num / den;
  typedef Ratio<num, den> type;
};


//definition of Basic_Unit::origin, so it can be ODR-usable (required for any call of the variable)
//In c++17, we can set the variable inline inside the Ratio class, which permit avoiding the
//following declaration :
template<double const& _Num, double const& _Den>
constexpr double Ratio<_Num, _Den>::value;


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
//=============================================================================
//=== RATIO ARITHMETIC ========================================================
//=============================================================================
//=============================================================================
//=============================================================================



template <typename ratio>
struct Ratio_invert
{
  static_assert(std::abs(ratio::num) > std::numeric_limits<double>::epsilon(), "Denominator cannot be zero.");
  static_assert(is_stb_Ratio<ratio>::value , "Template parameter should be an OmniUnit ratio.");

  typedef Ratio<ratio::den, ratio::num> type;
};


template <typename ratio1, typename ratio2>
class Ratio_times_Ratio
{
  static_assert(is_stb_Ratio<ratio1>::value && is_stb_Ratio<ratio2>::value, "Template parameters should be OmniUnit ratios.");

  static constexpr double _gcd = gcd(ratio1::num * ratio2::num, ratio1::den * ratio2::den);
  static constexpr double num = (ratio1::num * ratio2::num) / _gcd;
  static constexpr double den = (ratio1::den * ratio2::den) / _gcd;
public:
  typedef Ratio<num, den> type;
};


template <typename ratio, double const& val>
class Ratio_times_value
{
  static_assert(is_stb_Ratio<ratio>::value, "First template parameter should be an OmniUnit ratio.");
  static_assert(is_positive_integer(val), "Second template parameter may not have decimals and may be positive.");

  static constexpr double _gcd = gcd(ratio::num * val, ratio::den);
  static constexpr double num = (ratio::num * val) / _gcd;
  static constexpr double den = ratio::den / _gcd;
public:
  typedef Ratio<num, den> type;
};


template <double const& val, typename ratio>
struct value_times_Ratio
{
  static_assert(is_stb_Ratio<ratio>::value, "Second template parameter should be an OmniUnit ratio.");
  static_assert(is_positive_integer(val), "First template parameter may not have decimals and may be positive.");

  typedef typename Ratio_times_value<ratio, val>::type type;
};


template <typename ratio1, typename ratio2>
class Ratio_over_Ratio
{
  static_assert(std::abs(ratio2::num) > std::numeric_limits<double>::epsilon(), "Denominator cannot be zero.");
  static_assert(is_stb_Ratio<ratio1>::value && is_stb_Ratio<ratio2>::value, "Template parameters should be OmniUnit ratios.");

  static constexpr double _gcd = gcd(ratio1::num * ratio2::den, ratio1::den * ratio2::num);
  static constexpr double num = (ratio1::num * ratio2::den) / _gcd;
  static constexpr double den = (ratio1::den * ratio2::num) /_gcd;
public:
  typedef Ratio<num, den> type;
};


template <typename ratio, double const& val>
class Ratio_over_value
{
  static_assert(std::abs(val) > std::numeric_limits<double>::epsilon(), "Denominator cannot be zero.");
  static_assert(is_stb_Ratio<ratio>::value, "First template parameter should be an OmniUnit ratio.");
  static_assert(is_positive_integer(val), "Second template parameter may not have decimals and may be positive.");


  static constexpr double _gcd = gcd(ratio::num, ratio::den * val);
  static constexpr double num = ratio::num / _gcd;
  static constexpr double den = (ratio::den * val) /_gcd;
public:
  typedef Ratio<num, den> type;
};


template <double const& val, typename ratio>
class value_over_Ratio
{
  static_assert(std::abs(ratio::num) > std::numeric_limits<double>::epsilon(), "Denominator cannot be zero.");
  static_assert(is_stb_Ratio<ratio>::value, "Second template parameter should be an OmniUnit ratio.");
  static_assert(is_positive_integer(val), "First template parameter may not have decimals and may be positive.");


  static constexpr double _gcd = gcd(val * ratio::den, ratio::num);
  static constexpr double num = (val * ratio::den) / _gcd;
  static constexpr double den = (ratio::den * val) /_gcd;
public:
  typedef Ratio<num, den> type;
};


template <typename ratio, int exponent>
class Ratio_power
{
  static_assert(is_stb_Ratio<ratio>::value, "First template parameter should be an OmniUnit ratio.");

  static constexpr double _gcd = gcd(std::pow(ratio::num, exponent), std::pow(ratio::den, exponent));
  static constexpr double num = std::pow(ratio::num, exponent) / _gcd;
  static constexpr double den = std::pow(ratio::den, exponent) /_gcd;
public:
  typedef Ratio<num, den> type;
};


template <typename ratio, int basis>
class Ratio_root
{
  static_assert(is_stb_Ratio<ratio>::value, "First template parameter should be an OmniUnit ratio.");
  static_assert(basis != 0, "Basis must not be 0.");

  static constexpr double _gcd = gcd(std::pow(ratio::num, 1.0/basis), std::pow(ratio::den, 1.0/basis));
  static constexpr double num = std::pow(ratio::num, 1.0/basis) / _gcd;
  static constexpr double den = std::pow(ratio::den, 1.0/basis) /_gcd;
public:
  typedef Ratio<num, den> type;
};


//=============================================================================
//=============================================================================
//=============================================================================
//=== RATIO CONVERTER STD/OMNI =================================================
//=============================================================================
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
struct Ratio_std_to_omni
{
  static_assert(is_std_Ratio<_stdRatio>::value, "Template parameter should be a standard ratio.");

  static constexpr double num = static_cast<double>(_stdRatio::num);
  static constexpr double den = static_cast<double>(_stdRatio::den);

  typedef Ratio<num, den> type;
};


template<typename _stbRatio>
struct Ratio_omni_to_std
{
  static_assert(is_stb_Ratio<_stbRatio>::value, "Template parameter should be an OmniUnit ratio.");
  static_assert(_stbRatio::num < std::numeric_limits<intmax_t>::max(), "Too high numerator.");
  static_assert(_stbRatio::den < std::numeric_limits<intmax_t>::max(), "Too high denominator.");

  typedef std::ratio<static_cast<intmax_t>(_stbRatio::num), static_cast<intmax_t>(_stbRatio::den)> type;
};



//=============================================================================
//=============================================================================
//=============================================================================
//=== RATIO TYPEDEF ===========================================================
//=============================================================================
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



//=============================================================================
//=============================================================================
//=============================================================================
//=== DIMENSION DEFINITION ====================================================
//=============================================================================
//=============================================================================
//=============================================================================



template<int _length, int _mass, int _time, int _current,
int _temperature, int _quantity, int _luminosity, int _angle, int _solid_angle>
struct Dimension
{
  static constexpr int length = _length;
  static constexpr int mass = _mass;
  static constexpr int time = _time;
  static constexpr int current = _current;
  static constexpr int temperature = _temperature;
  static constexpr int quantity = _quantity;
  static constexpr int luminosity = _luminosity;
  static constexpr int angle = _angle;
  static constexpr int solid_angle = _solid_angle;
};


template<typename falseType>
struct is_Dimension : std::false_type
{
};


template<int length, int mass, int time, int current,
int temperature, int quantity, int luminosity, int angle, int solid_angle>
struct is_Dimension<Dimension<length, mass, time, current,
temperature, quantity, luminosity, angle, solid_angle>> : public std::true_type
{
};


//test if a dimension is a real dimension or not (scalar/angla,solid angle)
template<typename Dim>
struct is_noDim
{
  static_assert(is_Dimension<Dim>::value, "Template argument must be a Dimension.");

  static constexpr bool value = (
  Dim::length == 0 &&
  Dim::mass == 0 &&
  Dim::time == 0 &&
  Dim::current == 0 &&
  Dim::temperature == 0 &&
  Dim::quantity == 0 &&
  Dim::luminosity == 0)
  ? true : false;
};


template <typename dim1, typename dim2>
struct Dimension_multiply
{
  static_assert(is_Dimension<dim1>::value && is_Dimension<dim2>::value,
  "Template parameters should be dimensions.");

  typedef Dimension<
  dim1::length + dim2::length,
  dim1::mass + dim2::mass,
  dim1::time + dim2::time,
  dim1::current + dim2::current,
  dim1::temperature + dim2::temperature,
  dim1::quantity + dim2::quantity,
  dim1::luminosity + dim2::luminosity,
  dim1::angle + dim2::angle,
  dim1::solid_angle + dim2::solid_angle
  > type;
};


template <typename dim1, typename dim2>
struct Dimension_divide
{
  static_assert(is_Dimension<dim1>::value && is_Dimension<dim2>::value,
  "Template parameters should be dimensions.");

  typedef Dimension<
  dim1::length - dim2::length,
  dim1::mass - dim2::mass,
  dim1::time - dim2::time,
  dim1::current - dim2::current,
  dim1::temperature - dim2::temperature,
  dim1::quantity - dim2::quantity,
  dim1::luminosity - dim2::luminosity,
  dim1::angle - dim2::angle,
  dim1::solid_angle - dim2::solid_angle
  > type;
};


template <typename dim, int exponent>
struct Dimension_power
{
  static_assert(is_Dimension<dim>::value, "Template parameter should be dimension.");

  typedef Dimension<
  dim::length * exponent,
  dim::mass * exponent,
  dim::time * exponent,
  dim::current * exponent,
  dim::temperature * exponent,
  dim::quantity * exponent,
  dim::luminosity * exponent,
  dim::angle * exponent,
  dim::solid_angle * exponent
  > type;
};


template <typename dim, int basis>
struct Dimension_root
{
  static_assert(is_Dimension<dim>::value, "Template parameter should be dimension.");
  static_assert(basis != 0, "Basis must not be 0.");

  static_assert(
  modulo(static_cast<double>(dim::length) / static_cast<double>(basis), 1) <= std::numeric_limits<double>::epsilon() &&
  modulo(static_cast<double>(dim::mass) / static_cast<double>(basis), 1) <= std::numeric_limits<double>::epsilon() &&
  modulo(static_cast<double>(dim::time) / static_cast<double>(basis), 1) <= std::numeric_limits<double>::epsilon() &&
  modulo(static_cast<double>(dim::current) / static_cast<double>(basis), 1) <= std::numeric_limits<double>::epsilon() &&
  modulo(static_cast<double>(dim::temperature) / static_cast<double>(basis), 1) <= std::numeric_limits<double>::epsilon() &&
  modulo(static_cast<double>(dim::quantity) / static_cast<double>(basis), 1) <= std::numeric_limits<double>::epsilon() &&
  modulo(static_cast<double>(dim::luminosity) / static_cast<double>(basis), 1) <= std::numeric_limits<double>::epsilon() &&
  modulo(static_cast<double>(dim::angle) / static_cast<double>(basis), 1) <= std::numeric_limits<double>::epsilon() &&
  modulo(static_cast<double>(dim::solid_angle) / static_cast<double>(basis), 1) <= std::numeric_limits<double>::epsilon(),
  "Cannot root this dimension with this basis.");

  typedef Dimension<
  dim::length / basis,
  dim::mass / basis,
  dim::time / basis,
  dim::current / basis,
  dim::temperature / basis,
  dim::quantity / basis,
  dim::luminosity / basis,
  dim::angle / basis,
  dim::solid_angle / basis
  > type;
};


//it is useless to make this function part of the class Dimension (static constexpr)
//because std::string is not a litteral : the function cannot be interpreted at
//compile time, so class Dimension could neither (i guess...).
template<typename dimension>
constexpr std::string dimension_str()
{
  static_assert(is_Dimension<dimension>::value, "Template parameter should be dimension.");

  std::string dim = "";

  if(dimension::length != 0)
    dim += ("[L" + std::to_string(dimension::length) + "]");
  if(dimension::mass != 0)
    dim += ("[M" + std::to_string(dimension::mass) + "]");
  if(dimension::time != 0)
    dim += ("[Tm" + std::to_string(dimension::time) + "]");
  if(dimension::current != 0)
    dim += ("[I" + std::to_string(dimension::current) + "]");
  if(dimension::temperature != 0)
    dim += ("[Tp" + std::to_string(dimension::temperature) + "]");
  if(dimension::quantity != 0)
    dim += ("[N" + std::to_string(dimension::quantity) + "]");
  if(dimension::luminosity != 0)
    dim += ("[J" + std::to_string(dimension::luminosity) + "]");
  if(dimension::angle != 0)
    dim += ("[a" + std::to_string(dimension::angle) + "]");
  if(dimension::solid_angle != 0)
    dim += ("[sa" + std::to_string(dimension::solid_angle) + "]");
  if(dim.length() == 0)
    dim = "[/]";

  return dim;
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== ORIGIN MANAGEMENT =======================================================
//=============================================================================
//=============================================================================
//=============================================================================



template<double const& a, double const& b>
struct origin_product
{
  static constexpr double value = OMNI_TRUE_ZERO ? zero : a*b;
};


template<double const& a, double const& b>
struct origin_division
{
  static constexpr double value = (OMNI_TRUE_ZERO || std::abs(b) <= std::numeric_limits<double>::epsilon()) ? zero : a/b;
};


template<double const& origin, int exponent>
struct origin_power
{
  static constexpr double value = std::pow(origin, exponent);
};


template<double const& origin, int basis>
struct origin_root
{
  static_assert(basis != 0, "Basis must not be 0.");
  static constexpr double value = std::pow(origin, 1.0/basis);
};



} // namespace omni

#endif //OMNIUNIT_UTILITY_HH_