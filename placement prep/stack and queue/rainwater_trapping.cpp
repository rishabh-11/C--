int Solution::trap(const vector<int> &A) {
    int l[A.size()],r[A.size()];
    l[A.size()-1]=0;r[0]=0;
    for(int i=1;i<A.size();i++)
    {
        r[i]=max(r[i-1],A[i-1]);
    }
    for(int i=A.size()-2;i>=0;i--)
    {
        l[i]=max(l[i+1],A[i+1]);
    }
    int ans=0;
    for(int i=0;i<A.size();i++)
    {
        ans+=max(0,min(l[i],r[i])-A[i]);
    }
    return ans;
}
