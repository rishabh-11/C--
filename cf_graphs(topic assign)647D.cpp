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
int main(void){
 
    fastio();
    int n,m;
    cin>>n>>m;
    vector<int> v[n+1];//stores the graph
    vector<int> t[n+1];// stores the vertices in order of topic
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    int arr[n+1];// stores topic in order of vertices
    for(int i=1;i<=n;i++)
    {
        int c;
        cin>>c;
        t[c].pb(i);
        arr[i]=c;
    }
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        for(auto j : t[i])
        {
            // current vertex should be attached to other vertices such that all topics from 1 to i-1 are already covered and i is not covered
            int temp[i+1];
            for(int k=1;k<=i;k++){temp[k]=0;}
            for(auto k : v[j])
            {
                if(arr[k]>i)continue;
                else temp[arr[k]]++;    
            }
            for(int k=1;k<i;k++){if(temp[k]==0){cout<<-1;return 0;}}
            if(temp[i]!=0){cout<<-1;return 0;}
            ans.pb(j);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}