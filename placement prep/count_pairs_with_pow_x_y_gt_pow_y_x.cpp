int arr[5]={0};
       int arr1[5]={0};
       for(int i=0;i<M;i++)
       {
           if(X[i]<=4)
           {
               arr[X[i]]++;
           }
       }
       for(int i=0;i<N;i++)
       {
           if(Y[i]<=4)
           {
               arr1[Y[i]]++;
           }
       }
       long long int ans=0;
       sort(Y,Y+N);
       for(int i=0;i<M;i++)
       {
           if(X[i]>1)
           {
               ans+=(N-(upper_bound(Y,Y+N,X[i])-Y));
               ans+=(arr1[1]+arr1[0]);
               if(X[i]==2)
               ans-=(arr1[3]+arr1[4]);
               if(X[i]==3)
               ans+=arr1[2];    
           }
           //cout<<ans<<" ";
       }
    
        return ans;