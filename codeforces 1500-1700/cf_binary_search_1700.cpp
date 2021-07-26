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
bool check(ll arr[],ll m,ll n,ll w,ll val)
{
    ll m1=m;
    ll flag=0;
    ll num=0;
    ll arr1[n];
    fill(arr1,0);
    for(ll i=0;i<n;i++)
    {
        num+=arr1[i];
        if(arr[i]+num<val)
        {
            ll temp=val-arr[i]-num;
            if(temp<=m1)
            {
                m1-=temp;
                arr1[i]=temp;
                if(i+w<n)
                arr1[i+w]=(-temp);
                num+=arr1[i];
            }
            else
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==1)return false;
    return true;
}
int main()
{
    fastio();
    ll n,m,w;
    cin>>n>>m>>w;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll lo=1;
    ll hi=1e11;
    while(hi!=(1+lo))
    {
        ll val=(lo+hi)/2;
        ll flag=check(arr,m,n,w,val);
        if(flag==false)
        {
            hi=val;
        }
        else lo=val;
    }
    if(check(arr,m,n,w,hi))
    {
        cout<<hi;return 0;
    }
    cout<<lo;
    return 0;
}