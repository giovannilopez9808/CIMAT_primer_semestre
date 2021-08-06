CC=gcc
LIBS=`pkg-config --cflags --libs cairo`
LDFLAGS=-lm
SOURCES=main.c
OBJECTS=$(SOURCES:.c=.out)


$(OBJECTS): $(SOURCES)
	$(CC) -o $(OBJECTS) $(SOURCES) $(LIBS) $(LDFLAGS)

clean:
	rm -f $(OBJECTS) grafica.png
