CFLAGS = -ggdb -std=c++11
DEFINES = -DDEBUGGA
INCLUDES = 
LIBS = -lstdc++
EXAMPLE = main.o
CC=g++
EXECUTABLE=main.out

.cpp.o:
	$(CC) -c $(CFLAGS) $(DEFINES) $(INCLUDES) $<

all::	$(EXECUTABLE)

gnuplot_i.o:	gnuplot_i.hpp
main.o:	main.cpp

$(EXECUTABLE): $(EXAMPLE)
	$(CC) -o $@ $(CFLAGS) $(EXAMPLE) $(LIBS)

clean: 
	rm -f $(EXAMPLE) $(EXECUTABLE)
