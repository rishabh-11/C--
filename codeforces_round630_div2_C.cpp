#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int arr[26]={0};
        int temp=0;
        int max=0;
        char ch;
        int count=0,index;
        while(temp<k/2)
        {
            max=0;
            index=0;
            for(int i=0;i<26;i++)
            {
                arr[i]=0;
            }
            for(int i=temp,j=0;i<=(n/k-1)*k+temp;i+=k,j++)
            {
                arr[(int)s[i]-97]++;
                arr[(int)s[k-(temp+1)+k*j]-97]++;
            }
            for(int i=0;i<26;i++)
            {
                if(arr[i]>max)
                {
                    max=arr[i];
                    index=i;
                }
            }
            ch=(char)(index+97);
            for(int i=temp,j=0;i<=(n/k-1)*k+temp;i+=k,j++)
            {
                if(s[i]!=ch)
                {
                    count++;
                }
                if(s[k-(temp+1)+k*j]!=ch)
                {
                    count++;
                }
            }
            temp++;
            //cout<<ch<<"\n";
        }
        //cout<<count<<"\n";
        if(k%2==0)
        {
            cout<<count<<"\n";
        }
        else
        {
            max=0;index=0;
            for(int i=0;i<26;i++)
            {
                arr[i]=0;
            }
            for(int i=k/2;i<n;i+=k)
            {
                arr[(int)s[i]-97]++;
            }
            for(int i=0;i<26;i++)
            {
                if(arr[i]>max)
                {
                    max=arr[i];
                    index=i;
                }
            }
            ch=(char)(index+97);
            for(int i=k/2;i<n;i+=k)
            {
                if(s[i]!=ch)
                {
                    count++;
                }
            }
            cout<<count<<"\n";
        }
    }
}
