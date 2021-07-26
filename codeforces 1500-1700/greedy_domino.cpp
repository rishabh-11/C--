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
    return a.first>b.first;
}
int main() 
{
    fastio();
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        if(k>(n*(m/2)))
        {
            cout<<"NO\n";
            continue;
        }
        if(n%2==0 && m%2==0)
        {
            if(k%2==1)
            cout<<"NO\n";
            else
            cout<<"YES\n";
        }
        else if(n%2==1 && m%2==0)
        {
            if(k==0)cout<<"NO\n";
            else
            {
                k-=m/2;
                if(k>=0)
                {
                    if(k%2==0)cout<<"YES\n";
                    else cout<<"NO\n";
                }
                else cout<<"NO\n";
            }
        }
        else
        {
            swap(n,m);
            k=(n*m)/2-k;
            if(k==0)cout<<"NO\n";
            else
            {
                k-=m/2;
                if(k>=0)
                {
                    if(k%2==0)cout<<"YES\n";
                    else cout<<"NO\n";
                }
                else cout<<"NO\n";
            }
        }
        
    }
}