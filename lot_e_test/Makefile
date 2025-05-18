#Compiler : gcc ou clang
CC = gcc -g

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

#Dépendencies 

board.o : $(SRCDIR)/board.c 
player.o : $(SRCDIR)/player.c 
interface.o : $(SRCDIR)/interface.c
card.o : $(SRCDIR)/card.c 
main.o: $(SRCDIR)/main.c 

OBJS = $(OBJDIR)/board.o $(OBJDIR)/player.o $(OBJDIR)/interface.o $(OBJDIR)/card.o $(OBJDIR)/main.o

# Targets 
exec : $(OBJS)
	$(CC) -o $@ $^

# Clean

clean :
	rm -f $(OBJDIR)/*.o 
