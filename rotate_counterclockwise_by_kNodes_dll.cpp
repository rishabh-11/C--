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
int main()
{
    int n,k;
    cin>>n>>k;
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
    k=k%n;
    if(k!=0)
    {
        head->prev=tail;
        tail->next=head;
        node* previous=NULL;
        while(k)
        {
            previous=head;
            head=head->next;
            k--;
        }
        head->prev=NULL;
        previous->next=NULL;
        tail=previous;
    }
    print_list(&head);
    return 0;
}