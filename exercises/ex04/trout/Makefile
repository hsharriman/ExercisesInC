util.o: util.c util.h
	gcc -Wall -c util.c
trout.o: trout.h trout.c util.h
		gcc -Wall -c trout.c
main.o: trout.h util.h main.c
	gcc -Wall -c main.c
main: trout.o util.o main.o
		gcc *.o -o main
