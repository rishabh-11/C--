#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    
    int n;
    cin>>n;
    int a[n];
    int c[10]={0};
    for (int i=0; i<n; i++) 
    {
        cin>>a[i];
    }
    for(int i=0;i<10;i++)
    {
        int k=0;
        int b[n];
        for(int j=0;j<n;j++)
        {
            if(a[j]==i)
            {
                b[k]=j;
                k++;
            }
        }
        int max=0;
        for(int l=0;l<k;l++)
        {
            int count;
            if(l==0)
            {
                count=b[l]+1;
            }
            else if(l==k-1)
            {
                count=n-b[l];
            }
            else
            {
                count=b[l]-b[l-1];
            }
            if(max<count)
            {
                max=count;
            }
            c[i]=max;
        }
    }
    for(int i=0;i<10;i++)
    {
        if(c[i]==0)
        {
            c[i]=n;
        }
    }
    int min=c[0];
    int ans2;
    for(int i=0;i<10;i++)
    {
        if(c[i]<min)
        {
            min=c[i];
            ans2=i;
        }
    }
    cout<<min<<" "<<ans2<<endl;
	return 0;
}
