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
node* add(node* a,node* b)
{
    node* ans=NULL;
    int sum=0,carry=0;
    node* prev=NULL;
    while(a!=NULL||b!=NULL)
    {
        sum=carry+(a?a->data:0)+(b?b->data:0);
        carry=(sum>=10)?1:0;
        sum=sum%10;

        ans=create(sum,ans);
        if(a)a=a->next;
        if(b)b=b->next;

    }
    if(carry)
        ans=create(carry,ans);
    return ans;
}
int main()
{
    int n1,n2;
    cin>>n1;
    cin>>n2;
    node* head1=NULL;
    node* head2=NULL;
    for(int i=0;i<n1;i++)
    {
        int a;
        cin>>a;
        head1=create(a,head1);
    }
    cout<<"second:\n";
    for(int i=0;i<n2;i++)
    {
        int a;
        cin>>a;
        head2=create(a,head2);
    }
    node* ans=NULL;
    ans=add(head1,head2);
    node* temp1=ans;
    while(temp1)
    {

        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
    cout<<"\n";
    return 0;


}
