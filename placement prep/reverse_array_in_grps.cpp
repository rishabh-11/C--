int start=0;
        int i=min(n-1,k-1);
        while(i<n && start<n)
        {
            for(int j=start;j<=(start+i)/2;j++)
            {
                swap(arr[j],arr[i-j+start]);
            }
            start=i+1;
            i=min(n-1,i+k);
        }