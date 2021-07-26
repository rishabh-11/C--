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
	cout<<ans;
	return 0;
}