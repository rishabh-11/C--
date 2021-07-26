vector<vector<int>> v;
        int st=-1;
        for(int i=0;i<n;i++)
        {
            int flag=-1;
            if(i==0 && A[i]<A[i+1])flag=0;
            else if(i>0 && i<n && A[i]>=A[i+1] && A[i]>A[i-1])flag=1;
            else if(i>0 && i<n && A[i]<=A[i-1] && A[i]<A[i+1])flag=0;
            else if(i==n-1 && A[i]>A[i-1])flag=1;
            
            if(flag==0)
            {
                st=i;
            }
            else if(flag==1)
            {
                vector<int> temp;
                temp.push_back(st);
                temp.push_back(i);
                v.push_back(temp);
                st=-1;
            }
        }
        return v;