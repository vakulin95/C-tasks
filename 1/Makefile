CFLAGS = -c -Wall

all: built run clean

built: main.o
	@gcc main.o -o main.out

main.o: main.c
	@gcc $(CFLAGS) main.c

run:
	@./main.out

clean:
	@rm -rf *.out *.o
