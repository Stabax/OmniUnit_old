//Complete_Unit.hh

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



#ifndef OMNIUNIT_COMPLETE_UNIT_HH_
#define OMNIUNIT_COMPLETE_UNIT_HH_


#include "Basic_Unit.hh"



#ifdef OMNI_ENABLE_UNCERTAINTIES



namespace omni
{



//=============================================================================
//=============================================================================
//=============================================================================
//=== DEVIATION CALCULATION ===================================================
//=============================================================================
//=============================================================================
//=============================================================================



enum class Law {none, uniform, triangular, asymetric, normal, arcsinus, uniform_gap};


template <typename _Dimension, typename Period, double const& Origin>
float getDeviation(Basic_Unit<_Dimension, float, Period, Origin> variation, Law law)
{
  if(law == Law::none)
    return variation;
  else if(law == Law::uniform)
    return variation / std::sqrt(3.);
  else if(law == Law::triangular)
    return variation / std::sqrt(6.);
  else if(law == Law::asymetric)
    return variation / (3. * std::sqrt(2.)); //average = val min (or max) +/- variation/3
  else if(law == Law::arcsinus)
    return variation / std::sqrt(2.);
  else if(law == Law::normal)
    return variation / 3.;
  else if(law == Law::uniform_gap)
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


//=============================================================================
//=============================================================================
//=============================================================================
//=== COMPLETE UNIT CAST ======================================================
//=============================================================================
//=============================================================================
//=============================================================================

//Complete_Unit represents a unit handling uncertainties


//forward declaration
//origin is given in official unit (ratio<1, 1>)
template<typename _Dimension, typename Rep, typename Period, double const& Origin>
class Complete_Unit;


template<typename falseType>
struct is_Complete_Unit : std::false_type
{
};


template<typename Dimension, typename Rep, typename Period, double const& Origin>
struct is_Complete_Unit<Complete_Unit<Dimension, Rep, Period, Origin>> : public std::true_type
{
};


template<typename toUnit, typename Dimension, typename Rep, typename Period, double const& Origin,
typename = typename std::enable_if<is_Complete_Unit<toUnit>::value, toUnit>::type>
constexpr toUnit unit_cast(const Complete_Unit<Dimension, Rep, Period, Origin>& Obj)
{
  static_assert(std::is_same<typename toUnit::dim, Dimension>::value, "Cannot cast different dimensions.");
  return toUnit(unit_cast<Basic_Unit<Dimension, Rep, Period, Origin>>(Obj.value()).count(),
                unit_cast<Basic_Unit<Dimension, Rep, Period, Origin>>(Obj.error()).count());
}


template<typename T, typename Dimension, typename Rep, typename Period, double const& Origin,
typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
constexpr Complete_Unit<Dimension, T, Period, Origin> unit_cast(const Complete_Unit<Dimension, Rep, Period, Origin>& Obj)
{
  return unit_cast<Complete_Unit<Dimension, T, Period, Origin>>(Obj);
}


template<typename R, typename Dimension, typename Rep, typename Period, double const& Origin,
typename = typename std::enable_if<is_stb_Ratio<R>::value, R>::type>
constexpr Complete_Unit<Dimension, Rep, R, Origin> unit_cast(const Complete_Unit<Dimension, Rep, Period, Origin>& Obj)
{
  return unit_cast<Complete_Unit<Dimension, Rep, R, Origin>>(Obj);
}


template<double const& O, typename Dimension, typename Rep, typename Period, double const& Origin>
constexpr Complete_Unit<Dimension, Rep, Period, O> unit_cast(const Complete_Unit<Dimension, Rep, Period, Origin>& Obj)
{
  return unit_cast<Complete_Unit<Dimension, Rep, Period, O>>(Obj);
}


//=============================================================================
//=============================================================================
//=============================================================================
//=== BASIC UNIT CAST OVERLOAD FOR UNIT<TIME> =================================
//=============================================================================
//=============================================================================
//=============================================================================

//the purpose here is to make available unit_cast between omni::Unit<duration> and std::chrono::duration


//called if toUnit equals omniunit::duration
//cast omniunit::duration to another omniunit::duration
template <typename toUnit, typename Rep, typename Period, double const& Origin>
constexpr toUnit unit_cast_impl(
partial_specialization_wrapper<Complete_Unit<Dimension<0,0,1,0,0,0,0,0,0>, typename toUnit::rep, typename toUnit::period, toUnit::origin>>,
Complete_Unit<Dimension<0,0,1,0,0,0,0,0,0>, Rep, Period, Origin> const& Obj)
{
  return unit_cast<toUnit, Dimension<0,0,1,0,0,0,0,0,0>>(Obj);
}


//called if toUnit equals std::chrono::duration
//cast omniunit::duration to std::chrono::duration
template <typename toUnit, typename Rep, typename Period, double const& Origin>
constexpr toUnit unit_cast_impl(
partial_specialization_wrapper<std::chrono::duration<typename toUnit::rep, typename toUnit::period>>,
Complete_Unit<Dimension<0,0,1,0,0,0,0,0,0>, Rep, Period, Origin> const& Obj)
{
  return toUnit(Obj);
}


//cast omniunit::duration to toUnit
template <typename toUnit, typename Rep, typename Period, double const& Origin>
constexpr toUnit unit_cast(Complete_Unit<Dimension<0,0,1,0,0,0,0,0,0>, Rep, Period, Origin> const& Obj)
{
  return unit_cast_impl<toUnit>(partial_specialization_wrapper<toUnit>{}, Obj);
}


//called if toUnit equals omniunit::duration
//cast std::chrono::duration to omniunit::duration
template <typename toUnit, typename Rep, typename Period>
constexpr toUnit unit_cast_impl(
partial_specialization_wrapper<Complete_Unit<Dimension<0,0,1,0,0,0,0,0,0>, typename toUnit::rep, typename toUnit::period, toUnit::origin>>,
std::chrono::duration<Rep, Period> const& Obj)
{
  return toUnit(Obj);
}


//the unit_cast_impl function called when toUnit equals std::chrono::duration
//to cast std::chrono::duration to another std::chrono::duration is defined in Basic_Unit.hh


//The unit_cast function called to cast std::chrono::duration to toUnit
//is defined in Basic_Unit.hh



//=============================================================================
//=============================================================================
//=============================================================================
//=== COMPLETE_UNIT DEFINITION ================================================
//=============================================================================
//=============================================================================
//=============================================================================



template <typename _Dimension, typename Rep, typename Period, double const& Origin>
class Complete_Unit
{
  typedef _Dimension dim;
  typedef Rep rep;
  typedef Period period;
  inline static constexpr double origin = Origin;

  static_assert(is_Dimension<_Dimension>::value, "First template argument sould be a dimension.");
  static_assert(std::is_arithmetic<Rep>::value, "Second template argument should be an arithmetic type.");
  static_assert(is_stb_Ratio<Period>::value, "Third template argument should be an OmniUnit ratio.");


  constexpr Complete_Unit():
  _count(),
  _error()
  {
  }


  template<typename _RepC, typename _RepE, typename _RepEn, typename = typename std::enable_if<std::is_arithmetic<_RepC>::value && std::is_arithmetic<_RepE>::value, _RepC>::type>
  constexpr Complete_Unit(_RepC countArg, _RepE countErr, _RepEn enlargement = 1):
  _count(static_cast<Rep>(countArg)),
  _error(static_cast<Rep>(countErr / static_cast<_RepE>(enlargement)))
  {
  }


  template<typename _Rep, typename _Period, double const& _Origin>
  constexpr Complete_Unit(Complete_Unit<dim, _Rep, _Period, _Origin> const& Obj):
  Complete_Unit(unit_cast<Basic_Unit, dim>(Obj).count(), unit_cast<Basic_Unit, dim>(Obj).sigma())
  {
  }


  template<typename _Rep, typename _Period> //std::chrono::duration has no Origin parameter
  constexpr Complete_Unit(std::chrono::duration<_Rep, _Period> const& Obj, Complete_Unit<dim, _Rep, Period, zero> const& err = Complete_Unit<dim, _Rep, Period, zero>::zero()):
  Complete_Unit(Complete_Unit<dim, _Rep, typename Ratio_std_to_omni<_Period>::type, Origin>(Obj.count(), err.sigma()))
  {
    static_assert(std::is_same<dim, Dimension<0,0,1,0,0,0,0,0,0>>::value, "Only a duration is constructible with an std::chrono::duration");
  }


  constexpr Rep count() const
  {
    return _count.count();
  }


  constexpr Basic_Unit<_Dimension, Rep, Period, Origin> value() const
  {
    return _count;
  }


  template <typename T>
  constexpr Basic_Unit<_Dimension, Rep, Period, Origin> error(T enlargement = 1) const
  {
    static_assert(std::is_arithmetic<T>::value, "Enlargement factor must be arithmetic.");
    return _error * static_cast<Rep>(enlargement);
  }

  template <typename T>
  constexpr Rep sigma(T enlargement = 1) const
  {
    static_assert(std::is_arithmetic<T>::value, "Enlargement factor must be arithmetic.");
    return _error.count() * static_cast<Rep>(enlargement);
  }

private:
  Basic_Unit<_Dimension, Rep, Period, Origin> _count;
  Basic_Unit<_Dimension, Rep, Period, Origin> _error; //standard error of _count (not deviation)
};


} //namespace omni



#endif //OMNI_ENABLE_UNCERTAINTIES



#endif //OMNIUNIT_COMPLETE_UNIT_HH_