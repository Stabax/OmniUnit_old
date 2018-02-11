
#include "omniunit/omniunit.hh"
#include <iostream>


int main()
{

  stb::omni::mol<float> var(1);

  std::cout << stb::omni::rawQuantity<float>(var).count() << '\n';

return 0;
}
