/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *temp=node->next;
    struct ListNode *temp1= node;

    while(temp->next != NULL && temp != NULL)
    {
        temp1->val= temp->val;
        temp=temp->next;
        temp1=temp1->next;
    }
    temp1->val=temp->val;
    temp1->next =NULL;
    free(temp);
}