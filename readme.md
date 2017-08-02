STBLIB is an easy useful toolkit library for C++ language.
It enable you to start your projects faster.

This awesome library provides these features :

TIME :
-A Timer and a Counter, accurate to 10^-7 seconds. You juste have to start/pause/stop it.
-A Date provider, adjustable according to your local machine, to GMT time or with jet lag.

FILE-SYSTEM :
-A Directory class to manage them easily : display their content, move/create/rename/remove them, change their permissions, move through the tree...
-A File classe to manage text files : write and erase some specific lines, move/create/rename/remove the file, change its permissions...
-A Serialized-File in which there are data simply stored as key/value structure, convenient for settings or little saves storage.
-A base classe you should inherit for objetcts that are directory entry (such as sounds, music, pucture, video, symbolic link, executable ...).

ERROR :
-A basic error representation that hold text.
-An error that is detailed with the function and the source file of occurence.
-An error in which the text is loaded from a file (convenient for multi language application).
-A loggable error.
-The main goal of these class are to be inherited for your error representation (like GUI).

EXCEPTION :
-This library uses its own exception hiererchy (inherited of course from std::exception).
-These exceptions hold text descrition "what()", date, function and source file of occurence.
-These exceptions are loggable.
-You can inherite from stb::Exception to get your own exception tree with the same properties as above.



UPCOMMING FEATURES :
-Hash methods (like SHA256, SHA512, SHA1, bit shift, text lengh...).
-Better file system support (optimisations and enhancements).
-Copy/past into/from clipboard.
-Sound module (light filtration methods).
-Menu class for standard output (console, tty...).

