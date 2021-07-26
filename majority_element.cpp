#include <bits/stdc++.h>
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
int max(int a,int b){if(a>b)return a;return b;}
int min(int a,int b){if(a>b)return b;return a;}
bool sortbysec(const pair<string,ll> &a, const pair<string,ll> &b)
{
    return a.second<b.second;
}
int main(void){
 
    fastio();
    int s,p;
    cin>>s>>p;
    map<ll,ll> m;
    set<ll> s;
    for(int i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        m[a]+=1000000;
        m[b]-=1;
        s.insert(a);
        s.insert(b);
    }
    ll temp;
    for(int i=0;i<p;i++)
    {
        cin>>temp;
        auto a=lower_bound(s.begin(),s.end(),temp);
        if(a==s.end())cout<<0;
        else
        {
            ll val;
            if(*a==temp)
                val=m[*a];
            else
            {
                if(a==s.begin())
                {cout<<0;break;}
                val=m[*(a-1)];
            }
            ll count1=val/1000000;
            ll count_1=0;
            if(val%1000000!=0)
            {
                count1++;
            }
            else
            {
                count_1=1000000-val%1000000;
            }
            cout<<count1;
        }
    }
}
