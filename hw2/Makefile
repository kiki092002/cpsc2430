CC=g++
CFLAGS=-c -Wall
all: client
client: client.o myqueue.o
	$(CC) client.o myqueue.o -o client
client.o: client.cpp
	$(CC) $(CFLAGS) client.cpp
myqueue.o: myqueue.cpp
	$(CC) $(CFLAGS) myqueue.cpp
clean:
	rm -f *o client
