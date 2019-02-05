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
using radianPerMinute = Unit<AngularSpeed, Rep, Ratio<one, sixty>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using radianPerHour = Unit<AngularSpeed, Rep, Ratio<one, secondsPerHour>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using radianPerDay = Unit<AngularSpeed, Rep, Ratio<one, secondsPerDay>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using radianPerYear = Unit<AngularSpeed, Rep, typename Ratio_invert<secondsPerYear>::type, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using revolutionPerNanosecond = Unit<AngularSpeed, Rep, typename Ratio_over_Ratio<tau, nano>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using revolutionPerMicrosecond = Unit<AngularSpeed, Rep, typename Ratio_over_Ratio<tau, micro>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using revolutionPerMillisecond = Unit<AngularSpeed, Rep, typename Ratio_over_Ratio<tau, milli>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using revolutionPerSecond = Unit<AngularSpeed, Rep, tau, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using revolutionPerMinute = Unit<AngularSpeed, Rep, typename Ratio_over_value<tau, sixty>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using revolutionPerHour = Unit<AngularSpeed, Rep, typename Ratio_over_value<tau, secondsPerHour>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using revolutionPerDay = Unit<AngularSpeed, Rep, typename Ratio_over_value<tau, secondsPerDay>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using revolutionPerYear = Unit<AngularSpeed, Rep, typename Ratio_over_Ratio<tau, secondsPerYear>::type, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using degreePerNanosecond = Unit<AngularSpeed, Rep, typename Ratio_over_Ratio<typename Ratio_over_value<pi, degDef>::type, nano>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using degreePerMicrosecond = Unit<AngularSpeed, Rep, typename Ratio_over_Ratio<typename Ratio_over_value<pi, degDef>::type, micro>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using degreePerMillisecond = Unit<AngularSpeed, Rep, typename Ratio_over_Ratio<typename Ratio_over_value<pi, degDef>::type, milli>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using degreePerSecond = Unit<AngularSpeed, Rep, typename Ratio_over_value<pi, degDef>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using degreePerMinute = Unit<AngularSpeed, Rep, typename Ratio_over_value<typename Ratio_over_value<pi, degDef>::type, sixty>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using degreePerHour = Unit<AngularSpeed, Rep, typename Ratio_over_value<typename Ratio_over_value<pi, degDef>::type, secondsPerHour>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using degreePerDay = Unit<AngularSpeed, Rep, typename Ratio_over_value<typename Ratio_over_value<pi, degDef>::type, secondsPerDay>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using degreePerYear = Unit<AngularSpeed, Rep, typename Ratio_over_Ratio<typename Ratio_over_value<pi, degDef>::type, secondsPerYear>::type, zero>;



typedef radianPerNanosecond<> RadianPerNanosecond;
typedef radianPerMicrosecond<> RadianPerMicrosecond;
typedef radianPerMillisecond<> RadianPerMillisecond;
typedef radianPerSecond<> RadianPerSecond;
typedef radianPerMinute<> RadianPerMinute;
typedef radianPerHour<> RadianPerHour;
typedef radianPerDay<> RadianPerDay;
typedef radianPerYear<> RadianPerYear;
typedef revolutionPerNanosecond<> RevolutionPerNanosecond;
typedef revolutionPerMicrosecond<> RevolutionPerMicrosecond;
typedef revolutionPerMillisecond<> RevolutionPerMillisecond;
typedef revolutionPerSecond<> RevolutionPerSecond;
typedef revolutionPerMinute<> RevolutionPerMinute;
typedef revolutionPerHour<> RevolutionPerHour;
typedef revolutionPerDay<> RevolutionPerDay;
typedef revolutionPerYear<> RevolutionPerYear;
typedef degreePerNanosecond<> DegreePerNanosecond;
typedef degreePerMicrosecond<> DegreePerMicrosecond;
typedef degreePerMillisecond<> DegreePerMillisecond;
typedef degreePerSecond<> DegreePerSecond;
typedef degreePerMinute<> DegreenPerMinute;
typedef degreePerHour<> DegreePerHour;
typedef degreePerDay<> DegreePerDay;
typedef degreePerYear<> DegreePerYear;


} // namespace omni



#endif // ANGULAR_SPEED_HH_