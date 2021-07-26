#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main(void)
{
	fastio;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		{
		    cin>>arr[i];
		}
		int index=-1;
		for(int i=1;i<n-1;i++)
		{
		    if(arr[i]==arr[i-1] && arr[i]!=arr[i+1])
		    {
		        index=i;
		    }
		}
		int a[n];
		a[0]=1;
		int flag2=0,flag3=0;
		for(int i=1;i<n;i++)
		{
		    if(arr[i]==arr[i-1])
		    {
		        a[i]=a[i-1];
		    }
		    else
		    {
		        if(a[i-1]==1)
		        {
		            a[i]=2;
		            flag2=1;
		        }
		        else
		        {
		            a[i]=1;
		        }
		    }
		}
		if(arr[n-1]!=arr[0] && a[n-1]==1)
		{
		    if(a[n-2]==1)
		    {
		        a[n-1]=2;
		        flag2=1;
		    }
		    else if(index==-1)
		    {
		        a[n-1]=3;
		        flag3=1;
		    }
		    else
		    {
		        for(int i=index;i<n;i++)
		        {
		            if(a[i]==1){a[i]=2;flag2=1;}
		            else
		            a[i]=1;
		        }
		    }
		}
		if(flag3==1)
		{
		    cout<<3<<"\n";
		}
		else if(flag2==1)
		{
		    cout<<2<<"\n";
		}
		else
		{
		    cout<<1<<"\n";
		}
		for(int i=0;i<n;i++)
		{
		    cout<<a[i]<<" ";
		}
		cout<<"\n";
	}
} 