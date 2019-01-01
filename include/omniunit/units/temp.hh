//temp.hh

/*
Copyright (c) 2016, Denis Tosetto All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

  Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.

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



namespace omniunit
{

  typedef Dimension<2,1,-2,0,0,0,0,0,0> Energy;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using newtonMeter = Unit<Energy, Rep, base, zero>;



  typedef Dimension<1,1,-2,0,0,0,0,0,0> Force;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using newton = Unit<Force, Rep, base, zero>;



  typedef Dimension<2,1,-3,0,0,0,0,0,0> Power;
  constexpr double chE1 = 7355.;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using ch = Unit<Power, Rep, Ratio<chE1, E1>, zero>;



  typedef Dimension<0,0,-1,0,0,0,0,0,0> Frequency;
  constexpr double perMinRatio = 60.;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using perMinute = Unit<Frequency, Rep, Ratio<E0, perMinRatio>, zero>;


  typedef Dimension<1,0,-1,0,0,0,0,0,0> Speed;
  constexpr double secInHour = 3600.;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using kilometerPerHour = Unit<Speed, Rep, Ratio<E3, secInHour>, zero>;



  typedef Dimension<1,0,-2,0,0,0,0,0,0> Acceleration;

  template <typename Rep = OMNI_DEFAULT_TYPE>
  using meterPerSecond2 = Unit<Acceleration, Rep, base, zero>;
}



#endif //OMNI_TEMP_HH_