//duration.hh

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

#ifndef OMNIUNIT_DURATION_HH_
#define OMNIUNIT_DURATION_HH_

#include "../omniunit.hh"
#include"constants_for_units.hh"


namespace omni
{



typedef Dimension<0,0,1,0,0,0,0> Duration;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctosecond = Unit<Duration, Rep, yocto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptosecond = Unit<Duration, Rep, zepto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attosecond = Unit<Duration, Rep, atto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtosecond = Unit<Duration, Rep, femto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picosecond = Unit<Duration, Rep, pico, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanosecond = Unit<Duration, Rep, nano, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microsecond = Unit<Duration, Rep, micro, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millisecond = Unit<Duration, Rep, milli, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centisecond = Unit<Duration, Rep, centi, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decisecond = Unit<Duration, Rep, deci, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using second = Unit<Duration, Rep, base, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decasecond = Unit<Duration, Rep, deca, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectosecond = Unit<Duration, Rep, hecto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilosecond = Unit<Duration, Rep, kilo, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megasecond = Unit<Duration, Rep, mega, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigasecond = Unit<Duration, Rep, giga, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using terasecond = Unit<Duration, Rep, tera, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petasecond = Unit<Duration, Rep, peta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exasecond = Unit<Duration, Rep, exa, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettasecond = Unit<Duration, Rep, zetta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottasecond = Unit<Duration, Rep, yotta, zero>;





template <typename Rep = OMNI_DEFAULT_TYPE>
using minute = Unit<Duration, Rep, Ratio<sixty, E0>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hour = Unit<Duration, Rep, Ratio<secondsPerHour, E0>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using day = Unit<Duration, Rep, Ratio<secondsPerDay, E0>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using week = Unit<Duration, Rep, Ratio<secondsPerWeek, E0>, zero>;

//be careful using month
//the month defined here is an average
//while a real month could have 28, 29, 30 or 31 days
template <typename Rep = OMNI_DEFAULT_TYPE>
using month = Unit<Duration, Rep, Ratio_over_value<
secondsPerYear, monthsPerYear>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using year = Unit<Duration, Rep, secondsPerYear, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kiloyear = Unit<Duration, Rep, typename Ratio_times_Ratio<
typename year<Rep>::period, kilo>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megayear = Unit<Duration, Rep, typename Ratio_times_Ratio<
typename year<Rep>::period, mega>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigayear = Unit<Duration, Rep, typename Ratio_times_Ratio<
typename year<Rep>::period, giga>::type, zero>;


typedef yoctosecond<> Yoctosecond;
typedef zeptosecond<> Zeptosecond;
typedef attosecond<> Attosecond;
typedef femtosecond<>  Femtosecond;
typedef picosecond<> Picosecond;
typedef nanosecond<> Nanosecond;
typedef microsecond<> Microsecond;
typedef millisecond<> Millisecond;
typedef centisecond<> Centisecond;
typedef decisecond<> Decisecond;
typedef second<> Second;
typedef decasecond<> Decasecond;
typedef hectosecond<> Hectosecond;
typedef kilosecond<> Kilosecond;
typedef megasecond<> Megasecond;
typedef gigasecond<> Gigasecond;
typedef terasecond<> Terasecond;
typedef petasecond<> Petasecond;
typedef exasecond<> Exasecond;
typedef zettasecond<> Zettasecond;
typedef yottasecond<> Yottasecond;

typedef minute<> Minute;
typedef hour<> Hour;
typedef day<> Day;
typedef week<> Week;
typedef month<> Month;
typedef year<> Year;
typedef kiloyear<> Kiloyear;
typedef megayear<> Megayear;
typedef gigayear<> Gigayear;


namespace suffixes
{



constexpr yoctosecond<OMNI_LITTERAL_FLOATING> operator"" _ys(long double val){return val;}
constexpr zeptosecond<OMNI_LITTERAL_FLOATING> operator"" _zs(long double val){return val;}
constexpr attosecond<OMNI_LITTERAL_FLOATING> operator"" _as(long double val){return val;}
constexpr femtosecond<OMNI_LITTERAL_FLOATING> operator"" _fs(long double val){return val;}
constexpr nanosecond<OMNI_LITTERAL_FLOATING> operator"" _ns(long double val){return val;}
constexpr microsecond<OMNI_LITTERAL_FLOATING> operator"" _us(long double val){return val;}
constexpr millisecond<OMNI_LITTERAL_FLOATING> operator"" _ms(long double val){return val;}
constexpr centisecond<OMNI_LITTERAL_FLOATING> operator"" _cs(long double val){return val;}
constexpr decisecond<OMNI_LITTERAL_FLOATING> operator"" _ds(long double val){return val;}
constexpr second<OMNI_LITTERAL_FLOATING> operator"" _s(long double val){return val;}
constexpr decasecond<OMNI_LITTERAL_FLOATING> operator"" _das(long double val){return val;}
constexpr hectosecond<OMNI_LITTERAL_FLOATING> operator"" _hs(long double val){return val;}
constexpr kilosecond<OMNI_LITTERAL_FLOATING> operator"" _ks(long double val){return val;}
constexpr megasecond<OMNI_LITTERAL_FLOATING> operator"" _Ms(long double val){return val;}
constexpr gigasecond<OMNI_LITTERAL_FLOATING> operator"" _Gs(long double val){return val;}
constexpr terasecond<OMNI_LITTERAL_FLOATING> operator"" _Ts(long double val){return val;}
constexpr petasecond<OMNI_LITTERAL_FLOATING> operator"" _Ps(long double val){return val;}
constexpr exasecond<OMNI_LITTERAL_FLOATING> operator"" _Es(long double val){return val;}
constexpr zettasecond<OMNI_LITTERAL_FLOATING> operator"" _Zs(long double val){return val;}
constexpr yottasecond<OMNI_LITTERAL_FLOATING> operator"" _Ys(long double val){return val;}

constexpr minute<OMNI_LITTERAL_FLOATING> operator"" _min(long double val){return val;}
constexpr hour<OMNI_LITTERAL_FLOATING> operator"" _h(long double val){return val;}
constexpr day<OMNI_LITTERAL_FLOATING> operator"" _d(long double val){return val;}
constexpr week<OMNI_LITTERAL_FLOATING> operator"" _w(long double val){return val;}
constexpr month<OMNI_LITTERAL_FLOATING> operator"" _mon(long double val){return val;}
constexpr year<OMNI_LITTERAL_FLOATING> operator"" _y(long double val){return val;}
constexpr kiloyear<OMNI_LITTERAL_FLOATING> operator"" _ky(long double val){return val;}
constexpr megayear<OMNI_LITTERAL_FLOATING> operator"" _My(long double val){return val;}
constexpr gigayear<OMNI_LITTERAL_FLOATING> operator"" _Gy(long double val){return val;}




constexpr yoctosecond<OMNI_LITTERAL_INTEGER> operator"" _ys(unsigned long long int val){return val;}
constexpr zeptosecond<OMNI_LITTERAL_INTEGER> operator"" _zs(unsigned long long int val){return val;}
constexpr attosecond<OMNI_LITTERAL_INTEGER> operator"" _as(unsigned long long int val){return val;}
constexpr femtosecond<OMNI_LITTERAL_INTEGER> operator"" _fs(unsigned long long int val){return val;}
constexpr nanosecond<OMNI_LITTERAL_INTEGER> operator"" _ns(unsigned long long int val){return val;}
constexpr microsecond<OMNI_LITTERAL_INTEGER> operator"" _us(unsigned long long int val){return val;}
constexpr millisecond<OMNI_LITTERAL_INTEGER> operator"" _ms(unsigned long long int val){return val;}
constexpr centisecond<OMNI_LITTERAL_INTEGER> operator"" _cs(unsigned long long int val){return val;}
constexpr decisecond<OMNI_LITTERAL_INTEGER> operator"" _ds(unsigned long long int val){return val;}
constexpr second<OMNI_LITTERAL_INTEGER> operator"" _s(unsigned long long int val){return val;}
constexpr decasecond<OMNI_LITTERAL_INTEGER> operator"" _das(unsigned long long int val){return val;}
constexpr hectosecond<OMNI_LITTERAL_INTEGER> operator"" _hs(unsigned long long int val){return val;}
constexpr kilosecond<OMNI_LITTERAL_INTEGER> operator"" _ks(unsigned long long int val){return val;}
constexpr megasecond<OMNI_LITTERAL_INTEGER> operator"" _Ms(unsigned long long int val){return val;}
constexpr gigasecond<OMNI_LITTERAL_INTEGER> operator"" _Gs(unsigned long long int val){return val;}
constexpr terasecond<OMNI_LITTERAL_INTEGER> operator"" _Ts(unsigned long long int val){return val;}
constexpr petasecond<OMNI_LITTERAL_INTEGER> operator"" _Ps(unsigned long long int val){return val;}
constexpr exasecond<OMNI_LITTERAL_INTEGER> operator"" _Es(unsigned long long int val){return val;}
constexpr zettasecond<OMNI_LITTERAL_INTEGER> operator"" _Zs(unsigned long long int val){return val;}
constexpr yottasecond<OMNI_LITTERAL_INTEGER> operator"" _Ys(unsigned long long int val){return val;}

constexpr minute<OMNI_LITTERAL_INTEGER> operator"" _min(unsigned long long int val){return val;}
constexpr hour<OMNI_LITTERAL_INTEGER> operator"" _h(unsigned long long int val){return val;}
constexpr day<OMNI_LITTERAL_INTEGER> operator"" _d(unsigned long long int val){return val;}
constexpr week<OMNI_LITTERAL_INTEGER> operator"" _w(unsigned long long int val){return val;}
constexpr month<OMNI_LITTERAL_INTEGER> operator"" _mon(unsigned long long int val){return val;}
constexpr year<OMNI_LITTERAL_INTEGER> operator"" _y(unsigned long long int val){return val;}
constexpr kiloyear<OMNI_LITTERAL_INTEGER> operator"" _ky(unsigned long long int val){return val;}
constexpr megayear<OMNI_LITTERAL_INTEGER> operator"" _My(unsigned long long int val){return val;}
constexpr gigayear<OMNI_LITTERAL_INTEGER> operator"" _Gy(unsigned long long int val){return val;}



} //namespaxe suffixes



} //namespace omni



#endif //OMNIUNIT_DURATION_HH_
