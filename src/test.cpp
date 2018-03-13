#define GOPNIK blyat

#include "omniunit/omniunit.hh"
#include "omniunit/chronoscale.hh"

#include <iostream>
#include <thread>

namespace omni = stb::omni;

int main()
{

  stb::omni::Timer tim;
  tim.start();
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  std::cout << tim.get<stb::omni::millisecond<float>>() << '\n';

  omni::zedou<float> a(30);
  std::cout<< omni::meug<float>(a) << '\n';


return 0;
}
