#include <bits/stdc++.h>
using namespace std;
struct node
{
    node* next;
    node* prev;
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
void delete_element(int index,node** head,node** tail,int n)
{
	if(index==1)
	{
		node* temp=*head;
		*head=(*head)->next;
		(*head)->prev=NULL;
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
        current->prev=NULL;
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
        temp->prev=NULL;
        if(i==0)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
    }
    node* temp_head=head;
    int val,count=1;
    cin>>val;
    for(;temp_head!=NULL;)
    {
        int val1=temp_head->data;
        temp_head=temp_head->next;
    	if(val1<val)
   		{
   		    delete_element(count,&head,&tail,n);
   			continue;
   		}
    	count++;
    }
    print_list(&head);
	return 0;
}