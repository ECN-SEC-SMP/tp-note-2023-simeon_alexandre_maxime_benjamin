CC=g++
CFLAGS= -Wall
LDFLAGS=
EXEC=main

all: $(EXEC)

main: main.o Game/Game.o Position/Position.o Robot/Robot.o Target/Target.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o
