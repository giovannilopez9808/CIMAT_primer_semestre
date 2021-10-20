CC=gcc
IDIR=Modules/
CFLAGS= -Wall -Wextra -Werror -O3 -pedantic -ansi -std=c11
LDFLAGS=-std=c11 -lm
SOURCES=main.c
_FUNC=	binary_tree.c \
		linked_list.c \
		hash_table.c \
		sets.c \
		menu.c \
		functions.c
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

run:
	./main.out
