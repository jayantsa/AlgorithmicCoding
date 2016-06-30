#include<iostream>
#include<stack>
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
bool checkPal(node* &left,node* right)
{
    if(right==NULL)
        return true;

    bool isp=checkPal(left,right->next);
    if(isp==false)
        return false;

    bool isp1=(left->data==right->data);
    left=left->next;
    return isp1;
}
int main()
{
    int n;
    cin>>n;
    node* head=NULL;
    //stack<node*> s;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        head=create(a,head);
    }
    node* temp1=head;
    while(temp1)
    {
        //s.push(temp1);
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
    cout<<"\n";
    node* left=head;
    bool x=checkPal(left,head);
    cout<<x;
    if(x==1)
    {
        cout<<"Palindrome";
    }
    else
    {
        cout<<"NotPalindrome";
    }
    temp1=head;
    while(temp1)
    {
        //s.push(temp1);
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
return 0;

}

