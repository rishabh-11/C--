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
    return a.first>b.first;
}
int main() 
{
    fastio();
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int s[n];
        map<int,vector<int>> m;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            if(m[s[i]].size()<k)m[s[i]].pb(i);
        }
        int size=0;
        for(auto i:m)
        {
            size+=i.second.size();
        }
        int count=0;
        int var=1;
        int res[n];
        fill(res,0);
        int flag=0;
        for(auto i:m)
        {
            for(auto j:(i.second))
            {
                res[j]=var;
                var++;
                count++;
                if(var==k+1)var=1;
                if(count==((size/k)*k))
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)break;
        }
        for(int i=0;i<n;i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<"\n";
    }
}