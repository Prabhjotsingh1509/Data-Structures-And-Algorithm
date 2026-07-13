/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int max(int a ,int b)
{
    return (a>b)?a:b;
}
int pairSum(struct ListNode* head) {
    struct ListNode * slow = head;
    struct ListNode * fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow=slow->next;
        fast= fast->next->next;
    }
    struct ListNode *curr = slow;
    struct ListNode*prev= NULL;
    struct ListNode*next=NULL;

    while(curr != NULL)
    {
        next= curr->next;
        curr->next = prev;

        prev=curr;
        curr=next;
    }
    struct ListNode*first= head;
    int maxSum=0;

    while(prev != NULL)
    {
        maxSum=max(maxSum,first->val+prev->val);

        prev=prev->next;
        first=first->next;
    }
    return maxSum;
}