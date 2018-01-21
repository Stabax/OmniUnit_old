
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

template< class Rep, class Period >
void foo(const std::chrono::duration<Rep, Period>& sleep_duration )
{
  std::cout << sleep_duration.count() << '\n';
}


int main()
{
  stb::nanosecond<float> a(0);
  stb::Timer Tim;
  Tim.start();

  foo(a);

/*
  while(a < stb::second<int>(10))
  {
    std::this_thread::sleep_for(stb::second<int>(1))
    a = Timer.get();
    std::cout << a.dimension() << '\n';
  }
*/

return 0;
}
