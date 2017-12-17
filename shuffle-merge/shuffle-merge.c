struct node* ShuffleMerge(struct node* a, struct node* b) 
{
    struct node* result;
    struct node* recur;

    if (a==NULL) 
        return(b); // see if either list is empty
    else if (b==NULL) 
        return(a);

    else {
        // it turns out to be convenient to do the recursive call first --
        // otherwise a->next and b->next need temporary storage.
        recur = ShuffleMerge(a->next, b->next);
        result = a; // one node from a
        a->next = b; // one from b
        b->next = recur; // then the rest
        return(result);
    }
}
