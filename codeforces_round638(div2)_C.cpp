#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const ll MOD     = 1000*1000*1000+7;
const ll INF     = 1ll*1000*1000*1000*1000*1000*1000 + 7;
const ll MOD2    = 998244353;
const ld PI  = 3.141592653589793;
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);} 
ll power(ll x,ll y,ll p ){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
void solve(string &s,int k) 
{ 
   sort(s.begin(), s.end()); 
   int arr[26]={0};
   int count=0;
   for(int i=0;i<s.length();i++)
   {
       arr[(int)s[i]-97]++;
   }
   for(int i=0;i<26;i++)
   {
       if(arr[i]!=0)
       count++;
   }
   int i;
   vector<char> ans;
   for(i=0;i<26;i++)
   {
       if(arr[i]!=0 && arr[i]<k)
       {
           cout<<s[k-1]<<"\n";
           return;
       }
       else if(arr[i]>k)
       {
           if(count==1)
           {
               int temp=arr[i]/k;
               for(int j=0;j<temp;j++)
               {
                   ans.push_back(char(i+97));
               }
               temp=arr[i]%k;
               if(temp!=0)
               ans.push_back(char(i+97));
           }
           else
           {
               ans.push_back(char(i+97));
               for(int j=0;j<arr[i]-k;j++)
               {
                   ans.push_back(char(i+97));
               }
           }
           break;
       }
       else if(arr[i]==k)
       {
           ans.push_back(char(i+97));
           break;
       }
   }
   i++;count--;
   for(;i<26;i++)
   {
       if(arr[i]==0){continue;}
       count--;
       if(count==0 && ans.size()==1)
       {
           int temp=arr[i]/k;
           for(int j=0;j<temp;j++)
           {
               ans.push_back(char(i+97));
           }
           temp=arr[i]%k;
           if(temp!=0)
           ans.push_back(char(i+97));
       }
       else
       {
           for(int j=0;j<arr[i];j++)
           {
               ans.push_back(char(i+97));
           }
       }
   }
   for(i=0;i<ans.size();i++)
   {
       cout<<ans[i];
   }
   cout<<"\n";
}
int main(void){
    fastio();
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        solve(s,k);
    }
}
