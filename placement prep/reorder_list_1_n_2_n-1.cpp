/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* temp=head;
        ListNode* temp1=head;
        while(temp->next!=NULL and temp->next->next!=NULL)
        {
            temp=temp->next->next;
            temp1=temp1->next;
        }
        temp1=temp1->next;
        ListNode* next1=NULL;
        ListNode* prev=NULL;
        while(temp1!=NULL)
        {
            next1=temp1->next;
            temp1->next=prev;
            prev=temp1;
            temp1=next1;
        }
        while(1)
        {
            if(head==NULL and prev==NULL)break;
            ListNode* next2=head->next;
            head->next=prev;
            if(prev==NULL)break;
            ListNode* next3=prev->next;
            prev->next=next2;
            head=next2;
            prev=next3;
        }
        
    }
};