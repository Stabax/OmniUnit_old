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


  stb::GKWFile file("txt.txt");
  std::cout << file.findBegGroup("1")<<'\n';
  std::cout << file.findEndGroup("1")<<'\n';

  std::vector<std::string> test {"1", "2"};
  std::cout << file.findBegGroup(test)<<'\n';
  std::cout << file.findEndGroup(test)<<'\n';
  
  std::cout << file.findBegGroup({"1", "2", "3"})<<'\n';
  std::cout << file.findEndGroup({"1", "2", "3"})<<'\n';
/*
  do
  {
    std::cin >> choix;
    std::cin.ignore();
    if(choix == 1)
    {
      unsigned line;
      std::cin >> line;
      std::vector<std::string> vec = file.readLine(line, 2);
      for(unsigned i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << '\n';
      std::cin.ignore();
    }
  }while(choix != 0);
  
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
  
  //stb::File::create("file");
  //GFile file("hey.txt");
  
  //std::cout<<file.findGKeyword("hey", "YOLO", '.')<<'\n';


////////////////////////////////////////
  //TEST DE COUNTER
/*
  stb::Counter count;
  count.add(5);
  count.reset();
  count.add<std::milli>(5);
  count.start();
  while(1)
  {
    stb::sleep<std::micro>(50000);
    std::cout<< count.get<std::nano>() << std::endl;
  }
*/

////////////////////////////////////////
  //TEST DE TIMER
/*
  stb::Timer tim;
  //tim.pause();
  tim.start();
  tim.add<stb::minute>(10);

  //tim.subtract<stb::minute>(1);
  while(1)
  {
    stb::sleep<std::micro>(50000);
    std::cout<< tim.get<std::nano>() << std::endl;
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
