CC = g++

CXXFLAGS = -std=c++11 -pthread -Wall -Wextra -Wunused-macros -Wshadow -Wundef -pedantic -Wpointer-arith -Wcast-qual -Wcast-align -Wold-style-cast -Wconversion -Wsign-conversion -Wdouble-promotion -Wfloat-equal -Woverloaded-virtual  -Weffc++ -Wswitch-default -Werror -s -O2 -Os -Wl,--no-as-needed

# -Wunreachable-code ==> warning si un bout de code n'est jamais exétuté
#-Wdisabled-optimization ===> warning si le compilateur n'a pas réussi a optimisé un bout de code trop compliqué
#-m8-bit -m16-bit -m32-bit ===> l'alignement des variables se fait sur 8, 16 ou 32 bits (32 par défaut)
#-flto ===> supprime les erreurs de vtable quand des méthodes virtuelles sont déclarées(.h) mais non implémentées(.cpp) (vtable = VMT = virtual method table)

SFML = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio

NAME = stblib

BINDIR = bin

SRCDIR = src

SRCS =  $(SRCDIR)/main.cpp \
  $(SRCDIR)/Directory_Item.cpp  \
  $(SRCDIR)/Directory.cpp  \
  $(SRCDIR)/Basic_File.cpp	\
	$(SRCDIR)/File.cpp  		\
	$(SRCDIR)/KeyWordFile.cpp  		\
	$(SRCDIR)/GroupedKeyWordFile.cpp 	\
	$(SRCDIR)/time.cpp  \
  $(SRCDIR)/Timer.cpp  \
  $(SRCDIR)/Counter.cpp \
  $(SRCDIR)/Loggable.cpp  \
  $(SRCDIR)/Error.cpp \
  $(SRCDIR)/Exception.cpp  \
  $(SRCDIR)/Hasher.cpp

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
