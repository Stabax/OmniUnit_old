//Speed.hh

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

#ifndef SPEED_HH_
#define SPEED_HH_

#include "Unit.hpp" // Unit

namespace stb
{



//previous declaration needed to define cast
template<typename Rep, typename Period>
class Speed;



//=============================================================================
//=============================================================================
// CAST =======================================================================
//=============================================================================
//=============================================================================



template<typename toUnit, typename new_ratio, typename common_rep,
bool NumIsOne = false, bool DenIsOne = false>
class Speed_cast_impl : public casting_type_trait
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit cast(Speed<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;

    return toUnit(static_cast<rep>(static_cast<common_rep>(Obj.count())
      * static_cast<common_rep>(new_ratio::num) / static_cast<common_rep>(new_ratio::den)));
  }
};


template<typename toUnit, typename new_ratio, typename common_rep>
class Speed_cast_impl<toUnit, new_ratio, common_rep, true, true> : public casting_type_trait
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit cast(Speed<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;
    return toUnit(static_cast<rep>(Obj.count()));
  }
};


template<typename toUnit, typename new_ratio, typename common_rep>
class Speed_cast_impl<toUnit, new_ratio, common_rep, true, false> : public casting_type_trait
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit cast(Speed<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;
    return toUnit(static_cast<rep>(
    static_cast<common_rep>(Obj.count()) / static_cast<common_rep>(new_ratio::den)));
  }
};


template<typename toUnit, typename new_ratio, typename common_rep>
class Speed_cast_impl<toUnit, new_ratio, common_rep, false, true> : public casting_type_trait
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit
  cast(Speed<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;
    return toUnit(static_cast<rep>(
    static_cast<common_rep>(Obj.count()) * static_cast<common_rep>(new_ratio::num)));
  }
};


template<typename falseType>
class is_Speed : public std::false_type
{
};


template<typename Rep, typename Period>
class is_Speed<Speed<Rep, Period>> : public std::true_type
{
};


template<typename toUnit, typename Rep, typename Period>
constexpr typename std::enable_if<is_Speed<toUnit>::value, toUnit>::type
speed_cast(const Speed<Rep, Period>& Obj)
{
  typedef typename toUnit::period period;
  typedef typename toUnit::rep rep;
  typedef std::ratio_divide<Period, period> new_ratio;
  typedef typename std::common_type<rep, Rep, intmax_t>::type common_rep;
  typedef  Speed_cast_impl<toUnit, new_ratio,
  common_rep, new_ratio::num == 1, new_ratio::den == 1> type;
  return type::cast(Obj);
}





//=============================================================================
//=============================================================================
// DEFINITION =================================================================
//=============================================================================
//=============================================================================



template<typename Rep, typename Period = std::ratio<1>>
class Speed : public Unit<Rep, Period>
{
public:

  typedef Rep    rep;
  typedef Period period;


  static_assert(! is_Speed<Rep>::value, "rep cannot be a Speed");
  static_assert(std::chrono::__is_ratio<Period>::value,
  "period must be a specialization of ratio");
  static_assert(Period::num > 0, "period must be positive");


  constexpr Speed() = default;
  Speed(Speed const&) = default;


  template<typename _Rep, typename = typename std::enable_if<std::is_convertible<_Rep, Rep>::value
  && (std::chrono::treat_as_floating_point<Rep>::value || !std::chrono::treat_as_floating_point<_Rep>::value)>::type>
  constexpr explicit Speed(_Rep const& countArg):
  Unit<Rep, Period>(static_cast<Rep>(countArg))
  {
  }


  template<typename _Rep, typename _Period, typename = typename std::enable_if<std::chrono::treat_as_floating_point<Rep>::value
  || (std::ratio_divide<_Period, Period>::den == 1 && !std::chrono::treat_as_floating_point<_Rep>::value)>::type>
  constexpr Speed(Speed<_Rep, _Period> const& Obj):
  Unit<Rep, Period>(speed_cast<Speed>(Obj).count())
  {
  }


  ~Speed() = default;
  Speed& operator=(Speed const&) = default;


  static constexpr Speed zero()
  {
    return Speed(0);
  }


  Speed& operator++()
  {
    ++Unit<Rep, Period>::_count;
    return *this;
  }


  Speed operator++(int)
  {
    return Speed(Unit<Rep, Period>::_count++);
  }


  Speed& operator--()
  {
    --Unit<Rep, Period>::_count;
    return *this;
  }


  Speed operator--(int)
  {
    return Speed(Unit<Rep, Period>::_count--);
  }


  Speed& operator+=(Speed const& Obj)
  {
    Unit<Rep, Period>::_count += Obj.count();
    return *this;
  }


  Speed& operator-=(Speed const& Obj)
  {
    Unit<Rep, Period>::_count -= Obj.count();
    return *this;
  }


  Speed& operator*=(Rep coef)
  {
    Unit<Rep, Period>::_count *= coef;
    return *this;
  }


  Speed& operator/=(Rep coef)
  {
    if(coef == 0)
      throw Unit_exception("Divide by 0.");
    Unit<Rep, Period>::_count /= coef;
    return *this;
  }


  template <typename _Rep = Rep>
  typename std::enable_if<!std::chrono::treat_as_floating_point<_Rep>::value, Speed&>::type
  operator%=(Rep const& coef)
  {
    if(coef == 0)
      throw Unit_exception("Divide by 0.");
    Unit<Rep, Period>::_count %= coef;
    return *this;
  }


  template <typename _Rep = Rep>
  typename std::enable_if<!std::chrono::treat_as_floating_point<_Rep>::value, Speed&>::type
  operator%=(Speed const& Obj)
  {
    if(Obj.count() == 0)
      throw Unit_exception("Divide by 0.");
    Unit<Rep, Period>::_count %= Obj.count();
    return *this;
  }
};





