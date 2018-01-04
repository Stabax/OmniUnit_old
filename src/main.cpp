
#include <iostream>
#include "stblib/units.hh"


bool equal(double const& a, double const& b)
{
 return (b >= a && b <= a);
}


int main()
{

std::chrono::duration<float, std::ratio<1,1>> a(3);
stb::second<unsigned long long> b = a;

std::cout << b.count() << '\n';
return 0;
}
