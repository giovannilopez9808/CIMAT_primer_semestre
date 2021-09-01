CC=gcc
LDFLAGS=-lm -std=c11
SOURCES=main.c
CDFLAGS=-Wall -Wextra -Werror -pedantic -ansi
OBJECTS=$(SOURCES:.c=.out)


$(OBJECTS): $(SOURCES)
	$(CC) $(CDFLAGS) -o $(OBJECTS) $(SOURCES) $(LDFLAGS)

clean:
	rm -f $(OBJECTS) 
