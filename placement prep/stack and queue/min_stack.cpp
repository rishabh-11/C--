stack<int> s;
int min1;
MinStack::MinStack() {
    min1=-1;
    while(!s.empty())s.pop();
}

void MinStack::push(int x) {
    if(s.empty())
    {
        s.push(x);
        min1=x;
    }
    else
    {
        if(x<min1)
        {
            s.push(2*x-min1);
            min1=x;
        }
        else s.push(x);
    }
}

void MinStack::pop() {
    if(s.empty())return;
    if(s.top()<min1)
    {
        int val=2*min1-s.top();
        min1=val;
        s.pop();
    }
    else
    {
        s.pop();
    }
}

int MinStack::top() {
    if(s.empty())return -1;
    if(s.top()<min1)return min1;
    return s.top();
}

int MinStack::getMin() {
    if(s.empty())return -1;
    return min1;
}

