CC=gcc
LDFLAGS=-lm
SOURCES=main.c
OBJECTS=$(SOURCES:.c=.out)


$(OBJECTS): $(SOURCES)
	$(CC) -o $(OBJECTS) $(SOURCES) $(LDFLAGS)

clean:
	rm -f $(OBJECTS) 
