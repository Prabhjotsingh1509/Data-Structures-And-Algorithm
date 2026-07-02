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
void preorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
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
    int data;
    scanf("%d", &data);
    struct Node *root = createnode(data);
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