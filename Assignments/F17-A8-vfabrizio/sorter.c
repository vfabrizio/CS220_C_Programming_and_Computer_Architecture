#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node *sort_nodes(Node *head) {
	Node *current = head;
	while (current -> next != NULL) {
		if (current < (current -> next)) {
			head = swap(current, current->next, head);
			current = head;
		}
		else {
			current = current -> next;
		}
	}

	return head;
}

Node *swap(Node *n1, Node*n2, Node *head) {
	Node *n1_prev = n1 -> prev;
	Node *n2_next = n2 -> next;

	/*if n1 is the head*/
	if (n1 == head) {
		head = n2;
	}
	else {
		n1_prev -> next = n2;
	}
	n2 -> prev = n1_prev;

	n2-> next = n1;
	n1 -> prev = n2;

	n1 -> next = n2_next;
	
	/*n2 is tail*/
	if (n2_next) {
		n2_next -> prev = n1;
	}
	return head;
}