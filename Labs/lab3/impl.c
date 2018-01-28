#include <stdio.h>

struct bad_struct {
	short s1;
	long l1;
	short s2;
};

struct good_struct {
	short s1, s2;
	long l1;
};

union unit {
	char c;
	int i;
	long l;
};

unsigned int foo(int x[]) {
	return sizeof(x);
}

int main() {
	struct good_struct gs;
	struct bad_struct bs;
	union unit u;
	int x[30];
	
	/*printf("Size of gs: %d\n", sizeof(gs));
	printf("Size of bs: %d\n", sizeof(bs));
	
	printf("Address of gs.s1: %p\n", &gs.s1);
	printf("Address of gs.l1: %p\n", &gs.l1);
	printf("Address of gs.s2: %p\n", &gs.s2);
	
	printf("Address of bs.s1: %p\n", &bs.s1);
	printf("Address of bs.s2: %p\n", &bs.s2);
	printf("Address of bs.l1: %p\n", &bs.l1);
	
	printf("Size of u: %d\n", sizeof(u));
	printf("Address of u.c: %p\n", &u.c);
	printf("Address of u.i: %p\n", &u.i);
	printf("Address of u.l: %p\n", &u.l);
	
	scanf("Enter long: %lu", &u.l);
	printf("Size of u: %d\n", sizeof(u));
	printf("c: %c l: %lu i: %d &u.l: %s\n", u.c, u.l, u.i, &u.l);*/
	
	printf("Size of x: %d\n", sizeof(x));
	printf("Size of x from foo: %d\n", foo(x));
	
	return 0;
}
