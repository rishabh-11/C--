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
ListNode* merge(ListNode* A, ListNode* B)
{
    if(A==NULL)return B;
    if(B==NULL)return A;
    ListNode* head=NULL;
    ListNode* ans=NULL;

    while(A && B)
    {
        if(A->val<B->val)
        {
            if(head==NULL)
            {
                head=A;ans=A;
            }
            else
            {
                head->next=A;
                head=head->next;
            }
            A=A->next;
        }
        else
        {
            if(head==NULL)
            {
                head=B;ans=B;
            }
            else
            {
                head->next=B;
                head=head->next;
            }
            B=B->next;
        }
    }
    while(A)
    {
        head->next=A;
        head=head->next;
        A=A->next;
    }
    while(B)
    {
        head->next=B;
        head=head->next;
        B=B->next;
    }
    return ans;
}
ListNode* merge_sort(ListNode* A)
{
    if(A->next==NULL)return A;
    ListNode* mid=find_middle(A);
    ListNode* B=mid->next;
    //cout<<A->val<<" "<<mid->val<<" "<<B->val<<endl;
    mid->next=NULL;
    ListNode* head1 = NULL;
    if(B!=NULL)
    {
        head1 = merge_sort(B);
    }
    ListNode* head2 = merge_sort(A);
    ListNode* head = merge(head1,head2);
    return head;
}
ListNode* Solution::sortList(ListNode* A) {
    if(A==NULL || A->next==NULL)return A;
    ListNode* head = merge_sort(A);
    return head;
}