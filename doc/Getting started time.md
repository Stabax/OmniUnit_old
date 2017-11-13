# Getting started with time

## Units

Stblib is a time library, which mean that some functions take or return a duration.
So, most these functions needs a template parameter to know the unit of the duration (minute ? second ? millisecond ? ...).

example :

    stb::Timer tim;
    tim.start();

    tim.get<std::micro>();  //returns the time elapsed since start() in microseconds
    tim.get<stb::minute>(); //returns the time elapsed since start() in minutes

    stb::Date::get<stb::week>(stb::Date::gmt); //return the week of the year according to gmt time

This template parameter is a std::ratio. Those used in the previous example are typedef defined in the standard library and the Stblib library.

The standard library provides typedef on most useful ratios :\n
(non-exhaustive list)

    namespace std //Be careful, it is standard namespace
    {
        typedef ratio<1, 1000*1000*1000>  nano;
        typedef ratio<1, 1000*1000>       micro;
        typedef ratio<1, 1000>            milli;
    }

Some other ratios are defined in the Stblib, :\n
(exhaustive list)

    namsepace stb //Stblib namespace
    {
        typedef std::ratio<1, 1>             second;
        typedef std::ratio<60, 1>            minute;
        typedef std::ratio<60*60, 1>         hour;
        typedef std::ratio<60*60*24, 1>      day;
        typedef std::ratio<60*60*24*7, 1>    week;
        typedef std::ratio<60*60*24*30, 1>   month;
        typedef std::ratio<60*60*24*365, 1>  year;
    }

Of course, functions in Stblib can use your own std::ratio :

    stb::Timer tim;
    tim.start();
    tim.get< std::ratio<1, 2> >(); //returns the time elapsed since start() in half-seconds

Most of functions taking a duration like previously can also take a std::chrono::duration (see below). Check the existing typedefs in the standard library. You can of course use your own std::chrono::duration type.

## Using sleep

Stblib defines its own sleep functions to stop a thread, which can take :

    stb::sleep<std::milli>(10); //stops the current thread for 10 milliseconds
    stb::sleep<stb::hour>(2);   //stops the current thread for 2 hours

    stb::sleep(std::chrono::seconds(3)); //stops the current thread for 3 seconds by taking a std::chrono::duration

    stb::Timer tim;
    tim.start();
    stb::sleep(tim); //sleep for the time elapsed since start()

## Using Timer

    stb::Timer tim;
    tim.start();

    //returns an integer representing elapsed time since start() in milliseconds
    tim.get<std::milli>();

    //returns a std::chrono::duration representing elapsed time since start() in milliseconds
    tim.getDuration<std::chrono::milliseconds>();

    tim.add<stb::minute>(3);                 //add 3 minutes to the elapsed time
    tim.add(std::chrono::nanoseconds(16));   //add 16 nanoseconds to the elapsed time

    tim.clear(); //remove all time added or subtracted
    tim.stop();  //set pause and set the elapsed time to 0


## Using Countdown

    stb::Countdown count;
    count.add<stb::minute>(1);           //set the Countdown to 1 minute
    count.add(std::chrono::seconds(4));  //add 4 seconds

    count.start();

    unsigned i = count.get<std::milli>();
    while(i > 0)                              
    {                                 //while the Countdown is unfinished,
      stb::sleep<std::milli>(500);    //print the remaining time in milliseconds
      i = count.get<std::micro>();    //2 times per second (every 500 milliseconds)
      std::cout << i << std::endl;
    }

## Using Date

    //returns the date according to local time
    stb::Date::date(stb::Date::local);

    //returns the time according to local time
    stb::Date::time(stb::Date::local);

    //returns the date according to gmt time
    stb::Date::date(stb::Date::gmt);

    //set timelag to +4 hours
    stb::Date::setTimeLag(4);

    //returns the date according to timelag set previously
    stb::Date::date(stb::Date::timezone);

    //returns the hour, the month and the year of your local machine
    stb::Date::get<stb::hour>(stb::Date::local);
    stb::Date::get<stb::month>(stb::Date::local);
    stb::Date::get<stb::year>(stb::Date::local);
