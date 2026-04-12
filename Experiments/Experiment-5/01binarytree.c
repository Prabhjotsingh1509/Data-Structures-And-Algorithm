// Wap to implement a binary tree and also write traversal in a)inorder,b)preorder,c)postorder

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
int main()
{
    struct Node *root = createnode(5);
    root->left = createnode(3);
    root->left->left = createnode(1);
    root->left->right = createnode(2);

    root->right = createnode(10);
    root->right->left = createnode(5);
    printf("The pre order is :");
    preorder(root);
    printf("\n");
    printf("The post order is :");
    postorder(root);
    printf("\n");
    printf("The in order is :");
    inorder(root);
    printf("\n");
    return 0;
}
