/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(A==NULL)return A;
    int len=0;
    ListNode* head=A;
    ListNode* tail=A;
    ListNode* ans=A;
    while(A)
    {
        len++;
        if(A->next)
        {
            tail=A->next;
        }
        A=A->next;
    }
    B=B%len;
    if(B==0)return ans;
    len=len-B-1;
    ListNode* temp=head;
    while(len)
    {
        len--;
        temp=temp->next;
    }
    tail->next=head;
    ans=temp->next;
    temp->next=NULL;
    return ans;
}