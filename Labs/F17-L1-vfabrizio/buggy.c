#include <stdio.h>

int main()
{
	char str;
	char str1[255]; /* at most 255 characters */
	int x;
	
	str = 'c';
	
	/* Print the character */
	
	printf("Value of str is %c\n", str); /* 1: to print the value of str you have to use %c bc its a char */
	
	/* Accept a string from user (at most 255 characters) and display it. */
	printf("Enter string: "); 
	gets(str1);
	printf("You entered: ");
	puts(str1);

	x = 5;	
	/* Decrement x in a loop */
	while(x >= -5){ /* 2: there should be no ; here add brackets */
		x--;
	}
	printf("New value of x is %d\n", x);

	if(x == -6) { /* 3: x cant be between 5 and 10 and equal -6 */
		printf("x is NOT between 5 and 10\n");
	}
		/* If x lies between 5 and 10, print so. */
	else if(x > 5 && x < 10) /* 4: can't set inequality like that*/
		printf("x is between 5 and 10\n");
		
		/* Set x and str to 0, test them using the ternary operator, and print their equality. */
		x = str = 0;
		printf("x and str %s\n", ( x != str) ? "differ" : "are equal"); /* 5: != not =! */
		
		printf("All Done!!\n");
	
	return 0;
}
	
	

