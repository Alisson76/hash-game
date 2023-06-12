CFLAGS=-Wall
all: hash

hash: main.o socket/socketServer.o
	gcc -o hash main.o socket/socketServer.o

clean:
	rm hash *.o socket/*.o
