node* pop(list *l) {
	node *tmp = l->first;
	if (tmp)
		l->first = tmp->next;
	return tmp;
}

void push(list *l, node *n) {
	n->next = l->first;
	l->first = n;
}

void reverseit(list *l) {
	list newlist = { .first = NULL};
	node *tmp;
	while((tmp = pop(l))) {
		push(&newlist, tmp);
	}
	l->first = newlist.first;
}

