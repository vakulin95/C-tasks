CFLAGS = -c -Wall
LFLAGS = -lm -o

all: built run

built: main.o
	gcc main.o $(LFLAGS) main.out

main.o: main.c
	gcc $(CFLAGS) main.c

run:
	./main.out

fill: fill.c
	gcc fill.c -o fill.out && ./fill.out

clean:
	rm -rf *.out *.o
