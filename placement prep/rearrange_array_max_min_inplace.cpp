int add1=0;
    	int add2=n-1;
    	int flag=0;
    	int m=n;
    	int count=0;
    	while(m>0)
    	{
    	    m/=10;
    	    count++;
    	}
    	for(int i=0;i<n;i++)
    	{
    	    if(flag==0)
    	    {
                arr[i]=((arr[add2]%10000000)*10000000)+arr[i];
                add2--;
                flag=1;
    	    }
    	    else
    	    {
    	        arr[i]=((arr[add1]%10000000)*10000000)+arr[i];
                add1++;
                flag=0;
    	    }
    	}
    	for(int i=0;i<n;i++)
    	{
    	   arr[i]/=10000000;
    	}