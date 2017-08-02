CC = g++

INCDIR = include

BINDIR = bin

SRCDIR = src

TESTDIR = test

CXXFLAGS = -std=c++11 -pthread -Wall -Wextra -Wunused-macros -Wshadow -Wundef -pedantic -Wpointer-arith -Wcast-qual -Wcast-align -Wold-style-cast -Wconversion -Wsign-conversion -Wdouble-promotion -Wfloat-equal -Woverloaded-virtual -Weffc++ -Wswitch-default -s -O2 -Os -Wl,--no-as-needed -I$(INCDIR)

SHAREDFLAGS = -shared -fPIC

#-Werror ==> les warning se transforment en erreur
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





FS_SRCS =	$(SRCDIR)/Directory_Item.cpp  	\
		$(SRCDIR)/Directory.cpp  	\
		$(SRCDIR)/Basic_File.cpp	\
		$(SRCDIR)/File.cpp  		\
		$(SRCDIR)/KeyWordFile.cpp

FS_OBJS = $(FS_SRCS:.cpp=.o)



TIME_SRCS =	$(SRCDIR)/Date.cpp  		\
		$(SRCDIR)/Timer.cpp  		\
		$(SRCDIR)/Counter.cpp

TIME_OBJS = $(TIMESRCS:.cpp=.o)



EXC_SRCS =	$(SRCDIR)/Loggable.cpp  	\
		$(SRCDIR)/Error.cpp 		\
		$(SRCDIR)/Exception.cpp  	\
		$(SRCDIR)/Hasher.cpp

EXC_OBJS = $(EXCSRCS:.cpp=.o)





TEST_TIME_SRC =    $(TESTDIR)/time.cpp
TEST_TIME_OBJS = $(TEST_TIME_SRC:.cpp=.o)

TEST_FILE_SRC =    $(TESTDIR)/file.cpp
TEST_FILE_OBJS = $(TEST_FILE_SRC:.cpp=.o)





all: $(NAME)

$(NAME): $(FS_OBJS) $(TIME_OBJS) $(EXC_OBJS)
	$(CC) -o $(BINDIR)/$(NAME) $(FSOBJS) $(TIMEOBJS) $(EXCOBJS) $(CXXFLAGS) $(SHAREDFLAGS)

filesystem: $(FS_OBJS) $(EXC_OBJS)
	$(CC) -o $(BINDIR)/$(NAME) $(FSOBJS) $(EXCOBJS) $(CXXFLAGS) $(SHAREDFLAGS)

time: $(TIME_OBJS) $(EXC_OBJS)
	$(CC) -o $(BINDIR)/$(NAME) $(TIMEOBJS) $(EXCOBJS) $(CXXFLAGS) $(SHAREDFLAGS)





test: testtime testfile

testtime: $(TEST_TIME_OBJS)
	$(CC) -o $(BINDIR)/testtime -L$(BINDIR) $(TEST_TIME_OBJS) $(CXXFLAGS) $(LIBFLAGS)

testfile: $(TEST_FILE_OBJS)
	$(CC) -o $(BINDIR)/testfile -L$(BINDIR) $(TEST_FILE_OBJS) $(CXXFLAGS) $(LIBFLAGS)





clean:
	$(RM) $(FS_OBJS) $(TIME_OBJS) $(EXC_OBJS)

cleantest:
	$(RM) $(TEST_TIME_OBJS) $(TEST_FILE_OBJS)

fclean: clean cleantest
	$(RM) $(BINDIR)/$(NAME)

re: fclean all

.PHONY: all filesystem time test testtime testfile clean cleantest fclean re
