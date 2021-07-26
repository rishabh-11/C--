/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void func(TreeNode* A,TreeNode** ans,TreeNode* parent)
{
    if(A==NULL)return;
    if(A->left!=NULL && A->right==NULL)
    {
        if(parent)
        {
            if(parent->left==A)parent->left=A->left;
            else parent->right=A->left;
        }
        else
        {
            *ans=A->left;
        }
        func(A->left,ans,parent);
    }
    else if(A->left==NULL && A->right!=NULL)
    {
        if(parent)
        {
            if(parent->left==A)parent->left=A->right;
            else parent->right=A->right;
        }
        else
        {
            *ans=A->right;
        }
        func(A->right,ans,parent);
    }
    else
    {
        func(A->left,ans,A);
        func(A->right,ans,A);
    }
}
TreeNode* Solution::solve(TreeNode* A) {
    TreeNode* parent = NULL;
    TreeNode* ans=A;
    func(A,&ans,parent);
    return ans;
}