CC=g++
CFLAGS= -Wall
LDFLAGS=
EXEC=main

all: $(EXEC)


main: main.o Case/Case.o Player/Player.o Game/Game.o Position/Position.o Robot/Robot.o Target/Target.o utilitaires/utilitaires.o

	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o
