#include <iostream>
using namespace std;
void printDiagonal(int b,int c[4][4])
{
    if(b<=4)
    {
        for(int x=b-1,y=0;x>=0;x--,y++)
        {
            cout<<c[y][x];
        }
        cout<<endl;
    }
    else
    {
        int t=b-4;
        for(int x=3,y=t;x>=t;x--,y++)
        {
            cout<<c[y][x];
        }
        cout<<endl;
    }
}
void printreverseDiagonal(int b,int c[4][4])
{
    if(b<=4)
    {
        for(int x=b-1,y=0;x>=0;x--,y++)
        {
            cout<<c[x][y];
        }
        cout<<endl;
    }
    else
    {
        int t=b-4;
        for(int x=3,y=t;x>=t;x--,y++)
        {
            cout<<c[x][y];
        }
        cout<<endl;
    }
}
void printallDiagonal(int v[4][4])
{
    for(int k=1;k<8;k++)
    {
        printDiagonal(k,v);
    }
}
void printallreverseDiagonal(int v[4][4])
{
    for(int k=1;k<8;k++)
    {
        printreverseDiagonal(k,v);
    }
}
int main() {
	int a[4][4];
	for(int i=0;i<4;i++)
	{
	    for(int j=0;j<4;j++)
	    {
	        cin>>a[i][j];
	    }
	}
	int n;
	cin>>n;
	printDiagonal(n,a);
	printallDiagonal(a);
	printallreverseDiagonal(a);
	return 0;
}
