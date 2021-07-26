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
    int n,w,h,t=1;
    cin>>n>>w>>h;
    vector<pair<pair<int,int>,int>> v;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.pb(mp(mp(a,b),t));
        t++;
    }
    sort(v.begin(),v.end());
    int ans[n];for(int i=0;i<n;i++){ans[i]=i;}
    int flag[n];for(int i=0;i<n;i++){flag[i]=1;}
    int len[n];for(int i=0;i<n;i++){len[i]=1;}
    for(int i=0;i<n;i++){if(v[i].ff.ff<=w || v[i].ff.ss<=h){flag[i]=0;len[i]=0;ans[i]=-1;}}
    for(int i=1;i<n;i++)
    {
        if(v[i].ff.ff<=w || v[i].ff.ss<=h)continue;
        for(int j=0;j<i;j++)
        {
            if((v[j].ff.ff>w && v[j].ff.ss>h) && (v[j].ff.ff<v[i].ff.ff && v[j].ff.ss<v[i].ff.ss))
            {
                if(len[i]<=len[j]+1)
                {
                    ans[i]=j;
                    flag[i]=1;
                    len[i]=len[j]+1;
                }
            }
        }
    }
    vector<int> fin;
    int max=-1;int index=-1;
    for(int i=0;i<n;i++){if(max<len[i]){max=len[i];index=i;}}
    cout<<max<<"\n";
    //for(int i=0;i<n;i++){cout<<len[i]<<" ";}cout<<"\n";
    //for(int i=0;i<n;i++){cout<<ans[i]<<" "<<v[i].ss<<" "<<flag[i]<<"\n";}
    int i=index;
    while(true)
    {
        if(ans[i]==-1){break;}
        if(ans[i]==i){fin.pb(v[i].ss);break;}
        if(flag[i]==1){fin.pb(v[i].ss);}
        i=ans[i];
    }
    //cout<<fin.size()<<"\n";
    for(int i=fin.size()-1;i>=0;i--)
    {
        cout<<fin[i]<<" ";
    }
    return 0;    
}