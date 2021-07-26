vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque<int> q;
    vector<int> ans;
    if(B>A.size())B=A.size();
    for(int i=0;i<B;i++)
    {
        while(!(q.empty()) && A[q.back()]<A[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(A[q.front()]);
    for(int i=B;i<A.size();i++)
    {
        while(!(q.empty()) && q.front()<=i-B)
        {
            q.pop_front();
        }
        while(!(q.empty()) && A[q.back()]<A[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(A[q.front()]);
    }
    return ans;
}
