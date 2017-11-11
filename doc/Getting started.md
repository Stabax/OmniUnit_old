# Getting started

## Unit

Stblib is a time library, which mean that some functions take or return a duration.
So, most these functions needs a template parameter to know the unit of the duration (minute ? second ? millisecond ? ...).

example :

    stb::Timer Tim;
    Tim.start();

    Tim.get<std::micro>();  //returns the time elapsed since start() in microseconds
    Tim.get<stb::minute>(); //returns the time elapsed since start() in minutes

    stb::Date::get<stb::week>(stb::Date::gmt); //return the week of the year according to gmt time

This template parameter is a std::ratio. Those used in the previous example are typedef defined in the standard library and the Stblib library.

The standard library provides typedef on most useful std::ratios :\n
(non-exhaustive list)

    namespace std //Be careful, it is standard namespace
    {
        typedef std::ratio<1, 1000*1000*1000>  nano;
        typedef std::ratio<1, 1000*1000>       micro;
        typedef std::ratio<1, 1000>            milli;
        typedef std::ratio<1000, 1>            kilo;
        typedef std::ratio<1000*1000, 1>       mega;
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

    stb::Timer Tim;
    Tim.start();
    Tim.get< std::ratio<1, 2> >(); //returns the time elapsed since start() in half-seconds

## Using sleep

Stblib defines its own sleep functions which can take a std::duration or an integer :

    stb::sleep<std::milli>(10); //stops the current thread for 10 milliseconds
    stb::sleep<stb::hour>(2);   //stops the current thread for 2 hours

    stb::sleep<stb::seconds>(3);         //both these functions stop the thread for 3 seconds, but the
    stb::sleep(std::chrono::seconds(3)); //first one take an integer, and the second one take a std::chrono::duration
    //(Look at the standard documentation to have all existing typedef on std::chrono::duration)

## Using Timer

    Timer tim;
    tim.start();

    //returns an integer representing elapsed time since start() in milliseconds
    tim.get<std::milli>();

    //returns a std::chrono::duration representing elapsed time since start() in milliseconds
    tim.getDuration<std::chrono::milliseconds>();
    //(Look at the standard documentation to have all existing typedef on std::chrono::duration)

    tim.add<stb::minute>(3);                        //add 3 minutes to the elapsed time
    tim.addDuration(std::chrono::nanoseconds(16));  //add 16 nanoseconds to the elapsed time
    //subtraction exists for both versions

    tim.clear(); //remove all time added or subtracted
    tim.stop();  //set pause and set the elapsed time to 0


## Using Countdown

    stb::Countdown count;
    count.add<stb::minute>(1);  //set the Countdown to 1 minute
    count.start();              //start the Countdown

    count.subtractDuration(std::chrono::seconds(4);  //remove 4 seconds

    unsigned long long i = count.get<std::milli>();
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
