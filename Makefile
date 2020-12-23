# variables
CC = gcc
WGC = -Wall -g -c

# main command
all: isort txtfind

# main 
#main: main.o isort.o txtfind.o
#	$(CC) -Wall isort.o txtfind.o main.o -o main

isort: isort.o isort.h
	$(CC) -Wall isort.o -o isort

txtfind: txtfind.o txtfind.h
	$(CC) -Wall txtfind.o -o txtfind

#main.o: main.c isort.h txtfind.h
#	$(CC) $(WGC) main.c

isort.o: isort.c
	$(CC) $(WGC) isort.c

txtfind.o: txtfind.c
	$(CC) $(WGC) txtfind.c

# removing all .o, .out, isort and txtfind (exeute) files
clean:
	rm -f *.o *.out *.a *.so main isort txtfind