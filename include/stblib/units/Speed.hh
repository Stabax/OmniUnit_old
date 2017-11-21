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



//previous declaration needed to define cast and treat_as_flating_point
template<typename Rep, typename Period>
class Speed;



//=============================================================================
//=============================================================================
// CAST =======================================================================
//=============================================================================
//=============================================================================



template<typename toUnit, typename CF, typename CR,
bool NumIsOne = false, bool DenIsOne = false>
class Speed_cast_impl
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit cast(Speed<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;

    return toUnit(static_cast<rep>(static_cast<CR>(Obj.count())
      * static_cast<CR>(CF::num) / static_cast<CR>(CF::den)));
  }
};


template<typename toUnit, typename CF, typename CR>
class Speed_cast_impl<toUnit, CF, CR, true, true>
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit
  cast(Speed<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;
    return toUnit(static_cast<rep>(Obj.count()));
  }
};


template<typename toUnit, typename CF, typename CR>
class Speed_cast_impl<toUnit, CF, CR, true, false>
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit
  cast(Speed<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;
    return toUnit(static_cast<rep>(
    static_cast<CR>(Obj.count()) / static_cast<CR>(CF::den)));
  }
};


template<typename toUnit, typename CF, typename CR>
class Speed_cast_impl<toUnit, CF, CR, false, true>
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit
  cast(Speed<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;
    return toUnit(static_cast<rep>(
    static_cast<CR>(Obj.count()) * static_cast<CR>(CF::num)));
  }
};


template<typename _Tp>
class is_Speed : public std::false_type
{
};


template<typename _Rep, typename _Period>
class is_Speed<Speed<_Rep, _Period>> : public std::true_type
{
};


template<typename toUnit, typename _Rep, typename _Period>
constexpr typename std::enable_if<is_Speed<toUnit>::value,
toUnit>::type
speed_cast(const Speed<_Rep, _Period>& Obj)
{
  typedef typename toUnit::period				__to_period;
  typedef typename toUnit::rep				__to_rep;
  typedef std::ratio_divide<_Period, __to_period> 		__cf;
  typedef typename std::common_type<__to_rep, _Rep, intmax_t>::type __cr;
  typedef  Speed_cast_impl<toUnit, __cf, __cr, __cf::num == 1, __cf::den == 1> Objc;
  return Objc::cast(Obj);
}





//=============================================================================
//=============================================================================
// TREAT AS FLOATING POINT ====================================================
//=============================================================================
//=============================================================================



template<typename Rep>
struct treat_as_floating_point : std::is_floating_point<Rep>
{
};





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
  static_assert(is_ratio<Period>::value,
  "period must be a specialization of ratio");
  static_assert(Period::num > 0, "period must be positive");


  constexpr Speed() = default;
  Speed(Speed const&) = default;


  template<typename _Rep, typename = typename std::enable_if<std::is_convertible<_Rep, Rep>::value
  && (treat_as_floating_point<Rep>::value || !treat_as_floating_point<_Rep>::value)>::type>
  constexpr explicit Speed(_Rep const& countArg):
  Unit<Rep, Period>(static_cast<Rep>(countArg))
  {
  }


  template<typename _Rep, typename _Period, typename = typename std::enable_if<treat_as_floating_point<Rep>::value
  || (std::ratio_divide<_Period, Period>::den == 1 && !treat_as_floating_point<_Rep>::value)>::type>
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
    Unit<Rep, Period>::_count /= coef;
    return *this;
  }


  template <typename _Rep = Rep>
  typename std::enable_if<!treat_as_floating_point<_Rep>::value, Speed&>::type
  operator%=(Rep const& coef)
  {
    Unit<Rep, Period>::_count %= coef;
    return *this;
  }


  template <typename _Rep = Rep>
  typename std::enable_if<!treat_as_floating_point<_Rep>::value, Speed&>::type
  operator%=(Speed const& Obj)
  {
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
  return type(type(Obj1).count() - type(Obj1).count());
}


