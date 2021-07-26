#include <bits/stdc++.h>
using namespace std;
void power(long long int F[2][2],long long int n,long long int m);
void multiply(long long int F[2][2],long long int M[2][2],long long int m);
long long int fib(long long int n,long long int m)
{
    long long int F[2][2]={{1,1},{1,0}};
    if(n==0)
        return 0;
	power(F,n-1,m);
	return F[0][0];
}
void multiply(long long int F[2][2],long long int M[2][2],long long int m)
{
    long long int x,y,z,w;
	x=(((F[0][0]*M[0][0])%m)+((F[0][1]*M[1][0])%m))%m;
	y=(((F[0][0]*M[0][1])%m)+((F[0][1]*M[1][1])%m))%m;
	z=(((F[1][0]*M[0][0])%m)+((F[1][1]*M[1][0])%m))%m;
	w=(((F[1][0]*M[0][1])%m)+((F[1][1]*M[1][1])%m))%m;
	F[0][0]=x;
	F[0][1]=y;
	F[1][0]=z;
	F[1][1]=w;
}
void power(long long int F[2][2],long long int n,long long int m)
{
	long long int M[2][2]={{1,1},{1,0}};
	if(n==0 || n==1)
		return;
	power(F,n/2,m);
	multiply(F,F,m);
	if(n%2!=0)
		multiply(F,M,m);
}
int main()
{
	long long int n,m;
	cin>>n>>m;
	long long int ans=fib(n,m);
	cout<<ans;
	return 0;
}