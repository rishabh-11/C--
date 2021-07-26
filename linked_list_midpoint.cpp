#include <bits/stdc++.h>
using namespace std;
struct node
{
	node* next;
	int data;
};
void print_list(node* head)
{
    node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}
node* mid_point(node* head,int n)
{
	node* fast=head;
	node* slow=head;
    while(fast!=NULL)
    {
        if(fast->next!=NULL)
        {
            if(fast->next->next==NULL)
            {
                return slow;
            }
            fast=fast->next->next;
            slow=slow->next;
        }
        else
        {
            return slow;
        }
    }
	return slow;
}
int main()
{
	int n;
	cin>>n;
	node* head=NULL;
	node* tail=NULL;
	for(int i=0;i<n;i++)
	{
		int j;
		cin>>j;
		node* temp=new node();
		temp->data=j;
		temp->next=NULL;
		if(i==0)
		{
			head=temp;
			tail=temp;
		}
		else
		{
			tail->next=temp;
			tail=temp;
		}
	}
	node* mid=mid_point(head,n);
	if(mid!=NULL)
	{
		cout<<mid->data;
	}
	return 0;
}