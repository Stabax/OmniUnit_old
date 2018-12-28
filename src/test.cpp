#define GOPNIK blyat
#define OMNI_TRUE_ZERO true
#define OMNI_DISABLE_UNCERTAINTIES

#include "omniunit/omniunit.hh"
#include "omniunit/chronoscale.hh"

#include <iostream>
#include <thread>
#include <typeinfo>
#include <iomanip>


#if OMNI_TRUE_ZERO == true

#define VAR1 0
#define VAR2 0
#define VAR3 0
#define VAR4 0
#define VAR5 0
#define VAR6 0
#define VAR7 0

#define VAR8 2458.35
#define VAR9 2458.35
#define VAR10 2458.35
#define VAR11 -245.835
#define VAR12 -245.835
#define VAR13 -270
#define VAR14 -270


#else // non official zero

#define VAR1 0
#define VAR2 0
#define VAR3 0
#define VAR4 0

#endif

struct faux
{
  static int value;
};

int faux::value = 0;


template <typename T>
void show(int test, T const& var1, double ref = 0)
{
  bool a = (static_cast<float>(var1.count() - ref) <= std::numeric_limits<float>::epsilon());
  std::cout << "TEST " << std::to_string(test) << " : " << std::setprecision(15) << var1.count() << " " << var1.dimension() << " " << typeid(typename T::rep).name() << " "<< T::period::num << "/" << T::period::den << " "<< var1.origin << " " << std::boolalpha << a << "\n";

  if(a == false)
    faux::value++;
}


int main()
{
  omniunit::Unit<omniunit::Dimension<0,0,0,0,0,0,0,0,0>, float, omniunit::deci, omniunit::E1> scalar(-90);



  omniunit::kelvin<double> temp1(0);
  auto var1 = temp1 * 10;
  show(1, var1, VAR1);

  omniunit::kelvin<double> temp2(0);
  auto var2 = 10 * temp2;
  show(2, var2, VAR2);

  omniunit::kelvin<double> temp3(0);
  auto var3 = temp3 *= 10;
  show(3, var3, VAR3);

  omniunit::kelvin<double> temp4(0);
  auto var4 = temp4 / 10;
  show(4, var4, VAR4);

  omniunit::kelvin<double> temp5(0);
  auto var5 = temp5 /= 10;
  show(5, var5, VAR5);

  omniunit::kelvin<double> temp6(0);
  auto var6 = temp6 % 10;
  show(6, var6, VAR6);

  omniunit::kelvin<double> temp7(0);
  auto var7 = temp7 %= 10;
  show(7, var7, VAR7);



  omniunit::celsius<double> temp8(0);
  auto var8 = temp8 * 10;
  show(8, var8, VAR8);

  omniunit::celsius<double> temp9(0);
  auto var9 = 10 * temp9;
  show(9, var9, VAR9);

  omniunit::celsius<double> temp10(0);
  auto var10 = temp10 *= 10;
  show(10, var10, VAR10);

  omniunit::celsius<double> temp11(0);
  auto var11 = temp11 / 10;
  show(11, var11, VAR11);

  omniunit::celsius<double> temp12(0);
  auto var12 = temp12 /= 10;
  show(12, var12, VAR12);

  omniunit::celsius<double> temp13(0);
  auto var13 = temp13 % 10;
  show(13, var13, VAR13);

  omniunit::celsius<double> temp14(0);
  auto var14 = temp14 %= 10;
  show(14, var14, VAR14);


  std::cout << "nb de faux : " << faux::value << "\n";
return 0;
}
