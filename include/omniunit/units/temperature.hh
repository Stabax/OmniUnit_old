//temperature.hh

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

#ifndef TEMPERATURE_HH_
#define TEMPERATURE_HH_

#include"constants_for_units.hh"


namespace omni
{



typedef Dimension<0,0,0,0,1,0,0> Temperature;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctokelvin = Unit<Temperature, Rep, yocto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptokelvin = Unit<Temperature, Rep, zepto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attokelvin = Unit<Temperature, Rep, atto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtokelvin = Unit<Temperature, Rep, femto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picokelvin = Unit<Temperature, Rep, pico, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanokelvin = Unit<Temperature, Rep, nano, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microkelvin = Unit<Temperature, Rep, micro, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millikelvin = Unit<Temperature, Rep, milli, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centikelvin = Unit<Temperature, Rep, centi, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decikelvin = Unit<Temperature, Rep, deci, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kelvin = Unit<Temperature, Rep, base, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decakelvin = Unit<Temperature, Rep, deca, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectokelvin = Unit<Temperature, Rep, hecto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilokelvin = Unit<Temperature, Rep, kilo, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megakelvin = Unit<Temperature, Rep, mega, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigakelvin = Unit<Temperature, Rep, giga, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using terakelvin = Unit<Temperature, Rep, tera, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petakelvin = Unit<Temperature, Rep, peta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exakelvin = Unit<Temperature, Rep, exa, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettakelvin = Unit<Temperature, Rep, zetta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottakelvin = Unit<Temperature, Rep, yotta, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctocelsius = Unit<Temperature, Rep, yocto, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptocelsius = Unit<Temperature, Rep, zepto, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attocelsius = Unit<Temperature, Rep, atto, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtocelsius = Unit<Temperature, Rep, femto, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picocelsius = Unit<Temperature, Rep, pico, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanocelsius = Unit<Temperature, Rep, nano, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microcelsius = Unit<Temperature, Rep, micro, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millicelsius = Unit<Temperature, Rep, milli, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centicelsius = Unit<Temperature, Rep, centi, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decicelsius = Unit<Temperature, Rep, deci, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using celsius = Unit<Temperature, Rep, base, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decacelsius = Unit<Temperature, Rep, deca, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectocelsius = Unit<Temperature, Rep, hecto, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilocelsius = Unit<Temperature, Rep, kilo, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megacelsius = Unit<Temperature, Rep, mega, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigacelsius = Unit<Temperature, Rep, giga, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using teracelsius = Unit<Temperature, Rep, tera, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petacelsius = Unit<Temperature, Rep, peta, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exacelsius = Unit<Temperature, Rep, exa, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettacelsius = Unit<Temperature, Rep, zetta, celsiusConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottacelsius = Unit<Temperature, Rep, yotta, celsiusConstant>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctofahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, yocto>::type, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptofahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, zepto>::type, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attofahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, atto>::type, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtofahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, femto>::type, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picofahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, pico>::type, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanofahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, nano>::type, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microfahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, micro>::type, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millifahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, milli>::type, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centifahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, centi>::type, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decifahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, deci>::type, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using fahrenheit = Unit<Temperature, Rep, fahrenheitRatio, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decafahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, deca>::type, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectofahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, hecto>::type, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilofahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, kilo>::type, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megafahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, mega>::type, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigafahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, giga>::type, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using terafahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, tera>::type, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petafahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, peta>::type, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exafahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, exa>::type, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettafahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, zetta>::type, fahrenheitConstant>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottafahrenheit = Unit<Temperature, Rep, typename Ratio_times_Ratio<fahrenheitRatio, yotta>::type, fahrenheitConstant>;


typedef yoctokelvin<> Yoctokelvin;
typedef zeptokelvin<> Zeptokelvin;
typedef attokelvin<> Attokelvin;
typedef femtokelvin<>  Femtokelvin;
typedef picokelvin<> Picokelvin;
typedef nanokelvin<> Nanokelvin;
typedef microkelvin<> Microkelvin;
typedef millikelvin<> Millikelvin;
typedef centikelvin<> Centikelvin;
typedef decikelvin<> Decikelvin;
typedef kelvin<> Kelvin;
typedef decakelvin<> Decakelvin;
typedef hectokelvin<> Hectokelvin;
typedef kilokelvin<> Kilokelvin;
typedef megakelvin<> Megakelvin;
typedef gigakelvin<> Gigakelvin;
typedef terakelvin<> Terakelvin;
typedef petakelvin<> Petakelvin;
typedef exakelvin<> Exakelvin;
typedef zettakelvin<> Zettakelvin;
typedef yottakelvin<> Yottakelvin;



typedef yoctocelsius<> Yoctocelsius;
typedef zeptocelsius<> Zeptocelsius;
typedef attocelsius<> Attocelsius;
typedef femtocelsius<>  Femtocelsius;
typedef picocelsius<> Picocelsius;
typedef nanocelsius<> Nanocelsius;
typedef microcelsius<> Microcelsius;
typedef millicelsius<> Millicelsius;
typedef centicelsius<> Centicelsius;
typedef decicelsius<> Decicelsius;
typedef celsius<> Celsius;
typedef decacelsius<> Decacelsius;
typedef hectocelsius<> Hectocelsius;
typedef kilocelsius<> Kilocelsius;
typedef megacelsius<> Megacelsius;
typedef gigacelsius<> Gigacelsius;
typedef teracelsius<> Teracelsius;
typedef petacelsius<> Petacelsius;
typedef exacelsius<> Exacelsius;
typedef zettacelsius<> Zettacelsius;
typedef yottacelsius<> Yottacelsius;



typedef yoctofahrenheit<> Yoctofahrenheit;
typedef zeptofahrenheit<> Zeptofahrenheit;
typedef attofahrenheit<> Attofahrenheit;
typedef femtofahrenheit<>  Femtofahrenheit;
typedef picofahrenheit<> Picofahrenheit;
typedef nanofahrenheit<> Nanofahrenheit;
typedef microfahrenheit<> Microfahrenheit;
typedef millifahrenheit<> Millifahrenheit;
typedef centifahrenheit<> Centifahrenheit;
typedef decifahrenheit<> Decifahrenheit;
typedef fahrenheit<> Fahrenheit;
typedef decafahrenheit<> Decafahrenheit;
typedef hectofahrenheit<> Hectofahrenheit;
typedef kilofahrenheit<> Kilofahrenheit;
typedef megafahrenheit<> Megafahrenheit;
typedef gigafahrenheit<> Gigafahrenheit;
typedef terafahrenheit<> Terafahrenheit;
typedef petafahrenheit<> Petafahrenheit;
typedef exafahrenheit<> Exafahrenheit;
typedef zettafahrenheit<> Zettafahrenheit;
typedef yottafahrenheit<> Yottafahrenheit;


namespace suffixes
{



constexpr yoctokelvin<OMNI_LITTERAL_FLOATING> operator"" _yK(long double val){return val;}
constexpr zeptokelvin<OMNI_LITTERAL_FLOATING> operator"" _zK(long double val){return val;}
constexpr attokelvin<OMNI_LITTERAL_FLOATING> operator"" _aK(long double val){return val;}
constexpr femtokelvin<OMNI_LITTERAL_FLOATING> operator"" _fK(long double val){return val;}
constexpr nanokelvin<OMNI_LITTERAL_FLOATING> operator"" _nK(long double val){return val;}
constexpr microkelvin<OMNI_LITTERAL_FLOATING> operator"" _uK(long double val){return val;}
constexpr millikelvin<OMNI_LITTERAL_FLOATING> operator"" _mK(long double val){return val;}
constexpr centikelvin<OMNI_LITTERAL_FLOATING> operator"" _cK(long double val){return val;}
constexpr decikelvin<OMNI_LITTERAL_FLOATING> operator"" _dK(long double val){return val;}
constexpr kelvin<OMNI_LITTERAL_FLOATING> operator"" _K(long double val){return val;}
constexpr decakelvin<OMNI_LITTERAL_FLOATING> operator"" _daK(long double val){return val;}
constexpr hectokelvin<OMNI_LITTERAL_FLOATING> operator"" _hK(long double val){return val;}
constexpr kilokelvin<OMNI_LITTERAL_FLOATING> operator"" _kK(long double val){return val;}
constexpr megakelvin<OMNI_LITTERAL_FLOATING> operator"" _MK(long double val){return val;}
constexpr gigakelvin<OMNI_LITTERAL_FLOATING> operator"" _GK(long double val){return val;}
constexpr terakelvin<OMNI_LITTERAL_FLOATING> operator"" _TK(long double val){return val;}
constexpr petakelvin<OMNI_LITTERAL_FLOATING> operator"" _PK(long double val){return val;}
constexpr exakelvin<OMNI_LITTERAL_FLOATING> operator"" _EK(long double val){return val;}
constexpr zettakelvin<OMNI_LITTERAL_FLOATING> operator"" _ZK(long double val){return val;}
constexpr yottakelvin<OMNI_LITTERAL_FLOATING> operator"" _YK(long double val){return val;}

constexpr yoctocelsius<OMNI_LITTERAL_FLOATING> operator"" _yc(long double val){return val;}
constexpr zeptocelsius<OMNI_LITTERAL_FLOATING> operator"" _zc(long double val){return val;}
constexpr attocelsius<OMNI_LITTERAL_FLOATING> operator"" _ac(long double val){return val;}
constexpr femtocelsius<OMNI_LITTERAL_FLOATING> operator"" _fc(long double val){return val;}
constexpr nanocelsius<OMNI_LITTERAL_FLOATING> operator"" _nc(long double val){return val;}
constexpr microcelsius<OMNI_LITTERAL_FLOATING> operator"" _uc(long double val){return val;}
constexpr millicelsius<OMNI_LITTERAL_FLOATING> operator"" _mc(long double val){return val;}
constexpr centicelsius<OMNI_LITTERAL_FLOATING> operator"" _cc(long double val){return val;}
constexpr decicelsius<OMNI_LITTERAL_FLOATING> operator"" _dc(long double val){return val;}
constexpr celsius<OMNI_LITTERAL_FLOATING> operator"" _c(long double val){return val;}
constexpr decacelsius<OMNI_LITTERAL_FLOATING> operator"" _dac(long double val){return val;}
constexpr hectocelsius<OMNI_LITTERAL_FLOATING> operator"" _hc(long double val){return val;}
constexpr kilocelsius<OMNI_LITTERAL_FLOATING> operator"" _kc(long double val){return val;}
constexpr megacelsius<OMNI_LITTERAL_FLOATING> operator"" _Mc(long double val){return val;}
constexpr gigacelsius<OMNI_LITTERAL_FLOATING> operator"" _Gc(long double val){return val;}
constexpr teracelsius<OMNI_LITTERAL_FLOATING> operator"" _Tc(long double val){return val;}
constexpr petacelsius<OMNI_LITTERAL_FLOATING> operator"" _Pc(long double val){return val;}
constexpr exacelsius<OMNI_LITTERAL_FLOATING> operator"" _Ec(long double val){return val;}
constexpr zettacelsius<OMNI_LITTERAL_FLOATING> operator"" _Zc(long double val){return val;}
constexpr yottacelsius<OMNI_LITTERAL_FLOATING> operator"" _Yc(long double val){return val;}

constexpr yoctofahrenheit<OMNI_LITTERAL_FLOATING> operator"" _yf(long double val){return val;}
constexpr zeptofahrenheit<OMNI_LITTERAL_FLOATING> operator"" _zf(long double val){return val;}
constexpr attofahrenheit<OMNI_LITTERAL_FLOATING> operator"" _af(long double val){return val;}
constexpr femtofahrenheit<OMNI_LITTERAL_FLOATING> operator"" _ff(long double val){return val;}
constexpr nanofahrenheit<OMNI_LITTERAL_FLOATING> operator"" _nf(long double val){return val;}
constexpr microfahrenheit<OMNI_LITTERAL_FLOATING> operator"" _uf(long double val){return val;}
constexpr millifahrenheit<OMNI_LITTERAL_FLOATING> operator"" _mf(long double val){return val;}
constexpr centifahrenheit<OMNI_LITTERAL_FLOATING> operator"" _cf(long double val){return val;}
constexpr decifahrenheit<OMNI_LITTERAL_FLOATING> operator"" _df(long double val){return val;}
constexpr fahrenheit<OMNI_LITTERAL_FLOATING> operator"" _f(long double val){return val;}
constexpr decafahrenheit<OMNI_LITTERAL_FLOATING> operator"" _daf(long double val){return val;}
constexpr hectofahrenheit<OMNI_LITTERAL_FLOATING> operator"" _hf(long double val){return val;}
constexpr kilofahrenheit<OMNI_LITTERAL_FLOATING> operator"" _kf(long double val){return val;}
constexpr megafahrenheit<OMNI_LITTERAL_FLOATING> operator"" _Mf(long double val){return val;}
constexpr gigafahrenheit<OMNI_LITTERAL_FLOATING> operator"" _Gf(long double val){return val;}
constexpr terafahrenheit<OMNI_LITTERAL_FLOATING> operator"" _Tf(long double val){return val;}
constexpr petafahrenheit<OMNI_LITTERAL_FLOATING> operator"" _Pf(long double val){return val;}
constexpr exafahrenheit<OMNI_LITTERAL_FLOATING> operator"" _Ef(long double val){return val;}
constexpr zettafahrenheit<OMNI_LITTERAL_FLOATING> operator"" _Zf(long double val){return val;}
constexpr yottafahrenheit<OMNI_LITTERAL_FLOATING> operator"" _Yf(long double val){return val;}


constexpr yoctokelvin<OMNI_LITTERAL_INTEGER> operator"" _yK(unsigned long long int val){return val;}
constexpr zeptokelvin<OMNI_LITTERAL_INTEGER> operator"" _zK(unsigned long long int val){return val;}
constexpr attokelvin<OMNI_LITTERAL_INTEGER> operator"" _aK(unsigned long long int val){return val;}
constexpr femtokelvin<OMNI_LITTERAL_INTEGER> operator"" _fK(unsigned long long int val){return val;}
constexpr nanokelvin<OMNI_LITTERAL_INTEGER> operator"" _nK(unsigned long long int val){return val;}
constexpr microkelvin<OMNI_LITTERAL_INTEGER> operator"" _uK(unsigned long long int val){return val;}
constexpr millikelvin<OMNI_LITTERAL_INTEGER> operator"" _mK(unsigned long long int val){return val;}
constexpr centikelvin<OMNI_LITTERAL_INTEGER> operator"" _cK(unsigned long long int val){return val;}
constexpr decikelvin<OMNI_LITTERAL_INTEGER> operator"" _dK(unsigned long long int val){return val;}
constexpr kelvin<OMNI_LITTERAL_INTEGER> operator"" _K(unsigned long long int val){return val;}
constexpr decakelvin<OMNI_LITTERAL_INTEGER> operator"" _daK(unsigned long long int val){return val;}
constexpr hectokelvin<OMNI_LITTERAL_INTEGER> operator"" _hK(unsigned long long int val){return val;}
constexpr kilokelvin<OMNI_LITTERAL_INTEGER> operator"" _kK(unsigned long long int val){return val;}
constexpr megakelvin<OMNI_LITTERAL_INTEGER> operator"" _MK(unsigned long long int val){return val;}
constexpr gigakelvin<OMNI_LITTERAL_INTEGER> operator"" _GK(unsigned long long int val){return val;}
constexpr terakelvin<OMNI_LITTERAL_INTEGER> operator"" _TK(unsigned long long int val){return val;}
constexpr petakelvin<OMNI_LITTERAL_INTEGER> operator"" _PK(unsigned long long int val){return val;}
constexpr exakelvin<OMNI_LITTERAL_INTEGER> operator"" _EK(unsigned long long int val){return val;}
constexpr zettakelvin<OMNI_LITTERAL_INTEGER> operator"" _ZK(unsigned long long int val){return val;}
constexpr yottakelvin<OMNI_LITTERAL_INTEGER> operator"" _YK(unsigned long long int val){return val;}

constexpr yoctocelsius<OMNI_LITTERAL_INTEGER> operator"" _yc(unsigned long long int val){return val;}
constexpr zeptocelsius<OMNI_LITTERAL_INTEGER> operator"" _zc(unsigned long long int val){return val;}
constexpr attocelsius<OMNI_LITTERAL_INTEGER> operator"" _ac(unsigned long long int val){return val;}
constexpr femtocelsius<OMNI_LITTERAL_INTEGER> operator"" _fc(unsigned long long int val){return val;}
constexpr nanocelsius<OMNI_LITTERAL_INTEGER> operator"" _nc(unsigned long long int val){return val;}
constexpr microcelsius<OMNI_LITTERAL_INTEGER> operator"" _uc(unsigned long long int val){return val;}
constexpr millicelsius<OMNI_LITTERAL_INTEGER> operator"" _mc(unsigned long long int val){return val;}
constexpr centicelsius<OMNI_LITTERAL_INTEGER> operator"" _cc(unsigned long long int val){return val;}
constexpr decicelsius<OMNI_LITTERAL_INTEGER> operator"" _dc(unsigned long long int val){return val;}
constexpr celsius<OMNI_LITTERAL_INTEGER> operator"" _c(unsigned long long int val){return val;}
constexpr decacelsius<OMNI_LITTERAL_INTEGER> operator"" _dac(unsigned long long int val){return val;}
constexpr hectocelsius<OMNI_LITTERAL_INTEGER> operator"" _hc(unsigned long long int val){return val;}
constexpr kilocelsius<OMNI_LITTERAL_INTEGER> operator"" _kc(unsigned long long int val){return val;}
constexpr megacelsius<OMNI_LITTERAL_INTEGER> operator"" _Mc(unsigned long long int val){return val;}
constexpr gigacelsius<OMNI_LITTERAL_INTEGER> operator"" _Gc(unsigned long long int val){return val;}
constexpr teracelsius<OMNI_LITTERAL_INTEGER> operator"" _Tc(unsigned long long int val){return val;}
constexpr petacelsius<OMNI_LITTERAL_INTEGER> operator"" _Pc(unsigned long long int val){return val;}
constexpr exacelsius<OMNI_LITTERAL_INTEGER> operator"" _Ec(unsigned long long int val){return val;}
constexpr zettacelsius<OMNI_LITTERAL_INTEGER> operator"" _Zc(unsigned long long int val){return val;}
constexpr yottacelsius<OMNI_LITTERAL_INTEGER> operator"" _Yc(unsigned long long int val){return val;}

constexpr yoctofahrenheit<OMNI_LITTERAL_FLOATING> operator"" _yf(unsigned long long int val){return val;}
constexpr zeptofahrenheit<OMNI_LITTERAL_FLOATING> operator"" _zf(unsigned long long int val){return val;}
constexpr attofahrenheit<OMNI_LITTERAL_FLOATING> operator"" _af(unsigned long long int val){return val;}
constexpr femtofahrenheit<OMNI_LITTERAL_FLOATING> operator"" _ff(unsigned long long int val){return val;}
constexpr nanofahrenheit<OMNI_LITTERAL_FLOATING> operator"" _nf(unsigned long long int val){return val;}
constexpr microfahrenheit<OMNI_LITTERAL_FLOATING> operator"" _uf(unsigned long long int val){return val;}
constexpr millifahrenheit<OMNI_LITTERAL_FLOATING> operator"" _mf(unsigned long long int val){return val;}
constexpr centifahrenheit<OMNI_LITTERAL_FLOATING> operator"" _cf(unsigned long long int val){return val;}
constexpr decifahrenheit<OMNI_LITTERAL_FLOATING> operator"" _df(unsigned long long int val){return val;}
constexpr fahrenheit<OMNI_LITTERAL_FLOATING> operator"" _f(unsigned long long int val){return val;}
constexpr decafahrenheit<OMNI_LITTERAL_FLOATING> operator"" _daf(unsigned long long int val){return val;}
constexpr hectofahrenheit<OMNI_LITTERAL_FLOATING> operator"" _hf(unsigned long long int val){return val;}
constexpr kilofahrenheit<OMNI_LITTERAL_FLOATING> operator"" _kf(unsigned long long int val){return val;}
constexpr megafahrenheit<OMNI_LITTERAL_FLOATING> operator"" _Mf(unsigned long long int val){return val;}
constexpr gigafahrenheit<OMNI_LITTERAL_FLOATING> operator"" _Gf(unsigned long long int val){return val;}
constexpr terafahrenheit<OMNI_LITTERAL_FLOATING> operator"" _Tf(unsigned long long int val){return val;}
constexpr petafahrenheit<OMNI_LITTERAL_FLOATING> operator"" _Pf(unsigned long long int val){return val;}
constexpr exafahrenheit<OMNI_LITTERAL_FLOATING> operator"" _Ef(unsigned long long int val){return val;}
constexpr zettafahrenheit<OMNI_LITTERAL_FLOATING> operator"" _Zf(unsigned long long int val){return val;}
constexpr yottafahrenheit<OMNI_LITTERAL_FLOATING> operator"" _Yf(unsigned long long int val){return val;}


} //namespaxe suffixies



} //namespace omni


#endif //TEMPERATURE_HH_