template <typename Rep, typename Period, typename coefType>
constexpr Speed<typename common_rep_type<Rep, coefType>::type, Period>
operator* (Speed<Rep, Period> const& Obj, coefType const& coef)
{
  typedef typename std::common_type<Rep, coefType>::type common;
  typedef Speed<common, Period> type;
  return type(type(Obj).count() * static_cast<common>(coef));
}


template <typename Rep, typename Period, typename coefType>
constexpr Speed<typename common_rep_type<Rep, coefType>::type, Period>
operator* (coefType const& coef, Speed<Rep, Period> const& Obj)
{
  return Obj * coef;
}


template <typename Rep, typename Period, typename coefType>
constexpr Speed<typename common_rep_type<Rep, typename
std::enable_if<!is_Speed<coefType>::value, coefType>::type>::type, Period>
operator/ (Speed<Rep, Period> const& Obj, coefType const& coef)
{
  typedef typename std::common_type<Rep, coefType>::type common;
  typedef Speed<common, Period> type;
  return type(type(Obj).count() / static_cast<common>(coef));
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Rep1, Rep2>::type
operator/ (Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type type;
  return type(Obj1).count() / type(Obj2).count();
}


template <typename Rep, typename Period, typename coefType>
constexpr Speed<typename common_rep_type<Rep, typename
std::enable_if<!is_Speed<coefType>::value, coefType>::type>::type, Period>
operator% (Speed<Rep, Period> const& Obj, coefType const& coef)
{
  typedef Speed<typename std::common_type<Rep, coefType>::type, Period> type;
  return type(speed_cast<type>(Obj).count() % coef);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type
operator% (Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
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



typedef Speed<long long, std::ratio<1, 1>>          meterPerSecond;
typedef Speed<long long, std::ratio<1000, 1>>       kilometerPerSecond;
typedef Speed<long long, std::ratio<1000, 3600>>    kilometerPerHour;

typedef Speed<float, std::ratio<1, 1>>          meterPerSecond_f;
typedef Speed<float, std::ratio<1000, 1>>       kilometerPerSecond_f;
typedef Speed<float, std::ratio<1000, 3600>>    kilometerPerHour_f;





//=============================================================================
//=============================================================================
// CONSTANT ===================================================================
//=============================================================================
//=============================================================================



//Speed of lux through void
const Speed<bool, std::ratio<300*1000*1000, 1>> cRounded(1);
const meterPerSecond c(299792458);

//Speed of sound, in normal pressure and temperature conditions
const meterPerSecond cAir(340);
const meterPerSecond cWater(1480);
const meterPerSecond cIce(3200);
const meterPerSecond cGlass(5300);
const meterPerSecond cSteel(5700);
const meterPerSecond cLead(1200);
const meterPerSecond cTitanium(4950);
const meterPerSecond cConcrete(3100);
const meterPerSecond cGranite(6200);
const meterPerSecond cPeridotite(7700);

//Speed at the earth's equator
const kilometerPerHour vEquator(1670);

//Speeds in the sun system
const kilometerPerHour vMercury(172800);
const kilometerPerHour vVenus(126000);
const kilometerPerHour vEarth(104400);
const kilometerPerHour vMars(86400);
const kilometerPerHour vJupiter(46400);
const kilometerPerHour vSaturn(36000);
const kilometerPerHour vUranus(25200);
const kilometerPerHour vNeptune(18000);

//intestellar Speeds
//const kilometerPerHour vSun_aCentauri(828000);
//const kilometerPerHour vSun_Sirius(828000);
//const kilometerPerHour vSun_Eridiani(828000);
const kilometerPerSecond vSun_MilkyWay(230);

//intergalactic Speeds
const kilometerPerSecond vMilkyWay_Andromeda(120);
const kilometerPerSecond vMilkyWay_LocalGoup(65);
const kilometerPerSecond vLocalGroup_LocalSuperCluster(627);
const kilometerPerSecond vLocalSuperCluster_GreatAttractor(368);
const kilometerPerSecond vLocalSuperCluster_Laniakea = vLocalSuperCluster_GreatAttractor;



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
  typedef typename CT::type cr;
  typedef std::ratio<gcd_num::value,
    (Period1::den / gcd_den::value) * Period2::den> r;

public:

  typedef std::__success_type<stb::Speed<cr, r>> type;
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
