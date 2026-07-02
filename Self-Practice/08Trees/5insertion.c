#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};
struct Node *createnode(int value)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    new->data = value;
    new->left = NULL;
    new->right = NULL;

    return new;
}
struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
    {
        return createnode(key);
    }
    if (root->data > key)
    {
        root->left = insert(root->left, key);
    }
    if (root->data < key)
    {
        root->right = insert(root->right, key);
    }
    return root;
}
void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}
int main()
{
    struct Node *root = createnode(10);
    root->left = createnode(5);
    root->left->left = createnode(4);
    root->left->right = createnode(6);

    root->right = createnode(12);
    root->right->right = createnode(15);

    int key = 11;
    root = insert(root, key);
    inorder(root);
}