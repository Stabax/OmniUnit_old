
#include <iostream>
#include "stblib/units.hh"


bool equal(double const& a, double const& b)
{
 return (b >= a && b <= a);
}


int main()
{
  stb::second<float> a(1);
  stb::millisecond<float> b(1);
  a += b;

  std::cout << a.count() << '\n';
return 0;
}
