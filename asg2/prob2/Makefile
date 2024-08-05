CC=gcc
CFLAGS=-g -c -Wall
TARGET=run

${TARGET}: main.o linkedlist.o
	${CC} main.o linkedlist.o -o ${TARGET}
main.o: main.c
	${CC} ${CFLAGS} main.c -o main.o
linkedlist.o: 
	${CC} ${CFLAGS} linkedlist.c -o linkedlist.o
clean:
	rm -rf ${TARGET}
	rm -rf *.o