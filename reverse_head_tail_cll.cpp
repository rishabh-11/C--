#include <bits/stdc++.h>
using namespace std;
struct node
{
	node* next;
	int data;
};
void print_list(node** head,int n)
{
    node *temp=*head;
	while(temp!=NULL && n!=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
		n--;
	}
	cout<<"\n";
}
void reverse_head_tail(node** head,node** tail,int n)
{
	if(n==1)
		return;
	node* previous=*head;
	while(previous->next!=*tail)
	{
		previous=previous->next;
	}
	previous->next=*head;
	(*tail)->next=(*head)->next;
	node* temp=*head;
	*head=*tail;
	*tail=temp;
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
	tail->next=head;
	reverse_head_tail(&head,&tail,n);
	print_list(&head,n);
	return 0;
}