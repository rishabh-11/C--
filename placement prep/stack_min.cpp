int _stack :: getMin()
{
    if(s.empty())return -1;
    return minEle;
   //Your code here
}

/*returns poped element from stack*/
int _stack ::pop()
{
    if(s.empty())return -1;
    int ans=s.top();
    s.pop();
    if(ans<minEle)
    {
        int temp=minEle;
        minEle=2*minEle-ans;
        ans=temp;
    }
    return ans;
   //Your code here
}

/*push element x into the stack*/
void _stack::push(int x)
{
    if(s.empty())
    {
        minEle=x;
        s.push(x);
        return;
    }
    if(x<minEle)
    {
        s.push(2*x-minEle);
        minEle=x;    
    }
    else s.push(x);
   //Your code here
}