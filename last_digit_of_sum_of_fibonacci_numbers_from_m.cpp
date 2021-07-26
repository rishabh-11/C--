#include <bits/stdc++.h>
using namespace std;
void power(long long int F[2][2],long long int n);
void multiply(long long int F[2][2],long long int M[2][2]);
long long int fib(long long int n)
{
    long long int F[2][2]={{1,1},{1,0}};
    if(n==0)
        return 0;
	power(F,n-1);
	return F[0][0];
}
void multiply(long long int F[2][2],long long int M[2][2])
{
    long long int x,y,z,w;
	x=F[0][0]*M[0][0]+F[0][1]*M[1][0];
	y=F[0][0]*M[0][1]+F[0][1]*M[1][1];
	z=F[1][0]*M[0][0]+F[1][1]*M[1][0];
	w=F[1][0]*M[0][1]+F[1][1]*M[1][1];
	F[0][0]=x;
	F[0][1]=y;
	F[1][0]=z;
	F[1][1]=w;
}
void power(long long int F[2][2],long long int n)
{
	long long int M[2][2]={{1,1},{1,0}};
	if(n==0 || n==1)
		return;
	power(F,n/2);
	multiply(F,F);
	if(n%2!=0)
		multiply(F,M);
}
long long int temp1(long long int n,long long int fib_arr[],long long int sum)
{
	if(n<=0)
		return 0;
	long long int quotient=n/60;
	long long int remainder=n%60;
	long long int temp=0;
	for(long long int i=0;i<=remainder;i++)
	{
		temp+=fib_arr[i];
	}
	long long int res=sum*quotient+temp;
	return (res);
}
int main()
{
	long long int n,m;
	cin>>n>>m;
	long long int fib_arr[60]={0};
	long long int sum=0;
	for(long long int i=0;i<60;i++)
	{
		fib_arr[i]=(fib(i))%10;
		sum+=fib_arr[i];
	}
	long long int t2=temp1(n-1,fib_arr,sum);
	long long int t1=temp1(m,fib_arr,sum);
	long long int res=(t1-t2)%10;
	cout<<res<<"\n";
	return 0;
}