/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    if(A==NULL || A->next==NULL)return A;
    ListNode* temp = A->next;
    ListNode* prev = A;
    ListNode* ans = A;
    while(temp!=NULL)
    {
        ListNode* next = temp->next;
        ListNode* prev1=NULL;
        ListNode* curr=ans;
        while(curr!=temp)
        {
            if((curr->val)>(temp->val))
            {
                if(prev1)prev1->next=temp;
                else ans=temp;
                temp->next=curr;
                prev->next=next;
                break;
            }
            prev1=curr;
            curr=curr->next;
        }
        if(curr==temp)
        prev=temp;
        temp = next;
        //cout<<prev->val<<" "<<temp->val<<" "<<temp->next->val<<" "<<ans->val<<" "<<ans->next->val<<"\n";
    }
    return ans;
}