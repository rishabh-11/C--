/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* head=NULL;
    ListNode* ans=NULL;
    while(A)
    {
        ListNode* val1=A;
        while(A->next!=NULL && A->val==A->next->val)
        {
            A=A->next;
        }
        if(head==NULL)
        {
            head=val1;
            ans=val1;
        }
        else
        {
            head->next=val1;
            head=head->next;
        }
        A=A->next;
        head->next=NULL;
    }
    return ans;
}