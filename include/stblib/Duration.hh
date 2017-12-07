//Duration.hh

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

#ifndef DURATION_HH_
#define DURATION_HH_

/***************************
* DIMENSIONS OF THIS UNIT :
* [T]
***************************/

#include "Unit.hpp"
#include "exception.hh"
#include <chrono>   //duration

namespace stb
{



//previous declaration needed to define cas
template<typename Rep, typename Period>
class Duration;



//=============================================================================
//=============================================================================
// CAST =======================================================================
//=============================================================================
//=============================================================================



template<typename toUnit, typename new_ratio, typename common_rep,
bool NumIsOne = false, bool DenIsOne = false>
class duration_cast_impl : public casting_type_trait
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit cast(Duration<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;

    return toUnit(static_cast<rep>(static_cast<common_rep>(Obj.count())
      * static_cast<common_rep>(new_ratio::num) / static_cast<common_rep>(new_ratio::den)));
  }
};


template<typename toUnit, typename new_ratio, typename common_rep>
class duration_cast_impl<toUnit, new_ratio, common_rep, true, true> : public casting_type_trait
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit cast(Duration<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;
    return toUnit(static_cast<rep>(Obj.count()));
  }
};


template<typename toUnit, typename new_ratio, typename common_rep>
class duration_cast_impl<toUnit, new_ratio, common_rep, true, false> : public casting_type_trait
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit cast(Duration<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;
    return toUnit(static_cast<rep>(
    static_cast<common_rep>(Obj.count()) / static_cast<common_rep>(new_ratio::den)));
  }
};


template<typename toUnit, typename new_ratio, typename common_rep>
class duration_cast_impl<toUnit, new_ratio, common_rep, false, true> : public casting_type_trait
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit
  cast(Duration<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;
    return toUnit(static_cast<rep>(
    static_cast<common_rep>(Obj.count()) * static_cast<common_rep>(new_ratio::num)));
  }
};


template<typename falseType>
class is_Duration : public std::false_type
{
};


template<typename Rep, typename Period>
class is_Duration<Duration<Rep, Period>> : public std::true_type
{
};


template<typename toUnit, typename Rep, typename Period>
constexpr typename std::enable_if<is_Duration<toUnit>::value, toUnit>::type
duration_cast(const Duration<Rep, Period>& Obj)
{
  typedef typename toUnit::period period;
  typedef typename toUnit::rep rep;
  typedef std::ratio_divide<Period, period> new_ratio;
  typedef typename std::common_type<rep, Rep, intmax_t>::type common_rep;
  typedef  duration_cast_impl<toUnit, new_ratio,
  common_rep, new_ratio::num == 1, new_ratio::den == 1> type;
  return type::cast(Obj);
}





//=============================================================================
//=============================================================================
// DEFINITION =================================================================
//=============================================================================
//=============================================================================



template<typename Rep, typename Period = std::ratio<1>>
class Duration : public Unit<Rep, Period>, public std::chrono::duration<Rep, Period>
{
public:

  typedef Rep    rep;
  typedef Period period;


  static_assert(! is_Duration<Rep>::value, "rep cannot be a Duration");
  static_assert(std::chrono::__is_ratio<Period>::value,
  "period must be a specialization of ratio");
  static_assert(Period::num > 0, "period must be positive");


  constexpr Duration() = default;
  Duration(Duration const&) = default;


  template<typename _Rep, typename = typename std::enable_if<std::is_convertible<_Rep, Rep>::value
  && (std::chrono::treat_as_floating_point<Rep>::value || !std::chrono::treat_as_floating_point<_Rep>::value)>::type>
  constexpr explicit Duration(_Rep const& countArg):
  Unit<Rep, Period>(static_cast<Rep>(countArg)),
  std::chrono::duration<Rep, Period>(static_cast<Rep>(countArg))
  {
  }


  template<typename _Rep, typename _Period, typename = typename std::enable_if<std::chrono::treat_as_floating_point<Rep>::value
  || (std::ratio_divide<_Period, Period>::den == 1 && !std::chrono::treat_as_floating_point<_Rep>::value)>::type>
  constexpr Duration(Duration<_Rep, _Period> const& Obj):
  Unit<Rep, Period>(duration_cast<Duration>(Obj).count()),
  std::chrono::duration<Rep, Period>(Obj)
  {
  }


  template<typename _Rep, typename _Period, typename = typename std::enable_if<std::chrono::treat_as_floating_point<Rep>::value
  || (std::ratio_divide<_Period, Period>::den == 1 && !std::chrono::treat_as_floating_point<_Rep>::value)>::type>
  constexpr Duration(std::chrono::duration<_Rep, _Period> const& Obj):
  Unit<Rep, Period>(std::chrono::duration_cast<std::chrono::duration<Rep, Period>>(Obj).count()),
  std::chrono::duration<Rep, Period>(Obj)
  {
  }


