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
struct num{
  int val;
  int worth;
  num* ptr=NULL;
};
bool mysort(const num &a, const num &b)
{
    return a.val<b.val;
}
num arr[1000001];
int main(void){
 
    fastio();
    int n;
    cin>>n;
    arr[0].val=0;arr[0].worth=0;arr[1].val=0;arr[1].worth=1;
    for(int i=2;i<=n;i++)
    {
        vector<num> v;
        num temp;
        temp.val=arr[i-1].val+1;
        temp.ptr=&(arr[i-1]);
        v.pb(temp);
        temp.val=arr[i/3].val+ i%3+1;
        temp.ptr=&(arr[i/3]);
        v.pb(temp);
        temp.val=arr[i/2].val+ i%2+1;
        temp.ptr=&(arr[i/2]);
        v.pb(temp);
        sort(v.begin(),v.end(),mysort);
        arr[i]=v[0];arr[i].worth=i;
    }
    cout<<arr[n].val<<"\n";
    num* temp=arr[n].ptr;
    vector<int> v1;
    v1.pb(n);
    while(temp!=NULL)
    {
        v1.pb(temp->worth);temp=temp->ptr;
    }
    for(int i=v1.size()-1;i>=0;i--)
    {
        cout<<v1[i]<<" ";
    }
}
