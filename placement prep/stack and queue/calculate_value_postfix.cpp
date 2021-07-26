int Solution::evalRPN(vector<string> &A) {
    if(A.size()==1)return stoi(A[0]);
    stack<int> s;
    int ans=0,num1=0,num2=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=="*" || A[i]=="/" || A[i]=="+" || A[i]=="-")
        {
            num2=s.top();
            s.pop();
            num1=s.top();
            s.pop();
            int temp;
            if(A[i]=="*")temp=num1*num2;
            if(A[i]=="-")temp=num1-num2;
            if(A[i]=="+")temp=num1+num2;
            if(A[i]=="/")temp=num1/num2;
            s.push(temp);
        }
        else s.push(stoi(A[i]));
    }
    return s.top();
}
