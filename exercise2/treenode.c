#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// tree traversal

typedef struct node {
    char *string;
    struct node *leftchild;
    struct node *rightchild;
} Node;

void traverse_infix(Node *node)
{
    if (node->leftchild != NULL) {
        traverse_infix(node->leftchild);
    }

    fputs(node->string, stdout);
    //print(node->string);

    if (node->rightchild != NULL) {
        traverse_infix(node->rightchild);
    }
}

void traverse_prefix(Node *node)
{
    fputs(node->string, stdout);
    //print(node->string);
    
    if (node->leftchild != NULL) {
        traverse_prefix(node->leftchild);
    }

    if (node->rightchild != NULL) {
        traverse_prefix(node->rightchild);
    }
}


void traverse_postfix(Node *node)
{
    if (node->leftchild != NULL) {
        traverse_postfix(node->leftchild);
    }

    if (node->rightchild != NULL) {
        traverse_postfix(node->rightchild);
    }

    fputs(node->string, stdout);
    //print(node->string);
}

int insert(const char *string, Node *root) 
{
    /* Add a string to the tree. Keeps in order, ignores dupes.
     */
    int num = strcmp(root->string, string);
    Node *temp;

    while(1) {
        if ( 0 == num)
            /* duplicate string - ignore it. */
            return 1;
        else if (-1 == num) {
            /* create new node, insert as right sub-tree.
             */
            if ( NULL == root -> rightchild ) {
                temp = malloc(sizeof(Node));
                temp -> leftchild = NULL;
                temp -> rightchild= NULL;
                temp -> string = strdup(string);
                return 2;
            }
            else
                root = root -> rightchild;
        }
        else if ( NULL == root ->leftchild ) {
            /* create new node, insert as left sub-tree.
             */
            temp = malloc(sizeof(Node));
            temp -> leftchild = NULL;
            temp -> rightchild = NULL;
            temp -> string = strdup(string);
            return 2;
        }
        else
            root = root -> leftchild;
    }
}

int main() 
{
    Node *root;
    char line[100];

    /* Let user enter some data. Enter an EOF (e.g., ctrl-D or F6) when done.
     */
    while (fgets(line, 100, stdin))
        insert(line, root);

    /* print out the data, in order
     */
    traverse_infix(root);
    return 0;
}
