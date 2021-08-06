CC=gcc
CFLAGS=-c -Wall -I/usr/include/cairo
LDFLAGS=-L/usr/lib -lcairo
LIBS=`pkg-config --cflags --libs cairo`
SOURCES=hello.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=hello.out


all:	$(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(LIBS) $< -o $@ 

clean: 
	rm $(OBJECTS) $(EXECUTABLE)