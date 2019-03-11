

#include "omniunit/omniunit.hh"
#include "omniunit/chronoscale.hh"
#include "test.hh"

#include <iostream>
#include <thread>
#include <typeinfo>
#include <iomanip>


#if OMNI_TRUE_ZERO == true

#define VAR1 100
#define VAR2 100
#define VAR3 100
#define VAR4 1
#define VAR5 1
#define VAR6 0
#define VAR7 0

#define VAR8 2458.35
#define VAR9 2458.35
#define VAR10 2458.35
#define VAR11 -245.835
#define VAR12 -245.835
#define VAR13 -270
#define VAR14 -270

#define VAR15 2831.5
#define VAR16 2831.5
#define VAR17 10
#define VAR18 28.315
#define VAR19 10
#define VAR20 -273
#define VAR21 -273

#define VAR22 1
#define VAR23 0
#define VAR24 273.15
#define VAR25 -273.15
#define VAR26 0
#define VAR27 0
#define VAR28 2731.5
#define VAR29 0

#define VAR30 1
#define VAR31 74610.9225
#define VAR32 16.52725023
#define VAR33 0
#define VAR34 546.3

#else // non official zero

#define VAR1 100
#define VAR2 100
#define VAR3 100
#define VAR4 1
#define VAR5 1
#define VAR6 0
#define VAR7 0

#define VAR8 0
#define VAR9 0
#define VAR10 0
#define VAR11 0
#define VAR12 0
#define VAR13 0
#define VAR14 0

#define VAR15 -900
#define VAR16 -900
#define VAR17 -90
#define VAR18 10/9
#define VAR19 0
#define VAR20 -273
#define VAR21 -273

#define VAR22 1
#define VAR23 0
#define VAR24 273.15
#define VAR25 -273.15
#define VAR26 0
#define VAR27 0
#define VAR28 2731.5
#define VAR29 0

#define VAR30 4.53999e-005
#define VAR31 0
#define VAR32 0
#define VAR33 0
#define VAR34 0

#endif


using namespace omni::suffixes;


struct faux
{
  static int value;
};

int faux::value = 0;


template <typename dim, typename rep, typename rat, double const& ori>
void show(int test, omni::Basic_Unit<dim, rep, rat, ori> const& var1, double ref = 0)
{
  bool a = (static_cast<float>(var1.count() - ref) <= std::numeric_limits<float>::epsilon());
  std::cout << std::left << std::setw(8) << "TEST " + std::to_string(test)
  << std::left << std::setw(8) << std::boolalpha << a
  << std::left << std::setw(10) << var1.count()
  << std::left << std::setw(13) << var1.dimension()
  << std::left << std::setw(2) << typeid(rep).name()
  << std::left << std::setw(0) << rat::num << std::left << std::setw(0) << "/" << std::left << std::setw(8) << rat::den
  << std::left << std::setw(8) << var1.origin << "\n";

  if(a == false)
    faux::value++;
}

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
void show(int test, T const& var1, double ref = 0)
{
  bool a = (static_cast<float>(var1) - static_cast<float>(ref) <= std::numeric_limits<float>::epsilon());
  std::cout << std::left << std::setw(8) << "TEST " + std::to_string(test)
  << std::left << std::setw(8) << std::boolalpha << a
  << std::left << std::setw(10) << var1
  << std::left << std::setw(2) << typeid(T).name() << "\n";

  if(a == false)
    faux::value++;
}

