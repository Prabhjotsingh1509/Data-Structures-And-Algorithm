/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<math.h>
int getDecimalValue(struct ListNode* head) 
{
    struct ListNode *temp = head;
    int count =0;
    int res=0;
    while(temp != NULL)
    {
        count++;
        temp= temp->next;
    }
    temp= head;
    count--;
    while(temp != NULL)
    {
        if(temp->val== 1)
        {
            int v= pow(2,count);
            res+=v;
        }
        temp=temp->next;
        count--;    
    }
    return res;
}