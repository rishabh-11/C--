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
bool sortbysec(const pair<string,ll> &a, const pair<string,ll> &b)
{
    return a.second<b.second;
}
int main(void){
 
    fastio();
    ll t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string s[m];
        for(int i=0;i<m;i++)
        {
            cin>>s[i];
        }
        if(n==1)
        {
            cout<<s<<"\n";
            continue;
        }
        int flag=0;
        vector<pair<string,int>> v1;
        for(int i=0;i<n;i+=2)
        {
            if(i+1!=n)
            {
                vector<int> v;
                for(int j=0;j<m;j++)
                {
                    if(s[i][j]!=s[i+1][j])
                    {
                        v.pb(j);
                    }
                }
                if(v.size()>2)
                {
                    flag=1;
                    break;
                }
                else
                {
                    if(v.size()==1)
                    {
                        string s1=s[i];
                        for(char j='a';j<'z';j++)
                        {
                            s1[0]=j;
                            v1.pb(s1,0);
                        }
                    }
                    else
                    {
                        string s1=s[i];
                        string s2=s[i+1];
                        string temp1=s1;
                        temp1[v[0]]=s2[v[0]];
                        s1[v[1]]=s2[v[1]];
                        v1.pb(s1,0);v1.pb(temp1,0);

                    }
                }
            }
            else
            {
                v1.pb(s[n-1],1);
            }
        }
        if(flag==1)
        {
            cout<<-1<<"\n";
        }
        else
        {
            if(v1.size()==0)cout<<s[0]<<"\n";
            else
            {
                int flag1=0;
                if(v1[v1.size()-1].ss==0)
                {
                    for(int i=0;i<v1.size();i++)
                    {
                        for(int j=i+1;j<v1.size();j++)
                        {
                            if(v1[i].ff==v1[j].ff)
                            {
                                cout<<v1[i].ff<<"\n";
                                flag1=1;
                                break;
                            }
                        }
                        if(flag1==1)break;
                    }
                    if(flag1==0)cout<<"-1"<<"\n";continue;
                }
                else
                {
                    string str=v1[v1.size()-1].ff
                    for(int i=0;i<v1.size()-1;i++)
                    {
                        int count=0;
                        int flag1=0;
                        for(int j=0;j<m;j++)
                        {
                            if((v1[i].ff)[j]!=str[j])count++;
                        }
                        if(count<=1)
                        {
                            cout<<str<<"\n";
                            flag1=1;
                            break;
                        }
                    }
                    if(flag1==0)cout<<"-1"<<"\n";continue;   
                }
            }
        }
    }
}
