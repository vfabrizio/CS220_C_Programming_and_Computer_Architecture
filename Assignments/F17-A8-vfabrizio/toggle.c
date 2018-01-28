#include <stdio.h>
#include "toggle.h"

int main() {
	unsigned long num = 66;
	printf("num:%d\n", num);
	num = toggle_bit(num, 6);
	printf("toggled:%d\n", num);

	return 0;
}
