CC=gcc
LDFLAGS=-lm
SOURCES=main.c
CDFLAGS=-Wall
OBJECTS=$(SOURCES:.c=.out)


$(OBJECTS): $(SOURCES)
	$(CC) $(CDFLAGS) -o $(OBJECTS) $(SOURCES) $(LDFLAGS)

clean:
	rm -f $(OBJECTS) 
