vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> v(A.size(),-1);
    stack<int> s;
    for(int i=A.size()-1;i>=0;i--)
    {
        while(!s.empty() && A[s.top()]>A[i])
        {
            v[s.top()]=A[i];
            s.pop();
        }
        s.push(i);
    }
    return v;
}
