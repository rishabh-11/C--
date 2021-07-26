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
        if(val1==A)
        {
            if(head==NULL)
            {
                ans=A;head=A;
            }
            else
            {
                head->next=A;
                head=head->next;
            }
        }
        ListNode* temp = A;
        A=A->next;
        temp->next=NULL;
    }
    return ans;