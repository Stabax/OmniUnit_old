//moment_of_force.hh

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

#ifndef MOMENT_OF_FORCE_HH_
#define MOMENT_OF_FORCE_HH_

#include "constants_for_units.hh"



namespace omni
{



typedef Dimension<2,1,-2,0,0,0,0> MomentOfForce;


  template <typename Rep = OMNI_DEFAULT_TYPE>
  using newtonMeter = Unit<MomentOfForce, Rep, base, zero>;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using newtonMillimeter = Unit<MomentOfForce, Rep, milli, zero>;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using dyneCentimeter = Unit<MomentOfForce, Rep, Ratio<E0, E7>, zero>;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using kilogramforceMeter = Unit<MomentOfForce, Rep, Ratio<gE5, E5>, zero>;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using kilogramforceMillimeter = Unit<MomentOfForce, Rep, Ratio<gE5, E8>, zero>;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using poundforceFoot = Unit<MomentOfForce, Rep, Ratio<poundforceE13, E13>, zero>;

typedef newtonMeter<> NewtonMeter;
typedef newtonMillimeter<> NewtonMillimeter;
typedef dyneCentimeter<> DyneCentimeter;
typedef kilogramforceMeter<> KilogramforceMeter;
typedef kilogramforceMillimeter<> KilogramforceMillimeter;
typedef poundforceFoot<> PoundforceFoot;

namespace suffixes
{



  constexpr newtonMeter<OMNI_LITTERAL_FLOATING> operator"" _Nm(long double val) {return val;}
  constexpr newtonMillimeter<OMNI_LITTERAL_FLOATING> operator"" _Nmm(long double val) {return val;}
  constexpr dyneCentimeter<OMNI_LITTERAL_FLOATING> operator"" _dyncm(long double val) {return val;}
  constexpr kilogramforceMeter<OMNI_LITTERAL_FLOATING> operator"" _kgfm(long double val) {return val;}
  constexpr kilogramforceMillimeter<OMNI_LITTERAL_FLOATING> operator""_kgfmm (long double val) {return val;}
  constexpr poundforceFoot<OMNI_LITTERAL_FLOATING> operator""_lbfft (long double val) {return val;}

  constexpr newtonMeter<OMNI_LITTERAL_INTEGER> operator"" _Nm(unsigned long long int val) {return val;}
  constexpr newtonMillimeter<OMNI_LITTERAL_INTEGER> operator"" _Nmm(unsigned long long int val) {return val;}
  constexpr dyneCentimeter<OMNI_LITTERAL_INTEGER> operator"" _dyncm(unsigned long long int val) {return val;}
  constexpr kilogramforceMeter<OMNI_LITTERAL_INTEGER> operator"" _kgfm(unsigned long long int val) {return val;}
  constexpr kilogramforceMillimeter<OMNI_LITTERAL_INTEGER> operator""_kgfmm (unsigned long long int val) {return val;}
  constexpr poundforceFoot<OMNI_LITTERAL_INTEGER> operator""_lbfft (unsigned long long int val) {return val;}



}



}



#endif // MOMENT_OF_FORCE_HH_