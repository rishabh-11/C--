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
node *reverse (node *head, int k)  
{  
    node* current = head;  
    node* next = NULL;  
    node* prev = NULL;  
    int count = 0;  
      
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)  
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;
        current = next;  
        count++;
    }
    /* next is now a pointer to (k+1)th node  
    Recursively call for the list starting from current.  
    And make rest of the list as next of first node */
    if (next != NULL)
    head->next = reverse(next, k);  
  
    /* prev is new head of the input list */
    return prev;  
}
int main()
{
	int n,k;
	cin>>n>>k;
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
	node* head1=reverse(head,k);
	print_list(head1);
}