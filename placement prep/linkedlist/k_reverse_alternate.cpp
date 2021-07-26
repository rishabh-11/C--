/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A, int B) {
    if(A==NULL || A->next==NULL || B==1)return A;
    int i=1;
    ListNode* head=NULL;
    ListNode* headn=NULL;
    ListNode* curr=A;
    ListNode* prev=NULL;
    ListNode* next=NULL;
    ListNode* ans=NULL;
    int flag=0;
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
                if(flag==0)
                {
                    head->next=curr;
                    head=headn;
                }
                else
                {
                    head->next=headn;
                    head=headn;
                }
                //if(head!=NULL)
               //cout<<head->val<<"\n";
            }
            if(flag==0)
            {
                next=curr->next;
                curr->next=prev;
                prev=NULL;
                curr=next;
                flag=1;
            }
            else
            {
                head=curr;
                curr=curr->next;
                prev=NULL;
                next=NULL;
                flag=0;
            }
            headn=curr;
        }
        else if(flag==0)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        else
        {
            curr=curr->next;
        }
        i++;
    }
    return ans;

}