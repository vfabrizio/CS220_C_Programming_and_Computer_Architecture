#include "define.h"
#include<stdio.h>

int main(int argc, char const *argv[]) {
	printf("-----Number 1-----\n");
	struct point p1;
	struct point p2;
	p1.x = 8.32;
	p1.y = 9.27;
	p1.z = 3.45;
	p2.x = 6.66;
	p2.y = 4.81;
	p2.z = 7.62;
	printf("Euclidean distance: %f\n", distance(p1, p2));

	printf("-----Number 2-----\n");
	char s[200];
	char t[200];
	printf("Enter string s: ");
	scanf("%s", s);
	printf("\nEnter string t: ");
	scanf("%s", t);
	printf("Position of the rightmost occurance of %s in %s: %d\n", t, s, strrindex(s, t));

	printf("-----Number 3-----\n");
	char str[200];
	printf("Enter string str: ");
	scanf("%s", str);
	printf("Is %s a valid integer? %d\n", str, is_int(str));
       	
	return 0;
}
