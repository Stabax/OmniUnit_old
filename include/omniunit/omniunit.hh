//OmniUnit.hh

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



#ifndef OMNIUNIT_HH_
#define OMNIUNIT_HH_


#ifndef OMNI_DEFAULT_TYPE
  #define OMNI_DEFAULT_TYPE float
#endif // OMNI_DEFAULT_TYPE

#ifndef OMNI_OFFICIAL_ZERO
  #define OMNI_OFFICIAL_ZERO true
#endif // OMNI_OFFICIAL_ZERO

//easter eggs
#ifdef WESTERN_SPY
  #error "OmniUnit doesn't treat with western spy !"
#endif


#include <chrono>     // chrono::duration
#include <cmath>      // floor
#include <exception>  // exception
#include <iostream>   // ostream
#include <limits>     // numeric_limits
#include <ratio>      // ratio
#include <string>     // string



namespace stb
{



namespace omni
{



//=============================================================================
//=============================================================================
//=============================================================================
//=== EXCEPTIONS DEFINITION ===================================================
//=============================================================================
//=============================================================================
//=============================================================================



class exception : public std::exception
{
public:

  exception(std::string const& msg, std::string const& name):
  _msg("[OmniUnit.exception - " + name + " : " + msg + "]")
  {
  }

  virtual ~exception()
  {
  }

  virtual const char* what() const noexcept
  {
    return _msg.c_str();
  }

protected:
  std::string const _msg;
};





class Unit_exception : public exception
{
public:

  Unit_exception(std::string const& msg):
  exception(msg, "Unit_exception")
  {
  }

  virtual ~Unit_exception()
  {
  }
};



//=============================================================================
//=============================================================================
//=============================================================================
//=== UTILITY FUNCTIONS =======================================================
//=============================================================================
//=============================================================================
//=============================================================================



//modulo at compile time which can handle floating point.
template <typename T, typename U>
constexpr typename std::common_type<T, U>::type
modulo(T const& a, U const& b)
{
  //static_assert(b < 0 || b > 0, "Division by 0.");
  static_assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value, "Arguments should be arithmetic values.");
  typedef typename std::common_type<T, U>::type common;
  common a2 = static_cast<common>(a);
  common b2 = static_cast<common>(b);
  return a2 - (static_cast<common>(std::floor(a2/b2)) * b2);
}


static constexpr double zero = 0.;

/*
//The goal is to replace function gcd by type_trait gcd to allow the static_assertion
//in modulo. However, this doesn't work because modulo is not done at compile time
//because of std::floor...

template <double const& a, double const& b>
struct gcd_impl
{
  static constexpr double c = modulo(a, b);
  static constexpr double value = gcd_impl<b, c>::value;

};


template <double const& a>
struct gcd_impl<a, zero>
{
  static constexpr double value = a;

};
*/


//there is a standard gcd in c++17. It's too recent.
template <typename T, typename U>
constexpr typename std::common_type<T, U>::type
gcd(T const& a, U const& b)
{
  static_assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value, "Arguments should be arithmetic values.");

  typedef typename std::common_type<T, U>::type common;
  common a2 = static_cast<common>(a);
  common b2 = static_cast<common>(b);

  double tempo = 0;
  while (b2 > 0)
  {
    tempo = modulo(a2, b2);
    a2 = b2;
    b2 = tempo;
  }
  return a2;
}


//test if a double has no decimals and is positive
template <typename T>
constexpr bool is_positive_integer(T const& number)
{
  static_assert(std::is_arithmetic<T>::value, "Arguments should be arithmetic values.");

  T res = number - static_cast<T>(std::floor(number));
  return (res >=0 && res <=0 && number >= 0) ? true : false;
}


//wrapper for function partial specialization emulation
//allow to replace partial specialization (which doesn't exist for functions) with an overload
template <typename T>
struct partial_specialization_wrapper
{
};



//=============================================================================
//=============================================================================
//=============================================================================
//=== STATIC CONSTEXPR POWER OF TEN DEFINITION ================================
//=============================================================================
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
//=============================================================================
//=== RATIO DEFINITION ========================================================
//=============================================================================
//=============================================================================
//=============================================================================



template<double const& _Num, double const& _Den = E0>
struct Ratio
{
  static_assert(_Den > 0 || _Den < 0, "Denominator cannot be zero.");
  static_assert(is_positive_integer(_Num), "Numerator may not have decimals and may be positive.");
  static_assert(is_positive_integer(_Den), "Denominator may not have decimals and may be positive.");

  static constexpr double num = _Num / gcd(_Num, _Den);
  static constexpr double den = _Den / gcd(_Num, _Den);
  static constexpr double value = num / den;
  typedef Ratio<num, den> type;
};

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
  static_assert(ratio::num > 0 || ratio::num < 0, "Denominator cannot be zero.");
  static_assert(is_stb_Ratio<ratio>::value , "Template parameter should be an OmniUnit ratio.");

  typedef Ratio<ratio::den, ratio::num> type;
};


template <typename ratio1, typename ratio2>
class Ratio_multiply
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
class Ratio_divide
{
  static_assert(ratio2::num > 0 || ratio2::num < 0, "Denominator cannot be zero.");
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
  static_assert(val > 0 || val < 0, "Denominator cannot be zero.");
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
  static_assert(ratio::num > 0 || ratio::num < 0, "Denominator cannot be zero.");
  static_assert(is_stb_Ratio<ratio>::value, "Second template parameter should be an OmniUnit ratio.");
  static_assert(is_positive_integer(val), "First template parameter may not have decimals and may be positive.");


