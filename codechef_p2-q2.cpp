#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
int main(void)
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        ll rem[n];
        ll count1=0;
        vector<pair<ll,ll>> v;
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]%2!=0)
            rem[i]=0;
            else if(arr[i]%4==0)
            {rem[i]=2;v.push_back(make_pair(i,2));}
            else if(arr[i]%2==0)
            {rem[i]=1;count1++;v.push_back(make_pair(i,1));}
        }
        ll ans=((n*(n+1))/2)-count1;
        for(ll i=0;i<v.size();i++)
        {
            if(v[i].second==1)
            {
                ll temp1,temp2;
                if(i==0)
                {
                    temp1=v[i].first;
                }
                else
                {
                    temp1=v[i].first-v[i-1].first-1;
                }
                if(i==v.size()-1)
                {
                    temp2=n-v[i].first-1;
                }
                else
                {
                    temp2=v[i+1].first-v[i].first-1;
                }
                ans=ans-(temp1*(temp2+1)+temp2);
            }
        }
        cout<<ans<<"\n";
    }
}