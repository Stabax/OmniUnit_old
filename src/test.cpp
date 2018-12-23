#define GOPNIK blyat
#define OMNI_TRUE_ZERO true
#define OMNI_DISABLE_UNCERTAINTIES

#include "omniunit/omniunit.hh"
#include "omniunit/chronoscale.hh"

#include <iostream>
#include <thread>
#include <typeinfo>


#if OMNI_TRUE_ZERO == true

#define VAR1 2458.35
#define VAR2 2458.35
#define VAR3 0
#define VAR4 0
#define VAR5 283.15
#define VAR6 10
#define VAR7 0

#else // non official zero

#define VAR1 0
#define VAR2 0
#define VAR3 0
#define VAR4 0

#endif



template <typename T>
void show(T const& var1, double ref = 0)
{
  bool a = (var1.count() <= ref && var1.count() >= ref);
  std::cout << var1 << " " << var1.dimension() << " " << typeid(typename T::rep).name() << " "<< T::period::num << "/" << T::period::den << " "<< var1.origin << " " << std::boolalpha << a << "\n";
}


int main()
{


  omniunit::Unit<omniunit::Dimension<0,0,0,0,0,0,0,0,0>, float, omniunit::deci, omniunit::E1> scalar(-90);
  omniunit::celsius<double> temp1(0);
  omniunit::celsius<double> temp2(10);
  omniunit::kelvin<double> temp3(10);

  omniunit::celsius<double> temp4(0);

  show(temp1);

  auto var1 = temp1 * 10;
  show(var1, VAR1);

  auto var2 = temp1 *= 10;
  show(var2, VAR2);

  auto var3 = temp1 / 10;
  show(var3, VAR3);

  auto var4 = temp1 /= 10;
  show(var4, VAR4);

  auto var5 = temp1 + temp3;
  show(var5, VAR5);

  auto var6 = temp1 += temp3;
  show(var6, VAR6);

  auto var7 = temp1 + temp4;
  show(var7, VAR7);

  auto var9 = temp1 * temp2;
  show(var9);

return 0;
}
