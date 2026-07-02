#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};
int max(int x, int y)
{
    return x > y ? x : y;
}
int getheight(struct Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}
struct Node *createnode(int key)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    new->data = key;
    new->right = NULL;
    new->left = NULL;
    new->height = 1;
    return new;
}
int balfact(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return getheight(root->left) - getheight(root->right);
}
struct Node *rightrotate(struct Node *x)
{
    struct Node *y = x->left;
    struct Node *t = y->right;

    x->left = t;
    y->right = x;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    return y;
}
struct Node *leftrotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *t = y->left;

    x->right = t;
    y->left = x;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    return y;
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

    root->height = 1 + max(getheight(root->left), getheight(root->right));

    int bf = balfact(root);

    if (bf > 1 && key < root->left->data)
    {
        return rightrotate(root);
    }
    if (bf < -1 && key > root->right->data)
    {
        return leftrotate(root);
    }
    if (bf > 1 && key > root->left->data)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (bf < -1 && key < root->right->data)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
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
    struct Node *root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 4);

    int key = 3;
    root = insert(root, key);
    inorder(root);
}