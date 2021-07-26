int sum = 0;
        queue<int> q;
        int i=0;
        while(i<n && sum!=s)
        {
            if(sum>s)
            {
                sum-=arr[q.front()];
                q.pop();
            }
            else
            {
                sum+=arr[i];
                q.push(i);
                i++;
            }
        }
        vector<int> ans;
        if(sum<s)
        {
            ans.push_back(-1);
        }
        else
        {
            while(!(q.empty()) && sum!=s)
            {
                sum-=arr[q.front()];
                q.pop();
            }
            if(sum!=s)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(q.front()+1);
                while(q.size()!=1)
                {
                    q.pop();
                }
                ans.push_back(q.front()+1);    
            }
            
        }
        return ans;