CFLAGS:=-g -Wall -std=c99

all: poker

poker: poker.c
	$(CC) $(CFLAGS) -o poker poker.c

.PHONY: clean
clean:
	rm -fv poker output.txt
	rm -fv *~ \#*\# *.swp
