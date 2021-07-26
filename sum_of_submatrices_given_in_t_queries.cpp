#include <bits/stdc++.h>
using namespace std;
void prefix_sum_array(int **arr,int m,int n)
{
	for(int i=0,j=1;j<n;j++)
	{
		arr[i][j]=arr[i][j]+arr[i][j-1];
	}
	for(int i=1,j=0;i<n;i++)
	{
		arr[i][j]=arr[i][j]+arr[i-1][j];
	}
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			arr[i][j]=arr[i][j]+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
		}
	}
}
int sum_of_submatrix(int **arr,int m,int n,int lx,int ly,int rx,int ry)
{
	prefix_sum_array(arr,m,n);
	int res=arr[rx][ry]-arr[lx-1][ry]-arr[rx][ly-1]+arr[lx-1][ly-1];
	return res;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
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
		int lx,ly,rx,ry;
		cin>>lx>>ly>>rx>>ry;
		int sum=sum_of_submatrix(arr,m,n,lx,ly,rx,ry);
		for(int i=0;i<m;i++)
		{
		    for(int j=0;j<n;j++)
		    {
		        cout<<arr[i][j]<<" ";
		    }
		    cout<<"\n";
		}
		for(int i=0;i<m;i++)
		{
			delete [] arr[i];
		}
		delete [] arr;
		cout<<sum;
	}
	return 0;
}