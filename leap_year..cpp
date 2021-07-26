#include <bits/stdc++.h>
using namespace std;
bool isleap(long long int year)  
{    
    if (year % 400 == 0)  
        return true;  
    if (year % 100 == 0)  
        return false;    
    if (year % 4 == 0)  
        return true;  
    return false;  
}
int dayofweek(int y)  
{  
	int d=1,m=2;
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
}
int func(int year)
{
	int temp=dayofweek(year);
	if(isleap(year)==true && temp==6)
	{
		return 1;
	}
	else if(isleap(year)==false && (temp==6 || temp==0))
	{
		return 1;
	}
	return 0;
}
int main()
{
	int t;
	cin>>t;
	int arr[4001]={0};
	for(int i=2;i<=4000;i++)
	{
		int temp=dayofweek(i);
		if(isleap(i)==true && temp==6)
		{
			arr[i]=arr[i-1]+1;
		}
		else if(isleap(i)==false && (temp==6 || temp==0))
		{
			arr[i]=arr[i-1]+1;
		}
		else
		{
		    arr[i]=arr[i-1];
		}
	}

	while(t--)
	{
		int m1,y1,m2,y2;
		cin>>m1>>y1>>m2>>y2;
		if(m1>2)y1++;
		if(m2<2)y2--;
		if(y1>y2){cout<<0<<"\n";continue;}
		int count=0;
		if(y1<2000)
		{
			if(y2<2000)
			{
				count=count+arr[y2]-arr[y1];
				if(func(y1)==1)count++;
			}
			else
			{
				count=count+arr[2000]-arr[y1];
				if(func(y1)==1)count++;
				int temp1=y2/2000;
				int temp2=y2%(2000*temp1);
				count=count+arr[2000+temp2];
				count=count+(temp1-1)*arr[2000];
			}
			cout<<count<<"\n";
		}
		else
		{
			int temp1=y1/2000;
			int temp2=y1%(2000*temp1);
			count=count-arr[2000+temp2];
			count=count-(temp1-1)*arr[2000];

			int temp3=y2/2000;
			int temp4=y2%(2000*temp1);
			count=count+arr[2000+temp4];
			count=count+(temp3-1)*arr[2000];

			if(func(y1)==1)count++;
			
			cout<<count<<"\n";
		}
	}
}