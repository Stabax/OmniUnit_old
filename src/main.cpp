
#include "stblib/stblib.hh"
#include <iostream>
#include <limits>

int main()
{

  stb::kilometerPerSecond_f a(230);
  stb::kilometerPerHour_f b = stb::speed_cast<stb::kilometerPerHour_f>(a);

  //a = a * 2.0;

  std::cout << a.count() << '\n' << b.count() << '\n';

return 0;
}
