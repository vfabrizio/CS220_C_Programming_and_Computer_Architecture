# Complete this Makefile. Do not add anything below the include statement below.
# At a minimum, you should thoroughly test each of the two macros, the rotate, and the print_backtrace functions in main. Any implementation in main will not be used by the test suite. 

all: main

main: main.c asm.S bt.c
	clang main.c asm.S bt.c -std=c99 -g -o main

.PHONY: clean
clean:
	rm -fv main *.o
	rm -fv *~ \#*\# *.swp

include test.make
