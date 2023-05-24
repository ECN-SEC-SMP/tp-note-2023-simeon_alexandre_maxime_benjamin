CC=g++
CFLAGS= -Wall
LDFLAGS=
EXEC=main

all: $(EXEC)

main: main.o other.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o
