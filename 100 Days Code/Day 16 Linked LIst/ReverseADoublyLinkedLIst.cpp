#include <iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
    Node *prev;

    Node(int x)
    {
         data=x;
        next=prev=NULL;
    }
};

Node* reverseDll(Node* head)
{
  if(head==NULL||head->next==NULL)
    return head;
  Node* prev=NULL;
  Node*curr=head;

  while(curr!=NULL)
  {
      prev=curr->prev;
      curr->prev=curr->next;
      curr->next=prev;
      curr=curr->prev;
  }
    return prev->prev;
}
Node* insrtAtEnd(Node* head, int data)
{
    Node *temp = new Node(data);
    if(head==NULL)
        return temp;
    Node *curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next=temp;
    temp->prev=curr;

    return head;
}

void printList(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
    Node *head=NULL;
    head=insrtAtEnd(head, 30);
    head=insrtAtEnd(head, 40);
    head=insrtAtEnd(head, 50);
   head =  reverseDll(head);
    printList(head);
    return 0;
}
