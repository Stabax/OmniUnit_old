//settings.hh

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

#ifndef OMNIUNIT_SETTINGS_HH_
#define OMNIUNIT_SETTINGS_HH_

// if OMNI_INCLUDE_ALL_UNITS is true, all predefined units are included with omniunit.
// To decrease compilation time, OMNI_INCLUDE_ALL_UNITS should be set on false and
// units should be included one by one according to what units are needed.
// (See what files to include in /include/omniunit/units/ ).
// default : true
#define OMNI_INCLUDE_ALL_UNITS true

// OMNI_DEFAULT_TYPE is the default type internally handled by units
// to represent the value (not the uncertainty) when they
// are used with a capital (like Meter != meter).
// default : double
#define OMNI_DEFAULT_TYPE double

// if OMNI_USE_SAME_TYPE_FOR_UNCERTAINTIES is true, the type internally
// handled by units to represent the uncertainty is the same as the value type.
// Othewise, OMNI_DEFAULT_UNCERTAINTY_TYPE is used.
// default : true, double
#define OMNI_USE_SAME_TYPE_FOR_UNCERTAINTIES true
#define OMNI_DEFAULT_UNCERTAINTY_TYPE double

// if OMNI_TRUE_ZERO is true, then the true zero of the unit is considered in calculations.
// for example, if OMNI_TRUE_ZERO is :
// - true  : 0 celsius * 10 =       0 celsius (aka 273.15 kelvin)
// - false : 0 celsius * 10 = 2458.35 celsius (aka 2731.5 kelvin)
// because 0C = 273.15K, multiplied by 10 it equals 2731.5K = 2458.35C
// default : false
#define OMNI_TRUE_ZERO false

// OMNI_LITTERAL_INTEGER and OMNI_LITTERAL_FLOATING are the type handled
// by units returned by litteral operators, according to the operator overload used (integer or floating point).
// the type returned by  5_m is meter<OMNI_LITTERAL_INTEGER>
// the type returned by 5._m is meter<OMNI_LITTERAL_FLOATING>
// default : int and double
#define OMNI_LITTERAL_INTEGER int
#define OMNI_LITTERAL_FLOATING double

// if OMNI_USE_STD_EPSILON equals true, all INTERNAL comparisons between floating points are
// done according to default epsilon (FLT_EPSILON, DBL_EPSILON...). Else, INTERNAL comparisons are done with
// the value of OMNI_FLT_EPSILON, OMNI_DBL_EPSILON and OMNI_LDBL_EPSILON. (INTERNAL comparisons refer to
// comparisons internally needed, like in Ratio and Dimension operations).
// OMNI_USE_STD_EPSILON should equals true unless good reasons.
// default : true, 0.f, 0., and 0..
#define OMNI_USE_STD_EPSILON true
#define OMNI_FLT_EPSILON 0.f
#define OMNI_DBL_EPSILON 0.
#define OMNI_LDBL_EPSILON 0.

// if OMNI_COMPARISON_USE_STD_EPSILON equals true, all comparisons between units (through
// comparison operators == != <= < > >=) are done according to
// default epsilon (FLT_EPSILON, DBL_EPSILON...). Else, these comparisons are done with
// the value of OMNI_COMPARISON_FLT_EPSILON, OMNI_COMPARISON_DBL_EPSILON and OMNI_COMPARISON_LDBL_EPSILON.
// default : true, 0.f, 0., and 0..
#define OMNI_COMPARISON_USE_STD_EPSILON true
#define OMNI_COMPARISON_FLT_EPSILON 0.f
#define OMNI_COMPARISON_DBL_EPSILON 0.
#define OMNI_COMPARISON_LDBL_EPSILON 0.

// if OMNI_ENABLE_UNCERTAINTIES is true, then all the content of Complete_Units.hh is included
// and compiled with omniunit. If uncertainties are not needed, then OMNI_ENABLE_UNCERTAINTIES should
// be set on false to decrease compilation time.
// default : true
#define OMNI_ENABLE_UNCERTAINTIES true

// if OMNI_DEFAULT_IS_UNCERTAINTY is true, then Unit is a typedef on
// Complete_Unit instead of Basic_Unit. It meeans that all predefined units
// are Complete_Unit. If uncertainties are not needed, set OMNI_DEFAULT_IS_UNCERTAINTY to
// false to increase runtime speed, because Complete_Unit handles and computes more informations
// than Basic_Unit. Hard compilation error may appear if OMNI_ENABLE_UNCERTAINTIES is false and
// OMNI_DEFAULT_IS_UNCERTAINTY is true.
// default : false
#define OMNI_DEFAULT_IS_UNCERTAINTY false

// WIP
#define OMNI_DEFAULT_PROPAGATION quadratic
#define OMNI_PRIORITY_PROPAGATION linear
#define OMNI_VALID_SAMPLE_SIZE 100

#endif //OMNIUNIT_SETTINGS_HH_