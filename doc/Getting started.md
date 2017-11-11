# Getting started

# Useful types

Most of functions taking or returning a duration need a template parameter to know the unit of the duration.
This parameter must be a std::ratio. the standard library provides typedefs on the most useful :

    std::nano
    std::micro
    std::milli  
    std::kilo
    std::mega

Some others std::ratio are defined in the Stblib, useful for manipulating dates :

    stb::second
    stb::minute
    stb::hour
    stb::day
    stb::week
    stb::month
    stb::year

exemple of use :

    stb::Timer Tim;
    Tim.start();
    Tim.get<std::micro>();  //returns the time elapsed since start() in microseconds
    Tim.get<stb::minute>(); //returns the time elapsed since start() in minute

    stb::Date::time<stb::week>(stb::Date::gmt); //return the week of the year according to gmt time

# Using sleep

Stblib defines its own sleep functions which can take a std::duration or an integer :

    stb::sleep<std::milli>(10); //stops the current thread for 10 milliseconds
    stb::sleep<stb::hour>(2); //stops the current thread for 2 hours

    stb::sleep<stb::seconds>(3);  //both these functions stop the thread for 3 seconds, but the first one
    stb::sleep(std::chrono::seconds(3)); //take an integer, and the second one take a std::duration

# Using Timer

    Timer Tim;
    Tim.start();

    //returns an integer representing elapsed time since start() in milliseconds
    Tim.get<std::milli>();
    //returns a std::duration representing elapsed time since start() in milliseconds
    Tim.getDuration<std::chrono::milliseconds>();

    Tim.pause();
    Tim.start();

    Tim.add<stb::minute>(3); //add 3 minutes to the elapsed time
    Tim.addDuration(std::chrono::nanoseconds(16)); //add 16 nanoseconds to the elapsed time
    //Substract versions exists too

    Tim.stop(); //set pause and set the elapsed time to 0


# Using Countdown

# Using Date
