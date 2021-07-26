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
vector<ll> adj[100001];
bool visited[100001];
void dfs(ll i, ll count, double prob,double* ans)
{
    //cout<<i<<" "<<adj[i].size()<<"\n";
    if(i!=1 && adj[i].size()==1)
    {
        visited[i]=true;
        (*ans)+=(prob*count);
        //cout<<*ans<<" "<<prob<<" "<<count<<" "<<i<<"\n";
        return; 
    }
    if(visited[i])return;
    visited[i]=true;
    for(auto j : adj[i])
    {
        if(i==1)
        {
            dfs(j,count+1,prob/adj[i].size(),ans);
        }
        else
        dfs(j,count+1,prob/(adj[i].size()-1),ans);
    }
    
}
int main()
{
    fastio();
    ll n;
    cin>>n;
    fill(visited,false);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll count=0;
    cout<<setprecision(10);
    double ans=0;dfs(1,count,1,&ans);
    cout<<ans;
    return 0;
}