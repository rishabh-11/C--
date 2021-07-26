vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here
        vector<int> v;
        int r1=0,c1=0;
        r--;c--;
        while(r1<=r && c1<=c)
        {
            func(matrix,r1,r,c1,c,v);
            r1++;
            c1++;
            r--;c--;
        }
        return v;
    }
    void func(vector<vector<int>> &matrix, int r1, int r2, int c1, int c2, vector<int> &v)
    {
        for(int i=c1;i<=c2;i++)
        {
            v.push_back(matrix[r1][i]);
        }
        for(int i=r1+1;i<=r2;i++)
        {
            v.push_back(matrix[i][c2]);
        }
        for(int i=c2-1;i>=c1;i--)
        {
            if(r2!=r1)
            v.push_back(matrix[r2][i]);
        }
        for(int i=r2-1;i>r1;i--)
        {
            if(c1!=c2)
            v.push_back(matrix[i][c1]);
        }
    }