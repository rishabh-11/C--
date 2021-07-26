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
void insert_element(node** new_node,node** head,node** tail,int n)
{
	node* temp=*head;
	node* previous=NULL;
    while(n!=0 && ((*new_node)->data)>=(temp->data))
    {
    	previous=temp;
    	temp=temp->next;
    	n--;
    }
    if(temp==*head && n!=0)
    {
        (*new_node)->next=temp;   
    	*head=*new_node;
    	return;
    }
    previous->next=*new_node;
    (*new_node)->next=temp;
    if(n==0)
    {
		*tail=*new_node;   	
    }
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
	int val;
	cin>>val;
	node* temp=new node();
	temp->data=val;
	temp->next=NULL;
	insert_element(&temp,&head,&tail,n);
	n++;
	print_list(&head,n);
	return 0;
}