#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr1[1000000]={0};
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		arr1[arr[i]]++;
	}
	int start=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=0)
		{
			start=i;
			break;
		}
	}
	int height,base,sum=0;
	for(int i=start;i<n-1;i++)
	{
		height=arr[i];
		int temp_sum=0;base=0;
		int j;
		if(arr1[arr[i]]==0)
			continue;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<height)
			{
				base++;
				temp_sum+=arr[j];
			}
			else
			{
				break;
			}
		}
		i=j;
		sum=sum+(height*base)-temp_sum;
	}
	cout<<sum<<"\n";
	return 0;
}