//timer.hpp

/*
*Cette classe est un chronomètre
*ayant pour précision: la nanoseconde
*/

#include "Counter.hpp"

#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>
#include "time.hpp"

class Timer
{
public:
  //fonctions amies
  friend class Counter;
  
  //constructeurs
  Timer();
  Timer(Timer const &Other) = delete;

  //destructeur
  ~Timer();
  
  //accesseurs
  unsigned long long getNano() const; //retourne la durée écoulée en nanoseconde
  std::chrono::nanoseconds getNanoDuration() const; //retourne la durée écoulée en nanoseconde dans une instance std::chrono::duration
  
template<typename ratio = std::second>
unsigned long long get() const
{
  return (getNano() * ratio::den) / ((1000*1000*1000) * ratio::num); //on multiplie par 10^9 pour avoir des secondes, qui seront modifiées par le ratio std::ratio
}


template<typename unit = std::chrono::seconds>
unit getDuration() const
{
  return std::chrono::duration_cast<unit>(getNanoDuration());
}


  //méthodes
  void start();
  void pause();
  void stop();
  
  //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)
  Timer& operator=(Timer const &Other) = delete;

protected:
  //attributs
  std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> _Begin; //point du premier start() suivant le dernier stop()
  std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> _BeginPause; //point du dernier pause()
  std::chrono::nanoseconds _PausedTime; //de type std::chrono::duration, stock le temps total passé en pause() depuis le dernier stop()
  bool _isPaused;
  bool _isStopped;
};
//opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)

#endif //TIMER_H_
