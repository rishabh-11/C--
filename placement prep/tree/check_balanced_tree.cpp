/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int check(TreeNode* A)
{
    if(A==NULL)return 0;
    int left=check(A->left);
    int right=check(A->right);
    if(left==-1 or right==-1)return -1;
    if(abs(left-right)>1)return -1;
    return max(left,right)+1;
    
}
int Solution::isBalanced(TreeNode* A) {
    int ans=check(A);
    if(ans==-1)return 0;
    return 1;
}
