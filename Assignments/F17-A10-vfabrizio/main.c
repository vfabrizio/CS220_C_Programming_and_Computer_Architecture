#include <stdio.h>
#include "macros.h"
#include "bt.h"

extern unsigned long rotate(unsigned long val, unsigned long num, unsigned long direction);

void baz() {
	print_backtrace(4);
}

void bar() {
	baz();
}

void foo() {
	bar();
}

int main() {
	/*unsigned long v = 0xDEADBEEFDEADBEEF;

	printf("any 63 0: %d\n", TEST_IF_ANY_SET(v, 63, 0));
	printf("all 63 0: %d\n", TEST_IF_ALL_SET(v, 63, 0));
	printf("any 35 32: %d\n", TEST_IF_ANY_SET(v, 35, 32));
	printf("all 35 32: %d\n", TEST_IF_ALL_SET(v, 35, 32));
	printf("any 7 4: %d\n", TEST_IF_ANY_SET(v, 7, 4));
	printf("all 7 4: %d\n", TEST_IF_ALL_SET(v, 7, 4));
	printf("any 7 7: %d\n", TEST_IF_ANY_SET(v, 7, 7));
	printf("all 7 7: %d\n", TEST_IF_ALL_SET(v, 7, 7));
	printf("any 62 15: %d\n", TEST_IF_ANY_SET(v, 62, 15));
	printf("all 62 15: %d\n", TEST_IF_ALL_SET(v, 62, 15));

	printf("shift left 2: 0x%lx\n", rotate(v, (unsigned long) 2, (unsigned long) 1 ));
	printf("shift right 2: 0x%lx\n", rotate(v, (unsigned long) 2, (unsigned long) 0 ));
	printf("shift left 66: 0x%lx\n", rotate(v, (unsigned long) 66, (unsigned long) 1 ));
	printf("shift 0x1 right 1: 0x%lx\n", rotate((unsigned long) 0x1, (unsigned long) 1, (unsigned long) 0 ));
	printf("shift 0x45 left 25: 0x%lx\n", rotate((unsigned long) 0x45, (unsigned long) 25, (unsigned long) 1 ));
	printf("shift left 128: 0x%lx\n", rotate(v, (unsigned long) 128, (unsigned long) 1 ));
	*/
	foo();

	return 0;	
}