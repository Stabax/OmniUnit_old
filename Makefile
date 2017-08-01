CC = g++

INCDIR = include

BINDIR = bin

SRCDIR = src

TESTDIR = test

CXXFLAGS = -shared -fPIC -std=c++11 -pthread -Wall -Wextra -Wunused-macros -Wshadow -Wundef -pedantic -Wpointer-arith -Wcast-qual -Wcast-align -Wold-style-cast -Wconversion -Wsign-conversion -Wdouble-promotion -Wfloat-equal -Woverloaded-virtual -Weffc++ -Wswitch-default -Werror -s -O2 -Os -Wl,--no-as-needed -I$(INCDIR)

# -Wunreachable-code ==> warning si un bout de code n'est jamais exétuté
#-Wdisabled-optimization ===> warning si le compilateur n'a pas réussi a optimiser un bout de code trop compliqué
#-m8-bit -m16-bit -m32-bit ===> l'alignement des variables se fait sur 8, 16 ou 32 bits (32 par défaut)
#-flto ===> supprime les erreurs de vtable quand des méthodes virtuelles sont déclarées(.h) mais non implémentées(.cpp) (vtable = VMT = virtual method table)

LIBFLAGS = -lstblib

ifeq ($(OS),Windows_NT)
	NAME = libstblib.dll
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		NAME = libstblib.so
	endif
	ifeq ($(UNAME_S),Darwin)
		NAME = libstblib.Framework
	endif
endif





FSSRCS =	$(SRCDIR)/Directory_Item.cpp  	\
		$(SRCDIR)/Directory.cpp  	\
		$(SRCDIR)/Basic_File.cpp	\
		$(SRCDIR)/File.cpp  		\
		$(SRCDIR)/KeyWordFile.cpp

FSOBJS = $(FSSRCS:.cpp=.o)

TIMESRCS =	$(SRCDIR)/time.cpp  		\
		$(SRCDIR)/Timer.cpp  		\
		$(SRCDIR)/Counter.cpp

TIMEOBJS = $(TIMESRCS:.cpp=.o)

EXCSRCS =	$(SRCDIR)/Loggable.cpp  	\
		$(SRCDIR)/Error.cpp 		\
		$(SRCDIR)/Exception.cpp  	\
		$(SRCDIR)/Hasher.cpp

EXCOBJS = $(EXCSRCS:.cpp=.o)

TESTTIMESRC =    $(TESTDIR)/time.cpp

TESTTIMEOBJS = $(TESTTIMESRC:.cpp=.o)





all: $(NAME)

$(NAME): $(FSOBJS) $(TIMEOBJS) $(EXCOBJS)
	$(CC) -o $(BINDIR)/$(NAME) $(FSOBJS) $(TIMEOBJS) $(EXCOBJS) $(CXXFLAGS)

filesystem: $(FSOBJS) $(EXCOBJS)
	$(CC) -o $(BINDIR)/$(NAME) $(FSOBJS) $(EXCOBJS) $(CXXFLAGS)

time: $(TIMEOBJS) $(EXCOBJS)
	$(CC) -o $(BINDIR)/$(NAME) $(TIMEOBJS) $(EXCOBJS) $(CXXFLAGS)





test: testtime testfile

testtime: $(TESTTIMEOBJS)
	$(CC) -o $(BINDIR)/testtime -L$(BINDIR) $(TESTTIMEOBJS) $(CXXFLAGS) $(LIBFLAGS)

testfile: $(TESTFILE)
	$(CC) -o $(BINDIR)/testfile -L$(BINDIR) $(TESTFILEOBJS) $(CXXFLAGS) $(LIBFLAGS)





clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(BINDIR)/$(NAME)

re: fclean all

.PHONY: all clean fclean re
