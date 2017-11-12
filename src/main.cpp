
#include "stblib.hh"
#include <iostream>

int main()
{
  stb::Timer Tim;
  Tim.start();
  stb::sleep<stb::second>(2);
  std::cout << Tim.get<std::micro>() << '\n';

  std::cout << "Date : " << stb::Date::date(stb::Date::local) << '\n';
  std::cout << "Time : " << stb::Date::time(stb::Date::local) << '\n';

  stb::Countdown Count;
  Count.add(std::chrono::seconds(1));
  Count.start();

  unsigned i = Count.get<std::milli>();
  while(i > 0)
  {
    stb::sleep<std::milli>(500);
    i = Count.get<std::micro>();
    std::cout << i << std::endl;
  }

  Count.add<stb::second>(4);
  Count.add(std::chrono::seconds(4));
  stb::sleep(Count);

}
