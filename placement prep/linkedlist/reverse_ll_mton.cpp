/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode* st=NULL, *en=NULL, *temp=NULL;
    ListNode* ans=A;
    int count=1;
    ListNode* curr=NULL,*prev=NULL,*next=NULL;
    while(A)
    {
        ListNode* temp1 = A->next;
        if(count==B-1)
        {
            temp=A;
        }
        else if(count>=B && count<=C)
        {
            if(count==B)
            {
                st=A;
                curr=A;
            }
            if(count==C)
            {
                en=A;
                if(temp)
                temp->next=en;
                if(B==1)ans=A;
            }
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            
        }
        else
        {
            if(count==C+1)
            {
                st->next=A;
                break;
            }
        }
        count++;
        A=temp1;
    }
    return ans;
}