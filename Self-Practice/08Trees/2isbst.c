#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createnode(int value)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    new->data = value;
    new->left = NULL;
    new->right = NULL;

    return new;
}
int isBST(struct Node *root, struct Node *MIN, struct Node *MAX)
{
    if (root == NULL)
    {
        return 1;
    }
    if (MIN != NULL && root->data <= MIN->data)
    {
        return 0;
    }
    if (MAX != NULL && root->data >= MAX->data)
    {
        return 0;
    }

    return isBST(root->left, MIN, root) && isBST(root->right, root, MAX);
}
int main()
{
    struct Node *root = createnode(5);
    root->left = createnode(3);
    root->left->left = createnode(1);
    root->left->right = createnode(2);

    root->right = createnode(10);
    root->right->left = createnode(9);
    if (isBST(root, NULL, NULL))
    {
        printf("Tree is bst");
    }
    else
    {
        printf("Tree is not bst");
    }
}