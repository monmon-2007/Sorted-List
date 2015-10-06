# this target will compile all the files
#all:
#	gcc main.c linkList.c -o hello
#compile:

#all: hello

#hello: main.o linkList.o
#	gcc main.o linkList.o -o hello

#main.o: main.c 
#	gcc -c main.c

#linkList.o: linkList.c
#	gcc -c linkList.c

#libsl.a: linkList.o      #
#  ar rc libsl.a linkList.o #

#clean:
#	rm -rf *o hello

#COMPILER = gcc
#CCFLAGS  = -Wall
all: sl


linkList.o: linkList.c sorted-list.h
	gcc -c linkList.c
 
main.o: main.c sorted-list.h
	gcc -c main.c
 
libsl.a: linkList.o
	ar rvs libsl.a linkList.o
 
sl: main.o libsl.a
	gcc -o sl main.o libsl.a


clean:
	rm -f sl
	rm -f *.o
	rm -f *.a