#include <bits/stdc++.h>
using namespace std;
struct node
{
	node* next;
	int data;
};
void print_list(node** head)
{
    node *temp=*head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}
void insert_element(node** new_node,int index,node** head,node** tail,int n)
{
    if(index==1)
    {
        (*new_node)->next=*head;
        *head=*new_node;
    }
    else if(index==n)
    {
        (*tail)->next=*new_node;
        *tail=*new_node;
    }
    else
    {
        node* current=*head;
        while(index!=1)
        {
            index--;
            current=current->next;
        }
        (*new_node)->next=current->next;
        current->next=*new_node;
    }
}
void delete_element(int index,node** head,node** tail,int n)
{
	if(index==1)
	{
		node* temp=*head;
		*head=(*head)->next;
		delete temp;
	}
	else if(index==n)
	{
		node* temp=*tail;
		node* current=*head;
        while(current->next->next!=NULL)
        {
            current=current->next;
        }
        *tail=current;
        (*tail)->next=NULL;
        delete temp;
	}
	else
	{
		node* current=*head;
		node* temp=NULL;
        while(index!=1)
        {
            index--;
            temp=current;
            current=current->next;
        }
        temp->next=current->next;
        delete current;
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
		node* temp=new node();
		int j;
		cin>>j;
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
	print_list(&head);
	node* temp=new node();
	int j,index;
	cin>>j>>index;
	temp->data=j;
	temp->next=NULL;
	insert_element(&temp,index,&head,&tail,n);
	delete_element(6,&head,&tail,n);
	print_list(&head);
	return 0;
}