# OmniUnit overview #

## About ##

OmniUnit is a HEADER ONLY library for modern C++.

Strongly typed values are heavily recommended by the C++ creators themself in order to avoid ambiguities and hidden bugs. \n
C++ stantard has taken this recommendation into account by implementing std::chrono::duration to represent duration. \n
This is not enough.

* The main purpose of OmniUnit is to provide strong types to represent all physical units.
* Implicit conversions and compile-time dimensional analysis are performed when operating on these units.
* These units can handle uncertainties and propagate them through operators.
* Units from all systems are representable : metric, imperial, microscopic, astronomic...
* Units representing a time are fully, implicitly and reciprocally convertible to a std::chrono::duration.
* If a unit is not defined in OmniUnit, user defined units can be defined only through typedefs.
* It is not the main purpose of OmniUnit, but a Timer and a Countdown are available (accurate from 10^-3 to 10^-7 seconds depending of the OS), that can take a speed or a kinetic energy to take relativistic effects into account. They provide scalable time flow as well.

OmniUnit requires fully supported **C++14**.\n


### OmniUnit compiles with : ###
- gcc/g++ 6.2.0\n
- gcc/g++ 6.3.0\n

### OmniUnit doesn't compiles with : ###
- Visual Studio 2015 and earlier.\n

### Known bugs ###

No bugs are known.


## Why choose THIS unit library ? ##

It does exist some others library to represent and handle physical units in C++. Here's why you should use OmniUnit :

* Units conversion is fully supported and is implicit : millimeter = meter + inches is absolutely legal.
* Dimension check is done at compile-time. Length/time returns a speed. If Mass = length/time is tried, there is a compilation error. Thus there cannot be runtime issue.
* Uncertainties on values can be handled. If any, propagation of uncertainties through functions or unit composition/conversion is calculated.
* All physical units are supported. If one isn't implemented, you can easily create your own only with typedefs. Implicit conversion are automagically supported for your new unit, and dimensions are always checked at compile time.
* Units representing a time are fully, implicitly and reciprocally convertible to a std::chrono::duration.


## Documentation ##

See the full documentation here : http://stabax.org/doc/omniunit


## Use library ##

To get the library, clone the latest revision :

    git clone http://bitbucket.org/stabaxltd/stblib.git

Then copy the include/omniunit folder into your project folder and simply include the desired header files in your sources, and start using the features.


## Fast and basic example ##

    #include "omniunit/units.hh"
    #include <iostream>

    int main()
    {
      //a and b represent 3000 meters in different ways
      omniunit::millimeter<int> a(3000000);  //3000000 is handled by an integer
      omniunit::kilometer<float> b(3);       //3 is handled by a float

      omniunit::centimeterPerSecond<double> d = a / stb::second<int>(3); //OK, length/duration returns a speed.

      std::cout << d.count() << '\n';   //prints 100000

    return 0;
    }

As you can you can see, every thinkable conversion are done implicitly.

## Contributors ##

* Baxlan
* Stabax (http://stabax.org/)


## License ##

Copyright (c) 2016, Denis Tosetto All rights reserved. Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

* Neither the name of Denis Tosetto nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
