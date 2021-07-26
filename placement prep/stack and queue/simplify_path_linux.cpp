string Solution::simplifyPath(string A) {
    stack<string> s;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='/')
        {
            string temp="";
            i++;
            while(i<A.length() && A[i]!='/')
            {
                temp.append(1,A[i]);
                i++;
            }
            i--;
            if(temp=="..")
            {
                if(!s.empty())
                s.pop();
            }
            else if(temp!="." && temp!="")
            {
                s.push(temp);
            }
        }
    }
    string ans="/";
    vector<string> v;
    while(!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        ans.append(v[i]);
        if(i-1>=0)
        ans.append("/");
    }
    return ans;
}
