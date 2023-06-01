CC=g++
CFLAGS= -Wall
LDFLAGS=
EXEC=main

all: $(EXEC)

<<<<<<< HEAD
main: main.o Case/Case.o Player/Player.o Game/Game.o Position/Position.o Robot/Robot.o Target/Target.o
=======
main: main.o Player/Player.o Game/Game.o Position/Position.o Robot/Robot.o Target/Target.o Case/Case.o
>>>>>>> dcaa32ff534acf10dd108ff66fcdfb15e95f64d8
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o
