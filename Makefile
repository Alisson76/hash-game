CFLAGS=-Wall

hash: main.o
	gcc -o hash main.o

clean:
	rm hash *.o
