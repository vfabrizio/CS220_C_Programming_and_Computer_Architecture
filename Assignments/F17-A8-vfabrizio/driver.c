#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node two;

int main() {

	Node one;
	
	Node *three = (Node *) malloc (sizeof(Node));
	Node four;
	
	one.next = &two;
	one.prev = NULL;

	two.next = three;
	two.prev = &one;

	three -> next = &four;
	three -> prev = &two;

	four.next = NULL;
	four.prev = three;

	Node *head = &one;
	printf("first: %p\n", head);
	printf("second: %p\n", head->next);
	printf("third: %p\n", head->next->next);
	printf("fourth: %p\n", head->next->next->next);
	printf("fifth: %p\n", head->next->next->next->next);
	printf("\n");

	head = sort_nodes(head);

	printf("first: %p\n", head);
	printf("second: %p\n", head->next);
	printf("third: %p\n", head->next->next);
	printf("fourth: %p\n", head->next->next->next);
	printf("fifth: %p\n", head->next->next->next->next);

	return 0;
}