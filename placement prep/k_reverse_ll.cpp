/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::reverseList(ListNode* A, int B) {
    if(A==NULL || A->next==NULL || B==1)return A;
    int i=1;
    ListNode* head=NULL;
    ListNode* headn=NULL;
    ListNode* curr=A;
    ListNode* prev=NULL;
    ListNode* next=NULL;
    ListNode* ans=NULL;
    while(curr!=NULL)
    {
        if(i%B==0)
        {
            if(i==B)
            {
                ans=curr;
                head=A;
            }
            else
            {
                //cout<<head->val<<" "<<curr->val<<" ";
                head->next=curr;
                head=headn;
                //if(head!=NULL)
               //cout<<head->val<<"\n";
            }
            next=curr->next;
            curr->next=prev;
            prev=NULL;
            curr=next;
            headn=curr;
        }
        else
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        i++;
    }
    return ans;

}
