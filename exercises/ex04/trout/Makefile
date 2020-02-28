trout.o: trout.h trout.c
	gcc -c trout.c

util.o: util.h util.c
	gcc -c util.c

main.o: main.c util.h trout.h
	gcc -c main.c

trout: trout.o util.o main.o
	gcc -g -o -Wall trout trout.o util.o main.o
