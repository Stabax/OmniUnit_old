
#include <iostream>
#include "stblib/units.hh"


bool equal(double const& a, double const& b)
{
 return (b >= a && b <= a);
}


int main()
{

//std::cout << stb::Unit_cast<stb::meter<float>>(stb::gigaparsec<float>(1)).count() << '\n';
//std::cout << stb::Unit_cast<stb::second<float>>(stb::hour<float>(1)).count() << '\n';

auto a = stb::convertTemperature<stb::base>(stb::temp_unit::fahrenheit, 96);

std::cout << a.count() << '\n';
return 0;
}
