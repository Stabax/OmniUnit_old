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



namespace omni
{


//=============================================================================
//=============================================================================
//=============================================================================
//=== DEVIATION CALCULATION ===================================================
//=============================================================================
//=============================================================================
//=============================================================================



enum class Probability {none, uniform, triangular, triangular_asym, normal, arcsinus, uniform_gap};


template <typename _Dimension, typename Period, double const& Origin>
float getDeviation(Basic_Unit<_Dimension, float, Period, Origin> variation, Probability law)
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

private:
  Basic_Unit<_Dimension, Rep, Period, Origin> _count;
  Basic_Unit<_Dimension, Rep, Period, Origin> _error; //standard error of _count
};


} //namespace omni



#endif //COMPLETE