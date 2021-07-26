#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define fill(a,val) memset(a,val,sizeof(a))
#define pb  push_back
#define mp  make_pair
#define ff  first
#define ss  second
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const ll MOD     = 1000*1000*1000+7;
const ll INF     = 1ll*1000*1000*1000*1000*1000*1000 + 7;
const ll MOD2    = 998244353;
const ld PI  = 3.141592653589793;
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);} 
ll power(ll x,ll y,ll p ){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
ll power1(ll x,ll y){ll res=1;while(y>0){if(y&1)res=(res*x);y=y>>1;x=(x*x);}return res;}
ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
ll max(ll a,ll b){if(a>b)return a;return b;}
ll min(ll a,ll b){if(a>b)return b;return a;}
bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    return a.second<b.second;
}


int main()
{
    fastio();
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll st=0;
        ll count=0;
        ll n=s.length();
        ll ans=(n*(n+1))/2;
        ll i=0;
        while(s[i]=='?')
        {
            i++;
        }
        for(;i<n-1;i++)
        {
            if(s[i]=='?')
            {
                ll j=i;
                while(j<n && s[j]=='?')
                {
                    j++;
                    count++;
                }
                if(j<n && ((count%2!=0 && s[i-1]!=s[j]) || (count%2==0 && s[i-1]==s[j])))
                {
                    ans--;
                    ans-=(i-st-1);
                    ans-=(n-1-j);
                    ans-=((i-st-1)*(n-j-1));
                    st=i;
                }
                count=0;
                i=j-1;
                //cout<<ans<<" ";
                continue;
            }
            if(s[i]==s[i+1])
            {
                ll j=i;
                while(s[j]==s[j+1])
                {
                    j++;
                }
                ll temp=j-i+1;
                //cout<<i<<" "<<j<<" "<<st<<" ";
                ans-=(temp*(temp-1)/2);
                ans-=((i-st)*(temp-1));
                ans-=((n-j-1)*(temp-1));
                ans-=((i-st)*(n-j-1));
                st=j;
                i=j;
            }
            //cout<<ans<<" ";
        }
        cout<<ans<<"\n";
    }
    return 0;
}