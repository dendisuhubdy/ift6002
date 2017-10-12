void LinkedList::reversedLinkedList()
{
    if(head == NULL) return;

    Node *prev = NULL, *current = NULL, *next = NULL;
    current = head;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    // now let the head point at the last node (prev)
    head = prev;
}
