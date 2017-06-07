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
    explicit Counter();

    //destructeur

    //méthodes statiques et swap

    //accesseurs
    private:
    std::chrono::nanoseconds getNanoDuration() const; //retourne la durée restante en nanoseconde dans une instance std::chrono::duration

    public:
    template<typename ratio = second>
    unsigned long long get() const
    {
      return static_cast<unsigned long long>(getDuration<std::chrono::duration<long long, ratio>>().count());
    }


    template<typename unit = std::chrono::seconds>
    unit getDuration() const
    {
      return std::chrono::duration_cast<unit>(getNanoDuration());
    } 


    //mutateurs
    template<typename ratio = stb::second, typename durationType>
    void add(durationType duration)
    {
      _End = _End + std::chrono::duration<long long, ratio>(duration);
    }
    
    template<typename ratio = stb::second, typename durationType>
    void subtract(durationType duration)
    {
      _End = _End - std::chrono::duration<long long, ratio>(duration);
    }



    template<typename durationType>
    void addDuration(durationType const& duration)
    {
       _End = _End + duration;
    }
    template<typename durationType>
    void subtractDuration(durationType const& duration)
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
    void reset(); //remet _End à now et arrête le décompte

    //opérateurs méthodes ( =, (), [], ->, ++, --, +=, -=, /=, *=, %=)

  protected:
    //attributs
    std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> _End;
    Timer _Timer;
    
    
  };
  //opérateurs non méthodes (+, -, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

}//namespace

#endif //COUNTER_HH_
