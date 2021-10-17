CC=gcc
IDIR=Functions/
CFLAGS= -Wall -Wextra -Werror -pedantic -ansi -std=c11
LDFLAGS=-std=c11 -lm
SOURCES=main.c
_FUNC=	binary_tree.c
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
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./main.out Eigen_3x3.txt 2
