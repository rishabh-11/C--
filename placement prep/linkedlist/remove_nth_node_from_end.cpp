/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int len=0;
    ListNode* head=A;
    while(A)
    {
        len++;
        A=A->next;
    }
    int f=len-B;
    f=max(f,0);
    ListNode* head1=head, *prev=NULL;
    while(f)
    {
        prev=head1;
        head1=head1->next;
        f--;
    }
    if(prev==NULL)
    {
        return head->next;
    }
    prev->next=head1->next;
    return head;
    
}
