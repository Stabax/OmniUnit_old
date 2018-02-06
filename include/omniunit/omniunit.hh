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

#include <chrono>     // chrono::duration
#include <cmath>      // floor
#include <exception>  // exception
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
constexpr typename std::common_type<
typename std::enable_if<std::is_arithmetic<T>::value, T>::type,
typename std::enable_if<std::is_arithmetic<U>::value, U>::type>::type
modulo(T const& a, U const& b)
{
  //static_assert(b < 0 || b > 0, "Division by 0.");
  typedef typename std::common_type<T, U>::type common;
  common a2 = static_cast<common>(a);
  common b2 = static_cast<common>(b);
  return a2 - (static_cast<common>(std::floor(a2/b2)) * b2);
}



//there is a standard gcd in c++17. It's too recent.
template <typename T, typename U>
constexpr typename std::common_type<
typename std::enable_if<std::is_arithmetic<T>::value, T>::type,
typename std::enable_if<std::is_arithmetic<U>::value, U>::type>::type
gcd(T const& a, U const& b)
{
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



template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
constexpr bool is_positive_integer(T const& number)
{
  T res = number - static_cast<T>(std::floor(number));
  return (res >=0 && res <=0 && number >= 0) ? true : false;
}



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
int _temperature, int _quantity, int _luminosity>
struct Dimension
{
  static constexpr int length = _length;
  static constexpr int mass = _mass;
  static constexpr int time = _time;
  static constexpr int current = _current;
  static constexpr int temperature = _temperature;
  static constexpr int quantity = _quantity;
  static constexpr int luminosity = _luminosity;
};


template<typename falseType>
struct is_Dimension : std::false_type
{
};


template<int length, int mass, int time, int current,
int temperature, int quantity, int luminosity>
struct is_Dimension<Dimension<length, mass, time, current,
temperature, quantity, luminosity>> : public std::true_type
{
};


template <typename dim1, typename dim2>
struct Dimension_multiply
{
  static_assert(is_Dimension<dim1>::value && is_Dimension<dim2>::value,
  "Bad type, need a stb::Dimension.");

  typedef Dimension<
  dim1::length + dim2::length,
  dim1::mass + dim2::mass,
  dim1::time + dim2::time,
  dim1::current + dim2::current,
  dim1::temperature + dim2::temperature,
  dim1::quantity + dim2::quantity,
  dim1::luminosity + dim2::luminosity
  > type;
};


template <typename dim1, typename dim2>
struct Dimension_divide
{
  static_assert(is_Dimension<dim1>::value && is_Dimension<dim2>::value,
  "Bad type, need a stb::Dimension.");

  typedef Dimension<
  dim1::length - dim2::length,
  dim1::mass - dim2::mass,
  dim1::time - dim2::time,
  dim1::current - dim2::current,
  dim1::temperature - dim2::temperature,
  dim1::quantity - dim2::quantity,
  dim1::luminosity - dim2::luminosity> type;
};


//it is useless to make this function part of the class Dimension (static constexpr)
//because std::string is not a litteral : the function cannot be interpreted at
//compile time, so class Dimension could neither.
template<typename dimension>
typename std::enable_if<is_Dimension<dimension>::value, std::string>::type dimension_str()
{
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
template<typename _Dimension, typename Rep, typename Period>
class Unit;


template<typename falseType>
struct is_Unit : std::false_type
{
};


template<typename Dimension, typename Rep, typename Period>
struct is_Unit<Unit<Dimension, Rep, Period>> : public std::true_type
{
};


template<typename toUnit, typename Dimension, typename Rep, typename Period>
constexpr typename std::enable_if<is_Unit<toUnit>::value, toUnit>::type
unit_cast(const Unit<Dimension, Rep, Period>& Obj)
{
  static_assert(std::is_same<typename toUnit::dim, Dimension>::value, "Cannot cast different dimensions.");

  typedef typename Ratio_divide<Period, typename toUnit::period>::type new_Ratio;
  typedef typename std::common_type<typename toUnit::rep, Rep, double>::type common_rep;

  return toUnit(static_cast<typename toUnit::rep>(static_cast<common_rep>(Obj.count())
    * static_cast<common_rep>(new_Ratio::num) / static_cast<common_rep>(new_Ratio::den)));
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== UNIT DEFINITION =========================================================
//=============================================================================
//=============================================================================
//=============================================================================



template<typename _Dimension, typename Rep, typename Period>
class Unit
{
public:
  typedef _Dimension dim;
  typedef Rep rep;
  typedef Period period;

  static_assert(is_Dimension<_Dimension>::value, "First template argument of class stb::Unit sould be a stb::Dimension.");
  static_assert(std::is_floating_point<Rep>::value || std::is_integral<Rep>::value,
  "Second template argument of class stb::Unit should be a floating point or an inegral type.");
  static_assert(is_stb_Ratio<Period>::value, "Third template argument of class stb::Unit should be a stb::Ratio.");


  constexpr Unit() = default;
  Unit(Unit const&) = default;


  template<typename _Rep, typename = typename std::enable_if<std::is_convertible<_Rep, Rep>::value>>
  constexpr Unit(_Rep const& countArg):
  _count(static_cast<Rep>(countArg)),
  _dimension(dimension_str<dim>())
  {
  }


  template<typename __Dimension, typename _Rep, typename _Period>
  constexpr Unit(Unit<__Dimension, _Rep, _Period> const& Obj):
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


  constexpr std::string dimension()
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
    _count *= static_cast<typename std::common_type<Rep, _Rep>::type>(coef);
    return *this;
  }


  template<typename _Rep, typename _Period>
  Unit& operator*=(Unit<Dimension<0,0,0,0,0,0,0>, _Rep, _Period> const& Obj)
  {
    _count *= unit_cast<Unit<Dimension<0,0,0,0,0,0,0>, Rep, Period>>(Obj).count();
    return *this;
  }


  template<typename _Rep>
  Unit& operator/=(_Rep const& coef)
  {
    if(coef >= 0 && coef <= 0)
      throw Unit_exception("Divide by 0.");
    _count /= static_cast<typename std::common_type<Rep, _Rep>::type>(coef);
    return *this;
  }


  template<typename _Rep, typename _Period>
  Unit& operator/=(Unit<Dimension<0,0,0,0,0,0,0>, _Rep, _Period> const& Obj)
  {
    Rep count = unit_cast<Unit<Dimension<0,0,0,0,0,0,0>, Rep, Period>>(Obj).count();
    if(count >= 0 && count <= 0)
      throw Unit_exception("Divide by 0.");
    _count /= count;
    return *this;
  }


  template <typename _Rep>
  typename std::enable_if<! std::is_floating_point<_Rep>::value, Unit&>::type
  operator%=(_Rep const& coef)
  {
    if(coef == 0)
      throw Unit_exception("Divide by 0.");
    _count %= static_cast<typename std::common_type<Rep, _Rep>::type>(coef);
    return *this;
  }


  template<typename _Rep, typename _Period>
  typename std::enable_if<! std::is_floating_point<_Rep>::value, Unit&>::type
  operator%=(Unit<Dimension<0,0,0,0,0,0,0>, _Rep, _Period> const& Obj)
  {
    Rep count = unit_cast<Unit<Dimension<0,0,0,0,0,0,0>, Rep, Period>>(Obj).count();
    if(count == 0)
      throw Unit_exception("Divide by 0.");
    _count %= count;
    return *this;
  }


protected:
  Rep _count;
  const std::string _dimension;
};



//=============================================================================
//=============================================================================
//=============================================================================
//=== UNIT SPECIALIZATION FOR DURATION ========================================
//=============================================================================
//=============================================================================
//=============================================================================

// this specialization is needed to provide converter with std::chrono::duration



template<typename Rep, typename Period>
class Unit<Dimension<0,0,1,0,0,0,0>, Rep, Period>
{

protected:
  typedef Dimension<0,0,1,0,0,0,0> _Dimension;


public:
  typedef _Dimension dim;
  typedef Rep rep;
  typedef Period period;


  static_assert(is_Dimension<_Dimension>::value, "First template argument of class stb::Unit sould be a stb::Dimension.");
  static_assert(std::is_floating_point<Rep>::value || std::is_integral<Rep>::value,
  "Second template argument of class stb::Unit should be a floating point or an inegral type.");
  static_assert(is_stb_Ratio<Period>::value, "Third template argument of class stb::Unit should be a stb::Ratio.");


  constexpr Unit() = default;
  Unit(Unit const&) = default;


  template<typename _Rep, typename = typename std::enable_if<std::is_convertible<_Rep, Rep>::value>>
  constexpr Unit(_Rep const& countArg):
  _count(static_cast<Rep>(countArg)),
  _dimension(dimension_str<dim>())
  {
  }


  template<typename __Dimension, typename _Rep, typename _Period>
  constexpr Unit(Unit<__Dimension, _Rep, _Period> const& Obj):
  Unit(unit_cast<Unit>(Obj).count())
  {
  }


  template<typename _Rep, typename _Period>
  constexpr Unit(std::chrono::duration<_Rep, _Period> const& Obj):
  Unit(Unit<dim, _Rep, typename Ratio_std_to_stb<_Period>::type>(Obj.count()))
  {
  }


  ~Unit() = default;


  Unit& operator=(Unit const& Obj)
  {
    _count = Obj._count;
    return *this;
  }


  template<typename _Rep, typename _Period>
  Unit& operator=(std::chrono::duration<_Rep, _Period> const& Obj)
  {
    _count = Unit(Obj).count();
    return *this;
  }


  template<typename _Rep, typename _Period>
  operator std::chrono::duration<_Rep, _Period>() const
  {
    return std::chrono::duration<_Rep, _Period>
    (unit_cast<Unit<dim, _Rep,
    typename Ratio_std_to_stb<_Period>::type>>(*this).count());
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


  constexpr std::string dimension()
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


  template<typename T>
  Unit& operator*=(T const& coef)
  {
    _count *= static_cast<typename std::common_type<Rep, T>::type>(coef);
    return *this;
  }


  template<typename _Rep, typename _Period>
  Unit& operator*=(Unit<Dimension<0,0,0,0,0,0,0>, _Rep, _Period> const& Obj)
  {
    _count *= unit_cast<Unit<Dimension<0,0,0,0,0,0,0>, Rep, Period>>(Obj).count();
    return *this;
  }


  template<typename _Rep>
  Unit& operator/=(_Rep const& coef)
  {
    if(coef >= 0 && coef <= 0)
      throw Unit_exception("Divide by 0.");
    _count /= static_cast<typename std::common_type<Rep, _Rep>::type>(coef);
    return *this;
  }

  template<typename _Rep, typename _Period>
  Unit& operator/=(Unit<Dimension<0,0,0,0,0,0,0>, _Rep, _Period> const& Obj)
  {
    Rep count = unit_cast<Unit<Dimension<0,0,0,0,0,0,0>, Rep, Period>>(Obj).count();
    if(count >= 0 && count <= 0)
      throw Unit_exception("Divide by 0.");
    _count /= count;
    return *this;
  }


  template <typename _Rep>
  typename std::enable_if<! std::is_floating_point<_Rep>::value, Unit&>::type
  operator%=(_Rep const& coef)
  {
    if(coef == 0)
      throw Unit_exception("Divide by 0.");
    _count %= static_cast<typename std::common_type<Rep, _Rep>::type>(coef);
    return *this;
  }


  template<typename _Rep, typename _Period>
  typename std::enable_if<! std::is_floating_point<_Rep>::value, Unit&>::type
  operator%=(Unit<Dimension<0,0,0,0,0,0,0>, _Rep, _Period> const& Obj)
  {
    Rep count = unit_cast<Unit<Dimension<0,0,0,0,0,0,0>, Rep, Period>>(Obj).count();
    if(count == 0)
      throw Unit_exception("Divide by 0.");
    _count %= count;
    return *this;
  }


protected:
  Rep _count;
  const std::string _dimension;
};



//=============================================================================
//=============================================================================
//=============================================================================
//=== UNIT CAST OVERLOAD FOR UNIT SPECIALIZATION FOR DURATION =================
//=============================================================================
//=============================================================================
//=============================================================================

//the purpose is to make aviable unit_cast between stb::duration and std::chrono::duration



//wrapper for function partial specialization emulation
//allow to replace partial specialization (which doesn't exist for functions) by an overload
template <typename T>
struct partial_specialization_wrapper
{
};


//called if toUnit equals stb::duration
//cast stb::duration to another stb::duration
template <typename toUnit, typename Rep, typename Period>
constexpr Unit<Dimension<0, 0, 1, 0, 0, 0, 0>, typename toUnit::rep, typename toUnit::period>
unit_cast_impl(partial_specialization_wrapper<Unit<Dimension<0, 0, 1, 0, 0, 0, 0>, typename toUnit::rep, typename toUnit::period>>,
Unit<Dimension<0, 0, 1, 0, 0, 0, 0>, Rep, Period> const& Obj)
{
  return unit_cast<toUnit>(Obj);
}


//called if toUnit equals std::chrono::duration
//cast stb::duration to std::chrono::duration
template <typename toUnit, typename Rep, typename Period>
constexpr std::chrono::duration<typename toUnit::rep, typename toUnit::period>
unit_cast_impl(partial_specialization_wrapper<std::chrono::duration<typename toUnit::rep, typename toUnit::period>>,
Unit<Dimension<0, 0, 1, 0, 0, 0, 0>, Rep, Period> const& Obj)
{
  return toUnit(Obj);
}


//cast stb::duration to toUnit
template <typename toUnit, typename Rep, typename Period>
constexpr toUnit unit_cast(Unit<Dimension<0, 0, 1, 0, 0, 0, 0>, Rep, Period> const& Obj)
{
  return unit_cast_impl<toUnit>(partial_specialization_wrapper<toUnit>{}, Obj);
}


//called if toUnit equals stb::duration
//cast std::chrono::duration to stb::duration
template <typename toUnit, typename Rep, typename Period>
constexpr Unit<Dimension<0, 0, 1, 0, 0, 0, 0>, typename toUnit::rep, typename toUnit::period>
unit_cast_impl(partial_specialization_wrapper<Unit<Dimension<0, 0, 1, 0, 0, 0, 0>, typename toUnit::rep, typename toUnit::period>>,
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


//cast stb::duration to toUnit
template <typename toUnit, typename Rep, typename Period>
constexpr toUnit unit_cast(std::chrono::duration<Rep, Period> const& Obj)
{
  return unit_cast_impl<toUnit>(partial_specialization_wrapper<toUnit>{}, Obj);
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== ARITHMERIC OPERATORS WITHOUT DIMENSION CHANGE ===========================
//=============================================================================
//=============================================================================
//=============================================================================



template <typename Dimension, typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Unit<Dimension, Rep1, Period1>, Unit<Dimension, Rep2, Period2>>::type
operator+ (Unit<Dimension, Rep1, Period1> const& Obj1, Unit<Dimension, Rep2, Period2> const& Obj2)
{
  typedef typename std::common_type<Unit<Dimension, Rep1, Period1>, Unit<Dimension, Rep2, Period2>>::type type;
  return type(type(Obj1).count() + type(Obj2).count());
}


template <typename Dimension, typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Unit<Dimension, Rep1, Period1>, Unit<Dimension, Rep2, Period2>>::type
operator- (Unit<Dimension, Rep1, Period1> const& Obj1, Unit<Dimension, Rep2, Period2> const& Obj2)
{
  typedef typename std::common_type<Unit<Dimension, Rep1, Period1>, Unit<Dimension, Rep2, Period2>>::type type;
  return type(type(Obj1).count() - type(Obj2).count());
}


template <typename Dimension, typename Rep, typename Period, typename T>
constexpr Unit<Dimension, typename std::common_type<Rep, typename
std::enable_if<!is_Unit<T>::value, T>::type>::type, Period>
operator* (Unit<Dimension, Rep, Period> const& Obj, T const& coef)
{
  typedef typename std::common_type<Rep, T>::type common;
  typedef Unit<Dimension, common, Period> type;
  return type(type(Obj).count() * static_cast<common>(coef));
}


template <typename Dimension, typename Rep, typename Period, typename T>
constexpr Unit<Dimension, typename std::common_type<Rep, typename
std::enable_if<!is_Unit<T>::value, T>::type>::type, Period>
operator* (T const& coef, Unit<Dimension, Rep, Period> const& Obj)
{
  return Obj * coef;
}


template <typename Dimension, typename Rep, typename Period, typename T>
constexpr Unit<Dimension, typename std::common_type<Rep, typename
std::enable_if<!is_Unit<T>::value, T>::type>::type, Period>
operator/ (Unit<Dimension, Rep, Period> const& Obj, T const& coef)
{
  if(coef >= 0 && coef <= 0)
    throw Unit_exception("Divide by 0.");
  typedef typename std::common_type<Rep, T>::type common;
  typedef Unit<Dimension, common, Period> type;
  return type(type(Obj).count() / static_cast<common>(coef));
}


template <typename Dimension, typename Rep, typename Period, typename T>
constexpr Unit<Dimension, typename std::common_type<Rep, typename
std::enable_if<!is_Unit<T>::value, T>::type>::type, Period>
operator% (Unit<Dimension, Rep, Period> const& Obj, T const& coef)
{
  if(coef >= 0 && coef <= 0)
    throw Unit_exception("Divide by 0.");
  typedef Unit<Dimension, typename std::common_type<Rep, T>::type, Period> type;
  return type(modulo(type(Obj).count(), coef));
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== ARITHMERIC OPERATORS WITH DIMENSION CHANGE ==============================
//=============================================================================
//=============================================================================
//=============================================================================



template <typename Dimension1, typename Rep1, typename Period1,
typename Dimension2, typename Rep2, typename Period2>
constexpr Unit<typename Dimension_multiply<Dimension1, Dimension2>::type,
typename std::common_type<Rep1, Rep2>::type,
typename Ratio_multiply<Period1, Period2>::type>
operator* (Unit<Dimension1, Rep1, Period1> const& Obj1, Unit<Dimension2, Rep2, Period2> const& Obj2)
{
  typedef typename std::common_type<Rep1, Rep2>::type common;
  typedef typename Dimension_multiply<Dimension1, Dimension2>::type newDim;
  typedef typename Ratio_multiply<Period1, Period2>::type newPeriod;
  typedef Unit<newDim, common, newPeriod> type;

  return type(static_cast<common>(Obj1).count() * static_cast<common>(Obj2));
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
constexpr Unit<typename Dimension_divide<Dimension<0,0,0,0,0,0,0>, _Dimension>::type,
typename std::common_type<Rep, typename
std::enable_if<!is_Unit<T>::value, T>::type>::type,
typename Ratio_divide<Ratio<E0, E0>, Period>::type>
operator/ (T const& coef, Unit<_Dimension, Rep, Period> const& Obj)
{
  if(Obj.count() >= 0 && Obj.count() <= 0)
    throw Unit_exception("Divide by 0.");

  typedef typename std::common_type<Rep, T>::type common;
  typedef typename Dimension_divide<Dimension<0,0,0,0,0,0,0>, _Dimension>::type newDim;
  typedef typename Ratio_divide<Ratio<E0, E0>, Period>::type newPeriod;
  typedef Unit<newDim, common, newPeriod> type;

  return type(static_cast<common>(coef) / static_cast<common>(Obj).count());
}


template <typename _Dimension, typename Rep, typename Period, typename T>
constexpr Unit<Dimension<0,0,0,0,0,0,0>, typename std::common_type<Rep, T>::type, Period>
operator% (T const& coef, Unit<_Dimension, Rep, Period> const& Obj)
{
  if(Obj.count() >= 0 && Obj.count() <= 0)
    throw Unit_exception("Divide by 0.");

  typedef Unit<Dimension<0,0,0,0,0,0,0>, typename std::common_type<Rep, T>::type, Period> type;
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
//=== MATHEMATIC FUNCTIONS ====================================================
//=============================================================================
//=============================================================================
//=============================================================================




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



template<typename Dimension, typename Common, typename Period1, typename Period2>
struct Unit_common_type_wrapper
{
private:
  static constexpr double gcd_num = stb::omni::gcd(Period1::num, Period2::num);
  static constexpr double gcd_den = stb::omni::gcd(Period1::den, Period2::den);
  static constexpr double new_den = (Period1::den / gcd_den) * Period2::den;
  typedef typename Common::type common;
  typedef stb::omni::Ratio<gcd_num, new_den> new_Ratio;
public:
  typedef std::__success_type<stb::omni::Unit<Dimension, common, new_Ratio>> type;
};


template<typename Dimension, typename Period1, typename Period2>
struct Unit_common_type_wrapper<Dimension, std::__failure_type, Period1, Period2>
{
public:
  typedef std::__failure_type type;
};


template<typename Dimension1, typename Rep1, typename Period1,
typename Dimension2, typename Rep2, typename Period2>
struct common_type<stb::omni::Unit<Dimension1, Rep1, Period1>, stb::omni::Unit<Dimension2, Rep2, Period2>>
: public Unit_common_type_wrapper<
typename std::enable_if<std::is_same<Dimension1, Dimension2>::value, Dimension1>::type,
typename std::__member_type_wrapper<std::common_type<Rep1, Rep2>>::type,
Period1, Period2>::type
{
};



} //namespace std

#include "units/units.hh"



#endif //OMNIUNIT_HH_
