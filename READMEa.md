# Stblib overview

## Contributors

* Stabax® Ltd. (http://stabax.org/)
* Baxlan

## About

Stblib is a HEADER ONLY library for modern C++.


The library has two purposes :

* Provide strong types to represent units, such as time, intensity, length, speed ... and allow easy calculation between them, taking uncertainties into account. Creating new units is easy.
* Provide a solid and accurate time management module. This module implements timers, countdowns and dates with relativity support and scalable time flow. The time module has an accuracy near to the nanosecond.

## Why do you need this library ?



## Get Library

Clone the latest revision :

    git clone http://bitbucket.org/stabaxltd/stblib.git

## Use library

Simply include the desired header files in your sources.
Look at the getting started related page to learn how to use the features.

/!\\ IMPORTANT NOTE : your compiler must support **c++14**.

## Fast examples

    #include "stblib/units/length.hh"
    #include "stblib/units/duration.hh"
    #include "stblib/units/speed.hh"
    #include <iostream>

    //a and b represent 3000 meters in different ways
    stb::millimeter<int> a(3000000);  //3000000 is handled by an integer
    stb::kilometer<float> b(3);       //3 is handled by a float

    stb::centimeterPerSecond<double> d = a / stb::second<int>(3);
    //OK, length/duration returns a speed.

    std::cout << d.count() << '\n';   //prints 100000

As you can you can see, every thinkable conversion are done implicitly.
Let's see how to use time module :

    #include "Timer.hh"
    #include "Date.hh"
    #include <iostream>

    //prints the current gmt hour
    std::cout << stb::Date::get(stb::Date::hour, stb::Date::gmt) << '\n';
    //prints the current month of your machine
    std::cout << stb::Date::get(stb::Date::month, stb::Date::local) << '\n';

    stb::Timer tim;
    tim.start();
    //prints the time elapsed since start() in nanoseconds
    std::cout << tim.get<stb::nanoseconds<long long>>() << '\n';

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
