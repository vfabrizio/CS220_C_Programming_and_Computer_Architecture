all: prelim ret2libc

prelim: prelim.c
	gcc prelim.c -m32 -g -o prelim
	
ret2libc: ret2libc.c
	gcc ret2libc.c get_ebp.S -m32 -g -o ret2libc
	
clean:
	rm -fv prelim
	rm -fv ret2libc
