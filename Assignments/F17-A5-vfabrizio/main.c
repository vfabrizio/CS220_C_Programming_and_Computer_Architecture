#include "node.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
	Node n1, n2, n3;
	Node *new_head, *next;
	void *next_ptr;

	n1.var = 1;
	n2.var = 2;
	n3.var = 3;
	
	n1.val.c = 'a';
	n2.val.c = 'b';
	n3.val.c = 'c';
	
	n1.ptr = &(n2.ptr);
	n2.ptr = &(n3.ptr);
	n3.ptr = NULL;	

	new_head = my_reverse(&n1);

	printf("%d ", new_head -> var);
	printf("%c \n", new_head -> val.c);

	next_ptr = new_head ->ptr;
	next = (Node *)(next_ptr-8);
	printf("%d ", next -> var);
	printf("%c \n", next -> val.c);

	next_ptr = next -> ptr;
	next = (Node *)(next_ptr-8);
	printf("%d ", next -> var);
	printf("%c \n", next -> val.c);

	next_ptr = next -> ptr;
	next = (Node *)(next_ptr-8);
	printf("%p\n", n3.ptr);
	
	return 0;
}
