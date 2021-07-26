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
int n,m,k;
vector<int> v[200001];
int arr[200000+1];
bool visited[200000+1];
void dfs(int i,map<int,int> &m)
{
    if(visited[i])return;
    visited[i]=true;
    m[arr[i]]++;
    //cout<<m[1]<<" "<<m[2]<<" "<<m[3]<<"\n";
    for(auto s : v[i])
    {
        dfs(s,m);
    }
}
int main(void){
    fastio();
    for(int i=1;i<=200000;i++){visited[i]=false;}
    cin>>n>>m>>k;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    /*for(int i=1;i<=n;i++)
    {
        for(auto s : v[i])
        {
            cout<<s<<" ";
        }
        cout<<"\n";
    }*/
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            map<int,int>m;
            dfs(i,m);
            int max=0;int total=0;
            //cout<<1256<<" ";
           /* for(auto s : m)
            {
                cout<<s.ss<<" ";
            }*/
            for(auto val : m)
            {
                total+=val.ss;
                if(val.ss>max)
                    max=val.ss;
            }
            ans+=(total-max);
        }
    }
    cout<<ans;
}
