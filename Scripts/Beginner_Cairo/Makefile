main.o: main.c
	gcc -o main.o main.c $(shell pkg-config --cflags --libs cairo) -lm
clean:
	rm -f main.o main.png
