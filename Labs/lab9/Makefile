all: main

main: mem_access.c
	gcc mem_access.c -o mem_access
	./mem_access

.PHONY: clean
clean:
	rm -fv mem_access *.o
	rm -fv *~ \#*\# *.swp
	rm -f file64M
