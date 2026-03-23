/*Problem: Count Leaf Nodes

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

/* Structure of Tree Node */
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* Function to create new node */
struct TreeNode *newNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Function to count leaf nodes */
int countLeafNodes(struct TreeNode *root)
{

    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

/* Function to build tree using level order input */
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

    int leafCount = countLeafNodes(root);

    printf("Number of Leaf Nodes = %d", leafCount);

    return 0;
}