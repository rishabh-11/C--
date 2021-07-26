#include <bits/stdc++.h>
using namespace std;
bool sortinrev(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
} 
int main(void){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long double x[n],h[n];
        for(int i=0;i<n;i++)
        {
            cin>>x[i]>>h[i];
        }
        sort(h,h+n);
        long double sum=0;
        long double diff[n-1];
        long double temp[n];
        vector<pair<long double,long long int>> temp2;
        for(int i=1;i<n;i++)
        {
            diff[i-1]=x[i]-x[i-1];
        }
        for(int i=0;i<n-2;i++)
        {
            temp2.push_back(make_pair(diff[i]+diff[i+1],i+1));
        }
        temp2.push_back(make_pair(diff[0],-1));
        temp2.push_back(make_pair(diff[n-2],-2));
        sort(temp2.begin(),temp2.end(),sortinrev);
        for(int i=0;i<n;i++)
        {
            if(temp2[i].second==-1)
            {
                temp[0]=h[n-i-1];
            }
            else if(temp2[i].second==-2)
            {
                temp[n-1]=h[n-i-1];
            }
            else
            {
                temp[temp2[i].second]=h[n-i-1];
            }
        }
        for(int i=0;i<n-1;i++)
        {
             sum=sum+(diff[i]*(temp[i]+temp[i+1]))/2;
        }
        long long int ans= (long long int)(sum*2);
        cout<<ans<<"\n";
    }
}
