#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    //int t;
    //cin>>t;
    //while(t--)
    //{
        long long int n;
        cin>>n;
        long long int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        long long int count=0;
        long long int sum=0;
        map<long long int,long long int> m;
        long long int val=1;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            count++;
            if(sum<0)
            {
                if(val<0 && abs(val)>abs(arr[i]))
                {
                    sum+=abs(val);
                    m[arr[i]]++;
                    m[val]--;
                    if(m[val]==0)
                    {
                        m.erase(val);
                        val=1;
                    }
                    val=min(val,(m.begin())->first);
                }
                else
                {
                    sum-=arr[i];
                }
                count--;
            }
            else if(sum>=0 && arr[i]<0)
            {
                m[arr[i]]++;
                val=min(val,(m.begin())->first);
            }
            //cout<<sum<<" "<<val<<" "<<m.size()<<"\n";
        }
        cout<<count<<"\n";
    //}
}
