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
    int n;
    cin>>n;
    stack<int> spl,nov;
    int cur_sp,sp_lim=500;
    int ans=0;
    while(n--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int s;
            cin>>s;
            if(s>sp_lim)
            {
                while(!spl.empty() && spl.top()<s)
                {
                    spl.pop();
                    ans++;
                }
                if(!spl.empty())
                {
                    sp_lim=spl.top();
                }
                else sp_lim=500;
            }
            cur_sp=s;
        }
        else if(t==2)
        {
            while(!nov.empty())
            {
                nov.pop();
                ans++;
            }
        }
        else if(t==3)
        {
            int s;
            cin>>s;
            if(s>=cur_sp)
            {
                spl.push(s);
                sp_lim=s;
            }
            else ans++;
        }
        else if(t==4)
        {
            while(!(nov.empty()))
            {
                nov.pop();
            }
        }
        else if(t==5)
        {
            while(!spl.empty())
            {
                spl.pop();
            }
            sp_lim=500;
        }
        else
        {
            nov.push(1);
        }
    }
    cout<<ans<<"\n";
    return 0;
}