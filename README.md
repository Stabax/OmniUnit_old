# OmniUnit overview #

## About ##

OmniUnit is a HEADER ONLY library for modern C++.

Strongly typed values are heavily recommended by the C++ creators themself in order to avoid ambiguities and hidden bugs. \n
C++ stantard has taken this recommendation into account by implementing std::chrono::duration to represent duration. \n
It is not enough.

* The main purpose of OmniUnit is to provide strong types to represent all physical units ;
* Implicit conversions are performed when operating on units : Millimeter = meter + inches is absolutely legal ;
* compile-time dimensional analysis are performed when operating on units : Length/time returns a speed. Computing this as a Mass causes a compilation error, so there cannot be any runtime error ;
* Units from all systems are representable : metric, imperial, microscopic, astronomic... ;
* Units representing a time are fully, implicitly and reciprocally convertible to a std::chrono::duration :
* If a unit is not defined in OmniUnit, user defined units can be defined only through typedefs ;
* Units can handle uncertainties and propagate them through operators ; **comming soon**
* Suffixes (through litteral operator) are available for all predefined units, making Omniunit a user friendly library ;
* More than the five basic operations (+-*/%), Mathematic tools are provided to use units (exponential, power, trigonometric, hyperbolic, rounding functions, and matrix computation) ; **comming soon**
* It is not the main purpose of OmniUnit, but a Timer and a Countdown are available (accurate from 10^-4 to 10^-7 seconds depending of the OS), that can take a speed or a kinetic energy to take relativistic effects into account. They provide scalable time flow as well. **comming soon**

OmniUnit requires fully supported **C++17** (at least gcc/g++ 7.2 or Visual Studio 2017 with the option /constexpr).\n

## Versions ##

* OmniUnit is not officially distributed yet.


## Use the library ##

To get the library, clone the latest revision :

    git clone http://bitbucket.org/stabax/omniunit.git

Then copy the include/omniunit folder into your project folder and simply include the desired header files in your sources, and start using the features.

## Documentation ##

See the full documentation here : http://stabax.org/doc/omniunit.
If the servers are down, open __omniunit/doc/html/index.html__.

## Example ##

    #include "omniunit/omniunit.hh"
    #include <iostream>

    int main()
    {
        //a and b represent 3000 meters in different ways
        omni::Millimeter a(3000000);
        omni::Kilometer b(3);

        omni::CentimeterPerSecond c = a / stb::second(3); //OK, LENGTH/DURATION returns a SPEED.
        std::cout << c.count() << '\n';   //prints 100000

        omni::Gram d = c; //ERROR, this doesn't compile because "d" is of dimension MASS and "c" is of dimension SPEED

        omni::Inch e = omni::MilliMeter(5.2) + omni::Angstrom(124.347); //OK, all conversions are done implicitly

        omni::Joule kineticEnergy = 0.5 * omni::Ton(10) * omni::pow<2>(c); //OK

    return 0;
    }

## Contributors ##

* Baxlan
* Stabax (http://stabax.org/)

## License ##

/*
Copyright (c) 2019, Denis Tosetto All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

  Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

  Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

  Neither the name of Denis Tosetto nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND AN EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIE WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
