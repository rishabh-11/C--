string Solution::solve(string A) {
    string B="";
    int arr[26]={0};
    int ind=0;
    for(int i=0;i<A.length();i++)
    {
        arr[A[i]-'a']++;
        if(arr[A[ind]-'a']<2)
        {
            B.append(1,A[ind]);
        }
        else
        {
            while(ind<=i && arr[A[ind]-'a']>=2)
            {
                ind++;
            }
            if(ind==i+1)
            {
                B.append("#");
            }
            else B.append(1,A[ind]);
        }
    }
    return B;
}
