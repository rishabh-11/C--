int max1=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(max1<arr[i])max1=arr[i];
        }
        if(max1<0)return max1;
        
        int max_sum_till_now=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum<0)
            {
                sum=0;
            }
            max_sum_till_now=max(max_sum_till_now,sum);
        }
        return max_sum_till_now;