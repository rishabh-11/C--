#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(void){
    // Your code here!
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ind = 2;
    int st = -1;
    int len = 0;
    int i = 0;
    while(i<n-1 && s[i]==s[i+1])
    {
        i++;
        len++;
    }
    i++;
    len++;
    for(;i<n;i++)
    {
        if(s[i]>s[0])
        {
            break;
        }
        if(st!=-1)
        {
            if(s[i]<s[st])
            {
                len = i+1;
                st = -1;
            }
            else if(s[i]>s[st])
            {
                break;
            }
            else
            {
                st++;
                if(st==len)
                st = 0;
            }
            continue;
        }
        if(s[i]==s[0])
        {
            st = 1;
            len = i;
            continue;
        }
        len = i + 1;
    }
    string ans = "";
    // if(k==29140)
    // {
    //     cout<<len<<'-'<<i<<s[i]<<st<<s[st];
    //     //cout<<s<<"\n\n";
    // }
    s = s.substr(0,len);
    while(ans.length()<k)
    {
        ans=ans.append(s);
    }
    
    ans = ans.substr(0,k);
    cout<<ans;
}
