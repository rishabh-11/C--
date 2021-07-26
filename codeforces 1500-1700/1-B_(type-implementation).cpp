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
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        int count=0;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]>='0' && s[i]<='9' && s[i-1]>='A' && s[i-1]<='Z')count++;
        }
        if(count==1)
        {
            int index=0;
            for(int i=1;i<s.length();i++)
            {
                if(s[i]>='0' && s[i]<='9' && s[i-1]>='A' && s[i-1]<='Z'){index=i;break;}
            }
            int col=0;int t=26;
            for(int i=0;i<index-1;i++)
            {
                col+=t;
                t*=26;
            }
            t=pow(26,index-1);
            for(int i=0;i<index;i++)
            {
                col+=((int)s[i]-65)*t;
                t=t/26;
            }
            col++;
            cout<<'R';
            for(int i=index;i<s.length();i++){cout<<s[i];}
            cout<<'C'<<col<<"\n";
        }
        else
        {
            int index=0;
            for(int i=1;i<s.length();i++)
            {
                if(s[i]=='C'){index=i;break;}
            }
            string s1=s.substr(index+1,s.length()-index-1);
            int t=stoi(s1);
            int t1=26;int len=1;
            while(true)
            {
                if(t-t1>0)len++;
                else break;
                t-=t1;t1*=26;
            }
            for(int i=0;i<len;i++)
            {
                int t2=pow(26,len-i-1);
                for(int j=1;j<=26;j++)
                {
                    if(t-(j*t2)<=0)
                    {
                        cout<<(char)(j+64);
                        t-=(j-1)*t2;break;
                    }
                }
            }
            for(int i=1;;i++)
            {
                if(s[i]>='0' && s[i]<='9')cout<<s[i];
                else break;
            }
            cout<<"\n";
        }
    }
    return 0;    
}

