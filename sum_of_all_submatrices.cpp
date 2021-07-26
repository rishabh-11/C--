#include <bits/stdc++.h>
using namespace std;
int sum_of_all_submatrices(int **arr,int m,int n)
{
    int res=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			res=res+(arr[i][j]*(i+1)*(j+1)*(m-i)*(n-j));
		}
	}
	return res;
}
int main()
{
	int m,n;
	cin>>m>>n;
	int **arr = new int*[m];
	for(int i=0;i<m;i++)
	{
		arr[i]=new int[n];
	}
	for(int i=0;i<m;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        cin>>arr[i][j];
	    }
	}
	int sum=sum_of_all_submatrices(arr,m,n);
	for(int i=0;i<m;i++)
	{
		delete [] arr[i];
	}
	delete [] arr;
	cout<<sum;
	return 0;
}