#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(void){
    // Your code here!
    int t;
    cin>>t;
    while(t--)
    {
        double x,y,z,k;
        cin>>x>>y>>z>>k;
        double lo=0,hi=z;
        cout<<setprecision(10);
        int flag=0;
        while(lo<=hi)
        {
            double d = (lo+hi)/2;
            double d1 = d + 0.001;
            double d2 = d - 0.001;
            double val = sqrt((x*x)+(d*d))+k*sqrt((y*y)+((z-d)*(z-d)));
            double val1 = sqrt((x*x)+(d1*d1))+k*sqrt((y*y)+((z-d1)*(z-d1)));
            double val2 = sqrt((x*x)+(d2*d2))+k*sqrt((y*y)+((z-d2)*(z-d2)));
            if(val<=val1 && val<=val2)
            {
                cout<<sqrt((x*x)+(d*d))+sqrt((y*y)+((z-d)*(z-d)))<<"\n";
                flag=1;
                break;
            }
            else if(val<=val1 && val>=val2)
            {
                hi=d-0.001;
            }
            else
            {
                lo=d+0.001;
            }
        }
        if(flag==1)continue;
        double val3 = sqrt((x*x)+(lo*lo))+k*sqrt((y*y)+((z-lo)*(z-lo)));
        double val4 = sqrt((x*x)+(hi*hi))+k*sqrt((y*y)+((z-hi)*(z-hi)));
        if(val3>val4)
        {
            cout<<sqrt((x*x)+(hi*hi))+sqrt((y*y)+((z-hi)*(z-hi)))<<"\n";
        }
        else
        {
            cout<<sqrt((x*x)+(lo*lo))+sqrt((y*y)+((z-lo)*(z-lo)))<<"\n";
        }
    }
}