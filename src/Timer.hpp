//timer.hpp

/*
*Cette classe est un chronomètre
*ayant pour précision: la nanoseconde
*/

#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>

class Timer
{
public:
  //fonctions amies
  
  //constructeurs
  Timer();
  Timer(Timer const &Other) = delete;

  //destructeur
  ~Timer();
  
  //accesseurs
  unsigned long long getNano() const; //retournent la durée écoulée
  unsigned long long getMicro() const;
  unsigned long long getMilli() const;
  unsigned long long getSec() const;
  unsigned long long get() const; //retourne des secondes
  unsigned long long getMin() const;
  unsigned long long getHour() const;
  std::chrono::nanoseconds getNanoDuration() const;
  std::chrono::microseconds getMicroDuration() const;
  std::chrono::milliseconds getMilliDuration() const;
  std::chrono::seconds getSecDuration() const;
  std::chrono::seconds getDuration() const; //retourne des secondes
  std::chrono::minutes getMinDuration() const;
  std::chrono::hours getHourDuration() const;

  std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> getBegin() const;

  //méthodes
  void start();
  void pause();
  void stop();
  
public:
  //opérateurs méthodes ( =, (), [], -> )
  Timer& operator=(Timer const &Other) = delete;

protected:
  //attributs
  std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> _Begin;
  std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> _BeginPause;
  std::chrono::nanoseconds _PausedTime; //duration
  bool _isPaused;
  bool _isStopped;
};

#endif //TIMER_H_
