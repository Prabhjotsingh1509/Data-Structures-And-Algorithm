/*Problem: Height of Binary Tree

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

#include <stdio.h>
#include <stdlib.h>

/* Structure of a tree node */
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* Create a new node */
struct TreeNode *newNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Function to find height of binary tree */
int height(struct TreeNode *root)
{
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return 1 + (left > right ? left : right);
}

/* Build tree using level order input */
struct TreeNode *buildTree(int arr[], int n)
{

    if (n == 0)
        return NULL;

    struct TreeNode *nodes[n];

    for (int i = 0; i < n; i++)
        nodes[i] = newNode(arr[i]);

    for (int i = 0; i < n; i++)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n)
            nodes[i]->left = nodes[left];

        if (right < n)
            nodes[i]->right = nodes[right];
    }

    return nodes[0];
}

/* Main function */
int main()
{

    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter node values: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode *root = buildTree(arr, n);

    int h = height(root);

    printf("Height of Binary Tree = %d", h);

    return 0;
}