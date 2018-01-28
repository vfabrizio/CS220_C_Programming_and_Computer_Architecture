#include "functions.h"
#include <stdio.h>

int cryptic_calculator(void *payload){
	unsigned char *ptr = (unsigned char *)payload;
	short int num1, num2, num3;
	if (*ptr == '*') {
		num1 = *(short int *)(&ptr[2]);
		num2 = *(short int *)(&ptr[4]);
		num3 = *(short int *)(&ptr[6]);
		/*printf("%d, %d, %d\n", num1, num2, num3);*/
		return (int)num1 * (int)num2 * (int)num3;
	}else if (*ptr == '/') {
		num1 = *(short int *)(&ptr[2]);
		num2 = *(short int *)(&ptr[4]);
		if (num1 == 0) {
			return 0xBAD;
		}
		return (int)num2 / (int)num1;
	}
	return 0xBAD;
}

void my_memcpy(void *dst, void *src, unsigned int num_bytes){
	int i;
	char *Cdst = (char *)dst;
	char *Csrc = (char *)src;
	for (i = 0; i < num_bytes; i++) {
		if (Csrc[i] == '\0') break;
		if (Cdst[i] == '\0') break;
		Cdst[i] = Csrc[i];
	}
}

void swap_strs(char *s1, char *s2){
	char temp;
	int i, len;
	i = len = 0;
	while (*(s1 + i) != '\0') {
		len++;
		i++;
	}
	/*printf("len:%d\n", len);*/
	for (i = 0; i < len; i++) {
		temp = s1[i];
		s1[i] = s2[i]; 
		s2[i] = temp;
	}
}
