/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if(A==NULL || A->next==NULL)return A;
    ListNode* curr=A;
    ListNode* prev=NULL;
    ListNode* next=A->next;
    ListNode* head;
    while(curr && curr->next)
    {
        //cerr<<next->val<<" ";
        curr->next=next->next;
        if(prev)prev->next=next;
        else head=next;
        next->next=curr;
        prev=curr;
        curr=curr->next;
        if(curr)
        next=curr->next;
    }
    return head;
}
