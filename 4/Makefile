CFLAGS = -c -Wall
LFLAGS = -lm -o

all: fill built run clean plot

built: main.o
	@gcc main.o $(LFLAGS) main.out

main.o: main.c
	@gcc $(CFLAGS) main.c

run:
	@./main.out

fill: fill.c
	@gcc fill.c -o fill.out && ./fill.out

plot:
	@gnuplot "pl.gnu"

clean:
	@rm -rf *.out *.o
