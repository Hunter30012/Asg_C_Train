CC=gcc
CFLAGS=-g -c -Wall
TARGET=run

${TARGET}: main.o binarytree.o morse.o
	${CC} main.o binarytree.o morse.o -o ${TARGET}
main.o: main.c
	${CC} ${CFLAGS} main.c -o main.o
binarytree.o: binarytree.c
	${CC} ${CFLAGS} binarytree.c -o binarytree.o
morse.o: morse.c
	${CC} ${CFLAGS} morse.c -o morse.o
clean:
	rm -rf ${TARGET}
	rm -rf *.o