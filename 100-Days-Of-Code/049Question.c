/*
Problem: BST Insert

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/
#include <stdio.h>
#include <stdlib.h>

/* Structure of BST Node */
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* Create new node */
struct TreeNode *newNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* BST Insert Function */
struct TreeNode *insert(struct TreeNode *root, int val)
{

    if (root == NULL)
        return newNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

/* Inorder Traversal */
void inorder(struct TreeNode *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

/* Main Function */
int main()
{

    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct TreeNode *root = NULL;

    printf("Enter values: ");
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}