#include <bits/stdc++.h>
using namespace std;
struct node
{
	vector <node *> children;
};
int find_depth(node * root)
{
	if((root->children).size()==0)return 0;
	else if((root->children).size()==1) return 1+find_depth((root->children)[0]);
	{
		int depth=find_depth((root->children)[0]);
		for(int i=1;i<(root->children).size();i++)
		{
			depth=max(depth,find_depth((root->children)[i]));
		}
		return depth+1;
	}
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
	node * temp[n];
	node * root;
	for(int i=0;i<n;i++)
	{
		temp[i]=new node();
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i]==-1)
		{
			root=temp[i];
		}
		else
		{
			(temp[arr[i]]->children).push_back(temp[i]);
		}
	}
	int depth=find_depth(root);
	cout<<depth+1;
	return 0;
}