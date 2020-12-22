# variables
CC = gcc
WGC = -Wall -g -c

# main command
all: main

# main
main: main.o isort.o txtfind.o
	$(CC) -Wall isort.o txtfind.o main.o -o main

main.o: main.c isort.h txtfind.h
	$(CC) $(WGC) main.c

isort.o: isort.c
	$(CC) $(WGC) isort.c

txtfind.o: txtfind.c
	$(CC) $(WGC) txtfind.c

# removing all .o, .out and main (exeute) files
clean:
	rm -f *.o *.out *.a *.so main