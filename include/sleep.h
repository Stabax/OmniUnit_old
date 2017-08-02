//sleep.h

#ifndef SLEEP_H_
#define SLEEP_H_

#include "timeTypes.h"

namespace stb
{
  //ratio peut être stb::hour stb::minute stb::second std::milli, std::micro, std::nano ...
  template<typename ratio, typename durationType>
  void sleep(durationType const& duration)
  {
    std::this_thread::sleep_for(std::chrono::duration<long long, ratio>(duration));
  }

  //permet de sleep en envoyant une std::Duration
  template<typename durationType>
  void sleep(durationType const& duration)
  {
    std::this_thread::sleep_for(duration);
  }

}//namespace

  #endif //SLEEP_H_
