/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode* slow= head;
    struct ListNode* fast= head;

    while(fast != NULL && fast ->next != NULL)
    {
        slow= slow->next;
        fast= fast->next->next;
    }
    struct ListNode* prev= NULL;

    while(slow != NULL)
    {
        struct ListNode * next = slow->next;

        slow->next = prev;
        prev= slow;
        slow= next;
    }
    fast = head;
    while(prev != NULL)
    {
        if(fast->val != prev->val)
        {
            return false;
        }
        prev=prev->next;
        fast = fast->next;
    }
    return true;
}