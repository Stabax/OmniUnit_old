#define GOPNIK blyat
#define OMNI_OFFICIAL_ZERO true

#include "omniunit/omniunit.hh"
#include "omniunit/chronoscale.hh"

#include <iostream>
#include <thread>
#include <typeinfo>

namespace omni = stb::omni;

template <typename T>
void show(T const& var1)
{
  std::cout << var1 << " " << var1.dimension() << " " << typeid(typename T::rep).name() << " "<< T::period::num << "/" << T::period::den << " "<< var1.origin << '\n';
}

int main()
{


  omni::Unit<omni::Dimension<0,0,0,0,0,0,0,0,0>, float, omni::deci, omni::E1> scalar(-90);
  omni::def::celsius temp1(0);
  omni::def::celsius temp2(10);

  auto var1 = temp1 / 10;
  show(var1);

  auto var9 = temp1 * temp2;
  show(var9);


return 0;
}
