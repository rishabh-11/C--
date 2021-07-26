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


int main()
{
    fastio();
    int n,k;
    cin>>n>>k;
    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    queue<int> q;
    int count=0;
    int st=1;
    int en=k;
    pair<int,int> p={1,k};
    map<int,int> m;
    int i=1;
    for(;i<=k;i++)
    {
        m[arr[i]]++;
        q.push(arr[i]);
        if(m[arr[i]]==1)count++;
    }
    //cout<<en<<" "<<st<<"\n";
    for(i=k+1;i<=n;i++)
    {
        if(m[arr[i]]>0)
        {
            m[arr[i]]++;
            q.push(arr[i]);
            en++;
        }
        else
        {
            count++;
            if(count>k)
            {
                if((en-st)>(p.second-p.first))
                {
                    p.second=en;
                    p.first=st;
                }
                while(!q.empty() && count>k)
                {
                    m[q.front()]--;
                    st++;
                    if(m[q.front()]==0)
                    {
                        count--;
                    }
                    q.pop();
                }
            }
            m[arr[i]]++;
            q.push(arr[i]);
            en++;

        }
        //cout<<st<<" "<<en<<"\n";
    }
    if((en-st)>(p.second-p.first))
    {
        p.second=en;
        p.first=st;
    }
    cout<<p.first<<" "<<p.second;
    return 0;
}