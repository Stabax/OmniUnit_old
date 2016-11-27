CC = g++

CXXFLAGS = -std=c++11 -pthread -Wl,--no-as-needed -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wfloat-equal -Woverloaded-virtual -Wconversion -Wwrite-strings -Weffc++ -Wswitch-default -Wundef -Wunused -Wuninitialized -Werror -Os -s -O2 -flto -march=native
# -pthread -Wl,--no-as-needed sert à activer le multithreading

SFML = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio

NAME = stblib

BINDIR = bin

SRCDIR = src

SRCS =  $(SRCDIR)/main.cpp \
  $(SRCDIR)/Counter.cpp \
  $(SRCDIR)/Timer.cpp  \
  $(SRCDIR)/time.cpp  \
  $(SRCDIR)/Failure.cpp \
  $(SRCDIR)/general_exceptions.cpp  \
  $(SRCDIR)/Directory_Item.cpp  \
  $(SRCDIR)/Directory.cpp  \
  $(SRCDIR)/Basic_File.cpp	\
	$(SRCDIR)/File.cpp  		\
	$(SRCDIR)/KeyWordFile.cpp  		\
	$(SRCDIR)/GroupedKeyWordFile.cpp 	\
  $(SRCDIR)/Hasher.cpp  \
  $(SRCDIR)/Error.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): clean $(OBJS)
	$(CC) $(OBJS) -o $(BINDIR)/$(NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(BINDIR)/$(NAME)

re: fclean all

.PHONY: all clean fclean re
