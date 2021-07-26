 int minJumps(int A[], int n){
       if(n==1)return 0;
    
    for(int i=1;i<n;i++){
        A[i]=max(A[i],A[i-1]-1);
    }
    
    int pos=A[0];
    int count=1;
    while(pos<n-1){
        if(A[pos]==0) 
         return -1;
        pos+=A[pos];
        count++;
          
          }
    return count;
    }