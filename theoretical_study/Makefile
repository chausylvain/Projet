# Compiler : gcc ou clang
CC = gcc

#Options
CFLAGS = -g -Wall -Wextra 
LFLAGS =

# Program(s) == targets 
EXEC=exec clean

# First target 

all: $(EXEC)

#Règles implicites (ajoutées par défaut)
.SUFFIXES: .c .o
.c .o : # <==> %.o: %.c
	$(CC) $(CFLAGS) -c $<

#Dépendencies 

tache_c3.o	: tache_c3.c
tache_c6.o : tache_c6.c
tache_c10.o : tache_c10.c
main.o: tache_c10.c 

# Targets 
exec : main.o tache_c3.o tache_c6.o tache_c10.o
	$(CC) -o $@ $^

# Clean

clean :
	rm -f *.o 
