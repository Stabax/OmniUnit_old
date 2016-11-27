//Counter.hpp

/*
*Cette classe est un décompte
*ayant pour précision: la nanoseconde
*/

#ifndef COUNTER_H_
#define COUNTER_H_

#include "Timer.hpp"
#include "general_exceptions.hpp"

class Counter
{
  //fonctions amies

public:
  //constructeurs
  Counter();
  Counter(Counter const& Obj) = delete;

  //destructeur
  ~Counter();

  //méthodes statiques et swap

  //accesseurs
  unsigned long long getNano() const; //retournent la durée restante
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

  //mutateurs
  template<typename ratio, typename durationType>
  void add(durationType const& duration)
  {
    _End = _End + std::chrono::duration<long long, ratio>(duration);
  }
    
  template<typename durationType>
  void add(durationType const& duration)
  {
     _End = _End + duration;
  }
  
  template<typename ratio, typename durationType>
  void subtract(durationType const& duration)
  {
    _End = _End - std::chrono::duration<long long, ratio>(duration);
  }
  
  template<typename durationType>
  void subtract(durationType const& duration)
  {
    _End = _End - duration;
  }
  
  template<typename timePointType>
  void setEnd(timePointType const& timePoint)
  {
    _Timer.stop();
    _Timer.start();
    _End = timePoint;
    _initialized = true;
  }

  //méthodes
  template<typename ratio, typename durationType>
  void init(durationType const& duration)
  {
    _Timer.stop();
    _Timer.start();
    _End = std::chrono::high_resolution_clock::now() + std::chrono::duration<long long, ratio>(duration);
    _initialized = true;
  }
  
  template<typename durationType>
  void init(durationType const& duration)
  {
    _Timer.stop();
    _Timer.start();
    _End = std::chrono::high_resolution_clock::now() + duration;
    _initialized = true;
  }
  void start();
  void pause();

  //opérateurs méthodes ( =, (), [], -> )
  Counter& operator=(Counter const& Obj) = delete;

protected:
  //attributs
  std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> _End;
  Timer _Timer;
  bool _initialized;
  
  
};
//opérateurs non méthodes (+, ++, -, --, +=, -=, /=, *=, %=, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

#endif //COUNTER_H_
