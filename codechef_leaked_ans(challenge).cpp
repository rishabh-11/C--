#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int arr[n][k];
        vector<int> v[n];
        int ans1[n];
        int ans2[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                int a;
                cin>>a;
                arr[i][j]=a;
                v[i].push_back(a);
            }
        }
        for(int i=0;i<n;i++)
        {
            sort(v[i].begin(),v[i].end());
        }
        int arr1[n][m+1];
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                arr1[i][j]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            int count=1;
            for(int j=1;j<k;j++)
            {
                if(v[i][j]==v[i][j-1])
                {
                    count++;
                }
                else
                {
                    arr1[i][v[i][j-1]]=count;
                    count=1;
                }
            }
            arr1[i][v[i][k-1]]=count;
        }
        int temp[k];
        int q=0;
        int min=INT_MAX;
        int mina;
        memset(temp,0,sizeof(temp));
        for(int i=0;i<n;i++)
        {
            int flag=0;
            min=INT_MAX;
            for(int j=1;j<k;j++)
            {
                if(arr[i][j]!=arr[i][j-1])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)ans1[i]=arr[i][0];
            else
            {
                for(int j=0;j<k;j++)
                {
                    if(min>temp[j])
                    {
                        min=temp[j];
                        q=j;
                    }
                    else if(min==temp[j])
                    {
                        if(arr1[i][arr[i][q]]<arr1[i][arr[i][j]])
                        {
                            q=j;
                        }
                    }
                }
                ans1[i]=arr[i][q];
                for(int j=0;j<k;j++)
                {
                    if(arr[i][j]==arr[i][q])
                    {
                        temp[j]++;
                    }
                }
            }
            mina=min;
        }
        int temp1[k];
        int q1=0;
        int min1=INT_MAX;
        memset(temp1,0,sizeof(temp1));
        for(int i=0;i<n;i++)
        {
            int flag=0;
            min1=INT_MAX;
            for(int j=1;j<k;j++)
            {
                if(arr[i][j]!=arr[i][j-1])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)ans2[i]=arr[i][0];
            else
            {
                ans2[i]=arr[i][q1];
                for(int j=0;j<k;j++)
                {
                    if(arr[i][j]==arr[i][q1])
                    {
                        temp1[j]++;
                    }
                }
                for(int j=0;j<k;j++)
                {
                    if(min1>temp1[j])
                    {
                        min1=temp1[j];
                        q1=j;
                    }
                }
            }
        }
        if(min1>mina)
        {
            for(int i=0;i<n;i++)
            {
                cout<<ans2[i]<<" ";
            }
            cout<<"\n";    
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                cout<<ans1[i]<<" ";
            }
            cout<<"\n";
        }
        
    }
}