#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,s1,s2;
    cin>>n>>s1>>s2;
    pair<int,int> arr[n];
    int pos_x=0,pos_y=0,neg_x=0,neg_y=0;
    int first=0,second=0,third=0,fourth=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
        arr[i].first=arr[i].first-s1;
        arr[i].second=arr[i].second-s2;
        if(arr[i].first>0 && arr[i].second>0)
        {
            first++;
        }
        else if(arr[i].first<0 && arr[i].second>0)
        {
            second++;
        }
        else if(arr[i].first<0 && arr[i].second<0)
        {
            third++;
        }
        else if(arr[i].first>0 && arr[i].second<0)
        {
            fourth++;
        }
        else if(arr[i].first>0 && arr[i].second==0)
        {
            pos_x++;
        }
        else if(arr[i].first==0 && arr[i].second<0)
        {
            neg_y++;
        }
        else if(arr[i].first==0 && arr[i].second>0)
        {
            pos_y++;
        }
        else if(arr[i].first<0 && arr[i].second==0)
        {
            neg_x++;
        }
    }
    int neg_x1=neg_x+second+third;
    int neg_y1=neg_y+fourth+third;
    int pos_x1=pos_x+first+fourth;
    int pos_y1=pos_x+second+first;
    if(max(max(neg_y1,neg_x1),max(pos_y1,pos_x1))==neg_x1)
    {
        cout<<neg_x1<<"\n";
        cout<<(s1-1)<<" "<<s2<<"\n";
    }
    else if(max(max(neg_y1,neg_x1),max(pos_y1,pos_x1))==neg_y1)
    {
        cout<<neg_y1<<"\n";
        cout<<s1<<" "<<(s2-1)<<"\n";
    }
    else if(max(max(neg_y1,neg_x1),max(pos_y1,pos_x1))==pos_x1)
    {
        cout<<pos_x1<<"\n";
        cout<<(s1+1)<<" "<<s2<<"\n";
    }
    else
    {
        cout<<pos_y1<<"\n";
        cout<<s1<<" "<<(s2+1)<<"\n";
    }
}
