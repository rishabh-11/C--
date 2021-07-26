#include <bits/stdc++.h>
using namespace std;
/*works when array is sorted row and columnwise*/
bool find(int m,int n,int* arr,int element)
{
	int temp= *(arr+((n-1)*m));
	int i=n-1,j=0;
	while(temp!=element)
	{
		if(temp>element)
		{
			if(i==0)
				return false;
			temp= *(arr+((i-1)*m)+j);
			i--;
		}
		else
		{
			if(j==m-1)
				return false;
			temp= *(arr+(i*m)+j+1);
			j++;
		}
	}
	return true;
}
int main()
{
	int n,m;
	cin>>n>>m;
	int arr[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	int element;
	cin>>element;
	bool ans=find(m,n,(int*)arr,element);
	cout<<ans;
}