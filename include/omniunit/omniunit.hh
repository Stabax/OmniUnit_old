//omniunit.hh

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



#ifndef OMNIUNIT_OMNIUNIT_HH_
#define OMNIUNIT_OMNIUNIT_HH_

#include "settings.hh"

#if OMNI_USE_SAME_TYPE_FOR_UNCERTAINTIES
  #define OMNI_UTYPE Rep
  #define OMNI_UTYPE1 Rep1
  #define OMNI_UTYPE2 Rep2
  #define OMNI_UTYPE_ _Rep
#else
  #define OMNI_UTYPE OMNI_DEFAULT_UNCERTAINTY_TYPE
  #define OMNI_UTYPE1 OMNI_DEFAULT_UNCERTAINTY_TYPE
  #define OMNI_UTYPE2 OMNI_DEFAULT_UNCERTAINTY_TYPE
  #define OMNI_UTYPE2 OMNI_DEFAULT_UNCERTAINTY_TYPE
#endif //OMNI_USE_SAME_TYPE_FOR_UNCERTAINTIES

#include "classes/Unit.hh"

namespace omni
{
  template <typename _Dimension, typename Rep, typename Period, double const& Origin>
  using Unit = Basic_Unit<_Dimension, Rep, Period, Origin>;

} //namespace omni

#if OMNI_INCLUDE_ALL_UNITS == true

#include "units/units.hh"

#endif // OMNI_INCLUDE_ALL_UNITS


#endif //OMNIUNIT_OMNIUNIT_HH_
