//OmniUnit.hh

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



#ifndef OMNIUNIT_HH_
#define OMNIUNIT_HH_


#ifndef OMNI_DEFAULT_TYPE
  #define OMNI_DEFAULT_TYPE double
#endif // OMNI_DEFAULT_TYPE

#ifndef OMNI_TRUE_ZERO
  #define OMNI_TRUE_ZERO false
#endif // OMNI_TRUE_ZERO


#include "classes/Complete_Unit.hh"



namespace omniunit
{



#ifdef OMNI_ENABLE_UNCERTAINTIES



#else



template <typename _Dimension, typename Rep, typename Period, double const& Origin = zero>
using Unit = Basic_Unit<_Dimension, Rep, Period, Origin>;



#endif //OMNI_DISABLE_UNCERTAINTIES



} //namespace omniunit




#include "units/units.hh"



#endif //OMNIUNIT_HH_
