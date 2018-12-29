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

#define VAR15 2458.35
#define VAR16 2458.35
#define VAR17 2458.35
#define VAR18 -245.835
#define VAR19 -245.835
#define VAR20 -270
#define VAR21 -270

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
  std::cout << std::left << std::setw(8) << "TEST " + std::to_string(test)
  << std::left << std::setw(6) << std::boolalpha << a
  << std::left << std::setw(10) << var1.count()
  << std::left << std::setw(13) << var1.dimension()
  << std::left << std::setw(2) << typeid(typename T::rep).name()
  << std::left << std::setw(0) << T::period::num << std::left << std::setw(0) << "/" << std::left << std::setw(8) << T::period::den
  << std::left << std::setw(8) << var1.origin << "\n";

  if(a == false)
    faux::value++;
}


int main()
{
  typedef omniunit::Unit<omniunit::Dimension<0,0,0,0,0,0,0,0,0>, float, omniunit::deci, omniunit::E1> scalar;



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



  omniunit::celsius<double> temp15(0);
  scalar s15(-90); //1
  auto var15 = temp15 * s15;
  show(15, var15, VAR15);

  omniunit::celsius<double> temp16(0);
  scalar s16(-90); //1
  auto var16 = s16 * temp16;
  show(16, var16, VAR16);

  omniunit::celsius<double> temp17(0);
  scalar s17(-90); //1
  auto var17 = temp17 *= s17;
  show(17, var17, VAR17);

  omniunit::celsius<double> temp18(0);
  scalar s18(-90); //1
  auto var18 = temp18 / s18;
  show(18, var18, VAR18);

  omniunit::celsius<double> temp19(0);
  scalar s19(-90); //1
  auto var19 = temp19 /= s19;
  show(19, var19, VAR19);

  omniunit::celsius<double> temp20(0);
  scalar s20(-90); //1
  auto var20 = temp20 % 10;
  show(20, var20, VAR20);

  omniunit::celsius<double> temp21(0);
  scalar s21(-90); //1
  auto var21 = temp21 %= 10;
  show(21, var21, VAR21);

constexpr scalar x(1);
constexpr scalar y(3);
constexpr scalar z = (x/y);

  std::cout << "nb de faux : " << faux::value << "\n";
return 0;
}