  static constexpr double _gcd = gcd(val * ratio::den, ratio::num);
  static constexpr double num = (val * ratio::den) / _gcd;
  static constexpr double den = (ratio::den * val) /_gcd;
public:
  typedef Ratio<num, den> type;
};



//=============================================================================
//=============================================================================
//=============================================================================
//=== RATIO CONVERTER STD/STB =================================================
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


//it is useless to make this function part of the class Dimension (static constexpr)
//because std::string is not a litteral : the function cannot be interpreted at
//compile time, so class Dimension could neither (i guess...).
template<typename dimension>
std::string dimension_str()
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
//=== UNIT CAST ===============================================================
//=============================================================================
//=============================================================================
//=============================================================================



//forward declaration
//origin is given in official unit (ratio<1, 1>)
template<typename _Dimension, typename Rep, typename Period, double const& Origin = zero>
class Unit;


template<typename falseType>
struct is_Unit : std::false_type
{
};


template<typename Dimension, typename Rep, typename Period, double const& Origin>
struct is_Unit<Unit<Dimension, Rep, Period, Origin>> : public std::true_type
{
};


template<typename toUnit, typename Dimension, typename Rep, typename Period, double const& Origin>
constexpr toUnit unit_cast(const Unit<Dimension, Rep, Period, Origin>& Obj)
{
  static_assert(is_Unit<toUnit>::value, "First template argument should be a unit");
  static_assert(std::is_same<typename toUnit::dim, Dimension>::value, "Cannot cast different dimensions.");

  typedef typename Ratio_divide<Period, typename toUnit::period>::type new_Ratio;
  typedef typename std::common_type<typename toUnit::rep, Rep>::type common_rep;

  return toUnit(static_cast<typename toUnit::rep>((static_cast<common_rep>(Obj.count())
    * static_cast<common_rep>(new_Ratio::num) / static_cast<common_rep>(new_Ratio::den))
    + static_cast<common_rep>((Origin - toUnit::origin) / toUnit::period::value)));
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== UNIT DEFINITION =========================================================
//=============================================================================
//=============================================================================
//=============================================================================



template<typename _Dimension, typename Rep, typename Period, double const& Origin>
class Unit
{
public:
  typedef _Dimension dim;
  typedef Rep rep;
  typedef Period period;
  static constexpr double origin = Origin;

  static_assert(is_Dimension<_Dimension>::value, "First template argument sould be a dimension.");
  static_assert(std::is_arithmetic<Rep>::value, "Second template argument should be an arithmetic type.");
  static_assert(is_stb_Ratio<Period>::value, "Third template argument should be an OmniUnit ratio.");

  constexpr Unit() = default;
  Unit(Unit const&) = default;


  template<typename _Rep>
  constexpr explicit Unit(_Rep const& countArg):
  _count(static_cast<Rep>(countArg))
  {
    static_assert(std::is_arithmetic<_Rep>::value, "Argument should be an aritmetic value.");
  }


  template<typename __Dimension, typename _Rep, typename _Period, double const& _Origin>
  constexpr Unit(Unit<__Dimension, _Rep, _Period, _Origin> const& Obj):
  Unit(unit_cast<Unit>(Obj).count())
  {
  }


  ~Unit() = default;


  Unit& operator=(Unit const& Obj)
  {
    _count = Obj._count;
    return *this;
  }


  static constexpr Unit zero()
  {
    return Unit(0);
  }


  constexpr Rep count() const
  {
    return _count;
  }


  static constexpr Rep max()
  {
    return std::numeric_limits<Rep>::max();
  }


  static constexpr Rep min()
  {
    return std::numeric_limits<Rep>::lowest();
  }


  constexpr std::string dimension() const
  {
    return dimension_str<dim>();
  }


  Unit& operator++()
  {
    ++_count;
    return *this;
  }


  Unit operator++(int)
  {
    return Unit(_count++);
  }


  Unit& operator--()
  {
    --_count;
    return *this;
  }


  Unit operator--(int)
  {
    return Unit(_count--);
  }


  Unit operator-()
  {
    return Unit(-_count);
  }


  Unit& operator+=(Unit const& Obj)
  {
    _count += Obj.count();
    return *this;
  }


  Unit& operator-=(Unit const& Obj)
  {
    _count -= Obj.count();
    return *this;
  }


  template<typename _Rep>
  Unit& operator*=(_Rep const& coef)
  {
    if(OMNI_OFFICIAL_ZERO)
    {
      *this += Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    typedef typename std::common_type<Rep, _Rep>::type common;
    _count = static_cast<Rep>(static_cast<common>(_count) * static_cast<common>(coef));

    if(OMNI_OFFICIAL_ZERO)
    {
      *this -= Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    return *this;
  }


  template<typename _Rep, typename _Period, double const& _Origin>
  Unit& operator*=(Unit<Dimension<0,0,0,0,0,0,0,0,0>, _Rep, _Period, _Origin> Obj)
  {
    if(OMNI_OFFICIAL_ZERO)
    {
      *this += Unit<_Dimension, Rep, base, Origin>(Origin);
      Obj += Unit<Dimension<0,0,0,0,0,0,0,0,0>, _Rep, base, _Origin>(_Origin);
    }

    typedef typename std::common_type<Rep, _Rep>::type common;
    Unit<Dimension<0,0,0,0,0,0,0,0,0>, common, base, _Origin> newObj(Obj);
    _count = static_cast<Rep>(static_cast<common>(_count) * static_cast<common>(newObj.count()));

    if(OMNI_OFFICIAL_ZERO)
    {
      *this -= Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    return *this;
  }


  template<typename _Rep>
  Unit& operator/=(_Rep const& coef)
  {
    if(OMNI_OFFICIAL_ZERO)
    {
      *this += Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    if(coef >= 0 && coef <= 0)
      throw Unit_exception("Divide by 0.");

    typedef typename std::common_type<Rep, _Rep>::type common;
    _count = static_cast<Rep>(static_cast<common>(_count) / static_cast<common>(coef));

    if(OMNI_OFFICIAL_ZERO)
    {
      *this -= Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    return *this;
  }


  template<typename _Rep, typename _Period, double const& _Origin>
  Unit& operator/=(Unit<Dimension<0,0,0,0,0,0,0,0,0>, _Rep, _Period, _Origin> Obj)
  {
    if(OMNI_OFFICIAL_ZERO)
    {
      *this += Unit<_Dimension, Rep, base, Origin>(Origin);
      Obj += Unit<Dimension<0,0,0,0,0,0,0,0,0>, _Rep, base, _Origin>(_Origin);
    }

    typedef typename std::common_type<Rep, _Rep>::type common;
    Unit<Dimension<0,0,0,0,0,0,0,0,0>, common, base, _Origin> newObj(Obj);

    if(newObj.count() >= 0 && newObj.count() <= 0)
      throw Unit_exception("Divide by 0.");

    _count = static_cast<Rep>(static_cast<common>(_count) / static_cast<common>(newObj.count()));

    if(OMNI_OFFICIAL_ZERO)
    {
      *this -= Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    return *this;
  }


  template <typename _Rep>
  Unit& operator%=(_Rep const& coef)
  {
    if(OMNI_OFFICIAL_ZERO)
    {
      *this += Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    if(coef >= 0 && coef <= 0)
      throw Unit_exception("Divide by 0.");

    _count = static_cast<Rep>(modulo(_count, coef));

    if(OMNI_OFFICIAL_ZERO)
    {
      *this -= Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    return *this;
  }


  template<typename _Rep, typename _Period, double const& _Origin>
  Unit& operator%=(Unit<Dimension<0,0,0,0,0,0,0,0,0>, _Rep, _Period, _Origin> Obj)
  {
    if(OMNI_OFFICIAL_ZERO)
    {
      *this += Unit<_Dimension, Rep, base, Origin>(Origin);
      Obj += Unit<Dimension<0,0,0,0,0,0,0,0,0>, _Rep, base, _Origin>(_Origin);
    }

    Unit<Dimension<0,0,0,0,0,0,0,0,0>, _Rep, base, _Origin> newObj(Obj);
    if(newObj.count() == 0) //possible because newObj::rep is integer
      throw Unit_exception("Divide by 0.");
    _count = static_cast<Rep>(modulo(_count, newObj.count()));

    if(OMNI_OFFICIAL_ZERO)
    {
      *this -= Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    return *this;
  }


protected:
  Rep _count;
};


//definition of Unit::origin, so it can be ODR-usable (required for any call of the variable)
//In c++17, we can set the variable inline inside the Unit class, which permit avoiding the
//following declaration :
template<typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr double Unit<_Dimension, Rep, Period, Origin>::origin;



//=============================================================================
//=============================================================================
//=============================================================================
//=== UNIT SPECIALIZATION FOR DURATION ========================================
//=============================================================================
//=============================================================================
//=============================================================================

// this specialization is needed to provide converter with std::chrono::duration



template<typename Rep, typename Period, double const& Origin>
class Unit<Dimension<0,0,1,0,0,0,0,0,0>, Rep, Period, Origin>
{

protected:
  typedef Dimension<0,0,1,0,0,0,0,0,0> _Dimension;


public:
  typedef _Dimension dim;
  typedef Rep rep;
  typedef Period period;
  static constexpr double origin = Origin;


  static_assert(is_Dimension<_Dimension>::value, "First template argument sould be a dimension.");
  static_assert(std::is_arithmetic<Rep>::value, "Second template argument should be an arithmetic type.");
  static_assert(is_stb_Ratio<Period>::value, "Third template argument should be a ratio from OmniUnit.");


  constexpr Unit() = default;
  Unit(Unit const&) = default;


  template<typename _Rep>
  constexpr Unit(_Rep const& countArg):
  _count(static_cast<Rep>(countArg))
  {
    static_assert(std::is_arithmetic<_Rep>::value, "Argument should be an aritmetic value.");
  }


  template<typename __Dimension, typename _Rep, typename _Period, double const& _Origin>
  constexpr Unit(Unit<__Dimension, _Rep, _Period, _Origin> const& Obj):
  Unit(unit_cast<Unit, Dimension<0,0,1,0,0,0,0,0,0>>(Obj).count())
  {
  }


  template<typename _Rep, typename _Period> //std::chrono::duration has no Origin parameter
  constexpr Unit(std::chrono::duration<_Rep, _Period> const& Obj):
  Unit(Unit<dim, _Rep, typename Ratio_std_to_omni<_Period>::type, Origin>(Obj.count()))
  {
  }


  ~Unit() = default;


  Unit& operator=(Unit const& Obj)
  {
    _count = Obj._count;
    return *this;
  }


  template<typename _Rep, typename _Period> //std::chrono::duration has no Origin parameter
  Unit& operator=(std::chrono::duration<_Rep, _Period> const& Obj)
  {
    _count = Unit(Obj).count();
    return *this;
  }


  template<typename _Rep, typename _Period> //transform a stb::omni::duration into a std::chrono::duration
  operator std::chrono::duration<_Rep, _Period>() const
  {
    return std::chrono::duration<_Rep, _Period>(Unit<dim, _Rep, typename Ratio_std_to_omni<_Period>::type>(*this).count());
  }


  static constexpr Unit zero()
  {
    return Unit(0);
  }


  constexpr Rep count() const
  {
    return _count;
  }


  static constexpr Rep max()
  {
    return std::numeric_limits<Rep>::max();
  }


  static constexpr Rep min()
  {
    return std::numeric_limits<Rep>::lowest();
  }


  constexpr std::string dimension() const
  {
    return dimension_str<dim>();
  }


  Unit& operator++()
  {
    ++_count;
    return *this;
  }


  Unit operator++(int)
  {
    return Unit(_count++);
  }


  Unit& operator--()
  {
    --_count;
    return *this;
  }


  Unit operator--(int)
  {
    return Unit(_count--);
  }


  Unit operator-()
  {
    return Unit(-_count);
  }


  Unit& operator+=(Unit const& Obj)
  {
    _count += Obj.count();
    return *this;
  }


  Unit& operator-=(Unit const& Obj)
  {
    _count -= Obj.count();
    return *this;
  }


  template<typename _Rep>
  Unit& operator*=(_Rep const& coef)
  {
    if(OMNI_OFFICIAL_ZERO)
    {
      *this += Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    typedef typename std::common_type<Rep, _Rep>::type common;
    _count = static_cast<Rep>(static_cast<common>(_count) * static_cast<common>(coef));

    if(OMNI_OFFICIAL_ZERO)
    {
      *this -= Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    return *this;
  }


  template<typename _Rep, typename _Period, double const& _Origin>
  Unit& operator*=(Unit<Dimension<0,0,0,0,0,0,0,0,0>, _Rep, _Period, _Origin> Obj)
  {
    if(OMNI_OFFICIAL_ZERO)
    {
      *this += Unit<_Dimension, Rep, base, Origin>(Origin);
      Obj += Unit<Dimension<0,0,0,0,0,0,0,0,0>, _Rep, base, _Origin>(_Origin);
    }

    typedef typename std::common_type<Rep, _Rep>::type common;
    Unit<Dimension<0,0,0,0,0,0,0,0,0>, common, base, _Origin> newObj(Obj);
    _count = static_cast<Rep>(static_cast<common>(_count) * static_cast<common>(newObj.count()));

    if(OMNI_OFFICIAL_ZERO)
    {
      *this -= Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    return *this;
  }


  template<typename _Rep>
  Unit& operator/=(_Rep const& coef)
  {
    if(OMNI_OFFICIAL_ZERO)
    {
      *this += Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    if(coef >= 0 && coef <= 0)
      throw Unit_exception("Divide by 0.");

    typedef typename std::common_type<Rep, _Rep>::type common;
    _count = static_cast<Rep>(static_cast<common>(_count) / static_cast<common>(coef));

    if(OMNI_OFFICIAL_ZERO)
    {
      *this -= Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    return *this;
  }


  template<typename _Rep, typename _Period, double const& _Origin>
  Unit& operator/=(Unit<Dimension<0,0,0,0,0,0,0,0,0>, _Rep, _Period, _Origin> Obj)
  {
    if(OMNI_OFFICIAL_ZERO)
    {
      *this += Unit<_Dimension, Rep, base, Origin>(Origin);
      Obj += Unit<Dimension<0,0,0,0,0,0,0,0,0>, _Rep, base, _Origin>(_Origin);
    }

    typedef typename std::common_type<Rep, _Rep>::type common;
    Unit<Dimension<0,0,0,0,0,0,0,0,0>, common, base, _Origin> newObj(Obj);

    if(newObj.count() >= 0 && newObj.count() <= 0)
      throw Unit_exception("Divide by 0.");

    _count = static_cast<Rep>(static_cast<common>(_count) / static_cast<common>(newObj.count()));

    if(OMNI_OFFICIAL_ZERO)
    {
      *this -= Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    return *this;
  }


  template <typename _Rep>
  Unit& operator%=(_Rep const& coef)
  {
    if(OMNI_OFFICIAL_ZERO)
    {
      *this += Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    if(coef >= 0 && coef <= 0)
      throw Unit_exception("Divide by 0.");

    _count = static_cast<Rep>(modulo(_count, coef));

    if(OMNI_OFFICIAL_ZERO)
    {
      *this -= Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    return *this;
  }


  template<typename _Rep, typename _Period, double const& _Origin>
  Unit& operator%=(Unit<Dimension<0,0,0,0,0,0,0,0,0>, _Rep, _Period, _Origin> Obj)
  {
    if(OMNI_OFFICIAL_ZERO)
    {
      *this += Unit<_Dimension, Rep, base, Origin>(Origin);
      Obj += Unit<Dimension<0,0,0,0,0,0,0,0,0>, _Rep, base, _Origin>(_Origin);
    }

    Unit<Dimension<0,0,0,0,0,0,0,0,0>, _Rep, base, _Origin> newObj(Obj);
    if(newObj.count() == 0) //possible because newObj::rep is integer
      throw Unit_exception("Divide by 0.");
    _count = static_cast<Rep>(modulo(_count, newObj.count()));

    if(OMNI_OFFICIAL_ZERO)
    {
      *this -= Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    return *this;
  }



protected:
  Rep _count;
};


//definition of Unit::origin, so it can be ODR-usable (required for any call of the variable)
//In c++17, we can set the variable inline inside the Unit class, which permit avoiding the
//following declaration :
template<typename Rep, typename Period, double const& Origin>
constexpr double Unit<Dimension<0,0,1,0,0,0,0,0,0>, Rep, Period, Origin>::origin;



//=============================================================================
//=============================================================================
//=============================================================================
//=== UNIT CAST OVERLOAD FOR UNIT SPECIALIZATION FOR DURATION =================
//=============================================================================
//=============================================================================
//=============================================================================

//the purpose is to make aviable unit_cast between stb::duration and std::chrono::duration



//called if toUnit equals stb::duration
//cast stb::duration to another stb::duration
template <typename toUnit, typename Rep, typename Period, double const& Origin>
constexpr Unit<Dimension<0,0,1,0,0,0,0,0,0>, typename toUnit::rep, typename toUnit::period, toUnit::origin>
unit_cast_impl(partial_specialization_wrapper<Unit<Dimension<0,0,1,0,0,0,0,0,0>, typename toUnit::rep, typename toUnit::period /*, toUnit::origin*/>>,
Unit<Dimension<0,0,1,0,0,0,0,0,0>, Rep, Period, Origin> const& Obj)
{
  return unit_cast<toUnit, Dimension<0,0,1,0,0,0,0,0,0>>(Obj);
}


//called if toUnit equals std::chrono::duration
//cast stb::duration to std::chrono::duration
template <typename toUnit, typename Rep, typename Period, double const& Origin>
constexpr std::chrono::duration<typename toUnit::rep, typename toUnit::period>
unit_cast_impl(partial_specialization_wrapper<std::chrono::duration<typename toUnit::rep, typename toUnit::period>>,
Unit<Dimension<0,0,1,0,0,0,0,0,0>, Rep, Period, Origin> const& Obj)
{
  return toUnit(Obj);
}


//cast stb::duration to toUnit
template <typename toUnit, typename Rep, typename Period, double const& Origin>
constexpr toUnit unit_cast(Unit<Dimension<0,0,1,0,0,0,0,0,0>, Rep, Period, Origin> const& Obj)
{
  return unit_cast_impl<toUnit>(partial_specialization_wrapper<toUnit>{}, Obj);
}


//called if toUnit equals stb::duration
//cast std::chrono::duration to stb::duration
template <typename toUnit, typename Rep, typename Period>
constexpr Unit<Dimension<0,0,1,0,0,0,0,0,0>, typename toUnit::rep, typename toUnit::period, toUnit::origin>
unit_cast_impl(partial_specialization_wrapper<Unit<Dimension<0,0,1,0,0,0,0,0,0>, typename toUnit::rep, typename toUnit::period /*, toUnit::origin*/>>,
std::chrono::duration<Rep, Period> const& Obj)
{
  return toUnit(Obj);
}


//called if toUnit equals std::chrono::duration
//cast std::chrono::duration to another std::chrono::duration
template <typename toUnit, typename Rep, typename Period>
constexpr std::chrono::duration<typename toUnit::rep, typename toUnit::period>
unit_cast_impl(partial_specialization_wrapper<std::chrono::duration<typename toUnit::rep, typename toUnit::period>>,
std::chrono::duration<Rep, Period> const& Obj)
{
  return std::chrono::duration_cast<toUnit>(Obj);
}


//cast std::chrono::duration to toUnit
template <typename toUnit, typename Rep, typename Period>
constexpr toUnit unit_cast(std::chrono::duration<Rep, Period> const& Obj)
{
  return unit_cast_impl<toUnit>(partial_specialization_wrapper<toUnit>{}, Obj);
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== ARITHMETIC OPERATORS WITHOUT DIMENSION CHANGE ===========================
//=============================================================================
//=============================================================================
//=============================================================================



template <typename Dimension1, typename Rep1, typename Period1, double const& Origin1,
          typename Dimension2, typename Rep2, typename Period2, double const& Origin2>
constexpr typename std::common_type<Unit<Dimension1, Rep1, Period1, Origin1>, Unit<Dimension2, Rep2, Period2, Origin2>>::type
operator+ (Unit<Dimension1, Rep1, Period1, Origin1> const& Obj1, Unit<Dimension2, Rep2, Period2, Origin2> const& Obj2)
{
  static_assert(std::is_same<Dimension1, Dimension2>::value, "Cannot sum values with different dimension.");
  typedef typename std::common_type<Unit<Dimension1, Rep1, Period1, Origin1>, Unit<Dimension2, Rep2, Period2, Origin2>>::type type;
  return type(type(Obj1).count() + type(Obj2).count());
}


template <typename Dimension1, typename Rep1, typename Period1, double const& Origin1,
          typename Dimension2, typename Rep2, typename Period2, double const& Origin2>
constexpr typename std::common_type<Unit<Dimension1, Rep1, Period1, Origin1>, Unit<Dimension2, Rep2, Period2, Origin2>>::type
operator- (Unit<Dimension1, Rep1, Period1, Origin1> const& Obj1, Unit<Dimension2, Rep2, Period2, Origin2> const& Obj2)
{
  static_assert(std::is_same<Dimension1, Dimension2>::value, "Cannot subtract values with different dimension.");
  typedef typename std::common_type<Unit<Dimension1, Rep1, Period1, Origin1>, Unit<Dimension2, Rep2, Period2, Origin2>>::type type;
  return type(type(Obj1).count() - type(Obj2).count());
}


template <typename Dimension, typename Rep, typename Period, double const& Origin, typename T>
constexpr Unit<Dimension, typename std::common_type<Rep, T>::type, Period, Origin>
operator* (Unit<Dimension, Rep, Period, Origin> Obj, T const& coef)
{
  static_assert(std::is_arithmetic<T>::value, "Operands must be a unit and an arithmetic.");
  return Obj *= coef;

}


template <typename Dimension, typename Rep, typename Period, double const& Origin, typename T>
constexpr Unit<Dimension, typename std::common_type<Rep, T>::type, Period, Origin>
operator* (T const& coef, Unit<Dimension, Rep, Period, Origin> const& Obj)
{
  static_assert(std::is_arithmetic<T>::value, "Operands must be an arithmetic and a unit.");
  return Obj * coef;
}


template <typename Dimension, typename Rep, typename Period, double const& Origin, typename T>
constexpr Unit<Dimension, typename std::common_type<Rep, T>::type, Period, Origin>
operator/ (Unit<Dimension, Rep, Period, Origin> Obj, T const& coef)
{
  static_assert(std::is_arithmetic<T>::value, "Operands must be a unit and an arithmetic.");
  if(coef >= 0 && coef <= 0)
    throw Unit_exception("Divide by 0.");
  return Obj /= coef;
}


template <typename Dimension, typename Rep, typename Period, double const& Origin, typename T>
constexpr Unit<Dimension, typename std::common_type<Rep, T>::type, Period, Origin>
operator% (Unit<Dimension, Rep, Period, Origin> Obj, T const& coef)
{
  static_assert(std::is_arithmetic<T>::value, "Operands must be a unit and an arithmetic.");
  if(coef >= 0 && coef <= 0)
    throw Unit_exception("Divide by 0.");
  return Obj %= coef;
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== ARITHMERIC OPERATORS WITH DIMENSION CHANGE ==============================
//=============================================================================
//=============================================================================
//=============================================================================



//This type_trait return zero if origins 1 and 2 are different.
template<double const& a, double const& b>
struct origin_getter
{
  static constexpr double value = (a<=b && a >=b) ? a : zero;
};


template <typename Dimension1, typename Rep1, typename Period1, double const& Origin1,
          typename Dimension2, typename Rep2, typename Period2, double const& Origin2>
constexpr Unit<typename Dimension_multiply<Dimension1, Dimension2>::type,
typename std::common_type<Rep1, Rep2>::type,
typename Ratio_multiply<Period1, Period2>::type, origin_getter<Origin1, Origin2>::value>
operator* (Unit<Dimension1, Rep1, Period1, Origin1> Obj1, Unit<Dimension2, Rep2, Period2, Origin2> Obj2)
{
  if(OMNI_OFFICIAL_ZERO)
  {
    Obj1 += Unit<Dimension1, Rep1, base, Origin1>(Origin1);
    Obj2 += Unit<Dimension2, Rep2, base, Origin2>(Origin2);
  }

  typedef typename std::common_type<Rep1, Rep2>::type common;
  typedef typename Dimension_multiply<Dimension1, Dimension2>::type newDim;
  typedef typename Ratio_multiply<Period1, Period2>::type newPeriod;
  typedef Unit<newDim, common, newPeriod, origin_getter<Origin1, Origin2>::value> type;

  type toReturn(static_cast<common>(Obj1.count()) * static_cast<common>(Obj2.count()));

  if(OMNI_OFFICIAL_ZERO)
  {
    //WHAT TO DO HERE ?
  }

  return toReturn;
}


template <typename Dimension1, typename Rep1, typename Period1,
typename Dimension2, typename Rep2, typename Period2>
constexpr Unit<typename Dimension_divide<Dimension1, Dimension2>::type,
typename std::common_type<Rep1, Rep2>::type,
typename Ratio_divide<Period1, Period2>::type>
operator/ (Unit<Dimension1, Rep1, Period1> const& Obj1, Unit<Dimension2, Rep2, Period2> const& Obj2)
{
  if(Obj2.count() >= 0 && Obj2.count() <= 0)
    throw Unit_exception("Divide by 0.");

  typedef typename std::common_type<Rep1, Rep2>::type common;
  typedef typename Dimension_divide<Dimension1, Dimension2>::type newDim;
  typedef typename Ratio_divide<Period1, Period2>::type newPeriod;
  typedef Unit<newDim, common, newPeriod> type;

  return type(static_cast<common>(Obj1).count() / static_cast<common>(Obj2));
}


template <typename _Dimension, typename Rep, typename Period, typename T>
constexpr Unit<typename Dimension_divide<Dimension<0,0,0,0,0,0,0,0,0>, _Dimension>::type,
typename std::common_type<Rep, typename
std::enable_if<!is_Unit<T>::value, T>::type>::type,
typename Ratio_divide<Ratio<E0, E0>, Period>::type>
operator/ (T const& coef, Unit<_Dimension, Rep, Period> const& Obj)
{
  if(Obj.count() >= 0 && Obj.count() <= 0)
    throw Unit_exception("Divide by 0.");

  typedef typename std::common_type<Rep, T>::type common;
  typedef typename Dimension_divide<Dimension<0,0,0,0,0,0,0,0,0>, _Dimension>::type newDim;
  typedef typename Ratio_divide<Ratio<E0, E0>, Period>::type newPeriod;
  typedef Unit<newDim, common, newPeriod> type;

  return type(static_cast<common>(coef) / static_cast<common>(Obj).count());
}


template <typename _Dimension, typename Rep, typename Period, typename T>
constexpr Unit<Dimension<0,0,0,0,0,0,0,0,0>, typename std::common_type<Rep, T>::type, Period>
operator% (T const& coef, Unit<_Dimension, Rep, Period> const& Obj)
{
  if(Obj.count() >= 0 && Obj.count() <= 0)
    throw Unit_exception("Divide by 0.");

  typedef Unit<Dimension<0,0,0,0,0,0,0,0,0>, typename std::common_type<Rep, T>::type, Period> type;
  return type(modulo(coef, Obj.count()));
}


//MAYBE CHANGE THE PERIOD OF THE RETURN
template <typename Dimension1, typename Rep1, typename Period1,
typename Dimension2, typename Rep2, typename Period2>
constexpr Unit<Dimension1, typename std::common_type<Rep1, Rep2>::type, Period1>
operator% (Unit<Dimension1, Rep1, Period1> const& Obj1,
Unit<Dimension2, Rep2, Period2> const& Obj2)
{
  if(Obj2.count() >= 0 && Obj2.count() <= 0)
    throw Unit_exception("Divide by 0.");

  typedef Unit<Dimension1, typename std::common_type<Rep1, Rep2>::type, Period1> type;
  return type(modulo(Obj1.count(), Obj2.count()));
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== COMPARISON OPERATORS ====================================================
//=============================================================================
//=============================================================================
//=============================================================================



template <typename Dimension1, typename Rep1, typename Period1,
typename Rep2, typename Period2, typename Dimension2>
constexpr bool operator==(Unit<Dimension1, Rep1, Period1> const& Obj1,
Unit<Dimension2, Rep2, Period2> const& Obj2)
{
  static_assert(std::is_same<Dimension1, Dimension2>::value,
  "Cannot compare different dimensions.");

  typedef typename std::common_type<Unit<Dimension1, Rep1, Period1>,
  Unit<Dimension2, Rep2, Period2>>::type type;
  return type(Obj1).count() == type(Obj2).count();
}


template <typename Dimension1, typename Rep1, typename Period1,
typename Rep2, typename Period2, typename Dimension2>
constexpr bool operator!=(Unit<Dimension1, Rep1, Period1> const& Obj1,
Unit<Dimension2, Rep2, Period2> const& Obj2)
{
  static_assert(std::is_same<Dimension1, Dimension2>::value,
  "Cannot compare different dimensions.");

  return !(Obj1 == Obj2);
}


template <typename Dimension1, typename Rep1, typename Period1,
typename Rep2, typename Period2, typename Dimension2>
constexpr bool operator<(Unit<Dimension1, Rep1, Period1> const& Obj1,
Unit<Dimension2, Rep2, Period2> const& Obj2)
{
  static_assert(std::is_same<Dimension1, Dimension2>::value,
  "Cannot compare different dimensions.");

  typedef typename std::common_type<Unit<Dimension1, Rep1, Period1>,
  Unit<Dimension2, Rep2, Period2>>::type type;
  return type(Obj1).count() < type(Obj2).count();
}


template <typename Dimension1, typename Rep1, typename Period1,
typename Rep2, typename Period2, typename Dimension2>
constexpr bool operator<=(Unit<Dimension1, Rep1, Period1> const& Obj1,
Unit<Dimension2, Rep2, Period2> const& Obj2)
{
  static_assert(std::is_same<Dimension1, Dimension2>::value,
  "Cannot compare different dimensions.");

  return !(Obj2 < Obj1);
}


template <typename Dimension1, typename Rep1, typename Period1,
typename Rep2, typename Period2, typename Dimension2>
constexpr bool operator>(Unit<Dimension1, Rep1, Period1> const& Obj1,
Unit<Dimension2, Rep2, Period2> const& Obj2)
{
  static_assert(std::is_same<Dimension1, Dimension2>::value,
  "Cannot compare different dimensions.");

  return Obj2 < Obj1;
}


template <typename Dimension1, typename Rep1, typename Period1,
typename Rep2, typename Period2, typename Dimension2>
constexpr bool operator>=(Unit<Dimension1, Rep1, Period1> const& Obj1,
Unit<Dimension2, Rep2, Period2> const& Obj2)
{
  static_assert(std::is_same<Dimension1, Dimension2>::value,
  "Cannot compare different dimensions.");

  return ! (Obj1 < Obj2);
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== EXPONENTIAL FUNCTIONS ===================================================
//=============================================================================
//=============================================================================
//=============================================================================



template <typename Rep, typename Period>
Unit<Dimension<0,0,0,0,0,0,0,0,0>, Rep, Period> exp(Unit<Dimension<0,0,0,0,0,0,0,0,0>, Rep, Period> const& Obj)
{
  return std::exp(Obj.count());
}


template <typename Rep, typename Period>
Unit<Dimension<0,0,0,0,0,0,0,0,0>, Rep, Period> exp(Unit<Dimension<0,0,0,0,0,0,0,0,0>, Rep, Period> const& Obj, float basis)
{
  return std::exp(Obj.count() * std::log(basis));
}


template <typename Rep, typename Period>
Unit<Dimension<0,0,0,0,0,0,0,0,0>, Rep, Period> log(Unit<Dimension<0,0,0,0,0,0,0,0,0>, Rep, Period> const& Obj)
{
  return std::log(Obj.count());
}


template <typename Rep, typename Period>
Unit<Dimension<0,0,0,0,0,0,0,0,0>, Rep, Period> log(Unit<Dimension<0,0,0,0,0,0,0,0,0>, Rep, Period> const& Obj, float basis)
{
  return std::log(Obj.count()) / std::log(basis);
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== POWER FUNCTIONS =========================================================
//=============================================================================
//=============================================================================
//=============================================================================



template <typename Rep, typename Period, typename T = float>
T pow(float var, Unit<Dimension<0,0,0,0,0,0,0,0,0>, Rep, Period> const& exponent)
{
  return std::pow(var, exponent.count()); //A REFAIRE
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== TRIGONOMETRIC FUNCTIONS =================================================
//=============================================================================
//=============================================================================
//=============================================================================

//=============================================================================
//=============================================================================
//=============================================================================
//=== HYPERBOLIC FUNCTIONS ===================================================
//=============================================================================
//=============================================================================
//=============================================================================

//=============================================================================
//=============================================================================
//=============================================================================
//=== ROUNDING FUNCTIONS ======================================================
//=============================================================================
//=============================================================================
//=============================================================================



//=============================================================================
//=============================================================================
//=============================================================================
//=== STREAM OPERATOR =========================================================
//=============================================================================
//=============================================================================
//=============================================================================



template <typename Dimension, typename Rep, typename Period, double const& Origin>
std::ostream& operator<<(std::ostream& oss, Unit<Dimension, Rep, Period, Origin> const& Obj)
{
  oss << Obj.count();
  return oss;
}






#ifdef OMNI_DISABLE_UNCERTAINTIES



//template <typename _Dimension, typename Period, double const& Origin>
//using Unit =



#else



//=============================================================================
//=============================================================================
//=============================================================================
//=== PROPAGATION OF UNCERTAINTIES ============================================
//=============================================================================
//=============================================================================
//=============================================================================



struct PropagationUncertainties
{
  enum class Method {linear, quadratic, derived, double_variance};
  constexpr static Method linear = Method::linear;
  constexpr static Method quadratic = Method::quadratic;
  constexpr static Method derived = Method::derived;
  constexpr static Method double_variance = Method::double_variance;

  static Method sum;
  static Method product;
};
typedef PropagationUncertainties PU;


PU::Method PU::sum = PU::quadratic;
PU::Method PU::product = PU::quadratic;


//=============================================================================
//=============================================================================
//=============================================================================
//=== DEVIATION CALCULATION ===================================================
//=============================================================================
//=============================================================================
//=============================================================================



enum class Probability {none, uniform, triangular, triangular_asym, normal, arcsinus, uniform_gap};


template <typename _Dimension, typename Period, double const& Origin>
float getDeviation(Unit<_Dimension, float, Period, Origin> variation, Probability law)
{
  if(law == Probability::none)
    return variation;
  else if(law == Probability::uniform)
    return variation / std::sqrt(3.);
  else if(law == Probability::triangular)
    return variation / std::sqrt(6.);
  else if(law == Probability::triangular_asym)
    return variation / (3. * std::sqrt(2.)); // what about the average ?
  else if(law == Probability::arcsinus)
    return variation / std::sqrt(2.);
  else if(law == Probability::normal)
    return variation / 3.;
  else if(law == Probability::uniform_gap)
    return variation / (2. * std::sqrt(3.));
}


/*
template <typename T>
float getAverage(T container)
{

}


template <typename T>
float getUncertainty(T container)
{

}
*/



#endif // OMNI_DISABLE_UNCERTAINTIES

} //namespace omni



} //namespace stb





//=============================================================================
//=============================================================================
//=============================================================================
//=== COMMON_TYPE FOR UNIT ====================================================
//=============================================================================
//=============================================================================
//=============================================================================



namespace std _GLIBCXX_VISIBILITY(default)
{



template<typename Dimension1, typename Rep1, typename Period1, double const& Origin1,
         typename Dimension2, typename Rep2, typename Period2, double const& Origin2>
struct common_type<stb::omni::Unit<Dimension1, Rep1, Period1, Origin1>, stb::omni::Unit<Dimension2, Rep2, Period2, Origin2>>
{
private:
  static_assert(std::is_same<Dimension1, Dimension2>::value, "Cannot get a common unit between two units that have different dimension.");

  static constexpr double gcd_num = stb::omni::gcd(Period1::num, Period2::num);
  static constexpr double gcd_den = stb::omni::gcd(Period1::den, Period2::den);
  static constexpr double new_den = (Period1::den / gcd_den) * Period2::den;  // CHANGE THIS PERIOD CALCULATION !!
  typedef stb::omni::Ratio<gcd_num, new_den> new_Ratio;
  typedef typename std::common_type<Rep1, Rep2>::type common;
  static constexpr double origin = ((Origin1 < Origin2 || Origin1 > Origin2) ? 0. : Origin1); // should not compare floating point with == nor !=

public:
  typedef stb::omni::Unit<Dimension1, common, new_Ratio, origin> type;
};



} //namespace std



#include "units/units.hh"



#endif //OMNIUNIT_HH_
