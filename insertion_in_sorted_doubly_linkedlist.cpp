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
void insert_element(node** new_node,int index,node** head,node** tail,int n)
{
    if(index==0)
    {
        (*new_node)->next=*head;
        (*head)->prev=*new_node;
        *head=*new_node;
    }
    else if(index==n)
    {
        (*tail)->next=*new_node;
        (*new_node)->prev=*tail;
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
        (*new_node)->prev=current;
    }
}
int find_index(node* head,int data)
{
    int count=0;
    while(head!=NULL)
    {
        if(data<(head->data))
            return count;
        count++;
        head=head->next;
    }
    return count;
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
    print_list(&head);
    node* temp=new node();
    int j;
    cin>>j;
    temp->data=j;
    temp->next=NULL;
    temp->prev=NULL;
    int index=find_index(head,j);
    insert_element(&temp,index,&head,&tail,n);
    print_list(&head);
    return 0;
}