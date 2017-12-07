
#include <iostream>
#include "stblib/ratio.hh"


bool equal(double const& a, double const& b)
{
 return (b >= a && b <= a);
}


int main()
{

std::cout << stb::ratio<num, den>::value <<'\n';
std::cout << stb::ratio<num, den>::num <<'\n';
std::cout << stb::ratio<num, den>::den <<'\n';
using newR = stb::ratio_divide<stb::ratio_multiply<stb::ratio<num, den>, stb::ratio<num, den>>::type, stb::ratio<num, den>>::type;
std::cout << newR::value << '\n';
std::cout << newR::num <<'\n';
std::cout << newR::den <<'\n';



return 0;
}
