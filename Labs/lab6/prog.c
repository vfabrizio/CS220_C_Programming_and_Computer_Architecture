/* Prog.c */
#include <stdio.h>
void bad() {
	char *new_name = "Quick brown fox jumped over the lazy dog";
	unsigned char *temp;
	temp = (unsigned char *)(&new_name);

	/* tell compiler temp+offset_name contains an address to a string and set address of the new_string as the contents of new_name*/
	*((char **) (temp + 0x20)) = new_name;

	/* tell compiler temp+offset_age is a pointer to an integer and store 1000 in the location pointed to by that integer*/
	*((int *) (temp + 0x28)) = 1000;

	temp = (unsigned char *) (&new_name);
	*((unsigned long *) (temp + 0x18)) += 0x1b;
}

int main(){
	struct {
		char *name;
		int age;
	} student = {.name = "John", .age = 22};
	bad();
	printf("student.name = %s\nstudent.age = %d\n", student.name, student.age);
	return 0;
}
