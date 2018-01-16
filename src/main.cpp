
#include <iostream>
#include "stblib/units.hh"


bool equal(double const& a, double const& b)
{
 return (b >= a && b <= a);
}


int main()
{
  stb::megaparsec<float> a(2);
  auto c = a%2;
  stb::modulo(0, 1);
  stb::is_valid(0);

  std::cout << a.dimension() << '\n';

return 0;
}
