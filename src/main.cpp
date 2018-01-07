
#include <iostream>
#include "stblib/units.hh"


bool equal(double const& a, double const& b)
{
 return (b >= a && b <= a);
}


int main()
{
  stb::second<float> a(2);
  auto c = a/2;

  std::cout << c.count() << '\n';

return 0;
}
