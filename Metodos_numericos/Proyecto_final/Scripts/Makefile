CC=gcc
IDIR=Modules/
CFLAGS= -Wall -Wextra -Werror -pedantic -ansi -std=c11
LDFLAGS=-std=c11 -lm
SOURCES=main.c
_FUNC=	tools.c\
		heat_equation.c
FUNC=$(patsubst %,$(IDIR)%,$(_FUNC))
OBJS=$(SOURCES:.c=.o)
FOBJS=$(FUNC:.c=.o)
EXEC= main.out

$(EXEC) : $(FOBJS) $(OBJS)
	$(CC) $(CFLAGS) $(FOBJS) $(OBJS)  -o $(EXEC) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJS) $(FOBJS) $(EXEC)

valgrind:
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./main.out

run:
	./main.out