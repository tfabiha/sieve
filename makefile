all: main.o sieve.o
	gcc main.o sieve.o -lm

main.o: main.c sieve.h
	gcc -g -c main.c

sieve.o: sieve.c sieve.h
	gcc -g -c sieve.c

run: all
	./a.out

clear:
	rm *.o
	rm a.out
