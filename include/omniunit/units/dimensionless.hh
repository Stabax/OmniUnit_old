//dimensionless.hh

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

#ifndef DIMENSIONLESS_HH_
#define DIMENSIONLESS_HH_

#include"constants_for_units.hh"


namespace omni
{


template <typename Rep = OMNI_DEFAULT_TYPE>
using value = Unit<Dimensionless, Rep, base, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using radian = Unit<Dimensionless, Rep, base, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using milliradian = Unit<Dimensionless, Rep, milli, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using turn = Unit<Dimensionless, Rep, typename value_times_Ratio<two, pi>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using degree = Unit<Dimensionless, Rep, typename Ratio_over_value<pi, degVal>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using grad = Unit<Dimensionless, Rep, typename Ratio_over_value<pi, gradVal>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using minutearc = Unit<Dimensionless, Rep, typename Ratio_over_value<typename degree<Rep>::period, secondsPerMin>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using secondarc = Unit<Dimensionless, Rep, typename Ratio_over_value<typename degree<Rep>::period, secondsPerHour>::type, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using steradian = Unit<Dimensionless, Rep, base, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hemishpere = Unit<Dimensionless, Rep, typename value_times_Ratio<two, pi>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using shpere = Unit<Dimensionless, Rep, typename value_times_Ratio<four, pi>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using  degree2 = Unit<Dimensionless, Rep, typename Ratio_power<typename degree<Rep>::period, 2>::type, zero>;


typedef value<> Value;
typedef radian<> Radian;
typedef milliradian<> Milliradian;
typedef turn<> Turn;
typedef degree<> Degree;
typedef grad<> Grad;
typedef minutearc<> Minutearc;
typedef secondarc<> Secondarc;
typedef steradian<> Steradian;
typedef hemishpere<> Hemisphere;
typedef shpere<> Sphere;
typedef degree2<> Degree2;



namespace suffixes
{



constexpr Value operator"" _val(long double val){return val;}
constexpr Radian operator"" _rad(long double val){return val;}
constexpr Milliradian operator"" _mrad(long double val){return val;}
constexpr Turn operator"" _turn(long double val){return val;}
constexpr Degree operator"" _deg(long double val){return val;}
constexpr Grad operator"" _grad(long double val){return val;}
constexpr Minutearc operator"" _minarc(long double val){return val;}
constexpr Secondarc operator"" _sarc(long double val){return val;}
constexpr Steradian operator"" _sr(long double val){return val;}
constexpr Hemisphere operator"" _hsphe(long double val){return val;}
constexpr Sphere operator"" _sphe(long double val){return val;}
constexpr Degree2 operator"" _deg2(long double val){return val;}

constexpr Value operator"" _val(unsigned long long int val){return val;}
constexpr Radian operator"" _rad(unsigned long long int val){return val;}
constexpr Milliradian operator"" _mrad(unsigned long long int val){return val;}
constexpr Turn operator"" _turn(unsigned long long int val){return val;}
constexpr Degree operator"" _deg(unsigned long long int val){return val;}
constexpr Grad operator"" _grad(unsigned long long int val){return val;}
constexpr Minutearc operator"" _minarc(unsigned long long int val){return val;}
constexpr Secondarc operator"" _sarc(unsigned long long int val){return val;}
constexpr Steradian operator"" _sr(unsigned long long int val){return val;}
constexpr Hemisphere operator"" _hsphe(unsigned long long int val){return val;}
constexpr Sphere operator"" _sphe(unsigned long long int val){return val;}
constexpr Degree2 operator"" _deg2(unsigned long long int val){return val;}



} // namespace suffixes



} //namespace omni


#endif //DIMENSIONLESS_HH_