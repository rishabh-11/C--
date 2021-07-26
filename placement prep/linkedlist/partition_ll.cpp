/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    int x=B;
    if(A==NULL)return A;
    ListNode* t1 = A, *t2 = A->next,*prev1 = NULL,*prev2=A;
    ListNode* ans=A;
    while(t2)
    {
        if(t1->val>=x && t2->val<x)
        {
            if(prev1)prev1->next=t2;
            else ans=t2;
            prev1=t2;
            prev2->next = t2->next;
            t2->next=t1;
            t2=prev2->next;
        }
        else if(t1->val>=x && t2->val>=x)
        {
            prev2=t2;
            t2=t2->next;
        }
        else
        {
            prev2=t2;
            t2=t2->next;
            prev1=t1;
            t1=t1->next;
        }
    }
    return ans;
}