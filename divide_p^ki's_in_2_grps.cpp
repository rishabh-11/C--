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
ll power2(ll x,ll y,ll n){ll res=1;while(y>0){if(y&1)res=(res*x);y=y>>1;x=(x*x);if(res>n)return -1;}return res;}
ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
int max(int a,int b){if(a>b)return a;return b;}
int min(int a,int b){if(a>b)return b;return a;}
bool sortbysec(const pair<string,ll> &a, const pair<string,ll> &b)
{
    return a.second<b.second;
}
bool check(ll diff,ll p,ll* v,ll n)
{
    if(power2(p,diff,n)==-1 || power1(p,diff)*(*v)>n)
    {
        return false;
    }
    else
    {
        *v=(*v)*power1(p,diff)-1;
    }
    return true;
}
int main(void){
 
    fastio();
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,p;
        cin>>n>>p;
        ll arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        ll v=1;
        bool d[n];
        d[n-1]=true;
        ll flag=0;
        ll diff;
        for(int i=n-2;i>=0;i--)
        {
            if(flag==1)
            {
                d[i]=false;
                continue;
            }
            if(v==0)
            {
                d[i]=true;
                v=1;
            }
            else
            {
                diff=arr[i+1]-arr[i];
               // cout<<diff<<" "<<v<<"\n";
                bool var=check(diff,p,&v,n);
                d[i]=false;
                if(var==false)
                {
                    flag=1;
                }
            }
          // cout<<v<<"\n";
        }
        ll ans=0;
        for(int i=n-1;i>=0;i--)
        {
            if(d[i]==true)
            {
                ans=(ans+power(p,arr[i],MOD))%MOD;
            }
            else
            {
                ans=(ans-power(p,arr[i],MOD))%MOD;
                if(ans<0)ans+=MOD;
            }
        }
        cout<<ans<<"\n";
    }
    
}
