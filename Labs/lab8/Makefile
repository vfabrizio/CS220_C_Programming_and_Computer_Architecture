all: main

main: main.c bits.c
	gcc bits.c main.c -o main
	./main

.PHONY: clean
clean:
	rm -fv main *.o
	rm -fv *~ \#*\# *.swp