  ~Duration() = default;
  Duration& operator=(Duration const&) = default;


  constexpr Rep count() const
  {
    return Unit<Rep, Period>::_count;
  }


  static constexpr Duration zero()
  {
    return Duration(0);
  }


  Duration& operator++()
  {
    ++Unit<Rep, Period>::_count;
    std::chrono::duration<Rep, Period>::operator++();
    return *this;
  }


  Duration operator++(int)
  {
    std::chrono::duration<Rep, Period>::operator++(0);
    return Duration(Unit<Rep, Period>::_count++);
  }


  Duration& operator--()
  {
    --Unit<Rep, Period>::_count;
    std::chrono::duration<Rep, Period>::operator--();
    return *this;
  }


  Duration operator--(int)
  {
    std::chrono::duration<Rep, Period>::operator--(0);
    return Duration(Unit<Rep, Period>::_count--);
  }


  Duration& operator+=(Duration const& Obj)
  {
    Unit<Rep, Period>::_count += Obj.count();
    std::chrono::duration<Rep, Period>::operator+=(Obj);
    return *this;
  }


  Duration& operator-=(Duration const& Obj)
  {
    Unit<Rep, Period>::_count -= Obj.count();
    std::chrono::duration<Rep, Period>::operator-=(Obj);
    return *this;
  }


  Duration& operator*=(Rep const& coef)
  {
    Unit<Rep, Period>::_count *= coef;
    std::chrono::duration<Rep, Period>::operator*=(coef);
    return *this;
  }


  Duration& operator/=(Rep const& coef)
  {
    if(coef == 0)
      throw Unit_exception("Divide by 0.");
    Unit<Rep, Period>::_count /= coef;
    std::chrono::duration<Rep, Period>::operator/=(coef);
    return *this;
  }


  template <typename _Rep = Rep>
  typename std::enable_if<!std::chrono::treat_as_floating_point<_Rep>::value, Duration&>::type
  operator%=(Rep const& coef)
  {
    if(coef == 0)
      throw Unit_exception("Divide by 0.");
    Unit<Rep, Period>::_count %= coef;
    std::chrono::duration<Rep, Period>::operator%=(coef);
    return *this;
  }


  template <typename _Rep = Rep>
  typename std::enable_if<!std::chrono::treat_as_floating_point<_Rep>::value, Duration&>::type
  operator%=(Duration const& Obj)
  {
    if(Obj.count() == 0)
      throw Unit_exception("Divide by 0.");
    Unit<Rep, Period>::_count %= Obj.count();
    std::chrono::duration<Rep, Period>::operator%=(Obj);
    return *this;
  }
};





//=============================================================================
//=============================================================================
// OPERATORS ==================================================================
//=============================================================================
//=============================================================================



