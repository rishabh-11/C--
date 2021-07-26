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
int arr[4][4];
void left()
{
    for(int i=0;i<4;i++)
    {
        int index=0;
        for(int j=0;j<4;j++)
        {
            if(arr[i][j]!=0)
            {
                swap(arr[i][j],arr[i][index]);
                index++;
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        if(arr[i][0]!=0 && arr[i][1]!=0 && arr[i][0]==arr[i][1])
        {
            arr[i][0]+=arr[i][1];
            if(arr[i][2]==arr[i][3])
            {
                arr[i][2]+=arr[i][3];
                arr[i][1]=arr[i][2];
                arr[i][2]=0;arr[i][3]=0;
                continue;
            }
            arr[i][1]=arr[i][2];
            arr[i][2]=arr[i][3];
            arr[i][3]=0;
        }
        else if(arr[i][2]!=0 && arr[i][1]!=0 && arr[i][1]==arr[i][2])
        {
            arr[i][1]+=arr[i][2];
            arr[i][2]=arr[i][3];
            arr[i][3]=0;
        }
        else if(arr[i][2]!=0 && arr[i][3]!=0 && arr[i][2]==arr[i][3])
        {
            arr[i][2]+=arr[i][3];
            arr[i][3]=0;
        }
    }
    
}
void right()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<2;j++)
        {
            swap(arr[i][j],arr[i][3-j]);
        }
    }
    left();
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<2;j++)
        {
            swap(arr[i][j],arr[i][3-j]);
        }
    }
}
void up()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
    left();
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
}
void down()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
    right();
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
}
int main()
{
    fastio();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //int t;
    //cin>>t;
    //while(t--)
    //{
        
    //}
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>arr[i][j];
        }
    }
    //while(true)
    //{
        string s;
        cin>>s;
        if(s=="left")
        {
            left();
        }
        else if(s=="right")
        {
            right();
        }
        else if(s=="up")
        {
            up();
        }
        else if(s=="down")
        {
            down();
        }
        else
        {
            cout<<"invalid move\n";
        }
    //}
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}