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
bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    return a.second<b.second;
}
int main()
{
    fastio();
    int n;
    cin>>n;
    unordered_map<string,int> m;
    unordered_map<string,pair<int,int>> m1;
    pair<string,int> p[n];
    for(int i=0;i<n;i++)
    {
        string s;
        int sc;
        cin>>s>>sc;
        p[i].ff=s;p[i].ss=sc;
        m[s]+=sc;
    }
    int r=1;
    for(int i=0;i<n;i++)
    {
        m1[p[i].ff].ss+=p[i].ss;
        if(m1[p[i].ff].ff==0 && m1[p[i].ff].ss>=m[p[i].ff]){m1[p[i].ff].ff=r;}
        r++;
    }
    //for(auto i : m1){cout<<i.ff<<" "<<i.ss.ff<<" "<<i.ss.ss<<"\n";}
    int max=INT_MIN;int ro=INT_MAX; string name;
    for(auto i : m)
    {
        if((i.ss)>max){max=(i.ss);ro=m1[i.ff].ff;name=i.ff;}
        if((i.ss)==max && m1[i.ff].ff<ro){ro=m1[i.ff].ff;name=i.ff;}
    }
    cout<<name;
    return 0;    
}

