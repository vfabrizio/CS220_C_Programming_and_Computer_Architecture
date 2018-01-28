#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Node *my_reverse(Node *head) {
	Node *current = head;
	Node *next = NULL;

	void *prev_ptr = NULL;
	void *next_ptr;

	while(current->ptr != NULL) {
		next = (Node *)(current->ptr - 8);
		current->ptr = prev_ptr;
		prev_ptr = &(current->ptr);
		current  = next;
	}

	current->ptr = prev_ptr;

	return current;
}

/*
void printNode(Node *n) {
	while (n != NULL) {
		printf("&n: %lx, n->val int: %d, n->val char: %c, n->ptr: %lx, n->var: %d\n", &n, n->val.n, n->val.c, n->ptr, n->var);
		n = (Node *) n->ptr;
	}
	printf("NULL\n");
}
*/
