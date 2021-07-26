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
node* reverse_linkedlist(node* head,int n)
{
	if(n==1)
	{
		return head;
	}
	else if(n==2)
	{
		node* temp=head->next;
		temp->next=head;
		head->next=NULL;
		head=temp;
		return head;
	}
	else
	{
		node* temp=head->next;
		node* prev=head;
		node* after=head->next->next;
		while(after!=NULL)
		{
			if(prev==head)
			{
				prev->next=NULL;
				temp->next=prev;
				prev=temp;
				temp=after;
				after=after->next;
			}
			else
			{
				temp->next=prev;
				prev=temp;
				temp=after;
				after=after->next;
				if(after==NULL)
				{
					temp->next=prev;
				}
			}
		}
		head=temp;
	}
	return head;
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
	node* head1=reverse_linkedlist(head,n);
	print_list(head1);
}