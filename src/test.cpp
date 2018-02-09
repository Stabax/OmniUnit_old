
#include "omniunit/omniunit.hh"
#include <iostream>

int main()
{
  stb::omni::gram<int> var1(10);
  stb::omni::gram<float> var2(12.9);

  var1 = var2;

  std::cout << var1.count() << '\n';

return 0;
}
