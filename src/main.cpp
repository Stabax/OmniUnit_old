//main.cpp

#include "GroupedKeyWordFile.hpp"
#include "Counter.hpp"

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
  
  //Directory::createAll("dir1/dir2");
  GFile file("hey.txt");
  
  std::cout<<file.findGKeyword("hey", "YOLO", '.')<<'\n';


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
  Date::setTimeLag(2);
  std::cout<<Date::time()<<'\n';
  std::cout<<Date::time(Date::location::gmt)<<'\n';
  std::cout<<Date::time(Date::location::local)<<'\n';
  std::cout<<Date::time(Date::unit::year)<<'\n';
  std::cout<<Date::date(Date::location::local) << " " << Date::time(Date::location::local)<<'\n';
*/
////////////////////////////////////////

}
catch(Detailed_Loaded_Exception const &e)
{
  std::cout<<"Exception : "<<e.what() <<", at function : "<< e.getSenderFunction()<< ", at file : "<< e.getSenderFile()<<'\n';
}
catch(Detailed_Exception const &e)
{
  std::cout<<"Exception : "<<e.what() <<", at function : "<< e.getSenderFunction()<< ", at file : "<< e.getSenderFile()<<'\n';
}
catch(Loaded_Exception const &e)
{
  std::cout<<"Exception : "<<e.what()<<'\n';
}
catch(std::exception const &e)
{
  std::cout<<"Exception : "<<e.what()<<'\n';
}
catch(std::string const &e)
{
  std::cout<<e<<'\n';
}
catch(...)
{
  std::cout<<"Unknown exception thrown."<<'\n';
}

  return 0;
}
