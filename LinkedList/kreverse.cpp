#include<iostream>
using namespace std;
struct node
  {
     int data;
     struct Node *next;
  }
struct node* rev(node* head)
{

    if(head->next==NULL)
        return head;
    node* temp=head;
    node* temp1=rev(head->next);
    temp->next->next=temp;
    temp->next=NULL;
    return temp1;

}
struct node *reverse (struct node *head, int k)
{
  // Complete this method
  if(head==NULL)
    return NULL;

    struct node* temp=head;
    for(int i=0;i<k-1;i++)
    {
        if(temp->next)
        {
            temp=temp->next;
        }
        else
        {
            break;
        }
    }
    struct node* x=temp->next;
    temp->next=NULL;
    struct node* kt=head;
    head=rev(head);
    kt->next=reverse(x,k);
    return head;
}
int main()
{
  //call the above method here ...first create a linked list ..

}
