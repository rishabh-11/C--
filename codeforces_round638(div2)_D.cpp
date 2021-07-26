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
ll power1(ll x,ll y){ll res=1;while(y>0){if(y&1)res=(res*x);y=y>>1;x=(x*x);}return res;} 
ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
int main(void){
    fastio();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a=n;
        int count=0;
        while(a>0)
        {
            count++;
            a/=2;
        }
        int b=power1(2,count-1)-1;
        cout<<count-1<<"\n";
        int diff=n-b;
        //cout<<b<<" "<<diff<<"\n";
        if(diff>=power1(2,count-2))
        {
            for(int i=0;i<count-2;i++)
            {
                cout<<power1(2,i)<<" ";
            }
            cout<<diff-power1(2,count-2)<<"\n";
        }
        else
        {
            for(int i=0;i<count-3;i++)
            {
                cout<<power1(2,i)<<" ";
            }
            int temp=n-(power1(2,count-2)-1);
            //cout<<temp<<"\n";
            int c=temp/2;
            int d=temp-c;
            cout<<c-power1(2,count-3)<<" "<<d-c<<"\n";
        }
    }
    
}