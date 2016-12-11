//main.cpp

#include "GroupedKeyWordFile.hpp"
#include "Counter.hpp"

int main()
{

try
{
/*
Directory Dir("yolo/yata");
std::cout << Dir.create(m777) << '\n';
perror("mkdir");
*/
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

  GFile file;
  file.open("dir1/dir2/hey.txt");
  file.create(m777);
  //file.rename("hoy");
  file.move("");
  //std::cout<<file.getPath()<<'\n';
  
  //file.open();
  //file.displayState();
  file.addGroup("mot1");
  file.displayState();
  //file.addKeyword("NTM");
  file.addGKeyword("mot1", "yay");
  file.displayState();
  //std::cout<<file.findEndGroup("mot1")<<'\n';
  file.close();

  //std::cout<<BFile::extractDirPath("starfullah/yolo/t.txt")<<'\n';

////////////////////////////////////////
/*
  unsigned var;
  std::cin>>var;
  std::cout<<toBase(var, 8)<<'\n';
*/
////////////////////////////////////////
/*  
  sleep<std::second>(8);
*/
////////////////////////////////////////
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
  std::cout<<"Exception: "<<e.what() <<", at function : "<< e.getFunction()<< ", at file : "<< e.getFile()<<'\n';
}
catch(Detailed_Exception const &e)
{
  std::cout<<"Exception : "<<e.what() <<", at function : "<< e.getFunction()<< ", at file : "<< e.getFile()<<'\n';
}
catch(Loaded_Exception const &e)
{
  std::cout<<"Exception: "<<e.what()<<'\n';
}
catch(Failure const &e)
{
  std::cout<<"Exception : "<< e.getReason() <<'\n';
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

  return 0;
}
