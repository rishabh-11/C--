#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const ll MOD     = 1000*1000*1000+7;
const ll INF     = 1ll*1000*1000*1000*1000*1000*1000 + 7;
const ll MOD2    = 998244353;
const ld PI  = 3.141592653589793;
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);} 
ll power(ll x,ll y,ll p ){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
int main(void){
    fastio();
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        ll sum[n/2];
        for(int i=0;i<n/2;i++)
        {
            sum[i]=arr[i]+arr[n-i-1];
        }
        ll p[n/2];ll q[n/2];
        for(int i=0;i<n/2;i++)
        {
            p[i]=max(arr[i],arr[n-i-1])+k;
            q[i]=min(arr[i],arr[n-i-1])+1;
        }
        /*for(int i=0;i<n/2;i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<"\n";
        for(int i=0;i<n/2;i++)
        {
            cout<<q[i]<<" ";
        }
        cout<<"\n";*/
        sort(p,p+n/2);
        sort(q,q+n/2);
        sort(sum,sum+n/2);
        /*for(int i=0;i<n/2;i++)
        {
            cout<<sum[i]<<" ";
        }
        cout<<"\n";*/
        ll count=1;ll temp=sum[0];
        vector<pair<ll,ll>> v;
        for(int i=1;i<n/2;i++)
        {
            if(sum[i]==sum[i-1])count++;
            else
            {
                v.push_back(make_pair(temp,count));
                count=1;temp=sum[i];
            }
        }
        v.push_back(make_pair(temp,count));
       /*for(int i=0;i<v.size();i++)
        {
            cout<<v[i].first<<" "<<v[i].second<<"\n";
        }*/
        ll ans=INT_MAX;
        for(int i=0;i<v.size();i++)
        {
            ll a=n/2-v[i].second;
            ll c=lower_bound(p,p+n/2,v[i].first)-p;
            ll d=upper_bound(q,q+n/2,v[i].first)-q;
            d=n/2-d;
            //cout<<a<<" "<<c<<" "<<d<<"\n";
            if(a+c+d<ans)ans=a+c+d;
        }
        if(ans>n/2)ans=n/2;
        cout<<ans<<"\n";
    }
    
}
