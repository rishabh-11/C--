#include <bits/stdc++.h>
using namespace std;

int main() {
    std::cout.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,q,l,r,k;
        cin>>n>>q>>k>>l>>r;
        vector <pair<int,int>> v;
        for(int j=0;j<n;j++)
        {
            int c,p;
            cin>>c>>p;
            v.push_back(make_pair(p,c));
        }
        sort(v.begin(),v.end());
        int arr[q+1];
        arr[0]=0;
        for(int j=1;j<=q;j++)
        {
            arr[j]=-1;
        }
        int count=q;
        int lower=-1,upper=-2;
        for(int j=0;j<n;j++)
        {
            if(v[j].second>r)
            {
                if(k>=l && k<=r)
                {
                    lower=v[j].second-r;
                    upper=q;
                }
                else if(k<l)
                {
                    lower=v[j].second-r;
                    upper=v[j].second-l;
                    if(upper>q)
                    {
                        upper=q;
                    }
                }
            }
            else if(v[j].second<l)
            {
                if(k>=l && k<=r)
                {
                    lower=l-v[j].second;
                    upper=q;
                }
                else if(k>r)
                {
                    lower=l-v[j].second;
                    upper=r-v[j].second;
                    if(upper>q)
                    {
                        upper=q;
                    }
                }
            }
            else if(v[j].second>=l && v[j].second<=r)
            {
                if(k>r)
                {
                    lower=1;
                    upper=r-v[j].second;
                    if(upper>q)
                    {
                        upper=q;
                    }
                }
                else if(k<l)
                {
                    lower=1;
                    upper=v[j].second-l;
                    if(upper>q)
                    {
                        upper=q;
                    }
                }
                else
                {
                    lower=1;
                    upper=q;
                }
            }
            for(int index=lower;index<=upper;index++)
            {
                if(arr[index]==-1)
                {
                    arr[index]=v[j].first;
                }
                count--;
            }
            lower=-1,upper=-2;
            if(count==0)
            {
                break;
            }
        }
        for(int index=1;index<=q;index++)
        {
            cout<<arr[index]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
