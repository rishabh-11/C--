/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder1(TreeNode* A,int* l,int* r,int* prev,int* prev1,int* flag)
{
    if(A==NULL)return;
    if(*flag==2)return;
    else
    {
        inorder1(A->left,l,r,prev,prev1,flag);
        if(*flag==0 && A->val<(*prev))
        {
            *l=*prev;
            *prev=A->val;
            *flag=1;
        }
        if(*flag==1 && A->val>(*prev1) && A->val<(*prev))
        {
            *r=A->val;
            *flag=2;
        }
        if(*flag==0)
        {
            *prev1=*prev;
            *prev=A->val;
        }
        inorder1(A->right,l,r,prev,prev1,flag);
    }
}
vector<int> Solution::recoverTree(TreeNode* A) {
    int l=-1,r=-1;
    int flag=0;
    int prev=INT_MIN,prev1=INT_MIN;
    inorder1(A,&l,&r,&prev,&prev1,&flag);
    vector<int> ans;
    ans.push_back(l);
    if(r==-1)r=prev;
    ans.push_back(r);
    sort(ans.begin(),ans.end());
    return ans;
}
