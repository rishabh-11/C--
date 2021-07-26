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
ListNode* Solution::reorderList(ListNode* A) {
    if(A==NULL || A->next==NULL)return A;
    ListNode* head1=A;
    ListNode* mid=find_middle(A);
    ListNode* B=mid->next;
    mid->next=NULL;
    //cerr<<B->val;
    ListNode* curr=B;
    ListNode* prev=NULL, *next=NULL;
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    ListNode* head=head1,*ans=head1;
    head1=head1->next;
    while(head1)
    {
        ListNode* temp=head1->next,*temp1=prev->next;
        head->next=prev;
        head=head->next;
        head->next=head1;
        head=head->next;
        head1=temp;
        prev=temp1;
    }
    if(prev)
    {
        head->next=prev;
        head=head->next;
    }
    if(head)head->next=NULL;
    return ans;
}