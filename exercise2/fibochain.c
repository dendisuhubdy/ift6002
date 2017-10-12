#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node* prev;
} node;

node FiboSubst(node &x)
{
	if(x.val = 0) {
		node y;
		y.val = 0;
		y.prev = &x;
	}

	else if(x.val == 1) {
		node y;
		y.val = 1;
		y.next =NULL;
	}
	FiboSubst(y);
}

int FiboChain(int n)
{
	node x;
	x.val = 0;
	printf("%i ", x.val);

	for (int i=1; i <= n; i++) {
		node x = FiboSubst(&x);
		printf("%i ", x.val);
	}
}

int main()
{
	FiboChain(5);
}

