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
struct Node *recsearching(struct Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return recsearching(root->left, key);
    }
    else
    {
        return recsearching(root->right, key);
    }
}

int main()
{
    struct Node *root = createnode(10);
    root->left = createnode(5);
    root->left->left = createnode(4);
    root->left->right = createnode(6);

    root->right = createnode(11);
    root->right->right = createnode(15);
    struct Node *element = recsearching(root, 2);
    if (element == NULL)
    {
        printf("element not found");
    }
    else
    {
        printf("Found: %d", element->data);
    }
    return 0;
}