
#include <iostream>
#include <thread>

#include "stblib/units/length.hh"
#include "stblib/units/mass.hh"
#include "stblib/units/duration.hh"
#include "stblib/units/intensity.hh"
#include "stblib/units/temperature.hh"
#include "stblib/units/quantity.hh"
#include "stblib/units/luminosity.hh"

#include "stblib/Timer.hh"
#include "stblib/Date.hh"


int main()
{

  stb::second<long long> a(1000000);
  std::chrono::nanoseconds b(0);

  auto c = stb::duration_cast<int, std::kilo>(a);


  stb::Timer Tim;
  Tim.start();

  while(a < stb::second<long long>(10))
  {
    std::this_thread::sleep_for(std::chrono::nanoseconds(stb::second<int>(1)));
    a = Tim.get<>();
    std::cout << a.count() << std::endl;
  }

  std::cout << c.count() << std::endl;

return 0;
}
