
#include "stblib/stblib.hh"
#include <iostream>
#include <limits>

int main()
{

  stb::kilometerPerHour_f a(50);
  stb::meterPerSecond b = stb::speed_cast<stb::meterPerSecond>(a);
  //stb::meterPerSecond c(50);
  //float y = a / 2;

  //std::cout << y << '\n';


  stb::second_f h(1);
  h = h * 2;
return 0;
}
