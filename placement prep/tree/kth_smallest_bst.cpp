/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode* A,TreeNode** ans,int* B)
{
    if(A==NULL)return;
    inorder(A->left,ans,B);
    (*B)--;
    if(*B==0)
    {
        *ans=A;
        return;
    }
    inorder(A->right,ans,B);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    TreeNode* ans=NULL;
    inorder(A,&ans,&B);
    return ans->val;
}
