/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode*temp= head;
    struct ListNode*prev=NULL;

    while(prev == NULL && temp != NULL)
    {
        if(temp->val == val)
        {
            head=head->next;
            temp=temp->next;
        }
        else
        {
            prev=temp;
            temp=temp->next;
        }
    }
    while(temp != NULL )
    {    
        if(temp->val == val)
        {
            prev->next= temp->next; 
        }
        else
        {
            prev= temp;
        }
        temp = temp->next;
        
    }
    return head;
}