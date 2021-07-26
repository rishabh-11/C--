/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> ans;

void traverse(TreeNode* A,int* flag,int B)
{
    if(A->val==B)
    {
        ans.push_back(A->val);
        *flag=1;
        return;
    }
    if(A->left!=NULL)
    traverse(A->left,flag,B);
    if(*flag==1)
    {
        ans.push_back(A->val);
        return;
    }
    if(A->right!=NULL)
    traverse(A->right,flag,B);
    if(*flag==1)
    {
        ans.push_back(A->val);
        return;
    }
}
vector<int> Solution::solve(TreeNode* A, int B) {
    ans.clear();
    int flag=0;
    traverse(A,&flag,B);
    reverse(ans.begin(),ans.end());
    return ans;
}
