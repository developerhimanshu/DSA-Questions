#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next, *prev;
    Node(int x)
    {
        data=x;
        next=prev=NULL;
    }
};

Node *insertEnd(Node* head, int data)
{
    Node *temp = new Node(data);
    if(head == NULL)
        return temp;
    Node* curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    temp->prev=curr;
    curr->next=temp;

    return head;
}


Node* deleteLastNode(Node *head)
{
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    Node *curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->prev->next=NULL;
    delete curr;
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
    head=insertEnd(head, 10);
    head=insertEnd(head, 20);
    head=insertEnd(head, 30);
    head=insertEnd(head, 40);
    cout<<"Before deleting last Node: ";
    printList(head);

    head=deleteLastNode(head);
    cout<<"\nAfter deleting last Node: ";
    printList(head);
    return 0;
}
