#define GOPNIK blyat
#define OMNI_OFFICIAL_MULTIPLICATION true

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

  omni::Unit<omni::Dimension<0,0,0,0,0,0,0,0,0>, int, omni::base, omni::E1> scalar(10);
  std::cout << omni::Unit<omni::Dimension<0,0,0,0,0,0,0,0,0>, int, omni::base>(scalar) << '\n';

  omni::def::celsius temp(0);
  std::cout << (temp *= scalar) << '\n';

  //auto b = a * temp;
  //std::cout << b << b.dimension() <<'\n';

  omni::hour<float> h(54);
  h %= scalar;


  typedef typename std::common_type<omni::def::petameter, omni::def::femtometer>::type YABOK;
  std::cout << YABOK::period::num << "  " << YABOK::period::den << "\n";

return 0;
}
