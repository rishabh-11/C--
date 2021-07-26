#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
    if(y==0)
        return x;
    return gcd(y,x%y);
}
int main()
{
	int x,y;
	cin>>x>>y;
	int ans=gcd(max(x,y),min(x,y));
	long long int lcm=(((long long int)x)*((long long int)y))/ans;
	cout<<lcm;
	return 0;
}