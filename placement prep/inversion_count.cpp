long long int _mergesort(long long arr[], long long temp[], long long left, long long right)
    {
        long long  mid, inv_count=0;
        if(right>left)
        {
            mid=(right+left)/2;
            inv_count+=_mergesort(arr,temp,left,mid);
            inv_count+=_mergesort(arr,temp,mid+1,right);
            
            inv_count+=merge(arr,temp,left,mid+1,right);
        }
        return inv_count;
    }
    long long int merge(long long arr[],long long temp[],long long left,long long mid,long long right)
    {
        long long i=left;
        long long j=mid;
        long long k=left;
        long long inv_count=0;
        while(i<mid && j<=right)
        {
            if(arr[i]<=arr[j])
            {
                temp[k]=arr[i];
                i++;k++;
            }
            else
            {
                temp[k]=arr[j];
                k++;
                j++;
                inv_count+=(mid-i);
            }
        }
        while(i<mid)
        {
            temp[k++]=arr[i++];
        }
        while(j<=right)
        {
            temp[k++]=arr[j++];
        }
        for(i=left;i<=right;i++)
        {
            arr[i]=temp[i];
        }
        return inv_count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int temp[N];
        long long int ans=_mergesort(arr,temp,0,N-1);
        return ans;
    }