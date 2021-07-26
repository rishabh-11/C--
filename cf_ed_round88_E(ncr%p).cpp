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
ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
}
ll arr[5*100000+1]={0};
int main(void){
 
    fastio();
    ll n,k;
    cin>>n>>k;
    k--;
    if(k==0){cout<<n;return 0;}
    ll ans=0;
    arr[k]=1;
    for(ll i=k+1;i<=n;i++)
    {
        arr[i]=(((arr[i-1]*i)%MOD2)*modInverse(i-k,MOD2))%MOD2;
    }
    for(ll i=1;i<=n/k;i++)
    {
        ans=(ans+arr[n/i-1])%MOD2;
        //cout<<n/i-1<<" "<<ans<<"\n";
    }
    cout<<ans<<"\n";
}