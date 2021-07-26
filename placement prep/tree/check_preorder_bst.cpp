int check(vector<int> &A,int l,int r)
{
    if(l>=r)return 1;
    int i=l+1;
    for(;i<=r;i++)
    {
        if(A[i]>A[l])break;
    }
    int ls=1,rs=1;
    if(l+1<=i-1)
    {
        ls=check(A,l+1,i-1);
        if(A[l+1]>A[l])ls=0;
    }
    if(i<=r)
    {
        rs=check(A,i,r);
        if(A[l]>A[r])rs=0;
    }
    if(ls==0 || rs==0)return 0;
    return 1;
}
int Solution::solve(vector<int> &A) {
    stack<int>s;
    int root=INT_MIN;
    for(int i=0;i<A.size();i++){
        if(A[i]<root)   return false;
        while(!s.empty()&&A[i]>s.top()){
            root=s.top();
            s.pop();
        }
        s.push(A[i]);
    }
    return true;

}
int Solution::solve(vector<int> &A) {
    return check(A,0,A.size()-1);
}
