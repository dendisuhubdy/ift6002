#include <iostream>
#include <cstdlib>

/* The basic data structure of a ndoe
 */

struct node
{
    int data;
    struct node *left, *right;
};

void swap(int* a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

struct node *newNode(int data)
{
    struct node* node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

/* This function does inorder traversal to find out
 * two swapped nodes. It sets three pointers, first,
 * middle, and last. If the swapped nodes are adjacent
 * to each other, the first and middle contain the resultant
 * nod. Else the first and last contain the resultant nodes.
 */

void correctBSTUtil(struct node* root,
                   struct node** first,
                   struct node** middle, 
                   struct node** last,
                   struct node** prev)
{
    if (root)
    {
        correctBSTUtil(root->left, first, middle, last, prev);

        if (*prev && root->data < (*prev)->data)
        {
            // If this is the first violation, mark the two nodes
            // as 'first' and 'middle'
            //
            if (!*first)
            {
                *first = *prev;
                *middle = root;
            }
            else
            {
                *last = root;
            }
        }

        *prev = root;

        correctBSTUtil(root->right, first, middle, last, prev);
    }
}

void correctBST(struct node* root)
{
    // initialize pointers needed
    struct node *first, *middle, *last, *prev;
    first = middle = last = prev = NULL;

    // Set the pointers to find out the two nodes
    correctBSTUtil(root, &first, &middle, &last, &prev);

    // Fix (or correct) the tree
    //
    if (first && last) {
        swap(&(first->data), &(last->data));
    }
    else if(first && middle) {
        // Adjacent nodes are swapped 
        swap( &(first->data), &(middle->data));
    }
    // else nodes have not been swapped, passed tree is really BST
}

void printInorder(struct node* node)
{
    if (node == NULL) {
        return;
    }

    printInorder(node->left);
    std::cout << node->data << std::endl;
    printInorder(node->right);
}

int main()
{
    /*   6
        /  \
       10    2
      / \   / \
     1   3 7  12
     10 and 2 are swapped
    */

    struct node *root   = newNode(6);
    root->left          = newNode(10);
    root->right         = newNode(2);
    root->left->left    = newNode(1);
    root->left->right   = newNode(3);
    root->right->right  = newNode(12);
    root->right->left   = newNode(7);

    std::cout << "Inorder traversal of the original tree is " ;
    printInorder(root);

    std::cout << std::endl;

    correctBST(root);

    std::cout << "Now inorder traversal of the fixed tree is ";
    printInorder(root);
    
    std::cout << std::endl;

    return 0;
    // Time Complexity: O(n)
}
