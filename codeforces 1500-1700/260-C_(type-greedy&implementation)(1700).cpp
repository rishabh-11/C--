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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,x;
    cin>>n>>x;
    ll arr[n+1];int m=INT_MAX;int index=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(m>arr[i]){m=arr[i];index=i;}
        else if(m==arr[i])
        {
            if(x>=index && x<i)continue;
            m=arr[i];index=i;
        }
    }
    ll a=m*n;
    for(int i=1;i<=n;i++)
    {
        arr[i]-=m;
    }
    for(int i=index+1;i!=x+1;i++)
    {
        if(i==n+1)i=1;
        arr[i]--;
        a++;
    }
    arr[index]=a;
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}