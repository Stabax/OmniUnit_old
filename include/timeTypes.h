//timeTypes.h

#ifndef TIMETYPES_H_
#define TIMETYPES_H_

#include <ratio>

namespace stb
{

  typedef std::ratio<1, 1> second;
  typedef std::ratio<60, 1> minute;
  typedef std::ratio<60*60, 1> hour;
  typedef std::ratio<60*60*24, 1> day;
  typedef std::ratio<60*60*24*7, 1> week;
  typedef std::ratio<60*60*24*30, 1> month;
  typedef std::ratio<60*60*24*365, 1> year;
  
}//namespace

#endif //TIMETYPES_H_
