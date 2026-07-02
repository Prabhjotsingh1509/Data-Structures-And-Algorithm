#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left;
    int key;
    struct Node *right;
};
struct Node *createnode(int value)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    new->key = value;
    new->left = NULL;
    new->right = NULL;

    return new;
}
struct Node *searchitr(struct Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->key)
        {
            return root;
        }
        else if (key < root->key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

int main()
{
    struct Node *root = createnode(10);
    root->left = createnode(5);
    root->left->left = createnode(4);
    root->left->right = createnode(6);

    root->right = createnode(11);
    root->right->right = createnode(15);
    struct Node *element = searchitr(root, 15);
    if (element == NULL)
    {
        printf("element not found");
    }
    else
    {
        printf("Found: %d", element->key);
    }
    return 0;
}