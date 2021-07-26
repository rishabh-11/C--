/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    if(A==NULL)return A;
    ListNode *t1 = A, *t2 = A->next;
    while(t2){
        if(t1->val==1 && t2->val==0){
            t1->val=0;
            t2->val=1;
            t1=t1->next;
            t2=t2->next;
        }else if(t1->val==1 && t2->val==1){
            t2=t2->next;
        }else{
            t1=t1->next;
            t2=t2->next;
        }
    }
    return A;
}