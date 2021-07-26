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
    int n,m;
    cin>>n>>m;
    string a[n];int b[n][m],flag=0;
    for(int i=0;i<n;i++){cin>>a[i];}
    for(int i=0;i<n;i++)
    {
        int k=-1;
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='1')
            {
                if(k==-1)
                {
                    for(int l=0;l<=j;l++)
                    {
                        b[i][l]=j-l;
                    }
                    k=j;
                }
                else
                {
                    for(int l=k+1;l<=(j+k)/2;l++)
                    {
                        b[i][l]=l-k;
                    }
                    for(int l=(j+k)/2+1;l<=j;l++)
                    {
                        b[i][l]=j-l;
                    }
                    k=j;
                }
            }
        }
        if(k==-1)flag=1;
        else
        {
            for(int l=k+1;l<m;l++)
            {
                b[i][l]=l-k;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='0')
            {
                if(b[i][m-1]+j+1<b[i][j])
                {
                    b[i][j]=b[i][m-1]+j+1;
                }
            }
            else break;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(a[i][j]=='0')
            {
                if(b[i][0]+(m-j)<b[i][j])
                {
                    b[i][j]=b[i][0]+(m-j);
                }
            }
            else break;
        }
    }
    if(flag==1){cout<<-1;return 0;}
    int ans=INT_MAX;
    for(int i=0;i<m;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if(b[j][i]>m/2)b[j][i]=m-b[j][i];
            sum+=b[j][i];
        }
        if(sum<ans)ans=sum;
    }
    cout<<ans;
    return 0;    
}