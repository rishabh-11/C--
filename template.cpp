#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,
//tree_order_statistics_node_update> indexed_set;
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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans=0;
    for(ll i=b;i>=a;i--)
    {
        if(c-(d-i)>0)
        {
            if(d-i<b){ans=ans+(c-b+1)*(d-c+1);continue;}
            ans=ans+(c-(d-i))*(d-c+1);
            ll temp=d-c;
            ll num=d-i-b+1;
            if(num>=temp)
            ans=ans+(temp*(temp+1))/2;
            else
            {
                ll temp1=temp-num;
                ans=ans+(temp*(temp+1))/2-(temp1*(temp1+1))/2;
            }
            //cout<<ans<<" ";
        }
        else
        {
            ll temp=i;
            ll num=c-b+1;
            if(num>=temp)
            ans=ans+(temp*(temp+1))/2;
            else
            {
                ll temp1=temp-num;
                ans=ans+(temp*(temp+1))/2-(temp1*(temp1+1))/2;
            }
            //cout<<ans<<" ";
        
        }        
    }
    cout<<ans<<"\n";
    
}