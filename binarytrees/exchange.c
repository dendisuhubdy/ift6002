#include <stdio.h>
#include <stdlib.h>

typedef struct _node node;
struct _node {
	int data;
	node* next;
};

typedef struct _list list;
struct _list {
   node *first;
};

int exchange(node *n) {
	if (n->next = NULL)
		return 0;
	if(n->next->next = NULL)
		return 0;
	node *tmp = n->next->next;
	n->next->next = tmp->next;
	tmp->next = n->next;
	n->next = tmp;
	return 1;
}

int main()
{
	node test, test2;
	test.data=0;
	test.next=&test2;
	test2.data=0;
	test2.next=NULL;
	exchange(&test);
}
