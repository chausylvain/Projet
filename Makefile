#Compiler : gcc ou clang
CC = gcc

#Options
CFLAGS = -Wall -Wextra -std=c99 
LFLAGS =

# Program(s) == targets 
EXEC=exec clean

# First target 

all: $(EXEC)

#Répertoires

OBJDIR = obj
SRCDIR = src
INCDIR = include

#Règles implicites (ajoutées par défaut)
.SUFFIXES: .c .o
$(OBJDIR)/%.o: $(SRCDIR)/%.c # <==> %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# added the following for probabiliste.c and exp1.c
$(OBJDIR)/probabiliste.o: research_23/experiments/probabiliste.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/main.o: research_23/experiments/exp1.c
	$(CC) $(CFLAGS) -c $< -o $@

#Dépendencies 

board.o : $(SRCDIR)/board.c 
player.o : $(SRCDIR)/player.c 
interface.o : $(SRCDIR)/interface.c
card.o : $(SRCDIR)/card.c 
probabiliste.o: research_23/experiments/probabiliste.c # added this for probabiliste.c
main.o: research_23/experiments/exp1.c # changed this line for exp1.c

OBJS = $(OBJDIR)/board.o $(OBJDIR)/player.o $(OBJDIR)/interface.o $(OBJDIR)/card.o $(OBJDIR)/main.o $(OBJDIR)/probabiliste.o

# Targets 
exec : $(OBJS)
	$(CC) -o $@ $^

# Clean

clean :
	rm -f $(OBJDIR)/*.o 
