int t=0;
            for(int i=n-1;i>=0;i--)
            {
                int index=lower_bound(arr2+t,arr2+m,arr1[i])-arr2;
                if(t==m || (index==t &&  arr2[t]>=arr1[i]))break;
                swap(arr2[t],arr1[i]);
                t++;
            }
            sort(arr2,arr2+m);
            sort(arr1,arr1+n);