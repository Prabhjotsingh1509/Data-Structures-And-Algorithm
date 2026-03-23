/*Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

/* Structure of a Tree Node */
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

/* Function for Level Order Traversal */
void levelOrder(struct TreeNode *root)
{

    if (root == NULL)
        return;

    struct TreeNode *queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {

        struct TreeNode *temp = queue[front++];
        printf("%d ", temp->val);

        if (temp->left != NULL)
            queue[rear++] = temp->left;

        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }
}

/* Main Function */
int main()
{

    struct TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}