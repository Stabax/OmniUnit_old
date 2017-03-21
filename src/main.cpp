//main.cpp

#include <iostream>

#include "Directory.hh"
#include "GroupedKeyWordFile.hh"
#include "Counter.hh"
#include "Error.hh"


int main()
{
try
{
  //RANDOM TEST
/*
Directory Dir("yolo/yata");
std::cout << Dir.create(m777) << '\n';
perror("mkdir");
*/

////////////////////////////////////////
  //TEST DE DIRECTORY
/*
  Directory Dir("../src");
  Dir.open();

  std::vector<std::string> vec = Dir.getContent();
  std::vector<long> vec2 = Dir.getId();
  
  for(unsigned int i = 0; i < vec.size(); i++)
    std::cout<< vec2[i] << " --> " << vec[i]<<'\n';
*/ 

////////////////////////////////////////
  //TEST DES FILES
  
  stb::File::create("file");
  //GFile file("hey.txt");
  
  //std::cout<<file.findGKeyword("hey", "YOLO", '.')<<'\n';


////////////////////////////////////////
  //TEST DE COUNTER
/*
  Counter count;
  count.init<std::second>(8);
  while(count.get() > 0)
  {
    sleep<std::second>(1);
    std::cout<< count.get() << '\n';
  }
*/

////////////////////////////////////////
  //TEST DE TIMER
/*
  Timer tim;
  //tim.pause();

  while(tim.get() < 5)
  {
    sleep<std::second>(1);
    std::cout<< tim.get<std::nano>() << '\n';
  }
*/

////////////////////////////////////////
  //TEST DES DATES
/*
  //Date::setTimeLag(2);

  std::cout << Date::time<std::second>(Date::location::local) << '\n';
  std::cout << Date::time<std::minute>(Date::location::local) << '\n';
  std::cout << Date::time<std::hour>(Date::location::local) << '\n';
  std::cout << Date::time<std::day>(Date::location::local) << '\n';
  std::cout << Date::time<std::month>(Date::location::local) << '\n';
  std::cout << Date::time<std::year>(Date::location::local) << '\n';
*/
////////////////////////////////////////
  //TEST DE ERROR


////////////////////////////////////////
}
catch(stb::Exception const &e)
{
  std::cout<<"Exception : [" << e.getDate() << "] : " << e.what() << " , at function : " << e.getSenderFunction() << " , from source file : " << e.getSenderFile() << '\n';
}
catch(std::exception const &e)
{
  std::cout<<"Exception : " << e.what() << '\n';
}
catch(std::string const &e)
{
  std::cout << e << '\n';
}
catch(...)
{
  std::cout<<"Unknown exception thrown." << '\n';
}

  return 0;
}
