#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(),v.end());
	pair<int,int> range;
	vector<int> ans;
	range=make_pair(v[0].first,v[0].second);
	for(int i=1;i<n;i++)
	{
		if(range.second<v[i].first || range.first>v[i].second)
		{
			ans.push_back(range.first);
			range.first=v[i].first;
			range.second=v[i].second;
			if(i==n-1)
    		{
    		    ans.push_back(range.first);
    		}
			continue;
		}
		else if(range.first<=v[i].first && range.second>=v[i].second)
		{
			range.first=v[i].first;
			range.second=v[i].second;
		}
		else if(range.first<=v[i].first && range.second<=v[i].second)
		{
			range.first=v[i].first;
		}
		else if(range.first>=v[i].first && range.second>=v[i].second)
		{
			range.second=v[i].second;
		}
		if(i==n-1)
		{
		    ans.push_back(range.first);
		}
		
	}
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
