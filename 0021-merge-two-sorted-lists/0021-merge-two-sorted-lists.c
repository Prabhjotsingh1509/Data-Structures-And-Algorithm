/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 ==NULL)
    {
        return list2;
    }
    if(list2 ==NULL)
    {
        return list1;
    }
    struct ListNode*head=malloc(sizeof(struct ListNode));
    if(list1->val<list2->val)
    {
        head->val=list1->val;
        list1=list1->next;
    }
    else
    {
        head->val=list2->val;
        list2=list2->next;
    }
    struct ListNode * temp= head;
    while(list1!= NULL && list2!= NULL)
    {
        struct ListNode * new= malloc(sizeof(struct ListNode));
        new->next=NULL;
        if(list1->val<=list2->val)
        {
            new->val=list1->val;
            list1=list1->next;
            
        }
        else
        {
            new->val=list2->val;
            list2=list2->next;
        }
        temp->next=new;
        temp=temp->next;
    }
    while(list1!= NULL)
    {
        struct ListNode * new= malloc(sizeof(struct ListNode));
        new->next=NULL;
        new->val=list1->val;
        list1=list1->next;
        temp->next=new;
        temp=temp->next;
    }
    while(list2!= NULL)
    {
        struct ListNode * new= malloc(sizeof(struct ListNode));
        new->next=NULL;
        new->val=list2->val;
        list2=list2->next;
        temp->next=new;
        temp=temp->next;
    }
    return head;
}