
#include "stblib/relativity.hh"
#include <iostream>


int main()
{
  stb::hour a(3);

  stb::kilometer_hour b(100);

  std::cout << (a * b).count() << '\n';

return 0;
}
