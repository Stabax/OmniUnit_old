//Unit.hpp

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

#ifndef UNIT_HH_
#define UNIT_HH_

#include <string>
#include <type_traits>
#include <chrono>

#include "Ratio.hh"
#include "exception.hh"
#include "Dimension.hh"


namespace stb
{
//=============================================================================
//=============================================================================
// UNIT CAST ==================================================================
//=============================================================================
//=============================================================================



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
// UNIT DEFINITION ============================================================
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
// UNIT SPECIALIZATION FOR DURATION ===========================================
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
// UNIT_CAST OVERLOAD FOR DURATION SPECIALIZATION =============================
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
// ARITHMERIC OPERATORS WITHOUT DIMENSION CHANGE ==============================
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
// ARITHMERIC OPERATORS WITH DIMENSION CHANGE =================================
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
// COMPARISON OPERATORS =======================================================
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



} // namespace stb





//=============================================================================
//=============================================================================
// COMMON_TYPE ================================================================
//=============================================================================
//=============================================================================





namespace std _GLIBCXX_VISIBILITY(default)
{



template<typename Dimension, typename Common, typename Period1, typename Period2>
struct Unit_common_type_wrapper
{
private:
  static constexpr double gcd_num = stb::gcd(Period1::num, Period2::num);
  static constexpr double gcd_den = stb::gcd(Period1::den, Period2::den);
  static constexpr double new_den = (Period1::den / gcd_den) * Period2::den;
  typedef typename Common::type common;
  typedef stb::Ratio<gcd_num, new_den> new_Ratio;
public:
  typedef std::__success_type<stb::Unit<Dimension, common, new_Ratio>> type;
};


template<typename Dimension, typename Period1, typename Period2>
struct Unit_common_type_wrapper<Dimension, std::__failure_type, Period1, Period2>
{
public:
  typedef std::__failure_type type;
};


template<typename Dimension1, typename Rep1, typename Period1,
typename Dimension2, typename Rep2, typename Period2>
struct common_type<stb::Unit<Dimension1, Rep1, Period1>, stb::Unit<Dimension2, Rep2, Period2>>
: public Unit_common_type_wrapper<
typename std::enable_if<std::is_same<Dimension1, Dimension2>::value, Dimension1>::type,
typename std::__member_type_wrapper<std::common_type<Rep1, Rep2>>::type,
Period1, Period2>::type
{
};



}//namespace std



#endif //UNIT_HH_
