//temporary.hh

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

#ifndef OMNI_TEMP_HH_
#define OMNI_TEMP_HH_



namespace omni
{

  typedef Dimension<2,1,-2,0,0,0,0> Torque;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using newtonMeter = Unit<Torque, Rep, base, zero>;



  typedef Dimension<3,0,0,0,0,0,0> Volume;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using centimeter3 = Unit<Volume, Rep, typename Ratio_power<centi, 3>::type, zero>;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using liter = Unit<Volume, Rep, typename Ratio_power<deci, 3>::type, zero>;



  typedef Dimension<1,1,-2,0,0,0,0> Force;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using newton = Unit<Force, Rep, base, zero>;



  typedef Dimension<2,1,-3,0,0,0,0> Power;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using watt = Unit<Power, Rep, base, zero>;

  inline constexpr double chE1 = 7355.;
  template <typename Rep = OMNI_DEFAULT_TYPE>
  using horsepower = Unit<Power, Rep, Ratio<chE1, E1>, zero>;

  inline constexpr double hpDoubleE1 = 7457.;
  template <typename Rep = OMNI_DEFAULT_TYPE>
  using mechanicalhorsepower = Unit<Power, Rep, Ratio<hpDoubleE1, E1>, zero>;



  typedef Dimension<0,0,-1,0,0,0,0> Frequency;
  inline constexpr double perMinRatio = 60.;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using perMinute = Unit<Frequency, Rep, Ratio<E0, perMinRatio>, zero>;



  typedef Dimension<1,0,-1,0,0,0,0> Speed;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using meterPerSecond = Unit<Speed, Rep, base, zero>;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using meterPerMinute = Unit<Speed, Rep, Ratio<E0, sixty>, zero>;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using kilometerPerHour = Unit<Speed, Rep, Ratio<E3, secondsPerHour>, zero>;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using milePerHour = Unit<Speed, Rep, typename Ratio_over_value<Ratio<mileE3, E3>, secondsPerHour>::type, zero>;



  typedef Dimension<1,0,-2,0,0,0,0> Acceleration;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using meterPerSecond2 = Unit<Acceleration, Rep, base, zero>;



  typedef Dimension<-1,1,-2,0,0,0,0> Pressure;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using bar = Unit<Pressure, Rep, Ratio<E5, E0>, zero>;





  typedef mile<> Mile;
  typedef inch<> Inch;
  typedef centimeter3<> Centimeter3;
  typedef liter<> Liter;
  typedef newtonMeter<> NewtonMeter;
  typedef newton<> Newton;
  typedef watt<> Watt;
  typedef horsepower<> Horsepower;
  typedef mechanicalhorsepower<> Mechanicalhorsepower;
  typedef perMinute<> PerMinute;
  typedef meterPerSecond<> MeterPerSecond;
  typedef meterPerMinute<> MeterPerMinute;
  typedef kilometerPerHour<> KilometerPerHour;
  typedef meterPerSecond2<> MeterPerSecond2;
  typedef milePerHour<> MilePerHour;
  typedef bar<> Bar;

  namespace suffixes
  {
  constexpr centimeter3<OMNI_LITTERAL_FLOATING> operator"" _cm3(long double val) {return val;}
  constexpr liter<OMNI_LITTERAL_FLOATING> operator"" _L(long double val) {return val;}
  constexpr newton<OMNI_LITTERAL_FLOATING> operator"" _N(long double val) {return val;}
  constexpr watt<OMNI_LITTERAL_FLOATING> operator"" _W(long double val) {return val;}
  constexpr horsepower<OMNI_LITTERAL_FLOATING> operator""_hp (long double val) {return val;}
  constexpr mechanicalhorsepower<OMNI_LITTERAL_FLOATING> operator""_mhp (long double val) {return val;}
  constexpr perMinute<OMNI_LITTERAL_FLOATING> operator"" _PerMin(long double val) {return val;}
  constexpr meterPerSecond<OMNI_LITTERAL_FLOATING> operator""_mPers(long double val) {return val;}
  constexpr kilometerPerHour<OMNI_LITTERAL_FLOATING> operator"" _kmPerh(long double val) {return val;}
  constexpr meterPerSecond2<OMNI_LITTERAL_FLOATING> operator"" _mPers2(long double val) {return val;}
  constexpr milePerHour<OMNI_LITTERAL_FLOATING> operator"" _miPerh(long double val) {return val;}
  constexpr bar<OMNI_LITTERAL_FLOATING> operator"" _bar(long double val) {return val;}

  constexpr centimeter3<OMNI_LITTERAL_INTEGER> operator"" _cm3(unsigned long long int val) {return val;}
  constexpr liter<OMNI_LITTERAL_INTEGER> operator"" _L(unsigned long long int val) {return val;}
  constexpr newton<OMNI_LITTERAL_INTEGER> operator"" _N(unsigned long long int val) {return val;}
  constexpr watt<OMNI_LITTERAL_INTEGER> operator"" _W(unsigned long long int val) {return val;}
  constexpr horsepower<OMNI_LITTERAL_INTEGER> operator""_hp (unsigned long long int val) {return val;}
  constexpr mechanicalhorsepower<OMNI_LITTERAL_INTEGER> operator""_mhp (unsigned long long int val) {return val;}
  constexpr perMinute<OMNI_LITTERAL_INTEGER> operator"" _PerMin(unsigned long long int val) {return val;}
  constexpr meterPerSecond<OMNI_LITTERAL_INTEGER> operator""_mPers(unsigned long long int val) {return val;}
  constexpr kilometerPerHour<OMNI_LITTERAL_INTEGER> operator"" _kmPerh(unsigned long long int val) {return val;}
  constexpr meterPerSecond2<OMNI_LITTERAL_INTEGER> operator"" _mPers2(unsigned long long int val) {return val;}
  constexpr milePerHour<OMNI_LITTERAL_INTEGER> operator"" _miPerh(unsigned long long int val) {return val;}
  constexpr bar<OMNI_LITTERAL_INTEGER> operator"" _bar(unsigned long long int val) {return val;}
  }
} // namespace omni



#endif //OMNI_TEMP_HH_