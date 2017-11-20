//Duration.hh

/*
Copyright (c) 1998, Regents of the University of California All rights
reserved. Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
    Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
    Neither the name of the University of California, Berkeley nor the names
    of its contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef DURATION_HH_
#define DURATION_HH_

#include <chrono>    // duration
#include "Unit.hpp" // Unit

namespace stb
{



//=============================================================================
//=============================================================================
// DURATION DEFINITION ========================================================
//=============================================================================
//=============================================================================



template<typename Rep, typename Period = std::ratio<1>>
using Duration = std::chrono::duration<Rep, Period>;


/*
template<typename Rep, typename Period = std::ratio<1>>
class Dur : public std::chrono::duration<Rep, Period>, public Unit<Rep, Period>
{
public:

  Dur(Rep count):
  std::chrono::duration<Rep, Period>(count)
  {
  }

  //allow conversion std::chrono::duration ==> stb::Duration
  template <typename _rep, typename _period>
  Dur& operator=(std::chrono::duration<_rep, _period> const& Obj)
  {
    __r = std::chrono::duration_cast<Dur>(Obj).count();
    return *this;
  }


protected:
};
*/

template<typename toUnit, typename Rep, typename Period>
constexpr toUnit duration_cast(Duration<Rep, Period> const& duration)
{
  return std::chrono::duration_cast<toUnit>(duration);
}





//=============================================================================
//=============================================================================
// DURATION TYPEDEF ===========================================================
//=============================================================================
//=============================================================================



typedef Duration<long long, std::atto>                   attosecond;
typedef Duration<long long, std::femto>                  femtosecond;
typedef Duration<long long, std::pico>                   picosecond;
typedef Duration<long long, std::nano>                   nanosecond;
typedef Duration<long long, std::micro>                  microsecond;
typedef Duration<long long, std::milli>                  millisecond;
typedef Duration<long long, std::ratio<1, 1>>            second;
typedef Duration<long long, std::ratio<60, 1>>           minute;
typedef Duration<long long, std::ratio<3600, 1>>         hour;
typedef Duration<long long, std::ratio<3600*24, 1>>      day;
typedef Duration<long long, std::ratio<3600*24*7, 1>>    week;
typedef Duration<long long, std::ratio<3600*24*30, 1>>   month;
typedef Duration<long long, std::ratio<3600*24*365, 1>>  year;

typedef Duration<float, std::atto>                   attosecond_f;
typedef Duration<float, std::femto>                  femtosecond_f;
typedef Duration<float, std::pico>                   picosecond_f;
typedef Duration<float, std::nano>                   nanosecond_f;
typedef Duration<float, std::micro>                  microsecond_f;
typedef Duration<float, std::milli>                  millisecond_f;
typedef Duration<float, std::ratio<1, 1>>            second_f;
typedef Duration<float, std::ratio<60, 1>>           minute_f;
typedef Duration<float, std::ratio<3600, 1>>         hour_f;
typedef Duration<float, std::ratio<3600*24, 1>>      day_f;
typedef Duration<float, std::ratio<3600*24*7, 1>>    week_f;
typedef Duration<float, std::ratio<3600*24*30, 1>>   month_f;
typedef Duration<float, std::ratio<3600*24*365, 1>>  year_f;





//=============================================================================
//=============================================================================
// DURATION CONSTANT ==========================================================
//=============================================================================
//=============================================================================



//age of the universe
const year t0(1373*1000*1000);

//Planck time
const attosecond_f tp(0.00000000000000000000000005319);





//=============================================================================
//=============================================================================
// TYPEDEF ====================================================================
//=============================================================================
//=============================================================================



template<typename Rep, typename period = std::ratio<1>>
using Period = Duration<Rep, period>;





}//namespace stb

#endif //DURATION_HH_
