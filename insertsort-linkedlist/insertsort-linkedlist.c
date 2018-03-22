// Given a list, change it to be in sorted order (using SortedInsert()).
void InsertSort(struct node** headRef) {
struct node* result = NULL; // build the answer here
struct node* current = *headRef; // iterate over the original list
struct node* next;
while (current!=NULL) {
next = current->next; // tricky - note the next pointer before we change it
SortedInsert(&result, current);
current = next;
}
*headRef = result;
}
