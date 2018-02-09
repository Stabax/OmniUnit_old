
#include "omniunit/omniunit.hh"
#include <iostream>

int main()
{
  stb::omni::millisecond<float> omni1(1.8);

  std::chrono::hours standard1(omni1); //construction
  //conversion is done implicitly (moreover, std::chrono::hour handle an integer while stb::millisecond<float> handle a float... so standard1 equals 1, not 1.8)

  std::chrono::minutes standard2 = omni1; //same thing, but with assignment instead of construction

  //reciprocally
  omni1 = standard2; //assignment
  stb::omni::year<int> omni2(standard2); //construction

  //explicit conversion in C and C++ style

  //C style
  auto omni3 = stb::omni::second<unsigned>(standard1);
  auto standard3 = std::chrono::seconds(omni2);

  //C++ style
  auto omni4 = stb::omni::duration_cast<stb::omni::second<int>>(standard3);
  auto standard4 = stb::omni::duration_cast<std::chrono::nanoseconds>(omni3);

return 0;
}
