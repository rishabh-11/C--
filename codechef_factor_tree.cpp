#include <bits/stdc++.h>
using namespace std;
struct node
{
    int num;
    node* parent=NULL;
    int curr[169]={0};
    int prev[169]={0};
    vector<node*> children;
};
map<int,int> m;
bool prime[1001];
int prime_factorisation(int cost,int curr[])
{
    if(cost==2){curr[0]++;return 1;}
    if(cost==3){curr[1]++;return 1;}
    for(int i=2;i<1001;i++)
    {
        while(cost%i==0)
        {
            cost=cost/i;
            curr[m[i]]++;
        }
        if(cost==1)break;
    }
    if(cost!=1)curr[168]++;
    return cost;
}
void add(node* a,node* b)
{
    for(int i=0;i<168;i++)
    {
        (b->prev)[i]=(b->curr)[i]+(a->prev)[i];
    }
}
void set_prev(node* root)
{
    if((root->children).size()==0)return;
    for(int i=0;i<(root->children).size();i++)
    {
        add(root,(root->children)[i]);
        set_prev((root->children)[i]);
    }
}
void create_tree(vector<pair<node*,node*>> v,node* w,node* arr[])
{
    vector<pair<node*,node*>>::iterator itr;
    itr=v.begin();
    //cout<<v.size()<<" ";
    for(;itr!=v.end();itr++)
    {
        if((*itr).first==w || (*itr).second==w)
        {
            if((*itr).first==w)
            {w->children.push_back((*itr).second);((*itr).second)->parent=w;}
            else
            {w->children.push_back((*itr).first);((*itr).first)->parent=w;}
            v.erase(itr);
            itr--;
        }
    }
    if((w->children).size()==0)return;
    for(int i=0;i<(w->children).size();i++)
    {
        create_tree(v,(w->children)[i],arr);
    }
}
int main(void)
{
    memset(prime,true,sizeof(prime));
    for(int i=2;i*i<1001;i++)
    {
        if(prime[i]==true)
        {
            for(int j=i*i;j<1001;j+=i)
            {
                prime[j]=false;
            }
        }
    }
    int q=0;
    for(int i=2;i<1001;i++)
    {
        if(prime[i]==true)
        {
            m[i]=q;
            q++;
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int cost[n+1];
        node* arr[n+1];
        for(int i=1;i<=n;i++)
        {
            arr[i]=new node();
            arr[i]->num=i;
        }
        vector<pair<node*,node*>> v;
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            v.push_back(make_pair(arr[x],arr[y]));
        }
        node* root=NULL;
        if(n==1)
        {
            root=arr[1];
        }
        else{root=v[0].first;}
        create_tree(v,root,arr);
        /*cout<<v.size()<<"\n";
        for(int i=1;i<=n;i++)
        {
            cout<<(arr[i]->children).size()<<" ";
        }*/
        for(int i=1;i<=n;i++)
        {
            cin>>cost[i];
            cost[i]=prime_factorisation(cost[i],arr[i]->curr);
            /*for(int j=0;j<10;j++)
            {
                cout<<(arr[i]->curr)[j]<<" ";
            }
            cout<<"\n";*/
            //cout<<(arr[i]->curr)[168]<<" ";
        }
        for(int i=0;i<168;i++)
        {
            (root->prev)[i]=(root->curr)[i];
        }
        set_prev(root);
        /*for(int i=1;i<=n;i++)
        {
            for(int j=0;j<10;j++)
            {
                cout<<(arr[i]->prev)[j]<<" ";
            }
            cout<<"\n";
        }*/
        int q;
        cin>>q;
        while(q--)
        {
            int u,v;
            cin>>u>>v;
            if(u==v)
            {
                long long int ans=1;
                for(int i=0;i<169;i++)
                {
                    if((arr[u]->curr)[i]!=0)
                    {
                        ans=(ans*((arr[u]->curr)[i]+1))%1000000007;
                    }
                }
                cout<<ans<<"\n";
                continue;
            }
            vector<node*> pu,pv;
            pu.push_back(arr[u]);
            pv.push_back(arr[v]);
            node* temp1=arr[u];
            while((temp1->parent)!=NULL)
            {
                pu.push_back(temp1->parent);
                temp1=(temp1->parent);
            }
            node* temp2=arr[v];
            while((temp2->parent)!=NULL)
            {
                pv.push_back(temp2->parent);
                temp2=(temp2->parent);
            }
            /*for(int i=0;i<pu.size();i++)
            {
                cout<<pu[i]->num<<" ";
            }*/
            /*for(int i=0;i<pv.size();i++)
            {
                cout<<pv[i]->num<<" ";
            }*/
            int j=pu.size()-1;
            int k=pv.size()-1;
            int diff=j-k;
            while(j!=0 || k!=0)
            {
                if(pu[j]!=pv[k])
                {
                    break;
                }
                else
                {
                    if(j>0)j--;
                    if(k>0)k--;
                }
                if(pu[j]!=pv[k])
                {
                    break;
                }
            }
            if((j-k)==diff){j++;k++;}
            else if((j-k)>diff){k++;}
            else{j++;}
            long long int ans=1;
            vector<int> vec={};
            for(int i=0;i<=j;i++)
            {
                if((pu[i]->curr)[168]==1)
                {
                    vec.push_back(cost[pu[i]->num]);
                }
            }
            for(int i=0;i<k;i++)
            {
                if((pv[i]->curr)[168]==1)
                {
                    vec.push_back(cost[pv[i]->num]);
                }
            }
            /*for(int i=0;i<vec.size();i++)
            {
                cout<<vec[i]<<" ";
            }*/
            if(vec.empty()==false)
            {
                sort(vec.begin(),vec.end());
                int count=1;
                for(int i=1;i<vec.size();i++)
                {
                    if(vec[i]==vec[i-1])
                    {
                        count++;
                    }
                    else
                    {
                        ans=(ans*(count+1))%1000000007;
                        count=1;
                    }
                }
                ans=ans*(count+1)%1000000007;
            }
            //cout<<pu.size()<<" "<<pv.size()<<"\n";
            //cout<<j<<" "<<k<<"\n";
            int res[168]={0};
            for(int i=0;i<168;i++)
            {
                res[i]=(arr[u]->prev)[i]+(arr[v]->prev)[i]-(pu[j]->prev)[i]-(pu[j]->prev)[i]+(pu[j]->curr)[i];
                ans=(ans*(res[i]+1))%1000000007;
            }
            cout<<ans<<"\n";
        }
    }
}