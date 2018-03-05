
#include "omniunit/omniunit.hh"
#include "omniunit/chronoscale.hh"

#include <iostream>


int main()
{
  stb::omni::Timer tim;
  tim.start();
  std::cout << tim.get<stb::omni::microsecond<unsigned>>().count() << '\n';

return 0;
}
