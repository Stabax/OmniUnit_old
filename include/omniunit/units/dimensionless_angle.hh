//dimensionless_angle.hh

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

#ifndef DIMENSIONLESS_ANGLE_HH_
#define DIMENSIONLESS_ANGLE_HH_

#include "constants_for_units.hh"


namespace omni
{


template <typename Rep = OMNI_DEFAULT_TYPE>
using value = Unit<Dimensionless, Rep, base, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using radian = Unit<Dimensionless, Rep, base, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using milliradian = Unit<Dimensionless, Rep, milli, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using revolution = Unit<Dimensionless, Rep, tau, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using degree = Unit<Dimensionless, Rep, typename Ratio_over_value<pi, degDef>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using grad = Unit<Dimensionless, Rep, typename Ratio_over_value<pi, gradDef>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using arcminute = Unit<Dimensionless, Rep, typename Ratio_over_value<typename degree<Rep>::period, sixty>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using arcsecond = Unit<Dimensionless, Rep, typename Ratio_over_value<typename degree<Rep>::period, secondsPerHour>::type, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using steradian = Unit<Dimensionless, Rep, base, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hemisphere = Unit<Dimensionless, Rep, tau, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using sphere = Unit<Dimensionless, Rep, typename value_times_Ratio<four, pi>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using  degree2 = Unit<Dimensionless, Rep, typename Ratio_power<typename degree<Rep>::period, 2>::type, zero>;


typedef value<> Value;
typedef radian<> Radian;
typedef milliradian<> Milliradian;
typedef revolution<> Revolution;
typedef degree<> Degree;
typedef grad<> Grad;
typedef arcminute<> Arcminute;
typedef arcsecond<>Arcsecond;
typedef steradian<> Steradian;
typedef hemisphere<> Hemisphere;
typedef sphere<> Sphere;
typedef degree2<> Degree2;



namespace suffixes
{



constexpr value<OMNI_LITTERAL_FLOATING> operator"" _(long double val){return val;}
constexpr radian<OMNI_LITTERAL_FLOATING> operator"" _rad(long double val){return val;}
constexpr milliradian<OMNI_LITTERAL_FLOATING> operator"" _mrad(long double val){return val;}
constexpr revolution<OMNI_LITTERAL_FLOATING> operator"" _rev(long double val){return val;}
constexpr degree<OMNI_LITTERAL_FLOATING> operator"" _deg(long double val){return val;}
constexpr grad<OMNI_LITTERAL_FLOATING> operator"" _grad(long double val){return val;}
constexpr arcminute<OMNI_LITTERAL_FLOATING> operator"" _arcmin(long double val){return val;}
constexpr arcsecond<OMNI_LITTERAL_FLOATING> operator"" _arcs(long double val){return val;}
constexpr steradian<OMNI_LITTERAL_FLOATING> operator"" _sr(long double val){return val;}
constexpr hemisphere<OMNI_LITTERAL_FLOATING> operator"" _hsphe(long double val){return val;}
constexpr sphere<OMNI_LITTERAL_FLOATING> operator"" _sphe(long double val){return val;}
constexpr degree2<OMNI_LITTERAL_FLOATING> operator"" _deg2(long double val){return val;}

constexpr value<OMNI_LITTERAL_INTEGER> operator"" _(unsigned long long int val){return val;}
constexpr radian<OMNI_LITTERAL_INTEGER> operator"" _rad(unsigned long long int val){return val;}
constexpr milliradian<OMNI_LITTERAL_INTEGER> operator"" _mrad(unsigned long long int val){return val;}
constexpr revolution<OMNI_LITTERAL_INTEGER> operator"" _rev(unsigned long long int val){return val;}
constexpr degree<OMNI_LITTERAL_INTEGER> operator"" _deg(unsigned long long int val){return val;}
constexpr grad<OMNI_LITTERAL_INTEGER> operator"" _grad(unsigned long long int val){return val;}
constexpr arcminute<OMNI_LITTERAL_INTEGER> operator"" _arcmin(unsigned long long int val){return val;}
constexpr arcsecond<OMNI_LITTERAL_INTEGER> operator"" _arcs(unsigned long long int val){return val;}
constexpr steradian<OMNI_LITTERAL_INTEGER> operator"" _sr(unsigned long long int val){return val;}
constexpr hemisphere<OMNI_LITTERAL_INTEGER> operator"" _hsphe(unsigned long long int val){return val;}
constexpr sphere<OMNI_LITTERAL_INTEGER> operator"" _sphe(unsigned long long int val){return val;}
constexpr degree2<OMNI_LITTERAL_INTEGER> operator"" _deg2(unsigned long long int val){return val;}



} // namespace suffixes



} //namespace omni


#endif //DIMENSIONLESS_ANGLE_HH_