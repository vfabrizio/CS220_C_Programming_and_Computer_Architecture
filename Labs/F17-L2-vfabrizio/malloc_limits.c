#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	while(1) {
		malloc(1024 * 4);
		fork();
	}
	return 0;
}
