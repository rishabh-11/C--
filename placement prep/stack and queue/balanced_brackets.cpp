#include <bits/stdc++.h>
int Solution::solve(string A) {
    stack<int> s;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='(')
        {
            s.push(i);
        }
        else
        {
            if(s.empty())return 0;
            s.pop();
        }
    }
    if(s.empty())return 1;
    return 0;
}
