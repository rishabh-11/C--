#include <bits/stdc++.h>
#include <string>
typedef unsigned long long int ll;
#define MOD 998244353
using namespace std;
unsigned long long int power(ll a,ll b)
{
    if(b==0)return 1;
    ll p=power(a,b/2);
    p=(p*p)%MOD;
    return (b%2==0)?p:(a*p)%MOD;
}
unsigned long long int inverse_mod(ll a,ll b)
{
    return power(a,b-2);
}
unsigned long long int* solve(string s,ll a,ll b,ll c,ll d)
{
    ll* arr=new ll[4];
    arr[0]=a;arr[1]=b;arr[2]=c;arr[3]=d;
    if(s.length()==1 || s.length()==5)
    {
        if(s.length()==1)
        {
            arr[0]=1;arr[1]=1;arr[2]=1;arr[3]=1;
            return arr;
        }
        else
        {
            char op=s[2];
            if(op=='&')
            {
                arr[0]=9;arr[1]=1;arr[2]=3;arr[3]=3;
            }
            else if(op=='|')
            {
                arr[0]=1;arr[1]=9;arr[2]=3;arr[3]=3;
            }
            else
            {
                arr[0]=4;arr[1]=4;arr[2]=4;arr[3]=4;
            }
            return arr;
        }
    }
    ll open=0,close=0,i;
    for(i=0;i<s.length();i++)
    {
        if(s[i]=='(')open++;
        else if(s[i]==')')close++;
        else if(s[i]=='&' || s[i]=='|' || s[i]=='^')
        {
            if(open-close==1)break;
        }
    }
    string s1="";s1.append(s.substr(1,i-1));
    string s2="";s2.append(s.substr(i+1,s.length()-i-2));
    unsigned long long int* arr1=solve(s1,0,0,0,0);unsigned long long int* arr2=solve(s2,0,0,0,0);
    char op1=s[i];
    if(op1=='&')
    {
        arr[0]=((arr1[0]*arr2[0])%MOD+(arr1[0]*arr2[1])%MOD+(arr1[0]*arr2[2])%MOD+(arr1[0]*arr2[3])%MOD+(arr1[1]*arr2[0])%MOD+(arr1[2]*arr2[0])%MOD+(arr1[3]*arr2[0])%MOD+(arr1[2]*arr2[3])%MOD+(arr1[3]*arr2[2])%MOD)%MOD;
        arr[1]=((arr1[1]*arr2[1])%MOD)%MOD;
        arr[2]=((arr1[1]*arr2[2])%MOD+(arr1[2]*arr2[1])%MOD+(arr1[2]*arr2[2])%MOD)%MOD;
        arr[3]=((arr1[1]*arr2[3])%MOD+(arr1[3]*arr2[1])%MOD+(arr1[3]*arr2[3])%MOD)%MOD;
    }
    else if(op1=='|')
    {
        arr[1]=((arr1[1]*arr2[1])%MOD+(arr1[1]*arr2[0])%MOD+(arr1[1]*arr2[2])%MOD+(arr1[1]*arr2[3])%MOD+(arr1[0]*arr2[1])%MOD+(arr1[2]*arr2[1])%MOD+(arr1[3]*arr2[1])%MOD+(arr1[2]*arr2[3])%MOD+(arr1[3]*arr2[2])%MOD)%MOD;
        arr[0]=((arr1[0]*arr2[0])%MOD)%MOD;
        arr[2]=((arr1[0]*arr2[2])%MOD+(arr1[2]*arr2[0])%MOD+(arr1[2]*arr2[2])%MOD)%MOD;
        arr[3]=((arr1[3]*arr2[0])%MOD+(arr1[0]*arr2[3])%MOD+(arr1[3]*arr2[3])%MOD)%MOD;
    }
    else
    {
        arr[0]=((arr1[0]*arr2[0])%MOD+(arr1[1]*arr2[1])%MOD+(arr1[2]*arr2[2])%MOD+(arr1[3]*arr2[3])%MOD)%MOD;
        arr[1]=((arr1[0]*arr2[1])%MOD+(arr1[1]*arr2[0])%MOD+(arr1[2]*arr2[3])%MOD+(arr1[3]*arr2[2])%MOD)%MOD;
        arr[2]=((arr1[0]*arr2[2])%MOD+(arr1[2]*arr2[0])%MOD+(arr1[1]*arr2[3])%MOD+(arr1[3]*arr2[1])%MOD)%MOD;
        arr[3]=((arr1[0]*arr2[3])%MOD+(arr1[3]*arr2[0])%MOD+(arr1[1]*arr2[2])%MOD+(arr1[2]*arr2[1])%MOD)%MOD;
    }
    return arr;
}
int main(void)
{
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll a=0,b=0,c=0,d=0;
        unsigned long long int* ans=solve(s,a,b,c,d);
       // cout<<(*ans)<<" "<<(*(ans+1))<<" "<<(*(ans+2))<<" "<<(*(ans+3))<<"\n";
        ll temp=((*ans)+(*(ans+1))+(*(ans+2))+(*(ans+3)))%MOD;
        ll q=inverse_mod(temp,MOD);
        ll res1=((*ans)*q)%MOD;
        ll res2=((*(ans+1))*q)%MOD;
        ll res3=((*(ans+2))*q)%MOD;
        ll res4=((*(ans+3))*q)%MOD;
        cout<<res1<<" "<<res2<<" "<<res3<<" "<<res4<<"\n";
    }
}