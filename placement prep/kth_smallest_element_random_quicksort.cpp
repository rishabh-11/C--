int partition(int arr[], int l, int r)
    {
        int strt=l-1;
        for(int i=l;i<r;i++)
        {
            if(arr[i]<=arr[r])
            {
                strt++;
                swap(arr[strt],arr[i]);
            }
        }
        strt++;
        swap(arr[strt],arr[r]);
        return strt;
    }
    int randomPartition(int arr[], int l, int r)
    {
        int n = r-l+1;
        int pivot = rand() % n;
        swap(arr[l + pivot], arr[r]);
        return partition(arr, l, r);
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        int index = randomPartition(arr,l,r);
        /*for(int i=0;i<=r;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        cout<<index<<" "<<l<<" "<<r<<"\n";*/
        if(index==k-1)
        return arr[index];
        else if(index<k-1)return kthSmallest(arr,index+1,r,k);
        else return kthSmallest(arr,l,index-1,k);
    }