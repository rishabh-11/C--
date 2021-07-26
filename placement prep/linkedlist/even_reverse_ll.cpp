/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    if(A==NULL || A->next==NULL || A->next->next==NULL)return A;
    ListNode* odd=A;
    ListNode* even=A->next;
    ListNode* temp=A->next;
    ListNode* temp1=NULL;
    ListNode* odd1=odd, *even1=even, *ans=odd1;
    int flag=0;
    A=A->next->next;
    while(A!=NULL)
    {
        if(flag==0)
        {
            odd->next=A;
            odd=odd->next;
        }
        else{
            even->next=A;
            even=even->next;
        }
        flag=1-flag;
        A=A->next;
    }
    odd->next=NULL;
    even->next=NULL;
    //cerr<<1;
    ListNode* curr=even1, *prev=NULL, *next=NULL;
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    while(odd1 && prev)
    {
        ListNode* temp2=odd1->next;
        ListNode* temp3=prev->next;
        if(temp1==NULL)
        {
            temp1=odd1;
        }
        else
        {
            temp1->next=odd1;
            temp1=temp1->next;
        }
        temp1->next=prev;
        temp1=temp1->next;
        odd1=temp2;
        prev=temp3;
    }
    if(temp1)temp1->next=NULL;
    if(odd1)
    {
        if(temp1==NULL)temp1=odd1;
        else{
            temp1->next=odd1;
            temp1=temp1->next;
        }
        temp1->next=NULL;
    }
    return ans;
}