#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n;
	cin>>n;
	long long int count=0,q=1;
	if(n==1)
	{   
		cout<<1<<"\n";
	    cout<<1;
    }
    else
    {
        while(count<n)
    	{
    		count=((q+1)*q)/2;
    		q++;
    	}
    	long long int sum=0;
    	long long int temp=q-2,count1=q-2;
    	if(count==n){temp++;count1++;}
    	cout<<count1<<"\n";
    	for(long long int i=1;i<temp;i++)
    	{
    	    cout<<i<<" ";
    	    sum=sum+i;
    	}   
    	cout<<n-sum;
    }
}