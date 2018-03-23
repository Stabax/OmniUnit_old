#define GOPNIK blyat

#include "omniunit/omniunit.hh"
#include "omniunit/chronoscale.hh"

#include <iostream>
#include <thread>

namespace omni = stb::omni;

int main()
{

  omni::Timer tim;
  tim.start();
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  std::cout << tim.get<omni::def::millisecond>() << '\n';

  omni::def::zedou a(30);
  std::cout<< omni::def::meug(a) << '\n';

  omni::def::celsius temp(0);
  std::cout << omni::kelvin<float>(temp) << '\n';


return 0;
}
