#include <bits/stdc++.h>
using namespace std;
int mycompare(string x,string y)
{
    string temp1=x.append(y);
    string temp2=y.append(x);
    if(temp1>temp2)
        return 1;
    return 0;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	vector<string> v;
	for(int i=0;i<n;i++)
	{
	    v.push_back(to_string(arr[i]));
	}
	sort(v.begin(),v.end(),mycompare);
	for(int i=0;i<n;i++)
	{
	    cout<<v[i];
	}
	return 0;
}