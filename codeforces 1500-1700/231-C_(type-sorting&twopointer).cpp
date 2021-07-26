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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,k;
    cin>>n>>k;
    int arr[n];int ans[n];ans[0]=0;ans[n-1]=0;
    int len[n];for(int i=0;i<n;i++){len[i]=1;}
    int j=n-2;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=n-1;i>0;i--)
    {
        if(i!=n-1)
        {
            ans[i]=ans[i+1]-((arr[i+1]-arr[i])*(len[i+1]-1));
            len[i]=len[i+1]-1;
        }
        while(j>=0 && ans[i]<=k)
        {
            if(ans[i]+(arr[i]-arr[j])<=k)
            {
                ans[i]+=(arr[i]-arr[j]);
                j--;
                len[i]++;
            }
            else break;
        }
    }
    int index=0;int max=len[0];
    for(int i=1;i<n;i++)
    {
        if(max<len[i]){max=len[i];index=i;}
    }
    cout<<len[index]<<" "<<arr[index];
    return 0;
}