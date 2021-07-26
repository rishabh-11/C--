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
        ll arr[n];
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        string ans[n];
        int val=arr[0];
        ans[0]=to_string(arr[0]);
        for(int i=1;i<n;i++)
        {
            if(arr[i]-1==val)
            {
                ans[i]="";
                string temp;
                for(int j=ans[i-1].length()-1;j>=0;j--)
                {
                    if(ans[i-1][j]=='.')
                    {
                        temp=ans[i-1].substr(0,j+1);
                        temp.append(to_string(val+1));
                        val++;
                        ans[i]=temp;
                        break;
                    }
                }
                if(ans[i]=="")
                {
                    ans[i].append(to_string(arr[i]));
                }
                //cerr<<ans[i]<<" "<<val<<"\n";
            }
            else
            {
                if(arr[i]==1)
                {
                    string temp=ans[i-1];
                    ans[i]=temp.append(".1");
                    val=arr[i];
                    //cerr<<ans[i]<<"\n";
                    continue;
                }
                int count=0;
                for(int j=0;j<ans[i-1].length();j++)
                {
                    if(ans[i-1][j]=='.')
                    {
                        count++;
                    }
                }
                for(int j=i-2;j>=0;j--)
                {
                    int count1=0;
                    int index=-1;
                    for(int k=0;k<ans[j].length();k++)
                    {
                        if(ans[j][k]=='.')
                        {
                            count1++;
                            index=k;
                        }
                    }
                    if((count-1)==count1)
                    {
                        if(index==-1)
                        {
                            ans[i]=to_string(arr[i]);
                        }
                        else
                        {
                            string temp6=ans[j].substr(index+1,ans[j].length()-index-1);
                            if(temp6==to_string(arr[i]-1))
                            {
                                string temp5=ans[j].substr(0,index+1);
                                ans[i]=temp5.append(to_string(arr[i])); 
                                break;
                            }
                            else
                            {
                                count--;
                            }
                        }
                    }
                }
            }
            val=arr[i];
            //cerr<<ans[i]<<"\n";
        }
        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<"\n";
        }
    }
    return 0;
}