CC=gcc
LDFLAGS=-std=c11
SOURCES=main.c
CDFLAGS=-Wall
OBJECTS=$(SOURCES:.c=.out)


$(OBJECTS): $(SOURCES)
	$(CC) $(CDFLAGS) -o $(OBJECTS) $(SOURCES) $(LDFLAGS)

clean:
	rm -f $(OBJECTS) 
