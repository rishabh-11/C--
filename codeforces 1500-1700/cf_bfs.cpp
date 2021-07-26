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

vector<int> adj[401];

int dj(int n)
{
    int visited[n+1];
    int dist[n+1];
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        visited[i]=0;
        dist[i]=INT_MAX;
    }
    dist[1]=0;
    q.push(1);
    int count=0;
    while(!(q.empty()))
    {
        int t=q.front();
        q.pop();
        if(visited[t]==1)continue;
        visited[t]=1;
        for(auto i : adj[t])
        {
            dist[i]=min(dist[i],dist[t]+1);
            q.push(i);
        }
    }
    if(dist[n]!=INT_MAX)return dist[n];
    return -1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int flag=0;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        if((u==1 && v==n) || (u==n && v==1))
        {
            flag=1;
        }
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(flag==1)
    {
        for(int i=1;i<=n;i++)
        {
            int arr[n+1];
            fill(arr,0);
            for(auto j : adj[i])
            {
                arr[j]=1;
            }
            adj[i].clear();
            for(int j=1;j<=n;j++)
            {
                if(j==i)continue;
                if(arr[j]==0)
                {
                    adj[i].pb(j);
                }
            }
        }
    }
    if(n==2)cout<<-1;
    else
    cout<<dj(n);
    return 0;
}