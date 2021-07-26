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
 
int main(void){
    // Your code here!
    ll n;
    cin>>n;
    vector<pair<ll,ll>> v;
    ll tot=0;
    for(ll i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        tot+=a;
        v.pb(mp(b,a));
    }
    sort(v.begin(),v.end());
    ll ind=0;
    ll en=n-1;
    ll flag=0;
    ll ans=0;
    ll count=0;
    while(tot>0)
    {
        ll temp=v[ind].first;
        while(tot>0 && temp>0)
        {
            if(v[en].second<temp)
            {
                tot-=v[en].second;
                flag=1;
                temp-=v[en].second;
                ans+=v[en].second*2;
                count+=v[en].second;
                en--;
            }
            else
            {
                tot-=temp;
                v[en].second-=temp;
                ans+=temp*2;
                count+=temp;
                if(v[en].second==0)
                {
                    flag=1;
                    en--;
                }
                temp=0;
            }
        }
line:   //cout<<ind<<" "<<en<<" "<<v[en].second<<" "<<count<<" "<<tot<<" "<<v[ind].first<<" "<<ans<<"\n";
        while(tot>0 && count>=v[ind].first)
        {
            count+=v[ind].second;
            ans+=v[ind].second;
            tot-=v[ind].second;
            flag=1;
            ind++;
        }
        //cout<<ind<<" "<<en<<" "<<v[en].second<<" "<<count<<" "<<tot<<" "<<v[ind].first<<" "<<ans<<"\n";
        if(tot>0 && flag==1)
        {
            ll temp1=v[ind].first-count-v[ind].second;
            //cout<<temp1<<"\n";
            if(temp1>0)
            {
                while(tot>0 && temp1>0)
                {
                    if(v[en].second<=temp1)
                    {
                        tot-=v[en].second;
                        count+=v[en].second;
                        ans+=2*v[en].second;
                        temp1-=v[en].second;
                        en--;
                    }
                    else
                    {
                        tot-=temp1;
                        v[en].second-=temp1;
                        count+=temp1;
                        ans+=temp1*2;
                        temp1=0;
                    }
                }
                count+=v[ind].second;
                ans+=v[ind].second;
            }
            else
            {
                ans+=(v[ind].first-count);
                count+=(v[ind].first-count);
                
            }
            goto line;
        }
    }
    cout<<ans<<"\n";
    return 0;
    
}