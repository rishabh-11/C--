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
void reverse(node** head)
{
   node* current=*head;
   node* previous=NULL;
   node* after=NULL;
   while(current!=NULL)
   {
        after=current->next;
        current->next=previous;
        current->prev=after;
        previous=current;
        current=after;
   }
   *head=previous;
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
    reverse(&head);
    print_list(&head);
    return 0;
}