#include <stdio.h>

typedef struct {
	char op;
	short int num1;
	short int num2;
	short int num3;
} myStruct;

int cryptic_calculator(void *payload) {
	myStruct *mptr = (myStruct *)payload;

	if (mptr->op == '*') {
		printf("%hi, %hi, %hi\n", mptr->num1, mptr->num2, mptr->num3);
		return mptr->num1 * mptr->num2 * mptr->num3;
	}else if (mptr->op == '/') {
		if (mptr->num1 == 0) {
			return 0xBAD;
		}
		return mptr->num2 / mptr->num1;	
	}else {
		return 0xBAD;
	}
}

int main() {
	myStruct mys;
	mys.op = '*';
	mys.num1 = 234;
	mys.num2 = 456;
	mys.num3 = 789;
	printf("sizeof: %d\n", sizeof(mys));
	printf("Answer: %d\n", cryptic_calculator((void*)&mys));
	myStruct mys2;
	mys2.op = '/';
	mys2.num1 = 0;
	mys2.num2 = 12;
	printf("Answer: %d\n", cryptic_calculator((void*)&mys2));
}
