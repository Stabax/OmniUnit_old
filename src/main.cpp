
#include "stblib.hh"
#include <iostream>

int main()
{
  stb::Timer Tim;
  Tim.start();
  stb::sleep<stb::second>(2);
  std::cout << Tim.get<std::micro>() << '\n';

  std::cout << "Date : " << stb::Date::date(stb::Date::location::local) << '\n';
  std::cout << "Time : " << stb::Date::time(stb::Date::location::local) << '\n';

  stb::Counter Count;
  Count.add<stb::minute>(1);
  Count.start();

  unsigned long long i = Count.get<std::milli>();
  while(i > 0)
  {
    stb::sleep<std::milli>(500);
    i = Count.get<std::micro>();
    std::cout << i << std::endl;
  }
}
