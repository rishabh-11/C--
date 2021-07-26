sort(arr,arr+n);
	    int count=0;
	    for(int i=0;i<n;i++)
	    {
	        int f=i+1;
	        for(int j=i+1;j<n;j++)
	        {
                int sum=arr[i]+arr[j];
                while(f<n && arr[f]<sum)
                {
                    f++;
                }
                if(f!=n && arr[f]==sum)
                count++;
	        }
	    }
	    return count;