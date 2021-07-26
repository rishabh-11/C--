int Solution::largestRectangleArea(vector<int> &A) {
    vector<int> v(A.size(),-1);
    stack<int> s;
    for(int i=A.size()-1;i>=0;i--)
    {
        while(!s.empty() && A[s.top()]>A[i])
        {
            v[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())s.pop();
    vector<int> v1(A.size(),A.size());
    for(int i=0;i<A.size();i++)
    {
        while(!s.empty() && A[s.top()]>A[i])
        {
            v1[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    int ans=0;
    for(int i=0;i<A.size();i++)
    {
        int temp=0;
        temp+=(i-v[i]);
        temp+=(v1[i]-i-1);
        ans=max(ans,temp*A[i]);
    }
    return ans;
}
