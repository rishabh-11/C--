int pm[n],sm[n];
        pm[0]=0;
        sm[n-1]=0;
        for(int i=1;i<n;i++)
        {
            pm[i]=max(pm[i-1],arr[i-1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            sm[i]=max(sm[i+1],arr[i+1]);
        }
        // for(int i=1;i<n-1;i++)
        // {
        //     cout<<arr[i]<<" "<<pm[i]<<" "<<sm[i]<<"\n";
        // }
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            ans+=max(min(pm[i],sm[i])-arr[i],0);
        }
        return ans;