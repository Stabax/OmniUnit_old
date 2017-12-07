//Energy.hh

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

#ifndef Energy_HH_
#define Energy_HH_

/***************************
* DIMENSIONS OF THIS UNIT :
* [E]
***************************/

#include "Unit.hpp" // Unit

namespace stb
{



//previous declaration needed to define cast
template<typename Rep, typename Period>
class Energy;



//=============================================================================
//=============================================================================
// CAST =======================================================================
//=============================================================================
//=============================================================================



template<typename toUnit, typename new_ratio, typename common_rep,
bool NumIsOne = false, bool DenIsOne = false>
class energy_cast_impl : public casting_type_trait
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit cast(Energy<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;

    return toUnit(static_cast<rep>(static_cast<common_rep>(Obj.count())
      * static_cast<common_rep>(new_ratio::num) / static_cast<common_rep>(new_ratio::den)));
  }
};


template<typename toUnit, typename new_ratio, typename common_rep>
class energy_cast_impl<toUnit, new_ratio, common_rep, true, true> : public casting_type_trait
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit cast(Energy<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;
    return toUnit(static_cast<rep>(Obj.count()));
  }
};


template<typename toUnit, typename new_ratio, typename common_rep>
class energy_cast_impl<toUnit, new_ratio, common_rep, true, false> : public casting_type_trait
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit cast(Energy<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;
    return toUnit(static_cast<rep>(
    static_cast<common_rep>(Obj.count()) / static_cast<common_rep>(new_ratio::den)));
  }
};


template<typename toUnit, typename new_ratio, typename common_rep>
class energy_cast_impl<toUnit, new_ratio, common_rep, false, true> : public casting_type_trait
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit
  cast(Energy<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;
    return toUnit(static_cast<rep>(
    static_cast<common_rep>(Obj.count()) * static_cast<common_rep>(new_ratio::num)));
  }
};


template<typename falseType>
class is_Energy : public std::false_type
{
};


template<typename Rep, typename Period>
class is_Energy<Energy<Rep, Period>> : public std::true_type
{
};


template<typename toUnit, typename Rep, typename Period>
constexpr typename std::enable_if<is_Energy<toUnit>::value, toUnit>::type
energy_cast(const Energy<Rep, Period>& Obj)
{
  typedef typename toUnit::period period;
  typedef typename toUnit::rep rep;
  typedef std::ratio_divide<Period, period> new_ratio;
  typedef typename std::common_type<rep, Rep, intmax_t>::type common_rep;
  typedef  energy_cast_impl<toUnit, new_ratio,
  common_rep, new_ratio::num == 1, new_ratio::den == 1> type;
  return type::cast(Obj);
}





//=============================================================================
//=============================================================================
// DEFINITION =================================================================
//=============================================================================
//=============================================================================



template<typename Rep, typename Period = std::ratio<1>>
class Energy : public Unit<Rep, Period>
{
public:

  typedef Rep    rep;
  typedef Period period;


  static_assert(! is_Energy<Rep>::value, "rep cannot be a Energy");
  static_assert(std::chrono::__is_ratio<Period>::value,
  "period must be a specialization of ratio");
  static_assert(Period::num > 0, "period must be positive");


  constexpr Energy() = default;
  Energy(Energy const&) = default;


  template<typename _Rep, typename = typename std::enable_if<std::is_convertible<_Rep, Rep>::value
  && (std::chrono::treat_as_floating_point<Rep>::value || !std::chrono::treat_as_floating_point<_Rep>::value)>::type>
  constexpr explicit Energy(_Rep const& countArg):
  Unit<Rep, Period>(static_cast<Rep>(countArg))
  {
  }


  template<typename _Rep, typename _Period, typename = typename std::enable_if<std::chrono::treat_as_floating_point<Rep>::value
  || (std::ratio_divide<_Period, Period>::den == 1 && !std::chrono::treat_as_floating_point<_Rep>::value)>::type>
  constexpr Energy(Energy<_Rep, _Period> const& Obj):
  Unit<Rep, Period>(energy_cast<Energy>(Obj).count())
  {
  }


  ~Energy() = default;
  Energy& operator=(Energy const&) = default;


  static constexpr Energy zero()
  {
    return Energy(0);
  }


  Energy& operator++()
  {
    ++Unit<Rep, Period>::_count;
    return *this;
  }


  Energy operator++(int)
  {
    return Energy(Unit<Rep, Period>::_count++);
  }


  Energy& operator--()
  {
    --Unit<Rep, Period>::_count;
    return *this;
  }


  Energy operator--(int)
  {
    return Energy(Unit<Rep, Period>::_count--);
  }


  Energy& operator+=(Energy const& Obj)
  {
    Unit<Rep, Period>::_count += Obj.count();
    return *this;
  }


  Energy& operator-=(Energy const& Obj)
  {
    Unit<Rep, Period>::_count -= Obj.count();
    return *this;
  }


  Energy& operator*=(Rep coef)
  {
    Unit<Rep, Period>::_count *= coef;
    return *this;
  }


