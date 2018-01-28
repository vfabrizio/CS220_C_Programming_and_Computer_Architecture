#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	printf("-----Number 1-----\n");
	int ansFib, input;
	printf("Enter fib number: ");
	scanf("%d", &input);
	ansFib = isFib(input);
	printf("Element number: %d\n", ansFib);
	
	printf("-----Number 2-----\n");
	unsigned long n1;
	unsigned int ansVowels;
	printf("Enter long: ");
	scanf("%lu", &n1);
	ansVowels = count_vowels(n1);
	printf("Number of vowels in %lu: %d\n", n1, ansVowels);

	printf("-----Number 3-----\n");
	long n;
	unsigned int ansOnes;
	printf("Enter a 64-bit integer: ");
	scanf("%ld", &n);
	ansOnes = count_ones(n);
	printf("Number of 1s in binary: %d\n", ansOnes);

	printf("-----Number 4-----\n");
	unsigned long ansSwap, num;
	printf("Enter an 8-byte integer: ");
	scanf("%lx", &num);
	ansSwap = swap_bytes(num);
	printf("Answer: %ld\n", ansSwap);

	printf("-----Number 5-----\n");
	int a, b;
	long ansA4;
	printf("Enter a: ");
	scanf("%d", &a);
	printf("Enter b: ");
	scanf("%d", &b);
	ansA4 = a4_minus_b4(a, b);
	printf("Answer: %ld\n", ansA4);

	return 0;
}
