vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack <int> s;
        s.push(0);
        vector<long long> v(n,-1);
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[i]>arr[s.top()])
            {
                v[s.top()]=arr[i];
                s.pop();
            }
            s.push(i);
        }
        return v;
        
    }