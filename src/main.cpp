
#include <iostream>
#include "stblib/units/length.hh"
#include "stblib/units/mass.hh"
#include "stblib/units/duration.hh"
#include "stblib/units/intensity.hh"
#include "stblib/units/temperature.hh"
#include "stblib/units/quantity.hh"
#include "stblib/units/luminosity.hh"

bool equal(double const& a, double const& b)
{
 return (b >= a && b <= a);
}


int main()
{
  stb::megaparsec<float> a(2);
  auto c = a%2;
  stb::modulo(0, 1);

  std::cout << a.dimension() << '\n';

return 0;
}
