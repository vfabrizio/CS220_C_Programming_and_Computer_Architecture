#include <stdio.h>
#include <stdlib.h>
#include "functions.h" 

int main(int argc, char const *argv[]) {
	printf("-----Number 1-----\n");
	long i, *p;
	i = 0x0034deadbeef0020;
	p = &i;
	printf("Answer: %x\n", cryptic_calculator(p));
	
	unsigned char payload[7];
	payload[0] = '*';
	*((short int *)&(payload[2])) = (short int)234;
	*((short int *)&(payload[4])) = (short int)456;
	*((short int *)&(payload[6])) = (short int)789;
	printf("Answer: %d\n", cryptic_calculator((void *)&(payload[0])));

	payload[0] = '/';
	*((short int *)&(payload[2])) = (short int)30;
	*((short int *)&(payload[4])) = (short int)30000;
	printf("Answer: %d\n", cryptic_calculator((void *)&(payload[0])));
	
	payload[0] = 'b';
	*((short int *)&(payload[2])) = (short int)3;
	*((short int *)&(payload[4])) = (short int)30;
	printf("Answer: %d\n", cryptic_calculator((void *)&(payload[0])));

	printf("-----Number 2-----\n");
	char dst[6];
	char src[] = "hello";
	my_memcpy(dst, src, 5);
	printf("new dst: %s\n", dst);
	
	printf("-----Number 3-----\n");
	char s1[] = "hello";
	char s2[] = "byeee";
	printf("s1: %s, s2: %s\n", s1, s2);
	swap_strs(s1, s2);
	printf("new  s1: %s, new s2: %s\n", s1, s2);

	return 0;
}
