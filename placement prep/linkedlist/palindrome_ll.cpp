/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* find_middle(ListNode* strt)
{
    if(strt->next==NULL)return strt;
    ListNode* fast=strt, *slow=strt;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
int Solution::lPalin(ListNode* A) {
    if(A==NULL || A->next==NULL)return 1;
    ListNode* mid = find_middle(A);
    ListNode* B=mid->next;
    mid->next=NULL;
    
    ListNode* curr=B, *prev=NULL, *next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    while(prev)
    {
        if(prev->val!=A->val)
        {
            return 0;
        }
        A=A->next;
        prev=prev->next;
    }
    return 1;

}