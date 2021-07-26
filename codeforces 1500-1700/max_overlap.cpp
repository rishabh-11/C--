vector<pair<int,int>> v;
    	for(int i=0;i<n;i++)
    	{
    	    v.push_back({arr[i],-1});
    	    v.push_back({dep[i],1});
    	}
    	sort(v.begin(),v.end());
    	int count=0;
    	int c1=0;int c2=0;
    	for(int i=0;i<2*n;i++)
    	{
    	    if(v[i].second==-1)c1++;
    	    else c2++;
    	    count=max(count,c1-c2);
    	}
    	return count;