  Energy& operator/=(Rep coef)
  {
    if(coef == 0)
      throw Unit_exception("Divide by 0.");
    Unit<Rep, Period>::_count /= coef;
    return *this;
  }


  template <typename _Rep = Rep>
  typename std::enable_if<!std::chrono::treat_as_floating_point<_Rep>::value, Energy&>::type
  operator%=(Rep const& coef)
  {
    if(coef == 0)
      throw Unit_exception("Divide by 0.");
    Unit<Rep, Period>::_count %= coef;
    return *this;
  }


  template <typename _Rep = Rep>
  typename std::enable_if<!std::chrono::treat_as_floating_point<_Rep>::value, Energy&>::type
  operator%=(Energy const& Obj)
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
constexpr typename std::common_type<Energy<Rep1,Period1>, Energy<Rep2,Period2>>::type
operator+ (Energy<Rep1,Period1> const& Obj1, Energy<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Energy<Rep1,Period1>, Energy<Rep2,Period2>>::type type;
  return type(type(Obj1).count() + type(Obj2).count());
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Energy<Rep1,Period1>, Energy<Rep2,Period2>>::type
operator- (Energy<Rep1,Period1> const& Obj1, Energy<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Energy<Rep1,Period1>, Energy<Rep2,Period2>>::type type;
  return type(type(Obj1).count() - type(Obj2).count());
}


template <typename Rep, typename Period, typename coefType>
constexpr Energy<typename std::chrono::__common_rep_type<Rep, coefType>::type, Period>
operator* (Energy<Rep, Period> const& Obj, coefType const& coef)
{
  typedef typename std::common_type<Rep, coefType>::type common;
  typedef Energy<common, Period> type;
  return type(type(Obj).count() * coef);
}


template <typename Rep, typename Period, typename coefType>
constexpr Energy<typename std::chrono::__common_rep_type<Rep, coefType>::type, Period>
operator* (coefType const& coef, Energy<Rep, Period> const& Obj)
{
  return Obj * coef;
}


template <typename Rep, typename Period, typename coefType>
constexpr Energy<typename std::chrono::__common_rep_type<Rep, typename
std::enable_if<!is_Energy<coefType>::value, coefType>::type>::type, Period>
operator/ (Energy<Rep, Period> const& Obj, coefType const& coef)
{
  if(coef == 0)
    throw Unit_exception("Divide by 0.");
  typedef typename std::common_type<Rep, coefType>::type common;
  typedef Energy<common, Period> type;
  return type(type(Obj).count() / coef);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Rep1, Rep2>::type
operator/ (Energy<Rep1,Period1> const& Obj1, Energy<Rep2,Period2> const& Obj2)
{
  if(Obj2.count() == 0)
    throw Unit_exception("Divide by 0.");
  typedef typename std::common_type<Energy<Rep1,Period1>, Energy<Rep2,Period2>>::type type;
  return type(Obj1).count() / type(Obj2).count();
}


template <typename Rep, typename Period, typename coefType>
constexpr Energy<typename std::chrono::__common_rep_type<Rep, typename
std::enable_if<!is_Energy<coefType>::value, coefType>::type>::type, Period>
operator% (Energy<Rep, Period> const& Obj, coefType const& coef)
{
  if(coef == 0)
    throw Unit_exception("Divide by 0.");
  typedef Energy<typename std::common_type<Rep, coefType>::type, Period> type;
  return type(type(Obj).count() % coef);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Energy<Rep1,Period1>, Energy<Rep2,Period2>>::type
operator% (Energy<Rep1,Period1> const& Obj1, Energy<Rep2,Period2> const& Obj2)
{
  if(Obj2.count() == 0)
    throw Unit_exception("Divide by 0.");
  typedef typename std::common_type<Energy<Rep1,Period1>, Energy<Rep2,Period2>>::type type;
  return type(type(Obj1).count() % type(Obj2).count());
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator==(Energy<Rep1,Period1> const& Obj1, Energy<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Energy<Rep1,Period1>, Energy<Rep2,Period2>>::type type;
  return type(Obj1).count() == type(Obj2).count();
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator!=(Energy<Rep1,Period1> const& Obj1, Energy<Rep2,Period2> const& Obj2)
{
  return !(Obj1 == Obj2);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator<(Energy<Rep1,Period1> const& Obj1, Energy<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Energy<Rep1,Period1>, Energy<Rep2,Period2>>::type type;
  return type(Obj1).count() < type(Obj2).count();
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator<=(Energy<Rep1,Period1> const& Obj1, Energy<Rep2,Period2> const& Obj2)
{
  return !(Obj2 < Obj1);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator>(Energy<Rep1,Period1> const& Obj1, Energy<Rep2,Period2> const& Obj2)
{
  return Obj2 < Obj1;
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator>=(Energy<Rep1,Period1> const& Obj1, Energy<Rep2,Period2> const& Obj2)
{
  return ! (Obj1 < Obj2);
}





//=============================================================================
//=============================================================================
// TYPEDEF ====================================================================
//=============================================================================
//=============================================================================


//The real value of 1 eV is 1.602176565 Joule.
//But 1,6 is the maximum precision allowed before overflow error of ratio::den


typedef Energy<float,
std::__ratio_multiply<std::atto,
std::ratio<16, 100>>::type>                              electronvolt;
typedef Energy<float, std::atto>                         attojoule;
typedef Energy<float,
std::__ratio_multiply<electronvolt::period,
std::kilo>::type>                                        kiloelectronvolt;
typedef Energy<float, std::femto>                        femtojoule;
typedef Energy<float,
std::__ratio_multiply<electronvolt::period,
std::mega>::type>                                        megaelectronvolt;
typedef Energy<float, std::pico>                         picojoule;
//_a = accurate
typedef Energy<float,
std::__ratio_multiply<std::atto,
std::ratio<1602176565, 10>>::type>                       gigaelectronvolt_a;
typedef Energy<float,
std::__ratio_multiply<electronvolt::period,
std::giga>::type>                                        gigaelectronvolt;
typedef Energy<float, std::nano>                         nanojoule;
typedef Energy<float,
std::__ratio_multiply<std::femto,
std::ratio<1602176565, 10>>::type>                       teraelectronvolt_a;
typedef Energy<float,
std::__ratio_multiply<electronvolt::period,
std::tera>::type>                                        teraelectronvolt;
typedef Energy<float,
std::__ratio_multiply<std::pico,
std::ratio<1602176565, 10>>::type>                       petaelectronvolt_a;
typedef Energy<float,
std::__ratio_multiply<electronvolt::period,
std::peta>::type>                                        petaelectronvolt;
typedef Energy<float, std::micro>                        microjoule;
typedef Energy<float, std::milli>                        millijoule;
typedef Energy<float, std::ratio<1, 1>>                  joule;
typedef Energy<float, std::kilo>                         kilojoule;
typedef Energy<float, std::ratio<3600, 1>>               watthour;
typedef Energy<float, std::ratio<3600*24, 1>>            wattday;
typedef Energy<float, std::mega>                         megajoule;
typedef Energy<float,
std::__ratio_multiply<watthour::period,
std::kilo>::type>                                        kilowatthour;
typedef Energy<float,
std::__ratio_multiply<std::ratio<3600*24, 1>,
std::ratio<36525, 100>>::type>                           wattyear;
typedef Energy<float,
std::__ratio_multiply<wattday::period,
std::kilo>::type>                                        kilowattday;
typedef Energy<float, std::giga>                         gigajoule;
typedef Energy<float,
std::__ratio_multiply<watthour::period,
std::mega>::type>                                        megawatthour;
typedef Energy<float,
std::__ratio_multiply<wattyear::period,
std::kilo>::type>                                        kilowattyear;
typedef Energy<float,
std::__ratio_multiply<wattday::period,
std::mega>::type>                                        megawattday;
typedef Energy<float, std::tera>                         terajoule;
typedef Energy<float,
std::__ratio_multiply<watthour::period,
std::giga>::type>                                        gigawatthour;
typedef Energy<float,
std::__ratio_multiply<wattyear::period,
std::mega>::type>                                        megawattyear;
typedef Energy<float,
std::__ratio_multiply<wattday::period,
std::giga>::type>                                        gigawattday;
typedef Energy<float, std::peta>                         petajoule;
typedef Energy<float,
std::__ratio_multiply<watthour::period,
std::tera>::type>                                        terawatthour;
typedef Energy<float,
std::__ratio_multiply<wattyear::period,
std::giga>::type>                                        gigawattyear;
typedef Energy<float,
std::__ratio_multiply<wattday::period,
std::tera>::type>                                        terawattday;
typedef Energy<float, std::exa>                          exajoule;
typedef Energy<float,
std::__ratio_multiply<watthour::period,
std::peta>::type>                                        petawatthour;




//=============================================================================
//=============================================================================
// CONSTANT ===================================================================
//=============================================================================
//=============================================================================



namespace constant
{





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
class Energy_common_type_wrapper
{
private:

  typedef std::__static_gcd<Period1::num, Period2::num> gcd_num;
  typedef std::__static_gcd<Period1::den, Period2::den> gcd_den;
  typedef typename CT::type common_rep;
  typedef std::ratio<gcd_num::value,
    (Period1::den / gcd_den::value) * Period2::den> new_ratio;

public:

  typedef std::__success_type<stb::Energy<common_rep, new_ratio>> type;
};


template<typename Period1, typename Period2>
class Energy_common_type_wrapper<std::__failure_type, Period1, Period2>
{
public:

  typedef std::__failure_type type;
};


template<typename Rep1, typename Period1, typename Rep2, typename Period2>
class common_type<stb::Energy<Rep1, Period1>, stb::Energy<Rep2, Period2>>
        : public Energy_common_type_wrapper<typename std::__member_type_wrapper<
        std::common_type<Rep1, Rep2>>::type, Period1, Period2>::type
{
};



}//namespace std






#endif //Energy_HH_
