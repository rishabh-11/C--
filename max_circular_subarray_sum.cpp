#include <bits/stdc++.h>
using namespace std;
/*for this program to be true there must be atleast 1 positive element in the array otherwise it will give 0 as answer*/
int kadane(int arr[],int n)
{
	int max_sum=0;
	int max_sum_upto_here=0;
	for(int i=0;i<n;i++)
	{
		max_sum_upto_here+=arr[i];
		if(max_sum_upto_here<0)
			max_sum_upto_here=0;
		if(max_sum<max_sum_upto_here)
			max_sum=max_sum_upto_here;
	}
	return max_sum;
}
int circular_subarray_sum(int arr[],int n)
{
	int ans1=kadane(arr,n);
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
		arr[i]=-arr[i];
	}
	int temp=-(kadane(arr,n));
	int ans2=sum-temp;
	if(ans1>ans2)
		return ans1;
	return ans2;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int res=circular_subarray_sum(arr,n);
	cout<<res<<"\n";
	return 0;
}