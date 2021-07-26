#include <bits/stdc++.h>
#include <set>
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
vector<int> v[2000001];
void dfs(int i,vector<pair<int,int>> &ans, bool visited[])
{
    if(visited[i]==false)
    {
        visited[i]=true;
        for(auto j : v[i])
        {
            if(visited[j]==false)
            {
                ans[j].ff = ans[i].ff+1;
            }
            dfs(j,ans,visited);
        }
    }
}
int main(void){
    fastio();
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> ans;for(int i=0;i<=n;i++){ans.pb({1,i});}ans[1].ff=0;ans[0].ff=0;
        bool visited[n+1];for(int i=0;i<=n;i++){visited[i]=false;}
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        dfs(1,ans,visited);
        int o=0,e=0;
        for(int i=1;i<=n;i++)
        {
            if(ans[i].ff%2==0)e++;
            else o++;
        }
        cout<<min(o,e)<<"\n";
        for(int i=1;i<=n;i++)
        {
            if(o<e && ans[i].ff%2!=0)
            {
                cout<<ans[i].ss<<" ";
            }
            else if(e<=o && ans[i].ff%2==0)
            {
                cout<<ans[i].ss<<" ";
            }
        }   
        cout<<"\n";
        for(int i=0;i<=n;i++){v[i].clear();}
    }
    
}