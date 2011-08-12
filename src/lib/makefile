CFLAGS = -Wall -ansi -pedantic -g
INC = -I../includes

default: app
all: app tests

app: main supplement
	gcc main.o hash.o list.o lru_cache.o node.o -o ../../app $(CFLAGS) $(INC)

tests: tests-main supplement
	gcc tests-main.o hash.o list.o lru_cache.o node.o -o ../../tests $(CFLAGS) $(INC)

main: ../main.c
	gcc -c ../main.c -o main.o $(CFLAGS) $(INC)

tests-main: ../tests-main.c
	gcc -c ../tests-main.c -o tests-main.o $(CFLAGS) $(INC)

supplement: hash.c node.c list.c lru_cache.c ../includes/hash.h ../includes/node.h ../includes/list.h ../includes/lru_cache.h
	gcc -c node.c -o node.o $(CFLAGS) $(INC)
	gcc -c list.c -o list.o $(CFLAGS) $(INC)
	gcc -c hash.c -o hash.o $(CFLAGS) $(INC)
	gcc -c lru_cache.c -o lru_cache.o $(CFLAGS) $(INC)

clean:
	rm -rf *.o
