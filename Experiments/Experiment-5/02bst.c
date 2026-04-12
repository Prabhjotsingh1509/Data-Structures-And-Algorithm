//  wap to implement bst and insert the element bst

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left;
    int data;
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
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}
struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        root = createnode(value);
    }
    else if (root->data > value)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}
int main()
{
    struct Node *root = createnode(5);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 10);
    root = insert(root, 20);
    printf("The pre order is :");
    preorder(root);
    printf("\n");
    printf("The post order is :");
    postorder(root);
    printf("\n");
    printf("The in order is :");
    inorder(root);
    printf("\n");
}
