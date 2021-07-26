/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    if(A==NULL)return B;
    if(B==NULL)return A;
    int carry=0;
    ListNode* head=A,*ans=A;
    while(A!=NULL && B!=NULL)
    {
        int val1=carry+(A->val)+(B->val);
        carry=val1/10;
        val1=val1%10;
        head->val=val1;
        A=A->next;
        B=B->next;
        if(A)
        head=A;
        else 
        {head->next=B;head=B;}
    }
    while(A)
    {
        int val1=(A->val)+carry;
        carry=val1/10;
        val1=val1%10;
        head->val=val1;
        A=A->next;
        head->next=A;
        if(A==NULL)
        {
            if(carry>0)
            {
                ListNode* n = new ListNode(carry);
                head->next = n;
            }
        }
        head=A;
    }
    while(B)
    {
        int val1=(B->val)+carry;
        carry=val1/10;
        val1=val1%10;
        head->val=val1;
        B=B->next;
        head->next=B;
        if(B==NULL)
        {
            if(carry>0)
            {
                ListNode* n = new ListNode(carry);
                head->next = n;
            }
        }
        head=B;
    }
    return ans;
}