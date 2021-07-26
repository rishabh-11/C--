#include <bits/stdc++.h>
#include <set>
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
int div1[2750132]={0};
void sieve()
{
    int count=-1;
    for(ll i=2;i<2750132;i++)
    {
        if(div1[i]==0)
        {
            div1[i]=count;
            count--;
            for(ll j=i*i;j<2750132;j+=i)
            {
                if(div1[j]==0)
                {
                    div1[j]=i;
                }
            }
        }
    }
}
int main(void){
    fastio();
    sieve();
    int n;
    cin>>n;
    multiset<int,greater<int>> s;
    for(int i=0;i<2*n;i++)
    {
        int temp;
        cin>>temp;
        s.insert(temp);
    }
    multiset<int,greater<int>> :: iterator itr;
    multiset<int,greater<int>> :: iterator itr1;
    multiset<int,greater<int>> :: iterator temp;
    for(itr=s.begin();itr!=s.end();)
    {
        //cerr<<*itr<<" ";
        if(div1[*itr]>0)
        {
            cout<<*itr<<" ";
            temp=s.find((*itr)/div1[*itr]);
            itr1=itr;
            itr++;
            if(itr==temp)itr++;
            s.erase(itr1);
            s.erase(temp);
        }
        else
        {
            cout<<abs(div1[*itr])<<" ";
            itr1=itr;
            temp=s.find(abs(div1[*itr]));
            itr++;
            if(itr==temp)itr++;
            s.erase(temp);
            s.erase(itr1);
        }
    }
}