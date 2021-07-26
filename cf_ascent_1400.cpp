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


int main()
{
    fastio();
    ll n;
    cin>>n;
    vector<ll> ma,mi;
    ll ans=0;
    ll count=0;
    for(ll i=0;i<n;i++)
    {
        ll s;
        cin>>s;
        ll ma1=INT_MIN;
        ll mi1=INT_MAX;
        ll flag=0;
        ll arr[s];
        for(ll j=0;j<s;j++)
        {
            cin>>arr[j];
            if(ma1<arr[j])ma1=arr[j];
            if(mi1>arr[j])mi1=arr[j];
        }
        for(ll j=0;j<s-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                flag=1;break;
            }
        }
        if(flag==1)
        {
            count++;
        }
        else
        {
            ma.pb(ma1);
            mi.pb(mi1);
        }
    }
    ans+=(2*count*n-((count)*(count-1))-count);
    sort(ma.begin(),ma.end());
    // for(ll i=0;i<ma.size();i++)
    // {
    //     cout<<ma[i]<<" ";
    // }
    // cout<<"\n";
    // for(ll i=0;i<mi.size();i++)
    // {
    //     cout<<mi[i]<<" ";
    // }
    // cout<<"\n";
    // cout<<ans<<"\n";
    for(ll i=0;i<mi.size();i++)
    {
        ll temp=upper_bound(ma.begin(),ma.end(),mi[i])-ma.begin();
        // cout<<ma.size()-temp<<" ";
        ans+=(ma.size()-temp);
    }
    cout<<ans;
    return 0;
}