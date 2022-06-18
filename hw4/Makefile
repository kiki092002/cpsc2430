CC=g++
CFLAGS=-c -Wall
all: client
client: client.o citydict.o
	$(CC) client.o citydict.o -o client
client.o: client.cpp
	$(CC) $(CFLAGS) client.cpp
citydict.o: citydict.cpp
	$(CC) $(CFLAGS) citydict.cpp
clean:
	rm -f *o client
