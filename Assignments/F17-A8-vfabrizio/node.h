#ifndef _NODE_H
#define _NODE_H

struct _Node {
	struct _Node *next;
	struct _Node *prev;
};
typedef struct _Node Node;

Node *sort_nodes(Node *head);
Node *swap(Node *n1, Node *n2, Node *head);

#endif