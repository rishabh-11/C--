/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
stack<TreeNode*> p1;
TreeNode* l;
BSTIterator::BSTIterator(TreeNode *root) {
    while(!p1.empty())p1.pop();
    l=root;
    while(l && l->left)
    {
        p1.push(l);
        l=l->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(l==NULL)return false;
    return true;
}

/** @return the next smallest number */
int BSTIterator::next() {
    // TreeNode* l=A;
    // while(l->left)
    // {
    //     p1.push(l);
    //     l=l->left;
    // }
    if(l==NULL)return -1;
    int ans=l->val;
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
        while(!p1.empty() && p1.top()->val<l->val)
        {
            p1.pop();
        }
        if(!p1.empty())
        {
            l=p1.top();
            p1.pop();    
        }
        else l=NULL;
    }
    return ans;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
