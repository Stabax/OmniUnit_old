
#include "stblib/stblib.hh"
#include <iostream>


int main()
{
  stb::hour a(3);

  stb::kilometerPerHour b(100);

  std::cout << (a * b).count() << '\n';

return 0;
}
