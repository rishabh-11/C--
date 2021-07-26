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
int main()
{
    fastio();
    //int t;
    //cin>>t;
    //while(t--)
    //{
        int n;
        cin>>n;
        int x[n];
        for(int i=0;i<n;i++)
        {
            cin>>x[i];
        }
        sort(x,x+n);
        int min=1;int max=1;
        if(x[n-1]-x[0]<=1)
        {
            cout<<n<<"\n";
            for(int i=0;i<n;i++){cout<<x[i]<<" ";}
            return 0;
        }
        for(int i=1;i<n;i++)
        {
            if(x[i]==x[i-1])min++;
            else break;
        }
        for(int i=n-1;i>0;i--)
        {
            if(x[i]==x[i-1])max++;
            else break;
        }
        //cout<<min<<" "<<max<<"\n";
        int t;
        if(min<max)t=min;
        else t=max;
        int temp=n-min-max;
        if(temp%2!=0)temp--;
        if(temp<t*2)
        {
            cout<<n-t*2<<"\n";
            for(int i=0;i<t;i++)
            {
                cout<<x[0]+1<<" "<<x[0]+1<<" ";
            }
            for(int i=0;i<n-min-max;i++)
            {
                cout<<x[0]+1<<" ";
            }
            if(t==min)
            {
                for(int i=min+1;i<=max;i++)
                {
                    cout<<x[0]+2<<" ";
                }
            }
            else
            {
                for(int i=max+1;i<=min;i++)
                {
                    cout<<x[0]<<" ";
                }
            }    
        }
        else
        {
            cout<<n-temp<<"\n";
            for(int i=0;i<temp/2;i++)
            {
                cout<<x[0]<<" "<<x[0]+2<<" ";
            }
            for(int i=0;i<min;i++)
            {
                cout<<x[0]<<" ";
            }
            for(int i=0;i<max;i++)
            {
                cout<<x[0]+2<<" ";
            }
            if(temp+min+max!=n)cout<<x[0]+1<<" ";
        }
    //}
    return 0;    
}

