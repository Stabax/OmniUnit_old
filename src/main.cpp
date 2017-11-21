
#include "stblib/stblib.hh"
#include <iostream>

int main()
{

  stb::astronomicalUnit a(1);
  stb::lightminute_f b = stb::length_cast<stb::lightminute_f>(a);

  std::cout << b.count() <<'\n';

return 0;
}
