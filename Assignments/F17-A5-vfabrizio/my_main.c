#include "node.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

	Node *head;
	int i = 0;
	
	head = (Node *) malloc(sizeof(Node)*5);
	
	for (i = 0; i < 4; i++) {
		head[i].val.n = i+40;
		head[i].ptr = &head[i+1];
		head[i].var = i;
	}

	head[i].val.n = i+40;
	head[i].ptr = NULL;
	head[i].var = i;
	
	printf("Printing original\n");
	printNode(head);
	
	head = my_reverse(head);
	
	printf("\nPrinting new\n");
	printNode(head);


	return 0;
}
