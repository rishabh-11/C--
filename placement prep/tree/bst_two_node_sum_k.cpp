/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::t2Sum(TreeNode* A, int B) {
    stack<TreeNode*> p1,p2;
    TreeNode* l=A, *r=A;
    while(l->left)
    {
        p1.push(l);
        l=l->left;
    }
    while(r->right)
    {
        p2.push(r);
        r=r->right;
    }
    int flag=0;
    while(l!=r)
    {
        if((l->val+r->val)==B)return 1;
        else if((l->val+r->val)<B)
        {
            if(l->right)
            {
                p1.push(l);
                l=l->right;
                while(l->left)
                {
                    p1.push(l);
                    l=l->left;
                }
            }
            else
            {
                while(p1.top()->val<l->val)
                {
                    p1.pop();
                }
                l=p1.top();
                p1.pop();
            }
        }
        else
        {
            if(r->left)
            {
                p2.push(r);
                r=r->left;
                while(r->right)
                {
                    p2.push(r);
                    r=r->right;
                }
            }
            else
            {
                while(p2.top()->val>r->val)
                {
                    p2.pop();
                }
                r=p2.top();
                p2.pop();
            }
        }
    }
    return 0;
}
