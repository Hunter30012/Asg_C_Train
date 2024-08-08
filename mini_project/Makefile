CC=gcc
CFLAGS=-g -c -Wall
TARGET=run

${TARGET}: main.o binarytree.o
	${CC} main.o binarytree.o -o ${TARGET}
main.o: main.c
	${CC} ${CFLAGS} main.c -o main.o
binarytree.o: 
	${CC} ${CFLAGS} binarytree.c -o binarytree.o
clean:
	rm -rf ${TARGET}
	rm -rf *.o