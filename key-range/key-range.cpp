#include <iostream>
#include <cstdlib>

/* The basic data structure of a ndoe
 */

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int range1;
    int range2;
};


struct node *newNode(int data)
{
    struct node* node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
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
