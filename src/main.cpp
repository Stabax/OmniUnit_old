
#include "stblib/relativity.hh"
#include <iostream>


int main()
{

  stb::RelativeTimer a(1);
  stb::RelativeTimer b(2);

  a -= stb::second(10);

  a.start();
  b.start();

  for(unsigned i = 0; i < 5; ++i)
  {
    std::cout << a.get<stb::millisecond>().count() << "   " << b.get<stb::millisecond>().count() << std::endl;
    stb::sleep(stb::second(0.5));
  }
return 0;
}
