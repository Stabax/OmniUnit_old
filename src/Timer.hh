//timer.hh

/*
*Cette classe à sémentique de valeur est un chronomètre
*ayant pour précision 10^-7 secondes
*/


#include "Counter.hh"

#ifndef TIMER_HH_
#define TIMER_HH_

#include <chrono>

#include "time.h"


namespace stb
{

  class Timer
  {
  public:
    //fonctions amies
    friend class Counter;
    
    //constructeurs
    explicit Timer();

    //destructeur
    
    //accesseurs
    private:
    std::chrono::nanoseconds getNanoDuration() const; //retourne la durée écoulée en nanoseconde dans une instance std::chrono::duration

    public:
    template<typename ratio = second>  
    unsigned long long get() const  
    {
      return static_cast<unsigned long long>(getDuration<std::chrono::duration<long long, ratio>>().count()); //on multiplie par 10^9 pour avoir des secondes, qui sont modifiées par le ratio std::ratio
      //le type long long est signé car std::chrono::nano est signé (on s'aligne)
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
    
    template<typename ratio = second, typename durationType>  
    void add(durationType time)
    {
      _addedTime += std::chrono::duration<unsigned long long, ratio>(time);
    }

    template<typename ratio = second, typename durationType>  
    void subtract(durationType time)
    {
      unsigned long long current = get<ratio>();
      if(time < current)
        _addedTime -= std::chrono::duration<unsigned long long, ratio>(time);
      else
        _addedTime -= std::chrono::duration<unsigned long long, ratio>(current);
    }



    template<typename unit = std::chrono::seconds>
    void addDuration(unit const& time)
    {
      _addedTime += time;
    }
    
    template<typename unit = std::chrono::seconds>
    void subtractDuration(unit const& time)
    {
      unit current = get<unit>();
      if(time < current)
        _addedTime -= time;
      else
        _addedTime -= current;
    }   

    void clear();
    void reset();
    
    //opérateurs méthodes ( =, (), [], +=, -=, *=, /=, %=)

  protected:
    //attributs
    std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> _Begin; //point du premier start() suivant le dernier stop()
    std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> _BeginPause; //point du dernier pause()
    std::chrono::nanoseconds _PausedTime; //stock le temps total passé en pause() depuis le dernier stop()
    std::chrono::nanoseconds _addedTime; //temps ajouté / retiré (add ou substract)
    bool _isPaused;
    bool _isStopped;
  };
  //opérateurs non méthodes (++, --, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >>)

}//namespace

#endif //TIMER_HH_
