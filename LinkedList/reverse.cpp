#include<iostream>
using namespace std;
struct node{
int data;
node* next;
};
node* create(int data,node* head)
{
    if(head==NULL)
    {
        node* head=new node();
        head->data=data;
        head->next=NULL;
        return head;
    }
    node* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    node*t=new node();
    t->data=data;
    t->next=NULL;
    temp->next=t;
    return head;

}
node* rever(node* head)
{

    if(head->next==NULL)
        return head;
    node* temp=head;
    node* temp1=rever(head->next);
    temp->next->next=temp;
    temp->next=NULL;
    return temp1;

}
int main()
{
    int n;
    cin>>n;
    node* head=NULL;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        head=create(a,head);
    }
    node* temp1=head;
    while(temp1)
    {

        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
    cout<<"\n";
    head=rever(head);
    temp1=head;
    while(temp1)
    {

        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
    cout<<"\n";
    return 0;


}
