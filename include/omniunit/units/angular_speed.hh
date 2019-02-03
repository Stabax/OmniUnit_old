//angular_speed.hh

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

#ifndef ANGULAR_SPEED_HH_
#define ANGULAR_SPEED_HH_

#include "constants_for_units.hh"

namespace omni
{

typedef Dimension<0,0,-1,0,0,0,0> AngularSpeed;

template <typename Rep = OMNI_DEFAULT_TYPE>
using radianPerNanosecond = Unit<AngularSpeed, Rep, giga, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using radianPerMicrosecond = Unit<AngularSpeed, Rep, mega, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using radianPerMillisecond = Unit<AngularSpeed, Rep, kilo, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using radianPerSecond = Unit<AngularSpeed, Rep, base, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using radianPerMinute = Unit<AngularSpeed, Rep, Ratio<one, secondsPerMin>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using radianPerHour = Unit<AngularSpeed, Rep, Ratio<one, secondsPerHour>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using radianPerDay = Unit<AngularSpeed, Rep, Ratio<one, secondsPerDay>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using radianPerYear = Unit<AngularSpeed, Rep, typename Ratio_invert<secondsPerYear>::type, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using turnPerNanosecond = Unit<AngularSpeed, Rep, typename Ratio_over_Ratio<tau, nano>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using turnPerMicrosecond = Unit<AngularSpeed, Rep, typename Ratio_over_Ratio<tau, micro>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using turnPerMillisecond = Unit<AngularSpeed, Rep, typename Ratio_over_Ratio<tau, milli>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using turnPerSecond = Unit<AngularSpeed, Rep, tau, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using turnPerMinute = Unit<AngularSpeed, Rep, typename Ratio_over_value<tau, secondsPerMin>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using turnPerHour = Unit<AngularSpeed, Rep, typename Ratio_over_value<tau, secondsPerHour>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using turnPerDay = Unit<AngularSpeed, Rep, typename Ratio_over_value<tau, secondsPerDay>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using turnPerYear = Unit<AngularSpeed, Rep, typename Ratio_over_Ratio<tau, secondsPerYear>::type, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using degreePerNanosecond = Unit<AngularSpeed, Rep, typename Ratio_over_Ratio<typename Ratio_over_value<pi, degVal>::type, nano>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using degreePerMicrosecond = Unit<AngularSpeed, Rep, typename Ratio_over_Ratio<typename Ratio_over_value<pi, degVal>::type, micro>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using degreePerMillisecond = Unit<AngularSpeed, Rep, typename Ratio_over_Ratio<typename Ratio_over_value<pi, degVal>::type, milli>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using degreePerSecond = Unit<AngularSpeed, Rep, typename Ratio_over_value<pi, degVal>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using degreePerMinute = Unit<AngularSpeed, Rep, typename Ratio_over_value<typename Ratio_over_value<pi, degVal>::type, secondsPerMin>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using degreePerHour = Unit<AngularSpeed, Rep, typename Ratio_over_value<typename Ratio_over_value<pi, degVal>::type, secondsPerHour>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using degreePerDay = Unit<AngularSpeed, Rep, typename Ratio_over_value<typename Ratio_over_value<pi, degVal>::type, secondsPerDay>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using degreePerYear = Unit<AngularSpeed, Rep, typename Ratio_over_Ratio<typename Ratio_over_value<pi, degVal>::type, secondsPerYear>::type, zero>;



typedef radianPerNanosecond<> RadianPerNanosecond;
typedef radianPerMicrosecond<> RadianPerMicrosecond;
typedef radianPerMillisecond<> RadianPerMillisecond;
typedef radianPerSecond<> RadianPerSecond;
typedef radianPerMinute<> RadianPerMinute;
typedef radianPerHour<> RadianPerHour;
typedef radianPerDay<> RadianPerDay;
typedef radianPerYear<> RadianPerYear;
typedef turnPerNanosecond<> TurnPerNanosecond;
typedef turnPerMicrosecond<> TurnPerMicrosecond;
typedef turnPerMillisecond<> TurnPerMillisecond;
typedef turnPerSecond<> TurnPerSecond;
typedef turnPerMinute<> TurnPerMinute;
typedef turnPerHour<> TurnPerHour;
typedef turnPerDay<> TurnPerDay;
typedef turnPerYear<> TurnPerYear;
typedef degreePerNanosecond<> DegreePerNanosecond;
typedef degreePerMicrosecond<> DegreePerMicrosecond;
typedef degreePerMillisecond<> DegreePerMillisecond;
typedef degreePerSecond<> DegreePerSecond;
typedef degreePerMinute<> DegreenPerMinute;
typedef degreePerHour<> DegreePerHour;
typedef degreePerDay<> DegreePerDay;
typedef degreePerYear<> DegreePerYear;


namespace suffixes
{


constexpr radianPerNanosecond<OMNI_LITTERAL_FLOATING> operator"" _radPerns(long double val){return val;}
constexpr radianPerMicrosecond<OMNI_LITTERAL_FLOATING> operator"" _radPerus(long double val){return val;}
constexpr radianPerMillisecond<OMNI_LITTERAL_FLOATING> operator"" _radPerms(long double val){return val;}
constexpr radianPerSecond<OMNI_LITTERAL_FLOATING> operator"" _radPers(long double val){return val;}
constexpr radianPerMinute<OMNI_LITTERAL_FLOATING> operator"" _radPermin(long double val){return val;}
constexpr radianPerHour<OMNI_LITTERAL_FLOATING> operator"" _radPerh(long double val){return val;}
constexpr radianPerDay<OMNI_LITTERAL_FLOATING> operator"" _radPerd(long double val){return val;}
constexpr radianPerYear<OMNI_LITTERAL_FLOATING> operator"" _radPery(long double val){return val;}
constexpr turnPerNanosecond<OMNI_LITTERAL_FLOATING> operator"" _turnPerns(long double val){return val;}
constexpr turnPerMicrosecond<OMNI_LITTERAL_FLOATING> operator"" _turnPerus(long double val){return val;}
constexpr turnPerMillisecond<OMNI_LITTERAL_FLOATING> operator"" _turnPerms(long double val){return val;}
constexpr turnPerSecond<OMNI_LITTERAL_FLOATING> operator"" _turnPers(long double val){return val;}
constexpr turnPerMinute<OMNI_LITTERAL_FLOATING> operator"" _turnPermin(long double val){return val;}
constexpr turnPerHour<OMNI_LITTERAL_FLOATING> operator"" _turnPerh(long double val){return val;}
constexpr turnPerDay<OMNI_LITTERAL_FLOATING> operator"" _turnPerd(long double val){return val;}
constexpr turnPerYear<OMNI_LITTERAL_FLOATING> operator"" _turnPery(long double val){return val;}
constexpr degreePerNanosecond<OMNI_LITTERAL_FLOATING> operator"" _degPerns(long double val){return val;}
constexpr degreePerMicrosecond<OMNI_LITTERAL_FLOATING> operator"" _degPerus(long double val){return val;}
constexpr degreePerMillisecond<OMNI_LITTERAL_FLOATING> operator"" _degPerms(long double val){return val;}
constexpr degreePerSecond<OMNI_LITTERAL_FLOATING> operator"" _degPers(long double val){return val;}
constexpr degreePerMinute<OMNI_LITTERAL_FLOATING> operator"" _degPermin(long double val){return val;}
constexpr degreePerHour<OMNI_LITTERAL_FLOATING> operator"" _degPerh(long double val){return val;}
constexpr degreePerDay<OMNI_LITTERAL_FLOATING> operator"" _degPerd(long double val){return val;}
constexpr degreePerYear<OMNI_LITTERAL_FLOATING> operator"" _degPery(long double val){return val;}

constexpr radianPerNanosecond<OMNI_LITTERAL_INTEGER> operator"" _radPerns(unsigned long long int val){return val;}
constexpr radianPerMicrosecond<OMNI_LITTERAL_INTEGER> operator"" _radPerus(unsigned long long int val){return val;}
constexpr radianPerMillisecond<OMNI_LITTERAL_INTEGER> operator"" _radPerms(unsigned long long int val){return val;}
constexpr radianPerSecond<OMNI_LITTERAL_INTEGER> operator"" _radPers(unsigned long long int val){return val;}
constexpr radianPerMinute<OMNI_LITTERAL_INTEGER> operator"" _radPermin(unsigned long long int val){return val;}
constexpr radianPerHour<OMNI_LITTERAL_INTEGER> operator"" _radPerh(unsigned long long int val){return val;}
constexpr radianPerDay<OMNI_LITTERAL_INTEGER> operator"" _radPerd(unsigned long long int val){return val;}
constexpr radianPerYear<OMNI_LITTERAL_INTEGER> operator"" _radPery(unsigned long long int val){return val;}
constexpr turnPerNanosecond<OMNI_LITTERAL_INTEGER> operator"" _turnPerns(unsigned long long int val){return val;}
constexpr turnPerMicrosecond<OMNI_LITTERAL_INTEGER> operator"" _turnPerus(unsigned long long int val){return val;}
constexpr turnPerMillisecond<OMNI_LITTERAL_INTEGER> operator"" _turnPerms(unsigned long long int val){return val;}
constexpr turnPerSecond<OMNI_LITTERAL_INTEGER> operator"" _turnPers(unsigned long long int val){return val;}
constexpr turnPerMinute<OMNI_LITTERAL_INTEGER> operator"" _turnPermin(unsigned long long int val){return val;}
constexpr turnPerHour<OMNI_LITTERAL_INTEGER> operator"" _turnPerh(unsigned long long int val){return val;}
constexpr turnPerDay<OMNI_LITTERAL_INTEGER> operator"" _turnPerd(unsigned long long int val){return val;}
constexpr turnPerYear<OMNI_LITTERAL_INTEGER> operator"" _turnPery(unsigned long long int val){return val;}
constexpr degreePerNanosecond<OMNI_LITTERAL_INTEGER> operator"" _degPerns(unsigned long long int val){return val;}
constexpr degreePerMicrosecond<OMNI_LITTERAL_INTEGER> operator"" _degPerus(unsigned long long int val){return val;}
constexpr degreePerMillisecond<OMNI_LITTERAL_INTEGER> operator"" _degPerms(unsigned long long int val){return val;}
constexpr degreePerSecond<OMNI_LITTERAL_INTEGER> operator"" _degPers(unsigned long long int val){return val;}
constexpr degreePerMinute<OMNI_LITTERAL_INTEGER> operator"" _degPermin(unsigned long long int val){return val;}
constexpr degreePerHour<OMNI_LITTERAL_INTEGER> operator"" _degPerh(unsigned long long int val){return val;}
constexpr degreePerDay<OMNI_LITTERAL_INTEGER> operator"" _degPerd(unsigned long long int val){return val;}
constexpr degreePerYear<OMNI_LITTERAL_INTEGER> operator"" _degPery(unsigned long long int val){return val;}

} // namespace suffixes



} // namespace omni



#endif // ANGULAR_SPEED_HH_