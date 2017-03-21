//Counter.hh

/*
*Cette classe à sémentique de valeur
*est un décompte précis à 10^-7 secondes
*/


#ifndef COUNTER_HH_
#define COUNTER_HH_

#include "Timer.hh"


namespace stb
{

  class Counter
  {
    //fonctions amies

  public:
    //constructeurs
    template<typename ratio, typename durationType>
    explicit Counter(durationType const& duration) : _End(std::chrono::high_resolution_clock::now() + std::chrono::duration<long long, ratio>(duration))
    {
    }
    
    template<typename durationType>
    explicit Counter(durationType const& duration) : _End(std::chrono::high_resolution_clock::now() + duration)
    {
    }

    //destructeur

    //méthodes statiques et swap

    //accesseurs
    unsigned long long getNano() const; //retourne la durée restante en nanoseconde
    std::chrono::nanoseconds getNanoDuration() const; //retourne la durée restante en nanoseconde dans une instance std::chrono::duration
    
    template<typename ratio = second>
    unsigned long long get() const
    {
      return (getNano() * ratio::den) / ((1000*1000*1000) * ratio::num);
    }


    template<typename unit = std::chrono::seconds>
    unit getDuration() const
    {
      return std::chrono::duration_cast<unit>(getNanoDuration());
    } 


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
      _End = timePoint;
    }

    //méthodes
    void start();
    void pause();

    //opérateurs méthodes ( =, (), [], ->, ++, --, +=, -=, /=, *=, %=)

  protected:
    //attributs
    std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> _End;
    Timer _Timer;
    
    
  };
  //opérateurs non méthodes (+, -, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

}//namespace

#endif //COUNTER_HH_
