
#include <iostream>
#include "stblib/units.hh"


bool equal(double const& a, double const& b)
{
 return (b >= a && b <= a);
}


int main()
{
  stb::megaparsec<float> a(2);
  //auto c = a/2;

  std::cout << a.count() << '\n';

return 0;
}
