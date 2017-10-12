#include <stdio.h>
#include <stdlib.h>


#define n_fibo 5

typedef struct Node {
	int val;
	struct Node* prev;
} node;

int fibo(int val){
        if(val == 1 || val == 2) {
                return 1;
        }
        return fibo(val - 1) + fibo(val - 2);
}

node *set_fibo(int n)
{
    node *fibo_entry = malloc(sizeof(node));

    if ( fibo_entry == NULL ) {
        // error
    }

    fibo_entry->count = n;
    fibo_entry->fibo = fibo(n);
    fibo_entry->next = NULL;
    return fibo_entry;
}

int main()
{
	node *fibo_list = NULL;
	node *last_fibo = NULL;

	// Assume n_fibo is the number of Fibonacci numbers you want to store in order
	for ( int n = 1; n <= n_fibo; n++ ) {
		if ( n == 1 )
			fibo_list = last_fibo = set_fibo(1);
		else {
			last_fibo->next = set_fibo(n);
			last_fibo = last_fibo->next;
		}
	}
}
M

