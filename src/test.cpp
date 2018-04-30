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

  omni::def::kilocelsius temp(0);
  std::cout << omni::kilokelvin<float>(temp) << '\n';

  //auto b = a * temp;
  //std::cout << b << b.dimension() <<'\n';

  omni::Unit<omni::Dimension<0,0,0,0,0,0,0,0,0>, int, omni::base, omni::E2> scalar(10);
  omni::hour<float> h(54);
  h %= scalar;

  omni::def::second sec(2);
  auto ya6ak = omni::duration_cast<omni::def::hour>(sec);

  typedef typename std::common_type<omni::def::petameter, omni::def::femtometer>::type YABOK;
  std::cout << YABOK::period::num << "  " << YABOK::period::den << "\n";

return 0;
}
