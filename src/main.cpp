
#include "stblib/units.hh"
#include <iostream>


int main()
{
  stb::Duration<float, std::ratio<1, 1>> a(10);
  a = std::chrono::seconds(3) * 2;
  std::chrono::duration<float, std::ratio<1, 1>> b(a);


  //stb::millisecond c(a);

return 0;
}
