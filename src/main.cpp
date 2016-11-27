//main.cpp

#include "GroupedKeyWordFile.hpp"
#include "Counter.hpp"

int main()
{

//try
//{
////////////////////////////////////////
/*
  Directory Dir("../src");
  Dir.open();

  std::vector<std::string> vec = Dir.getContent();
  std::vector<long> vec2 = Dir.getId();
  
  for(unsigned int i = 0; i < vec.size(); i++)
    std::cout<< vec2[i] << " --> " << vec[i]<<'\n';
*/ 
////////////////////////////////////////
/*
  GFile file;
  file.setPath("dir1/dir2/hey");
  
  file.create();
  file.rename("hoy");
  file.move("");
  std::cout<<file.getPath()<<'\n';
  
  file.open();
  file.addGroup("mot1");
  file.addKeyword("NTM");
  file.addGKeyword("mot1", "yay");
  std::cout<<file.findEndGroup("mot1")<<'\n';
  file.close();

  std::cout<<BFile::extractDirPath("starfullah/yolo/t.txt")<<'\n';
*/
////////////////////////////////////////
/*
  unsigned var;
  std::cin>>var;
  std::cout<<decToHexa(var)<<'\n';
*/

////////////////////////////////////////
/*  
  sleep<std::second>(8);
*/
////////////////////////////////////////
/*
  Counter count;
  count.init<std::second>(8);
  while(count.getMilli() > 0)
  {
    sleep<std::second>(1);
    std::cout<< count.get() << '\n';
  }
*/
////////////////////////////////////////

  Date::setTimeLag(2);
  std::cout<<Date::time()<<'\n';
  std::cout<<Date::time(Date::location::gmt)<<'\n';
  std::cout<<Date::time(Date::location::local)<<'\n';
  std::cout<<Date::time(Date::unit::year)<<'\n';
  std::cout<<Date::date(Date::location::local) << " " << Date::time(Date::location::local)<<'\n';

////////////////////////////////////////

//}
/*
catch(Loaded_Exception const &e)
{
  std::cout<<"Exception: "<<e.what()<<'\n';
}
catch(Detailed_Exception const &e)
{
  std::cout<<"Exception: "<<e.what()<<", at function: "<< e.function()<<'\n';
}
catch(Failure const &e)
{
  std::cout<<"Exception: Failure thrown."<<'\n';
}
catch(std::exception const &e)
{
  std::cout<<"Exception: "<<e.what()<<'\n';
}
catch(std::string const &e)
{
  std::cout<<e<<'\n';
}
catch(...)
{
  std::cout<<"Unknown exception thrown."<<'\n';
}
*/
  return 0;
}
