CC=gcc
LDFLAGS=-std=c11
SOURCES=main.c
CDFLAGS=-Wall -Wextra -Werror -pedantic -ansi -g
OBJECTS=$(SOURCES:.c=.out)


$(OBJECTS): $(SOURCES)
	$(CC) $(CDFLAGS) -o $(OBJECTS) $(SOURCES) $(LDFLAGS)

clean:
	rm -f $(OBJECTS) 

valgrind:
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./main.out data.txt

