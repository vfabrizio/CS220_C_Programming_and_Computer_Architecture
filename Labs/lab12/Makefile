all: main

pthread: pthread.c
	gcc pthread.c -o pthread -pthread
	
mutex: mutex.c
	gcc mutex.c -o mutex -pthread

main: final.c
	gcc final.c -o final -pthread

.PHONY: clean
clean:
	rm -fv final *.o
	rm -fv pthread *.o
	rm -fv mutex *.o
	rm -fv *~ \#*\# *.swp
