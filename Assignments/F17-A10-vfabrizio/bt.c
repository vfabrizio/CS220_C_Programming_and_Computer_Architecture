#include <stdio.h>
#include <stdint.h>
#include "bt.h"

extern unsigned long *get_rbp();

void print_backtrace(int count) {
	unsigned long *curr_rbp = get_rbp();

	unsigned char *main_end = (unsigned char *) &main;
	while (*(main_end) != 0xC3 && *(main_end) != 0xCB) {
		main_end++;
	}

	int level = 1;
	unsigned long ret_addr = 0;
	while (count > 0) {
		ret_addr = (unsigned long) *(curr_rbp + 0x1);
		printf("#%d\t0x%016lx\n", level, ret_addr);
		if(ret_addr > (unsigned long) &main && ret_addr < (unsigned long) &main_end) {
			break;
		}else {
			level++;
			curr_rbp = (unsigned long *) *curr_rbp;
			count--;
		}
	}
	return;
}
