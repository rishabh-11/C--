#include <bits/stdc++.h>
using namespace std;
void rotate_90(int* arr,int n)
{
	for(int i=0;i<n/2;i++)
	{
		int temp1= *(arr+(n-i-1)*n+i);
		int temp2= *(arr+(i*n)+i);
		int temp3= *(arr+(n-i-1)*n+n-i-1);
		int temp4= *(arr+(i*n)+n-i-1);
		*(arr+(i*n)+i)=temp1;
		*(arr+(i*n)+n-i-1)=temp2;
		*(arr+(n-i-1)*n+i)=temp3;
		*(arr+(n-i-1)*n+n-i-1)=temp4;
		for(int k=i+1;k<n-1-i;k++)
		{
			temp1= *(arr+(n-1-i)*n+k);
			temp2= *(arr+(k)*n+i);
			temp3= *(arr+(i*n)+n-1-k);
			temp4= *(arr+(n-1-k)*n+n-1-i);
			*(arr+(k*n)+i)=temp1;
			*(arr+(i*n)+n-1-k)=temp2;
			*(arr+((n-1-k)*n)+n-1-i)=temp3;
			*(arr+(n-i-1)*n+k)=temp4;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	rotate_90((int*)arr,n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}