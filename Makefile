CC=gcc
CFLAGS=-c -I.

objects = string.o malloc_string.o list.o tree.o

main: Main.c $(objects)
	$(CC) -o exercises Main.c $(objects)

string.o: StringBasics.h StringBasics.c
	$(CC) $(CFLAGS) -o string.o StringBasics.c

malloc_string.o: MallocStrings.h MallocStrings.c
	$(CC) $(CFLAGS) -o malloc_string.o MallocStrings.c

list.o: list.h list.c
	$(CC) $(CFLAGS) -o list.o list.c

tree.o: tree.h tree.c
	$(CC) $(CFLAGS) -o tree.o tree.c

clean:
	rm exercises $(objects)
