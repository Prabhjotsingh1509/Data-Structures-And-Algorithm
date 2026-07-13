/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* temp= head;
    int count=0;
    while(temp!= NULL)
    {
        count++;
        temp=temp->next;
    }
    int pos = count - n;
    if(pos == 0)
    {
        head=head->next;
        return head;
    }
    struct ListNode *prev=NULL;
    temp=head;
    for(int i=0;i<pos;i++)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;

    free(temp);
    return head;
}