int main()
{
  typedef omni::Unit<omni::Dimension<0,0,0,0,0,0,0>, float, omni::deci, omni::E1> scalar;



  omni::kelvin<double> temp1(10);
  auto var1 = temp1 * 10;
  show(1, var1, VAR1);

  omni::kelvin<double> temp2(10);
  auto var2 = 10 * temp2;
  show(2, var2, VAR2);

  omni::kelvin<double> temp3(10);
  auto var3 = temp3 *= 10;
  show(3, var3, VAR3);

  omni::kelvin<double> temp4(10);
  auto var4 = temp4 / 10;
  show(4, var4, VAR4);

  omni::kelvin<double> temp5(10);
  auto var5 = temp5 /= 10;
  show(5, var5, VAR5);

  omni::kelvin<double> temp6(10);
  auto var6 = temp6 % 10;
  show(6, var6, VAR6);

  omni::kelvin<double> temp7(10);
  auto var7 = temp7 %= 10;
  show(7, var7, VAR7);



  omni::celsius<double> temp8(0);
  auto var8 = temp8 * 10;
  show(8, var8, VAR8);

  omni::celsius<double> temp9(0);
  auto var9 = 10 * temp9;
  show(9, var9, VAR9);

  omni::celsius<double> temp10(0);
  auto var10 = temp10 *= 10;
  show(10, var10, VAR10);

  omni::celsius<double> temp11(0);
  auto var11 = temp11 / 10;
  show(11, var11, VAR11);

  omni::celsius<double> temp12(0);
  auto var12 = temp12 /= 10;
  show(12, var12, VAR12);

  omni::celsius<double> temp13(0);
  auto var13 = temp13 % 10;
  show(13, var13, VAR13);

  omni::celsius<double> temp14(0);
  auto var14 = temp14 %= 10;
  show(14, var14, VAR14);



  omni::celsius<double> temp15(10);
  scalar s15(-90); //1
  auto var15 = temp15 * s15;
  show(15, var15, VAR15);

  omni::celsius<double> temp16(10);
  scalar s16(-90); //1
  auto var16 = s16 * temp16;
  show(16, var16, VAR16);

  omni::celsius<double> temp17(10);
  scalar s17(-90); //1
  auto var17 = temp17 *= s17;
  show(17, var17, VAR17);

  omni::celsius<double> temp18(10);
  scalar s18(-90); //1
  auto var18 = temp18 / s18;
  show(18, var18, VAR18);

  omni::celsius<double> temp19(10);
  scalar s19(-90); //1
  auto var19 = temp19 /= s19;
  show(19, var19, VAR19);

  omni::celsius<double> temp20(10);
  scalar s20(-90); //1
  auto var20 = temp20 % s20;
  show(20, var20, VAR20);

  omni::celsius<double> temp21(10);
  scalar s21(-90); //1
  auto var21 = temp21 %= s21;
  show(21, var21, VAR21);



  omni::celsius<double> temp22(0);
  auto var22 = 273.15 / temp22;
  show(22, var22, VAR22);

  omni::celsius<double> temp23(0);
  auto var23 = 273.15 % temp23;
  show(23, var23, VAR23);

  omni::celsius<double> temp24(0);
  omni::kelvin<double> k24(0);
  auto var24 = k24 + temp24;
  show(24, var24, VAR24);

  omni::celsius<double> temp25(0);
  omni::kelvin<double> k25(0);
  auto var25 = k25 - temp25;
  show(25, var25, VAR25);

  omni::celsius<double> temp26(0);
  omni::kelvin<double> k26(0);
  auto var26 = temp26 += k26;
  show(26, var26, VAR26);

  omni::celsius<double> temp27(0);
  omni::kelvin<double> k27(0);
  auto var27 = temp27 -= k27;
  show(27, var27, VAR27);

  omni::celsius<double> temp28(0);
  omni::kelvin<double> k28(10);
  auto var28 = k28 * temp28;
  show(28, var28, VAR28);

  omni::celsius<double> temp29(0);
  omni::kelvin<double> k29(0);
  auto var29 = k29 / temp29;
  show(29, var29, VAR29);


  omni::Unit<omni::Dimension<0,0,0,0,0,0,0>, long double, omni::deci, omni::E1> temp30(-100); //1
  auto var30 = omni::exp(temp30);
  show(30, var30, VAR30);

  omni::celsius<double> temp31(0);
  auto var31 = omni::pow(temp31);
  show(31, var31, VAR31);

  omni::Basic_Unit<omni::Dimension<0,0,0,0,2,0,0>, double, omni::base, omni::celsiusConstant> temp32(0);
  auto var32 = omni::nroot(temp32);
  show(32, var32, VAR32);

  omni::celsius<double> temp33(0);
  auto var33 =-temp33;
  show(33, var33, VAR33);

  omni::celsius<double> temp34(0);
  auto var34 = temp34 + temp34;
  show(34, var34, VAR34);

  //constexpr scalar x(1);
  //constexpr scalar y(3);
  //constexpr scalar z = (x/y);

  std::cout << "nb de faux : " << faux::value << "\n";
  std::cout << omni::modulo(10, -9.f) << "\n"; //BUG

  omni::KilometerPerHour _speed;
  omni::Inch radius;
  omni::revolutionPerMinute<int> _revolutions;
  omni::NewtonMeter _torque;
  omni::perMinute<int> _mRevolutions;
  omni::Horsepower mPower;
  omni::Meter gradient;
  omni::Kilogram _mass;
  omni::Millisecond tickDuration;

  _revolutions = (_speed < omni::KilometerPerHour(5) ? omni::PerMinute(800) : omni::PerMinute(_speed / (2 * 3.14 * radius)) * 1);
  _torque = ((_revolutions > _mRevolutions ? -1  : 1) * mPower / omni::pow<2>(_mRevolutions)) * _revolutions;
  omni::Watt cineticDiff =  omni::Horsepower(0) - (_mass * omni::MeterPerSecond2(9.81) * (gradient / (_speed * tickDuration)) * _speed);

  [[maybe_unused]] omni::NewtonMeter cinetic = (_speed > omni::KilometerPerHour(0) ? omni::NewtonMeter(0.5 * _mass * omni::pow<2>(_speed)) : omni::NewtonMeter(cineticDiff * tickDuration));

  getM();
  foo();


  omni::Watt puiss = omni::RevolutionPerMinute(100) * omni::NewtonMeter(100);

  std::cout << puiss << "\n";

  omni::RevolutionPerMinute res = omni::KilometerPerHour(57.45) * omni::Revolution(1) / (omni::Inch(15) * omni::pi::value);

  std::cout << res << "\n";

  omni::Second t2(0);
  std::chrono::seconds t3(t2);

  omni::Timer tim;
  tim.start();
  //auto dur = tim.get();

return 0;
}
