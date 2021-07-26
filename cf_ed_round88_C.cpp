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
int main(void){
 
    fastio();
    int t1;
    cin>>t1;
    while(t1--)
    {
        ll h,c,t;
        cin>>h>>c>>t;
        ll a=h-t;
        ll b=t-c;
        ld d=abs(ld((a-b))/2);
        if(a-b>=0){cout<<2<<"\n";}
        else
        {
            ll temp=b-a;
            if(temp<=a){
                ll temp1=a/temp;
                ll temp2=a-temp1*temp;
                ll temp3=(temp1+1)*temp-a;
                ld ans1=ld(temp2)/(2*temp1+1);
                ld ans2=ld(temp3)/(2*temp1+3);
                //cout<<temp2<<" "<<temp3<<" "<<temp1<<" "<<ans1<<" "<<ans2<<"\n";
                if(ans1<=ans2)
                {
                    if(ans1<d)
                        cout<<2*temp1+1<<"\n";
                    else
                        cout<<2<<"\n";
                }
                else
                {
                    if(ans2<d)
                        cout<<2*temp1+2+1<<"\n";
                    else
                        cout<<2<<"\n";
                }
            }
            else
            {
                ld ans1=a;
                ld ans2=ld((b-2*a))/3;
                if(ans1<=ans2){
                    if(ans1<=d){
                        cout<<1<<"\n";
                    }
                    else
                    {
                        cout<<2<<"\n";
                    }
                }
                else
                {
                    if(ans2<d)cout<<3<<"\n";
                    else cout<<2<<"\n";
                }

            }
        }
    }
 
}