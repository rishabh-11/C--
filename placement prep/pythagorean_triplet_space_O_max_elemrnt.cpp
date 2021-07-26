int max1=INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	        max1=max(max1,arr[i]);
	    }
	    int a[max1+1];
	    for(int i=0;i<=max1;i++)
	    {
	        a[i]=0;
	    }
	    for(int i=0;i<n;i++)
	    {
	        a[arr[i]]=1;
	    }
	    for(int i=1;i<=max1;i++)
	    {
	        for(int j=i+1;j<=max1;j++)
	        {
	            int temp=sqrt(i*i+j*j);
	            if((temp*temp)==(i*i+j*j) && a[temp]==1 && a[i]==1 && a[j]==1)
	            return true;
	        }
	    }
	    return false;