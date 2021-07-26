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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int flag=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]==0)flag=1;
        }
        if(flag==1)cout<<"YES\n";
        else
        {   
            vector<vector<int>> v;
            int ma=power1(2,n);
            for(int i=1;i<ma;i++)
            {
                vector<int> v1;
                int count=0,temp=i;
                while(temp>0)
                {
                    if(temp%2==1)v1.pb(count);
                    count++;
                    temp/=2;
                }
                v.push_back(v1);
            }
            for(int i=0;i<v.size();i++)
            {
                for(int j=i+1;j<v.size();j++)
                {
                    int flag1=1;
                    int sum1=0,sum2=0;
                    for(int k=0;k<v[i].size();k++)
                    {
                        auto itr=lower_bound(v[j].begin(),v[j].end(),v[i][k]);
                        if(itr!=v[j].end() && (*itr)==v[i][k])
                        {
                            flag1=0;break;
                        }
                        sum1+=arr[v[i][k]];
                    }
                    if(flag1==1)
                    {
                        for(int k=0;k<v[j].size();k++)
                        {
                            sum2+=arr[v[j][k]];
                        }
                        if(sum1==sum2 || sum1+sum2==0)
                        {
                            flag=1;break;
                        }
                    }
                }
                if(flag==1)break;
            }
            if(flag==1)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}