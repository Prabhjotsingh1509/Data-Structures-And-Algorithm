/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // struct ListNode* temp= head;
    // int count=0;
    // while(temp!= NULL)
    // {
    //     count++;
    //     temp=temp->next;
    // }
    // int pos = count - n;
    // if(pos == 0)
    // {
    //     head=head->next;
    //     return head;
    // }
    // struct ListNode *prev=NULL;
    // temp=head;
    // for(int i=0;i<pos;i++)
    // {
    //     prev=temp;
    //     temp=temp->next;
    // }
    // prev->next=temp->next;

    // free(temp);
    // return head;
    struct ListNode *dummy= malloc(sizeof(struct ListNode));
    dummy->next= head;

    struct ListNode* slow= dummy;
    struct ListNode* fast=dummy;

    for(int i=0;i<=n;i++)
    {
        fast = fast->next;
    }
    while(fast != NULL)
    {
        fast = fast->next;
        slow=slow->next;
    }
    struct ListNode * temp = slow->next;
    slow->next= temp->next;

    free(temp);
    return dummy->next;
}