//=============================================================================
//=============================================================================
// OPERATORS ==================================================================
//=============================================================================
//=============================================================================



template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type
operator+ (Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type type;
  return type(type(Obj1).count() + type(Obj2).count());
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type
operator- (Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type type;
  return type(type(Obj1).count() - type(Obj2).count());
}


template <typename Rep, typename Period, typename coefType>
constexpr Speed<typename std::chrono::__common_rep_type<Rep, coefType>::type, Period>
operator* (Speed<Rep, Period> const& Obj, coefType const& coef)
{
  typedef typename std::common_type<Rep, coefType>::type common;
  typedef Speed<common, Period> type;
  return type(type(Obj).count() * coef);
}


template <typename Rep, typename Period, typename coefType>
constexpr Speed<typename std::chrono::__common_rep_type<Rep, coefType>::type, Period>
operator* (coefType const& coef, Speed<Rep, Period> const& Obj)
{
  return Obj * coef;
}


template <typename Rep, typename Period, typename coefType>
constexpr Speed<typename std::chrono::__common_rep_type<Rep, typename
std::enable_if<!is_Speed<coefType>::value, coefType>::type>::type, Period>
operator/ (Speed<Rep, Period> const& Obj, coefType const& coef)
{
  if(coef == 0)
    throw Unit_exception("Divide by 0.");
  typedef typename std::common_type<Rep, coefType>::type common;
  typedef Speed<common, Period> type;
  return type(type(Obj).count() / coef);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Rep1, Rep2>::type
operator/ (Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  if(Obj2.count() == 0)
    throw Unit_exception("Divide by 0.");
  typedef typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type type;
  return type(Obj1).count() / type(Obj2).count();
}


template <typename Rep, typename Period, typename coefType>
constexpr Speed<typename std::chrono::__common_rep_type<Rep, typename
std::enable_if<!is_Speed<coefType>::value, coefType>::type>::type, Period>
operator% (Speed<Rep, Period> const& Obj, coefType const& coef)
{
  if(coef == 0)
    throw Unit_exception("Divide by 0.");
  typedef Speed<typename std::common_type<Rep, coefType>::type, Period> type;
  return type(type(Obj).count() % coef);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type
operator% (Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  if(Obj2.count() == 0)
    throw Unit_exception("Divide by 0.");
  typedef typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type type;
  return type(type(Obj1).count() % type(Obj2).count());
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator==(Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type type;
  return type(Obj1).count() == type(Obj2).count();
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator!=(Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  return !(Obj1 == Obj2);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator<(Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type type;
  return type(Obj1).count() < type(Obj2).count();
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator<=(Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  return !(Obj2 < Obj1);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator>(Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  return Obj2 < Obj1;
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator>=(Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  return ! (Obj1 < Obj2);
}





//=============================================================================
//=============================================================================
// TYPEDEF ====================================================================
//=============================================================================
//=============================================================================



typedef Speed<float, std::ratio<1000, 3600>>    kilometer_hour;
typedef Speed<float, std::ratio<1, 1>>          meter_second;
typedef Speed<float, std::ratio<1000, 1>>       kilometer_second;





//=============================================================================
//=============================================================================
// CONSTANT ===================================================================
//=============================================================================
//=============================================================================





namespace constant
{



//Speed of lux through void
const meter_second cRounded(300000000);
const meter_second c(299792458);

//Speed of sound, at normal pressure and temperature conditions
const meter_second cAir(340);
const meter_second cWater(1480);
const meter_second cSteel(5700);
const meter_second cLead(1200);
const meter_second cGranite(6200);
const meter_second cPeridotite(7700);

//Speed at the earth's equator
const kilometer_hour vEquator(1670);

//Speed of planets around the sun
const kilometer_hour vMercury(172800);
const kilometer_hour vVenus(126000);
const kilometer_hour vEarth(104400);
const kilometer_hour vMars(86400);
const kilometer_hour vJupiter(46400);
const kilometer_hour vSaturn(36000);
const kilometer_hour vUranus(25200);
const kilometer_hour vNeptune(18000);

//Speed of the moon around the earth
const kilometer_hour vMoon(3680);

//Speed of sun the system around the milkyway
const kilometer_second vSun(230);

//Speed of the milkyway toward andromeda
const kilometer_second vAndromeda(120);



}//namespace constant


}//namespace stb





//=============================================================================
//=============================================================================
// COMMON_TYPE ================================================================
//=============================================================================
//=============================================================================



namespace std _GLIBCXX_VISIBILITY(default)
{
//std:: qualification is provided even if not needed in order
//to know where types/functions come from



template<typename CT, typename Period1, typename Period2>
class Speed_common_type_wrapper
{
private:

  typedef std::__static_gcd<Period1::num, Period2::num> gcd_num;
  typedef std::__static_gcd<Period1::den, Period2::den> gcd_den;
  typedef typename CT::type common_rep;
  typedef std::ratio<gcd_num::value,
    (Period1::den / gcd_den::value) * Period2::den> new_ratio;

public:

  typedef std::__success_type<stb::Speed<common_rep, new_ratio>> type;
};


template<typename Period1, typename Period2>
class Speed_common_type_wrapper<std::__failure_type, Period1, Period2>
{
public:

  typedef std::__failure_type type;
};


template<typename Rep1, typename Period1, typename Rep2, typename Period2>
class common_type<stb::Speed<Rep1, Period1>, stb::Speed<Rep2, Period2>>
        : public Speed_common_type_wrapper<typename std::__member_type_wrapper<
        std::common_type<Rep1, Rep2>>::type, Period1, Period2>::type
{
};



}//namespace std






#endif //SPEED_HH_
