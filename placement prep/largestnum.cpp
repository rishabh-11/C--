string Solution::largestNumber(const vector<int> &A) {
    vector<int> v;
    int n=A.size();
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==0)count++;
        v.push_back(A[i]);
    }
    if(count==n)
    {
        return "0";
    }
    sort(v.begin(),v.end(),[](int &a,int &b)
    {
        string t1=to_string(a);
        string t2=to_string(b);
        int i=0,j=0;
        while(1)
        {
            if(j>i && j==0)return true;
            if(i>j && i==0)return true;
            if(t1[i]==t2[j])
            {
                i++;j++;
            }
            else if(t1[i]>t2[j])
            {
                return true;
            }
            else
            {
                return false;
            }
            if(i==t1.size() && j==t2.size())
            {
                return true;
            }
            if(i==t1.size())
            {
                i=0;
            }
            if(j==t2.size())
            {
                j=0;
            }
        }
    });
    string s="";
    for(int i=0;i<n;i++)
    {
        s.append(to_string(v[i]));
    }
    return s;
}