template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Duration<Rep1,Period1>, Duration<Rep2,Period2>>::type
operator+ (Duration<Rep1,Period1> const& Obj1, Duration<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Duration<Rep1,Period1>, Duration<Rep2,Period2>>::type type;
  return type(type(Obj1).count() + type(Obj2).count());
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Duration<Rep1,Period1>, Duration<Rep2,Period2>>::type
operator- (Duration<Rep1,Period1> const& Obj1, Duration<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Duration<Rep1,Period1>, Duration<Rep2,Period2>>::type type;
  return type(type(Obj1).count() - type(Obj2).count());
}


template <typename Rep, typename Period, typename coefType>
constexpr Duration<typename std::chrono::__common_rep_type<Rep, coefType>::type, Period>
operator* (Duration<Rep, Period> const& Obj, coefType const& coef)
{
  typedef typename std::common_type<Rep, coefType>::type common;
  typedef Duration<common, Period> type;
  return type(type(Obj).count() * coef);
}


template <typename Rep, typename Period, typename coefType>
constexpr Duration<typename std::chrono::__common_rep_type<Rep, coefType>::type, Period>
operator* (coefType const& coef, Duration<Rep, Period> const& Obj)
{
  return Obj * coef;
}


template <typename Rep, typename Period, typename coefType>
constexpr Duration<typename std::chrono::__common_rep_type<Rep, typename
std::enable_if<!is_Duration<coefType>::value, coefType>::type>::type, Period>
operator/ (Duration<Rep, Period> const& Obj, coefType const& coef)
{
  if(coef == 0)
    throw Unit_exception("Divide by 0.");
  typedef typename std::common_type<Rep, coefType>::type common;
  typedef Duration<common, Period> type;
  return type(type(Obj).count() / coef);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Rep1, Rep2>::type
operator/ (Duration<Rep1,Period1> const& Obj1, Duration<Rep2,Period2> const& Obj2)
{
  if(Obj2.count() == 0)
    throw Unit_exception("Divide by 0.");
  typedef typename std::common_type<Duration<Rep1,Period1>, Duration<Rep2,Period2>>::type type;
  return type(Obj1).count() / type(Obj2).count();
}


template <typename Rep, typename Period, typename coefType>
constexpr Duration<typename std::chrono::__common_rep_type<Rep, typename
std::enable_if<!is_Duration<coefType>::value, coefType>::type>::type, Period>
operator% (Duration<Rep, Period> const& Obj, coefType const& coef)
{
  if(coef == 0)
    throw Unit_exception("Divide by 0.");
  typedef Duration<typename std::common_type<Rep, coefType>::type, Period> type;
  return type(type(Obj).count() % coef);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Duration<Rep1,Period1>, Duration<Rep2,Period2>>::type
operator% (Duration<Rep1,Period1> const& Obj1, Duration<Rep2,Period2> const& Obj2)
{
  if(Obj2.count() == 0)
    throw Unit_exception("Divide by 0.");
  typedef typename std::common_type<Duration<Rep1,Period1>, Duration<Rep2,Period2>>::type type;
  return type(type(Obj1).count() % type(Obj2).count());
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator==(Duration<Rep1,Period1> const& Obj1, Duration<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Duration<Rep1,Period1>, Duration<Rep2,Period2>>::type type;
  return type(Obj1).count() == type(Obj2).count();
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator!=(Duration<Rep1,Period1> const& Obj1, Duration<Rep2,Period2> const& Obj2)
{
  return !(Obj1 == Obj2);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator<(Duration<Rep1,Period1> const& Obj1, Duration<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Duration<Rep1,Period1>, Duration<Rep2,Period2>>::type type;
  return type(Obj1).count() < type(Obj2).count();
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator<=(Duration<Rep1,Period1> const& Obj1, Duration<Rep2,Period2> const& Obj2)
{
  return !(Obj2 < Obj1);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator>(Duration<Rep1,Period1> const& Obj1, Duration<Rep2,Period2> const& Obj2)
{
  return Obj2 < Obj1;
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator>=(Duration<Rep1,Period1> const& Obj1, Duration<Rep2,Period2> const& Obj2)
{
  return ! (Obj1 < Obj2);
}





//=============================================================================
//=============================================================================
// TYPEDEF ====================================================================
//=============================================================================
//=============================================================================



template<typename Rep, typename period = std::ratio<1>>
using Period = Duration<Rep, period>;





typedef Duration<float, std::atto>                      attosecond;
typedef Duration<float, std::femto>                     femtosecond;
typedef Duration<float, std::pico>                      picosecond;
typedef Duration<float, std::nano>                      nanosecond;
typedef Duration<float, std::micro>                     microsecond;
typedef Duration<float, std::milli>                     millisecond;
typedef Duration<float, std::ratio<1, 1>>               second;
typedef Duration<float, std::ratio<60, 1>>              minute;
typedef Duration<float, std::ratio<3600, 1>>            hour;
typedef Duration<float, std::ratio<3600*24, 1>>         day;
typedef Duration<float, std::ratio<3600*24*7, 1>>       week;
typedef Duration<float, std::ratio<3600*24*30, 1>>      month;
typedef Duration<float,
std::__ratio_multiply<std::ratio<3600*24, 1>,
std::ratio<36525, 100>>::type>                          year;
typedef Duration<float,
std::__ratio_multiply<year::period, std::kilo>::type>   kiloyear;
typedef Duration<float,
std::__ratio_multiply<year::period, std::mega>::type>   megayear;
typedef Duration<float,
std::__ratio_multiply<year::period, std::giga>::type>   gigayear;





//=============================================================================
//=============================================================================
// DURATION CONSTANT ==========================================================
//=============================================================================
//=============================================================================



namespace constant
{



//age of the universe
const gigayear t0(13.798); //+-37

//age of the sun system and its planets
const gigayear tSunSystem(4.568);

//Planck time
const attosecond tp(0.0000000000000000000000000539106); //+-32

//some radioactive decay constants
//TO DO



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
class Duration_common_type_wrapper
{
private:

  typedef std::__static_gcd<Period1::num, Period2::num> gcd_num;
  typedef std::__static_gcd<Period1::den, Period2::den> gcd_den;
  typedef typename CT::type common_rep;
  typedef std::ratio<gcd_num::value,
    (Period1::den / gcd_den::value) * Period2::den> new_ratio;

public:

  typedef std::__success_type<stb::Duration<common_rep, new_ratio>> type;
};


template<typename Period1, typename Period2>
class Duration_common_type_wrapper<std::__failure_type, Period1, Period2>
{
public:

  typedef std::__failure_type type;
};


template<typename Rep1, typename Period1, typename Rep2, typename Period2>
class common_type<stb::Duration<Rep1, Period1>, stb::Duration<Rep2, Period2>>
        : public Duration_common_type_wrapper<typename std::__member_type_wrapper<
        std::common_type<Rep1, Rep2>>::type, Period1, Period2>::type
{
};



}//namespace std






#endif //DURATION_HH_
