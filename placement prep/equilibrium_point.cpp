long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        long long sum1=0;
        int ind=-1;
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            sum1+=arr[i-1];
            if((sum-sum1-arr[i])==(sum1))
            {
                ind=i+1;break;
            }
        }
        return ind;