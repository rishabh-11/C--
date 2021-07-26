/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return NULL;
        if(head->next==NULL)return NULL;
        ListNode* temp=head;
        ListNode* temp1=head;
        while(1)
        {
            if(temp->next!=NULL and temp->next->next!=NULL)
            {
                temp=temp->next->next;
                head=head->next;
                if(temp==head)
                {
                    while(temp1!=temp)
                    {
                        temp=temp->next;
                        temp1=temp1->next;
                    }
                    return temp;
                }
            }
            else
            {
                return NULL;
            }
        }
    }
};