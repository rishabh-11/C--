#include <bits/stdc++.h>
#include <algorithm>  
using namespace std;
 
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int x;
    cin>>x;
    long long int temp=sqrt(x);
    for(long long int i=temp;i>0;i--)
    {
        if(x%i==0)
        {
            long long int temp1=__gcd(i,x/i);
            if(temp1==1)
            {
                cout<<i<<" "<<(x/i);
                break;
            }
        }
    }
}