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
#include "ratio.hh"
#include "exception.hh"


namespace stb
{



//=============================================================================
//=============================================================================
// DIMENSION DEFINITION =======================================================
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


  static constexpr std::string dimension()
  {
    std::string dim = "";

    if(length != 0)
      dim += ("[L" + std::to_string(length) + "]");
    if(mass != 0)
      dim += ("[M" + std::to_string(mass) + "]");
    if(time != 0)
      dim += ("[Tm" + std::to_string(time) + "]");
    if(current != 0)
      dim += ("[I" + std::to_string(current) + "]");
    if(temperature != 0)
      dim += ("[Tp" + std::to_string(temperature) + "]");
    if(quantity != 0)
      dim += ("[N" + std::to_string(quantity) + "]");
    if(luminosity != 0)
      dim += ("[J" + std::to_string(luminosity) + "]");
    if(dim.length() == 0)
      dim = "[/]";

    return dim;
  }
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
struct areSameDimension
{
  static constexpr bool value =
  dim1::length == dim2::length &&
  dim1::mass == dim2::mass &&
  dim1::time == dim2::time &&
  dim1::current == dim2::current &&
  dim1::temperature == dim2::temperature &&
  dim1::quantity == dim2::quantity &&
  dim1::luminosity == dim2::luminosity ? true : false;
};





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
Unit_cast(const Unit<Dimension, Rep, Period>& Obj)
{
  static_assert(areSameDimension<typename toUnit::dimension, Dimension>::value, "Cannot cast different dimensions.");

  typedef typename toUnit::period period;
  typedef typename toUnit::rep rep;
  typedef typename ratio_divide<Period, period>::type new_ratio;
  typedef typename std::common_type<rep, Rep, double>::type common_rep;

  return toUnit(static_cast<rep>(static_cast<common_rep>(Obj.count())
    * static_cast<common_rep>(new_ratio::num) / static_cast<common_rep>(new_ratio::den)));
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
  static_assert(is_ratio<Period>::value, "Third template argument of class stb::Unit should be a std::ratio.");


  constexpr Unit() = default;
  Unit(Unit const&) = default;


  template<typename _Rep, typename = typename std::enable_if<std::is_convertible<_Rep, Rep>::value>>
  constexpr Unit(_Rep const& countArg):
  _count(static_cast<Rep>(countArg)),
  _dimension(Dimension<_Dimension::length, _Dimension::mass,
  _Dimension::time, _Dimension::current, _Dimension::temperature,
  _Dimension::quantity, _Dimension::luminosity>::dimension())
  {
  }


  template<typename __Dimension, typename _Rep, typename _Period>
  constexpr Unit(Unit<__Dimension, _Rep, _Period> const& Obj):
  Unit(Unit_cast<Unit>(Obj).count())
  {
  }


  ~Unit() = default;
  Unit& operator=(Unit const&) = default;


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
    return dim::dimension();
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
    _count *= Unit_cast<Unit<Dimension<0,0,0,0,0,0,0>, Rep, Period>>(Obj).count();
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
    Rep count = Unit_cast<Unit<Dimension<0,0,0,0,0,0,0>, Rep, Period>>(Obj).count();
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
    Rep count = Unit_cast<Unit<Dimension<0,0,0,0,0,0,0>, Rep, Period>>(Obj).count();
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
  typedef _Dimension dimension;
  typedef Rep rep;
  typedef Period period;


  static_assert(is_Dimension<_Dimension>::value, "First template argument of class stb::Unit sould be a stb::Dimension.");
  static_assert(std::is_floating_point<Rep>::value || std::is_integral<Rep>::value,
  "Second template argument of class stb::Unit should be a floating point or an inegral type.");
  static_assert(is_ratio<Period>::value, "Third template argument of class stb::Unit should be a std::ratio.");


  constexpr Unit() = default;
  Unit(Unit const&) = default;


  template<typename _Rep, typename = typename std::enable_if<std::is_convertible<_Rep, Rep>::value>>
  constexpr Unit(_Rep const& countArg):
  _count(static_cast<Rep>(countArg)),
  _dimension(Dimension<_Dimension::length, _Dimension::mass,
  _Dimension::time, _Dimension::current, _Dimension::temperature,
  _Dimension::quantity, _Dimension::luminosity>::dimension())
  {
  }


  template<typename __Dimension, typename _Rep, typename _Period>
  constexpr Unit(Unit<__Dimension, _Rep, _Period> const& Obj):
  Unit(Unit_cast<Unit>(Obj).count())
  {
  }


  template<typename _Rep, typename _Period>
  constexpr Unit(std::chrono::duration<_Rep, _Period> const& Obj):
  Unit(Unit_cast<Unit>(Obj).count())
  {
  }


  ~Unit() = default;
  Unit& operator=(Unit const&) = default;


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
    _count *= Unit_cast<Unit<Dimension<0,0,0,0,0,0,0>, Rep, Period>>(Obj).count();
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
    Rep count = Unit_cast<Unit<Dimension<0,0,0,0,0,0,0>, Rep, Period>>(Obj).count();
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
    Rep count = Unit_cast<Unit<Dimension<0,0,0,0,0,0,0>, Rep, Period>>(Obj).count();
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
// OPERATORS ==================================================================
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


template <typename Dimension, typename Rep, typename Period, typename coefType>
constexpr Unit<Dimension, typename std::common_type<Rep, typename
std::enable_if<!is_Unit<coefType>::value, coefType>::type>::type, Period>
operator* (Unit<Dimension, Rep, Period> const& Obj, coefType const& coef)
{
  typedef typename std::common_type<Rep, coefType>::type common;
  typedef Unit<Dimension, common, Period> type;
  return type(type(Obj).count() * coef);
}


template <typename Dimension, typename Rep, typename Period, typename coefType>
constexpr Unit<Dimension, typename std::common_type<Rep, typename
std::enable_if<!is_Unit<coefType>::value, coefType>::type>::type, Period>
operator* (coefType const& coef, Unit<Dimension, Rep, Period> const& Obj)
{
  return Obj * coef;
}


template <typename Dimension, typename Rep, typename Period, typename coefType>
constexpr Unit<Dimension, typename std::common_type<Rep, typename
std::enable_if<!is_Unit<coefType>::value, coefType>::type>::type, Period>
operator/ (Unit<Dimension, Rep, Period> const& Obj, coefType const& coef)
{
  if(coef >= 0 && coef <= 0)
    throw Unit_exception("Divide by 0.");
  typedef typename std::common_type<Rep, coefType>::type common;
  typedef Unit<Dimension, common, Period> type;
  return type(type(Obj).count() / coef);
}

/*
template <typename Dimension, typename Rep, typename Period, typename coefType>
constexpr Unit<Dimension, typename std::common_type<Rep, typename
std::enable_if<!is_Unit<coefType>::value, coefType>::type>::type, Period>
operator% (Unit<Dimension, Rep, Period> const& Obj, coefType const& coef)
{
  if(coef >= 0 && coef <= 0)
    throw Unit_exception("Divide by 0.");
  typedef Unit<Dimension, typename std::common_type<Rep, coefType>::type, Period> type;
  return type(type(Obj).count() % coef);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Unit<Rep1,Period1>, Unit<Rep2,Period2>>::type
operator% (Unit<Rep1,Period1> const& Obj1, Unit<Rep2,Period2> const& Obj2)
{
  if(Obj2.count() == 0)
    throw Unit_exception("Divide by 0.");
  typedef typename std::common_type<Unit<Rep1,Period1>, Unit<Rep2,Period2>>::type type;
  return type(type(Obj1).count() % type(Obj2).count());
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator==(Unit<Rep1,Period1> const& Obj1, Unit<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Unit<Rep1,Period1>, Unit<Rep2,Period2>>::type type;
  return type(Obj1).count() == type(Obj2).count();
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator!=(Unit<Rep1,Period1> const& Obj1, Unit<Rep2,Period2> const& Obj2)
{
  return !(Obj1 == Obj2);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator<(Unit<Rep1,Period1> const& Obj1, Unit<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Unit<Rep1,Period1>, Unit<Rep2,Period2>>::type type;
  return type(Obj1).count() < type(Obj2).count();
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator<=(Unit<Rep1,Period1> const& Obj1, Unit<Rep2,Period2> const& Obj2)
{
  return !(Obj2 < Obj1);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator>(Unit<Rep1,Period1> const& Obj1, Unit<Rep2,Period2> const& Obj2)
{
  return Obj2 < Obj1;
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator>=(Unit<Rep1,Period1> const& Obj1, Unit<Rep2,Period2> const& Obj2)
{
  return ! (Obj1 < Obj2);
}

*/



} // namespace stb





//=============================================================================
//=============================================================================
// COMMON_TYPE ================================================================
//=============================================================================
//=============================================================================





namespace std _GLIBCXX_VISIBILITY(default)
{



template<typename CT, typename Period1, typename Period2>
class Unit_common_type_wrapper
{
private:

  static constexpr double gcd_num = gcd(Period1::num, Period2::num);
  static constexpr double gcd_den = gcd(Period1::den, Period2::den);
  typedef typename CT::type common_rep;
  typedef stb::ratio<gcd_num, (Period1::den / gcd_den) * Period2::den> new_ratio;

public:
  typedef std::__success_type<stb::Unit<typename CT::dimension, common_rep, new_ratio>> type;
};


template<typename Period1, typename Period2>
class Unit_common_type_wrapper<std::__failure_type, Period1, Period2>
{
public:
  typedef std::__failure_type type;
};


template<typename Dimension1, typename Rep1, typename Period1,
typename Dimension2, typename Rep2, typename Period2>
class common_type<stb::Unit<Dimension1, Rep1, Period1>, stb::Unit<Dimension2, Rep2, Period2>>
: public Unit_common_type_wrapper<typename std::__member_type_wrapper<
std::common_type<Rep1, Rep2>>::type, Period1, Period2>::type
{
};



}//namespace std





#endif //UNIT_HH_
