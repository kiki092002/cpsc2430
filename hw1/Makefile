CC=g++
CFLAGS=-c -Wall
all: client
client: client.o poly.o
	$(CC) client.o poly.o -o client
client.o: client.cpp
	$(CC) $(CFLAGS) client.cpp
poly.cpp: poly.cpp
	$(CC) $(CFLAGS) poly.cpp
clean:
	rm -f *o client
