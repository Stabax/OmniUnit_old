# OmniUnit overview

## About

OmniUnit is a modular HEADER ONLY library for modern C++.

* The main purpose of OmniUnit is to provide strong types to represent physical unit, with implicit conversions and compile-time dimensional analysis.
* OmniUnit is also a context to provide some header-only modules which use these units. See the provided modules in the sections below.

The library has NO dependencies.

OmniUnit requires **C++14**
Doesn't compile on Visual Studio because of constant-expressions.
Compile on gcc 6.2.0 and higher.

Please, give feedback to know on what compiler the project works or not.

## Features : Why choose this unit library ?

It does exist some others library to represent and handle physical units.
Here's why you may use OmniUnit :

* You can represent physical units with strong types instead of literals. It is useful to avoid ambiguities in function overloads and to handle correctly your values.
* Units conversion is fully supported and is implicit : millimeter var = meter(3) + inches(5) is absolutely legal.
* Dimension check is done at compile-time. length/time returns a speed. If you write gram = meter(2)/second(1), there is a compilation error. Thus there is no runtime issues.
* All physical units are supported. If one isn't implemented, you can easily create your own only with typedef. Implicit conversion will automatically be supported for your new unit and dimension check at compile time is always available.
* Units are fully compliant with decimal prefixes (kilo, milli, nano...) but also your defined prefixes ! Indeed, you can create your own with a simple typedef.
* This library offers some header-only modules which use units. See below.

## Modules

### ChronoScale

This module provides timers, countdowns and dates with relativity support and scalable time flow. timers accuracy is near the nanosecond.




## Use library

To get the library, clone the latest revision :

    git clone http://bitbucket.org/stabaxltd/stblib.git

Then copy the include/omniunit folder into your project folder and simply include the desired header files in your sources.

Look at the getting started related page to learn how to use the features.


## Fast and basic example

    #include "omniunit/omniunit.hh"
    #include <iostream>

    //a and b represent 3000 meters in different ways
    stb::millimeter<int> a(3000000);  //3000000 is handled by an integer
    stb::kilometer<float> b(3);       //3 is handled by a float

    stb::centimeterPerSecond<double> d = a / stb::second<int>(3); //OK, length/duration returns a speed.

    std::cout << d.count() << '\n';   //prints 100000

As you can you can see, every thinkable conversion are done implicitly.

## Contributors

* Stabax® Ltd. (http://stabax.org/)
* Baxlan

## Trello

If you are interested by the next versions of the library, check the workflow at :
https://trello.com/b/ceG9w8T6/stblib

## License

This library is released under BSD License Copyright 2017 Stabax Ltd.

Copyright (c) 1998, Regents of the University of California
All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.
* Neither the name of the University of California, Berkeley nor the
  names of its contributors may be used to endorse or promote products
  derived from this software without specific prior written permission.

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
