int Solution::maxSpecialProduct(vector<int> &A) {
    vector<int> v(A.size(),0);
    stack<int> s;
    for(int i=A.size()-1;i>=0;i--)
    {
        while(!s.empty() && A[s.top()]<A[i])
        {
            v[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())s.pop();
    vector<int> v1(A.size(),0);
    for(int i=0;i<A.size();i++)
    {
        while(!s.empty() && A[s.top()]<A[i])
        {
            v1[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    long long ans=0;
    for(int i=0;i<A.size();i++)
    {
        ans=max(ans,(long long)v[i]*v1[i]);
    }
    return ans%1000000007;
}
