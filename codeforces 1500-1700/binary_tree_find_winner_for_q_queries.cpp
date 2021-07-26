#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define fill(a,val) memset(a,val,sizeof(a))
#define pb  push_back
#define mp  make_pair
#define ff  first
#define ss  second
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const ll MOD     = 1000*1000*1000+7;
const ll INF     = 1ll*1000*1000*1000*1000*1000*1000 + 7;
const ll MOD2    = 998244353;
const ld PI  = 3.141592653589793;
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);} 
ll power(ll x,ll y,ll p ){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
ll power1(ll x,ll y){ll res=1;while(y>0){if(y&1)res=(res*x);y=y>>1;x=(x*x);}return res;}
ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
ll max(ll a,ll b){if(a>b)return a;return b;}
ll min(ll a,ll b){if(a>b)return b;return a;}
bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    return a.second<b.second;
}


string s;

struct node{
    ll num=-1;
    ll val=0;
    ll val_t=0;
    node* left=NULL;
    node* right=NULL;
    node* parent=NULL;
};

void func(node* temp)
{
    //cout<<temp->num<<"\n";
    if(temp->left==NULL)
    {
        temp->val=1;
        //cout<<temp->val<<"\n";
        return;
    }
    func(temp->right);
    func(temp->left);
    if(s[temp->num]=='?')
    temp->val=(temp->left->val) + (temp->right->val);
    else if(s[temp->num]=='1')
    {
        temp->val=(temp->right->val);
    }
    else temp->val=(temp->left->val);
    //cout<<temp->val<<"\n";
}

void func2(node* temp)
{
    if(s[temp->num]=='?')
    temp->val=(temp->left->val) + (temp->right->val);
    else if(s[temp->num]=='1')
    {
        temp->val=(temp->right->val);
    }
    else temp->val=(temp->left->val);
    
    if(temp->parent==NULL)return;
    func2(temp->parent);
}

int main()
{
    fastio();
    ll k;
    cin>>k>>s;
    ll strt=power1(2,k+1)-1;
    node* arr[strt+1];
    for(ll i=power1(2,k+1)-1;i>=1;i--)
    {
        arr[i]=new node();
        arr[i]->num=i-power1(2,k)-1;
    }
    strt--;
    for(ll i=power1(2,k+1)-1;i>=1;i--)
    {
        if(strt<=0)break;
        arr[i]->right=arr[strt];
        arr[strt]->parent=arr[i];
        strt--;
        arr[i]->left=arr[strt];
        arr[strt]->parent=arr[i];
        strt--;
    }
    node* temp=arr[power1(2,k+1)-1];
    func(temp);
    //cout<<arr[power1(2,k+1)-1]->val<<"\n";
    ll q;
    cin>>q;
    while(q>0)
    {
        ll p;char a;
        cin>>p>>a;
        s[p-1]=a;
        func2(arr[p+power1(2,k)]);
        cout<<arr[power1(2,k+1)-1]->val<<"\n";
        //func2(arr[p+power1(2,k)]);
        q--;
    }
    
    return 0;
}