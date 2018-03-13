
#include "omniunit/omniunit.hh"
#include "omniunit/chronoscale.hh"

#include <iostream>
#include <thread>


int main()
{

  stb::omni::Timer tim;
  tim.start();
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  std::cout << tim.get<stb::omni::millisecond<float>>() << '\n';


return 0;
}
