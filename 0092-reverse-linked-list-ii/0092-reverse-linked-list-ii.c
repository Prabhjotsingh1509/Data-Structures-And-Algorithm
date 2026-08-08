/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode dummy;
    dummy.next=head;
    struct ListNode *prev = &dummy;
    struct ListNode *curr = head;
    int count=0;
    while(count < left-1)
    {
   prev=curr;
        curr=curr->next;
        count++;
    }

    count =0;
    while(count< right-left)
    {
        struct ListNode * temp =curr->next;
        curr->next= temp->next;
        temp->next=prev->next;
        prev->next= temp;
        count++;
    }
    return dummy.next;
}