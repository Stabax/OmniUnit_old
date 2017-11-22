
#include "stblib/units/temp_Duration.hh"
#include <iostream>

int main()
{

  stb::Duration<float, std::ratio<1, 1>> a(10);

  std::chrono::duration<float, std::ratio<1, 1>> b(10);

  auto c = b + a;

  std::cout << c.count() << '\n';

return 0;
}
