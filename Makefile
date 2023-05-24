CC=g++
CFLAGS= -Wall
LDFLAGS=
EXEC=div

all: $(EXEC)

div: main.o lit_ecrit.o utilitaires.o operations.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o
