/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    
    int len=0;
    ListNode* head=A;
    while(A)
    {
        len++;
        A=A->next;
    }
    if((len/2)+1-B<=0)return -1;
    int target=((len/2)+1)-B-1;
    while(target)
    {
        target--;
        head=head->next;
    }
    return head->val;
}