//Basic_Unit.hh

/*
Copyright (c) 2019, Denis Tosetto All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

  Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.

  Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

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



#ifndef OMNIUNIT_BASIC_UNIT_HH_
#define OMNIUNIT_BASIC_UNIT_HH_


#include "utility.hh"

#include <chrono>
#include <iostream>



namespace omni
{



//=============================================================================
//=============================================================================
//=============================================================================
//=== BASIC UNIT CAST =========================================================
//=============================================================================
//=============================================================================
//=============================================================================

//Basic_Unit represent a unit without handling uncertainties


//forward declaration
//origin is given in official unit (ratio<1, 1>)
template<typename _Dimension, typename Rep, typename Period, double const& Origin>
class Basic_Unit;


template<typename falseType>
struct is_Basic_Unit : std::false_type
{
};


template<typename Dimension, typename Rep, typename Period, double const& Origin>
struct is_Basic_Unit<Basic_Unit<Dimension, Rep, Period, Origin>> : public std::true_type
{
};


template<typename toUnit, typename Dimension, typename Rep, typename Period, double const& Origin,
typename = typename std::enable_if<is_Basic_Unit<toUnit>::value, toUnit>::type>
constexpr toUnit unit_cast(const Basic_Unit<Dimension, Rep, Period, Origin>& Obj)
{
  static_assert(std::is_same<typename toUnit::dim, Dimension>::value, "Cannot cast different dimensions.");

  typedef typename Ratio_over_Ratio<Period, typename toUnit::period>::type new_Ratio;
  typedef typename std::common_type<typename toUnit::rep, Rep>::type common_rep;

  return toUnit(static_cast<typename toUnit::rep>((static_cast<common_rep>(Obj.count())
    * static_cast<common_rep>(new_Ratio::num) / static_cast<common_rep>(new_Ratio::den))
    + static_cast<common_rep>((Origin - toUnit::origin) / toUnit::period::value)));
}


template<typename T, typename Dimension, typename Rep, typename Period, double const& Origin,
typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
constexpr Basic_Unit<Dimension, T, Period, Origin> unit_cast(const Basic_Unit<Dimension, Rep, Period, Origin>& Obj)
{
  return unit_cast<Basic_Unit<Dimension, T, Period, Origin>>(Obj);
}


template<typename R, typename Dimension, typename Rep, typename Period, double const& Origin,
typename = typename std::enable_if<is_stb_Ratio<R>::value, R>::type>
constexpr Basic_Unit<Dimension, Rep, R, Origin> unit_cast(const Basic_Unit<Dimension, Rep, Period, Origin>& Obj)
{
  return unit_cast<Basic_Unit<Dimension, Rep, R, Origin>>(Obj);
}


template<double const& O, typename Dimension, typename Rep, typename Period, double const& Origin>
constexpr Basic_Unit<Dimension, Rep, Period, O> unit_cast(const Basic_Unit<Dimension, Rep, Period, Origin>& Obj)
{
  return unit_cast<Basic_Unit<Dimension, Rep, Period, O>>(Obj);
}


//=============================================================================
//=============================================================================
//=============================================================================
//=== BASIC_UNIT CAST OVERLOAD FOR UNIT<TIME> =================================
//=============================================================================
//=============================================================================
//=============================================================================

//the purpose here is to make available unit_cast between omni::Unit<duration> and std::chrono::duration


//wrapper for function partial specialization emulation
//allow to replace partial specialization (which doesn't exist for functions) with an overload
template <typename T>
struct partial_specialization_emulator
{
};


//called if toUnit equals omniunit::duration
//cast omniunit::duration to another omniunit::duration
template <typename toUnit, typename Rep, typename Period, double const& Origin>
constexpr toUnit unit_cast_impl(
partial_specialization_emulator<Basic_Unit<Dimension<0,0,1,0,0,0,0>, typename toUnit::rep, typename toUnit::period, toUnit::origin>>,
Basic_Unit<Dimension<0,0,1,0,0,0,0>, Rep, Period, Origin> const& Obj)
{
  return unit_cast<toUnit, Dimension<0,0,1,0,0,0,0>>(Obj);
}


//called if toUnit equals std::chrono::duration
//cast omniunit::duration to std::chrono::duration
template <typename toUnit, typename Rep, typename Period, double const& Origin>
constexpr toUnit unit_cast_impl(
partial_specialization_emulator<std::chrono::duration<typename toUnit::rep, typename toUnit::period>>,
Basic_Unit<Dimension<0,0,1,0,0,0,0>, Rep, Period, Origin> const& Obj)
{
  return toUnit(Obj);
}


//cast omniunit::duration to toUnit
template <typename toUnit, typename Rep, typename Period, double const& Origin>
constexpr toUnit unit_cast(Basic_Unit<Dimension<0,0,1,0,0,0,0>, Rep, Period, Origin> const& Obj)
{
  return unit_cast_impl<toUnit>(partial_specialization_emulator<toUnit>{}, Obj);
}


//called if toUnit equals omniunit::duration
//cast std::chrono::duration to omniunit::duration
template <typename toUnit, typename Rep, typename Period>
constexpr toUnit unit_cast_impl(
partial_specialization_emulator<Basic_Unit<Dimension<0,0,1,0,0,0,0>, typename toUnit::rep, typename toUnit::period, toUnit::origin>>,
std::chrono::duration<Rep, Period> const& Obj)
{
  return toUnit(Obj);
}


//called if toUnit equals std::chrono::duration
//cast std::chrono::duration to another std::chrono::duration
template <typename toUnit, typename Rep, typename Period>
constexpr toUnit unit_cast_impl(
partial_specialization_emulator<std::chrono::duration<typename toUnit::rep, typename toUnit::period>>,
std::chrono::duration<Rep, Period> const& Obj)
{
  return std::chrono::duration_cast<toUnit>(Obj);
}


//cast std::chrono::duration to toUnit
template <typename toUnit, typename Rep, typename Period>
constexpr toUnit unit_cast(std::chrono::duration<Rep, Period> const& Obj)
{
  return unit_cast_impl<toUnit>(partial_specialization_emulator<toUnit>{}, Obj);
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== BASIC_UNIT DEFINITION ===================================================
//=============================================================================
//=============================================================================
//=============================================================================

//Basic_Unit represents a unit without handling uncertainties



template<typename _Dimension, typename Rep, typename Period, double const& Origin>
class Basic_Unit
{
public:
  typedef _Dimension dim;
  typedef Rep rep;
  typedef Period period;
  inline static constexpr double origin = Origin;

  static_assert(is_Dimension<_Dimension>::value, "First template argument sould be a dimension.");
  static_assert(std::is_arithmetic<Rep>::value, "Second template argument should be an arithmetic type.");
  static_assert(is_stb_Ratio<Period>::value, "Third template argument should be an OmniUnit ratio.");

  constexpr Basic_Unit():
  _count(static_cast<Rep>(0))
  {
  }


  template<typename _Rep, typename = typename std::enable_if<std::is_arithmetic<_Rep>::value, _Rep>::type>
  constexpr Basic_Unit(_Rep const& countArg):
  _count(static_cast<Rep>(countArg))
  {
  }


  template<typename _Rep, typename _Period, double const& _Origin>
  constexpr Basic_Unit(Basic_Unit<dim, _Rep, _Period, _Origin> const& Obj):
  Basic_Unit(unit_cast<Basic_Unit, dim>(Obj).count())
  {
  }


  template<typename _Rep, typename _Period> //std::chrono::duration has no Origin parameter
  constexpr Basic_Unit(std::chrono::duration<_Rep, _Period> const& Obj):
  Basic_Unit(Basic_Unit<dim, _Rep, typename Ratio_std_to_omni<_Period>::type, Origin>(Obj.count()))
  {
    static_assert(std::is_same<dim, Dimension<0,0,1,0,0,0,0>>::value, "Only a duration is constructible with an std::chrono::duration");
  }


  ~Basic_Unit() = default;


  template<typename _Rep, typename _Period, double const& _Origin>
  constexpr Basic_Unit& operator=(Basic_Unit<dim, _Rep, _Period, _Origin> const& Obj)
  {
    _count = Basic_Unit(Obj)._count;
    return *this;
  }


  template<typename _Rep, typename _Period> //std::chrono::duration has no Origin parameter
  constexpr Basic_Unit& operator=(std::chrono::duration<_Rep, _Period> const& Obj)
  {
    static_assert(std::is_same<dim, Dimension<0,0,1,0,0,0,0>>::value, "Only a duration is assignable with an std::chrono::duration");
    _count = Basic_Unit(Obj)._count;
    return *this;
  }


  template<typename _Rep, typename _Period> //transform a stb::omni::duration into a std::chrono::duration
  constexpr operator std::chrono::duration<_Rep, _Period>() const
  {
    static_assert(std::is_same<dim, Dimension<0,0,1,0,0,0,0>>::value, "Only a duration is convertible to an std::chrono::duration");
    return std::chrono::duration<_Rep, _Period>(Basic_Unit<dim, _Rep, typename Ratio_std_to_omni<_Period>::type, omni::zero>(*this).count());
  }

  static constexpr Basic_Unit zero()
  {
    return Basic_Unit(0);
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


  constexpr std::string dimension() const //A MODIFIER, RETOURNER UNE CHAR*
  {
    return dimension_str<dim>();
  }


  Basic_Unit ceil(unsigned decimal = 1)
  {
    _count = static_cast<Rep>(std::ceil(_count * decimal)) / static_cast<Rep>(decimal);
  }


  Basic_Unit floor(unsigned decimal = 1)
  {
    _count = static_cast<Rep>(std::floor(_count * decimal)) / static_cast<Rep>(decimal);
  }


  Basic_Unit round(unsigned decimal = 1)
  {
    _count = static_cast<Rep>(std::round(_count * decimal)) / static_cast<Rep>(decimal);
  }


  Basic_Unit trunc(unsigned decimal = 1)
  {
    _count = static_cast<Rep>(std::trunc(_count * decimal)) / static_cast<Rep>(decimal);
  }


  Basic_Unit& operator++()
  {
    ++_count;
    return *this;
  }


  Basic_Unit operator++(int)
  {
    return Basic_Unit(_count++);
  }


  Basic_Unit& operator--()
  {
    --_count;
    return *this;
  }


  Basic_Unit operator--(int)
  {
    return Basic_Unit(_count--);
  }


  // Origin must be deduced not to convert it
  template <typename __Dimension, typename _Rep, typename _Period, double const& _origin>
  Basic_Unit& operator+=(Basic_Unit<__Dimension, _Rep, _Period, _origin> const& Obj)
  {
    static_assert(std::is_same<__Dimension, _Dimension>::value, "Cannot sum values with different dimension.");
    _count += Basic_Unit<__Dimension, Rep, Period, _origin>(Obj).count();
    return *this;
  }

  // Origin must be deduced not to convert it
  template <typename __Dimension, typename _Rep, typename _Period, double const& _origin>
  Basic_Unit& operator-=(Basic_Unit<__Dimension, _Rep, _Period, _origin> const& Obj)
  {
    static_assert(std::is_same<__Dimension, _Dimension>::value, "Cannot subtract values with different dimension.");
    _count -= Basic_Unit<__Dimension, Rep, Period, _origin>(Obj).count();
    return *this;
  }


  template<typename _Rep>
  Basic_Unit& operator*=(_Rep const& coef)
  {
    static_assert(std::is_arithmetic<_Rep>::value, "Operands must be a unit and an arithmetic.");
    if(OMNI_TRUE_ZERO)
    {
      *this += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    typedef typename std::common_type<Rep, _Rep>::type common;
    _count = static_cast<Rep>(static_cast<common>(_count) * static_cast<common>(coef));

    if(OMNI_TRUE_ZERO)
    {
      *this -= Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    return *this;
  }


  template<typename _Rep, typename _Period, double const& _Origin>
  Basic_Unit& operator*=(Basic_Unit<Dimension<0,0,0,0,0,0,0>, _Rep, _Period, _Origin> Obj)
  {
    if(OMNI_TRUE_ZERO)
    {
      *this += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
      Obj += Basic_Unit<Dimension<0,0,0,0,0,0,0>, _Rep, base, _Origin>(_Origin);
    }

    typedef typename std::common_type<Rep, _Rep>::type common;
    Basic_Unit<Dimension<0,0,0,0,0,0,0>, common, base, _Origin> newObj(Obj); //SEARCH NOT TO CONVERT TO BASE PLS
    _count = static_cast<Rep>(static_cast<common>(_count) * static_cast<common>(newObj.count()));

    if(OMNI_TRUE_ZERO)
    {
      *this -= Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    return *this;
  }


  template<typename _Rep>
  Basic_Unit& operator/=(_Rep const& coef)
  {
    static_assert(std::is_arithmetic<_Rep>::value, "Operands must be a unit and an arithmetic.");

    if(OMNI_TRUE_ZERO)
    {
      *this += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    typedef typename std::common_type<Rep, _Rep>::type common;
    _count = static_cast<Rep>(static_cast<common>(_count) / static_cast<common>(coef));

    if(OMNI_TRUE_ZERO)
    {
      *this -= Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    return *this;
  }


  template<typename _Rep, typename _Period, double const& _Origin>
  Basic_Unit& operator/=(Basic_Unit<Dimension<0,0,0,0,0,0,0>, _Rep, _Period, _Origin> Obj)
  {
    if(OMNI_TRUE_ZERO)
    {
      *this += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
      Obj += Basic_Unit<Dimension<0,0,0,0,0,0,0>, _Rep, base, _Origin>(_Origin);
    }

    typedef typename std::common_type<Rep, _Rep>::type common;
    Basic_Unit<Dimension<0,0,0,0,0,0,0>, common, base, _Origin> newObj(Obj); //SEARCH NOT TO CONVERT TO BASE PLS
    _count = static_cast<Rep>(static_cast<common>(_count) / static_cast<common>(newObj.count()));

    if(OMNI_TRUE_ZERO)
    {
      *this -= Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    return *this;
  }


  template <typename _Rep>
  Basic_Unit& operator%=(_Rep const& coef)
  {
    static_assert(std::is_arithmetic<_Rep>::value, "Operands must be a unit and an arithmetic.");

    if(OMNI_TRUE_ZERO)
    {
      *this += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    _count = static_cast<Rep>(modulo(_count, coef));

    if(OMNI_TRUE_ZERO)
    {
      *this -= Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    return *this;
  }


  template<typename __Dimension, typename _Rep, typename _Period, double const& _Origin>
  Basic_Unit& operator%=(Basic_Unit<__Dimension, _Rep, _Period, _Origin> Obj)
  {
    if(OMNI_TRUE_ZERO)
    {
      *this += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
      Obj += Basic_Unit<__Dimension, _Rep, base, _Origin>(_Origin);
    }

    Basic_Unit<__Dimension, _Rep, base, _Origin> newObj(Obj); //SEARCH NOT TO CONVERT TO BASE PLS
    _count = static_cast<Rep>(modulo(_count, newObj.count()));

    if(OMNI_TRUE_ZERO)
    {
      *this -= Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
    }

    return *this;
  }


private:
  Rep _count;
};



//=============================================================================
//=============================================================================
//=============================================================================
//=== ARITHMETIC OPERATORS WITHOUT DIMENSION CHANGE ===========================
//=============================================================================
//=============================================================================
//=============================================================================


template<typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto operator-(Basic_Unit<_Dimension, Rep, Period, Origin> const& Obj)
{
  return Basic_Unit<_Dimension, Rep, Period, Origin>(-Obj.count());
}


template <typename Dimension1, typename Rep1, typename Period1, double const& Origin1,
          typename Dimension2, typename Rep2, typename Period2, double const& Origin2>
constexpr auto operator+ (Basic_Unit<Dimension1, Rep1, Period1, Origin1> const& Obj1, Basic_Unit<Dimension2, Rep2, Period2, Origin2> const& Obj2)
{
  static_assert(std::is_same<Dimension1, Dimension2>::value, "Cannot sum values with different dimension.");
  typedef typename std::common_type<Basic_Unit<Dimension1, Rep1, Period1, Origin1>, Basic_Unit<Dimension2, Rep2, Period2, Origin2>>::type type;
  return type(type(Obj1).count() + type(Obj2).count());
}


template <typename Dimension1, typename Rep1, typename Period1, double const& Origin1,
          typename Dimension2, typename Rep2, typename Period2, double const& Origin2>
constexpr auto operator- (Basic_Unit<Dimension1, Rep1, Period1, Origin1> const& Obj1, Basic_Unit<Dimension2, Rep2, Period2, Origin2> const& Obj2)
{
  static_assert(std::is_same<Dimension1, Dimension2>::value, "Cannot subtract values with different dimension.");
  typedef typename std::common_type<Basic_Unit<Dimension1, Rep1, Period1, Origin1>, Basic_Unit<Dimension2, Rep2, Period2, Origin2>>::type type;
  return type(type(Obj1).count() - type(Obj2).count());
}


template <typename Dimension, typename Rep, typename Period, double const& Origin, typename T>
constexpr auto operator* (Basic_Unit<Dimension, Rep, Period, Origin> Obj, T const& coef)
{
  static_assert(std::is_arithmetic<T>::value, "Operands must be a unit and an arithmetic.");
  return Obj *= coef;
}


template <typename Dimension, typename Rep, typename Period, double const& Origin, typename T>
constexpr auto operator* (T const& coef, Basic_Unit<Dimension, Rep, Period, Origin> const& Obj)
{
  static_assert(std::is_arithmetic<T>::value, "Operands must be an arithmetic and a unit.");
  return Obj * coef;
}


template <typename Dimension, typename Rep, typename Period, double const& Origin, typename T>
constexpr auto operator/ (Basic_Unit<Dimension, Rep, Period, Origin> Obj, T const& coef)
{
  static_assert(std::is_arithmetic<T>::value, "Operands must be a unit and an arithmetic.");
  return Obj /= coef;
}


template <typename Dimension1, typename Rep1, typename Period1, double const& Origin1,
          typename Dimension2, typename Rep2, typename Period2, double const& Origin2>
constexpr auto operator% (Basic_Unit<Dimension1, Rep1, Period1, Origin1> Obj1, Basic_Unit<Dimension2, Rep2, Period2, Origin2> const& Obj2)
{
  return Obj1 %= Obj2;
}


template <typename Dimension, typename Rep, typename Period, double const& Origin, typename T>
constexpr auto operator% (Basic_Unit<Dimension, Rep, Period, Origin> Obj, T coef)
{
  static_assert(std::is_arithmetic<T>::value, "Operands must be a unit and an arithmetic.");
  return Obj %= coef;
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin, typename T>
constexpr auto operator% (T const& coef, Basic_Unit<_Dimension, Rep, Period, Origin> const& Obj)
{
  static_assert(std::is_arithmetic<T>::value, "Operands must be a unit and an arithmetic.");

  return (Basic_Unit<Dimension<0,0,0,0,0,0,0>, T, base, zero>(coef) %= Obj).count();
}


//=============================================================================
//=============================================================================
//=============================================================================
//=== ARITHMERIC OPERATORS WITH DIMENSION CHANGE ==============================
//=============================================================================
//=============================================================================
//=============================================================================



template <typename Dimension1, typename Rep1, typename Period1, double const& Origin1,
          typename Dimension2, typename Rep2, typename Period2, double const& Origin2>
constexpr auto operator* (Basic_Unit<Dimension1, Rep1, Period1, Origin1> Obj1, Basic_Unit<Dimension2, Rep2, Period2, Origin2> Obj2)
{
  if(OMNI_TRUE_ZERO)
  {
    Obj1 += Basic_Unit<Dimension1, Rep1, base, Origin1>(Origin1);
    Obj2 += Basic_Unit<Dimension2, Rep2, base, Origin2>(Origin2);
  }

  typedef typename std::common_type<Rep1, Rep2>::type common;
  typedef typename Dimension_multiply<Dimension1, Dimension2>::type newDim;
  typedef typename Ratio_times_Ratio<Period1, Period2>::type newPeriod;
  typedef Basic_Unit<newDim, common, newPeriod, origin_product<Origin1, Origin2>::value> type;

  type toReturn(static_cast<common>(Obj1.count()) * static_cast<common>(Obj2.count()));

  return toReturn;
}


template <typename Dimension1, typename Rep1, typename Period1, double const& Origin1,
          typename Dimension2, typename Rep2, typename Period2, double const& Origin2>
constexpr auto operator/ (Basic_Unit<Dimension1, Rep1, Period1, Origin1> Obj1, Basic_Unit<Dimension2, Rep2, Period2, Origin2> Obj2)
{
  if(OMNI_TRUE_ZERO)
  {
    Obj1 += Basic_Unit<Dimension1, Rep1, base, Origin1>(Origin1);
    Obj2 += Basic_Unit<Dimension2, Rep2, base, Origin2>(Origin2);
  }

  typedef typename std::common_type<Rep1, Rep2>::type common;
  typedef typename Dimension_divide<Dimension1, Dimension2>::type newDim;
  typedef typename Ratio_over_Ratio<Period1, Period2>::type newPeriod;
  typedef Basic_Unit<newDim, common, newPeriod, origin_division<Origin1, Origin2>::value> type;

  return type(static_cast<common>(Obj1.count()) / static_cast<common>(Obj2.count()));
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin, typename T>
constexpr auto operator/ (T const& coef, Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_arithmetic<T>::value, "Operands must be a unit and an arithmetic.");
  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  typedef typename std::common_type<Rep, T>::type common;
  typedef typename Dimension_divide<Dimension<0,0,0,0,0,0,0>, _Dimension>::type newDim;
  typedef typename Ratio_over_Ratio<Ratio<E0, E0>, Period>::type newPeriod;
  typedef Basic_Unit<newDim, common, newPeriod, origin_division<zero, Origin>::value> type;

  return type(static_cast<common>(coef) / static_cast<common>(Obj.count()));
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== COMPARISON OPERATORS ====================================================
//=============================================================================
//=============================================================================
//=============================================================================



template <typename Dimension1, typename Rep1, typename Period1, double const& Origin1,
          typename Rep2, typename Period2, typename Dimension2, double const& Origin2>
constexpr bool operator==(Basic_Unit<Dimension1, Rep1, Period1, Origin1> const& Obj1,
Basic_Unit<Dimension2, Rep2, Period2, Origin2> const& Obj2)
{
  static_assert(std::is_same<Dimension1, Dimension2>::value,
  "Cannot compare different dimensions.");

  typedef typename std::common_type<Basic_Unit<Dimension1, Rep1, Period1, Origin1>,
  Basic_Unit<Dimension2, Rep2, Period2, Origin2>>::type type;
  return (type(Obj1).count() - type(Obj2).count()) <= Epsilon<typename type::rep>::value;
}


template <typename Dimension1, typename Rep1, typename Period1, double const& Origin1,
          typename Rep2, typename Period2, typename Dimension2, double const& Origin2>
constexpr bool operator!=(Basic_Unit<Dimension1, Rep1, Period1, Origin1> const& Obj1,
Basic_Unit<Dimension2, Rep2, Period2, Origin2> const& Obj2)
{
  static_assert(std::is_same<Dimension1, Dimension2>::value,
  "Cannot compare different dimensions.");

  return !(Obj1 == Obj2);
}


template <typename Dimension1, typename Rep1, typename Period1, double const& Origin1,
          typename Rep2, typename Period2, typename Dimension2, double const& Origin2>
constexpr bool operator<(Basic_Unit<Dimension1, Rep1, Period1, Origin1> const& Obj1,
Basic_Unit<Dimension2, Rep2, Period2, Origin2> const& Obj2)
{
  static_assert(std::is_same<Dimension1, Dimension2>::value,
  "Cannot compare different dimensions.");

  typedef typename std::common_type<Basic_Unit<Dimension1, Rep1, Period1, Origin1>,
  Basic_Unit<Dimension2, Rep2, Period2, Origin2>>::type type;
  return type(Obj1).count() < type(Obj2).count();
}


template <typename Dimension1, typename Rep1, typename Period1, double const& Origin1,
          typename Rep2, typename Period2, typename Dimension2, double const& Origin2>
constexpr bool operator<=(Basic_Unit<Dimension1, Rep1, Period1, Origin1> const& Obj1,
Basic_Unit<Dimension2, Rep2, Period2, Origin2> const& Obj2)
{
  static_assert(std::is_same<Dimension1, Dimension2>::value,
  "Cannot compare different dimensions.");

  return !(Obj2 < Obj1);
}


template <typename Dimension1, typename Rep1, typename Period1, double const& Origin1,
          typename Rep2, typename Period2, typename Dimension2, double const& Origin2>
constexpr bool operator>(Basic_Unit<Dimension1, Rep1, Period1, Origin1> const& Obj1,
Basic_Unit<Dimension2, Rep2, Period2, Origin2> const& Obj2)
{
  static_assert(std::is_same<Dimension1, Dimension2>::value,
  "Cannot compare different dimensions.");

  return Obj2 < Obj1;
}


template <typename Dimension1, typename Rep1, typename Period1, double const& Origin1,
          typename Rep2, typename Period2, typename Dimension2, double const& Origin2>
constexpr bool operator>=(Basic_Unit<Dimension1, Rep1, Period1, Origin1> const& Obj1,
Basic_Unit<Dimension2, Rep2, Period2, Origin2> const& Obj2)
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



template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto exp(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "exp parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return std::exp(newObj.count());
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto exp(Basic_Unit<_Dimension, Rep, Period, Origin> Obj, float basis)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "exp parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return std::exp(static_cast<Rep>(Obj.count() * std::log(basis)));
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto log(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "ln parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return std::log(Obj.count());
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto log(Basic_Unit<_Dimension, Rep, Period, Origin> Obj, double basis)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "ln parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return log(Obj) / std::log(basis);
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== POWER FUNCTIONS =========================================================
//=============================================================================
//=============================================================================
//=============================================================================



template <int exponent = 2, typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto pow(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  typedef Basic_Unit<typename Dimension_power<_Dimension, exponent>::type, Rep, typename Ratio_power<Period, exponent>::type, origin_power<Origin, exponent>::value> type;
  return type(std::pow(Obj.count(), exponent));
}


template <int basis = 2, typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto nroot(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(basis != 0, "Basis must not be 0.");
  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  typedef Basic_Unit<typename Dimension_root<_Dimension, basis>::type, Rep, typename Ratio_root<Period, basis>::type, origin_root<Origin, basis>::value> type;
  return type(std::pow(Obj.count(), 1./basis));
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto sqrt(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  return nroot(Obj);
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== TRIGONOMETRIC FUNCTIONS =================================================
//=============================================================================
//=============================================================================
//=============================================================================


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto cos(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return std::cos(newObj.count());
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto sin(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return std::sin(newObj.count());
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto tan(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return std::tan(newObj.count());
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto sec(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return 1./cos(Obj);
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto csc(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return 1./sin(Obj);
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto cot(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return 1./tan(Obj);
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== REVERSE TRIGONOMETRIC FUNCTIONS =========================================
//=============================================================================
//=============================================================================
//=============================================================================



template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto acos(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return std::acos(newObj.count());
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto asin(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return std::asin(newObj.count());
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto atan(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return std::atan(newObj.count());
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto asec(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return acos(1./newObj);
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto acsc(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return asin(1./newObj);
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto acot(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);

  return atan(1./newObj);
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== HYPERBOLIC FUNCTIONS ===================================================
//=============================================================================
//=============================================================================
//=============================================================================



template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto cosh(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return std::cosh(newObj.count());
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto sinh(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return std::sinh(newObj.count());
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto tanh(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return std::tanh(newObj.count());
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto sech(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return 1./cosh(Obj);
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto csch(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return 1./sinh(Obj);
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto coth(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return 1./tanh(Obj);
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== REVERSE HYPERBOLIC FUNCTIONS ============================================
//=============================================================================
//=============================================================================
//=============================================================================



template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto acosh(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return std::acosh(newObj.count());
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto asinh(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return std::asinh(newObj.count());
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto atanh(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return std::atanh(newObj.count());
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto asech(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return acosh(1./newObj);
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto acsch(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);
  return asinh(1./newObj);
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto acoth(Basic_Unit<_Dimension, Rep, Period, Origin> Obj)
{
  static_assert(std::is_same<_Dimension, Dimension<0,0,0,0,0,0,0>>::value, "cos parameter must be dimensionless.");

  if(OMNI_TRUE_ZERO)
  {
    Obj += Basic_Unit<_Dimension, Rep, base, Origin>(Origin);
  }

  Basic_Unit<_Dimension, Rep, base, Origin> newObj(Obj);

  return atanh(1./newObj);
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== ROUNDING FUNCTIONS ======================================================
//=============================================================================
//=============================================================================
//=============================================================================



template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto ceil(Basic_Unit<_Dimension, Rep, Period, Origin> Obj, unsigned decimal = 1)
{
  return Obj.ceil(decimal);
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto floor(Basic_Unit<_Dimension, Rep, Period, Origin> Obj, unsigned decimal = 1)
{
  return Obj.floor(decimal);
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto round(Basic_Unit<_Dimension, Rep, Period, Origin> Obj, unsigned decimal = 1)
{
  return Obj.round(decimal);
}


template <typename _Dimension, typename Rep, typename Period, double const& Origin>
constexpr auto trunc(Basic_Unit<_Dimension, Rep, Period, Origin> Obj, unsigned decimal = 1)
{
  return Obj.trunc(decimal);
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== STREAM OPERATOR =========================================================
//=============================================================================
//=============================================================================
//=============================================================================



template <typename left_operande_t, typename Dimension, typename Rep, typename Period, double const& Origin>
left_operande_t& operator<<(left_operande_t& left_operande, Basic_Unit<Dimension, Rep, Period, Origin> const& Obj)
{
  left_operande << Obj.count();
  return left_operande;
}



} //namespace omni



//=============================================================================
//=============================================================================
//=============================================================================
//=== COMMON_TYPE FOR BASIC_UNIT ==============================================
//=============================================================================
//=============================================================================
//=============================================================================



namespace std _GLIBCXX_VISIBILITY(default)
{



template<typename Dimension1, typename Rep1, typename Period1, double const& Origin1,
         typename Dimension2, typename Rep2, typename Period2, double const& Origin2>
struct common_type<omni::Basic_Unit<Dimension1, Rep1, Period1, Origin1>, omni::Basic_Unit<Dimension2, Rep2, Period2, Origin2>>
{
private:
  static_assert(std::is_same<Dimension1, Dimension2>::value, "Cannot get a common unit between two units that have different dimension.");

  //the common period is the nearest of 1/1 in order of magnitude
  //should it be the average in log scale ? or the greater one ?
  typedef typename std::conditional< (std::abs(std::log10(Period1::value)) < std::abs(std::log10(Period2::value))),
  Period1, Period2>::type new_Ratio;

  typedef typename std::common_type<Rep1, Rep2>::type common;

  //if origins are differents, then the common origin is 0...
  static constexpr double origin = (std::abs(Origin1 - Origin2) <= omni::InternEpsilon<double>::value) ? Origin1 : omni::zero;

public:
  typedef omni::Basic_Unit<Dimension1, common, new_Ratio, origin> type;
};



} //namespace std



#endif //OMNIUNIT_BASIC_UNIT_HH_