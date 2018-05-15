#define GOPNIK blyat
#define OMNI_OFFICIAL_ZERO false

#include "omniunit/omniunit.hh"
#include "omniunit/chronoscale.hh"

#include <iostream>
#include <thread>

namespace omni = stb::omni;

int main()
{
/*
  omni::Timer tim;
  tim.start();
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  std::cout << tim.get<omni::def::millisecond>() << '\n';
*/

  omni::Unit<omni::Dimension<0,0,0,0,0,0,0,0,0>, int, omni::deci, omni::E1> scalar(-90);

  omni::def::kilocelsius temp(10);
  omni::def::kilometer a(10);
  auto b = a * temp;
  std::cout << b << b.dimension() << " " << decltype(b)::period::num << '\n';

  //typedef typename std::common_type<omni::def::petameter, omni::def::femtometer>::type YABOK;
  //std::cout << YABOK::period::num << "/ " << YABOK::period::den << "\n";

return 0;
}
