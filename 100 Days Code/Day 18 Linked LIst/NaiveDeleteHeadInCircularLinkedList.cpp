#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int x)
    {
        data=x;
        next=NULL;  
    }
};

Node *deletehead(Node *head)
{
    if(head==NULL)
        return NULL;
    if(head->next == head)
    {
        delete head;
        return NULL;
    }
    Node *p = head;
    while(p->next != head)
        p=p->next;
    p->next = head->next;
    delete head;
    return p->next;
}


void printList(Node *head)
{
    if(head == NULL)
        return;
    else
    {
        Node *p = head;
        do{
            cout<<p->data<<" ";
            p=p->next;
        }while(p != head);
    }
}
int main()
{
    Node*head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=head;
    cout<<"Before deleting the head: "<<endl;
    printList(head);
    head=deletehead(head);
    cout<<"\nAfter deleting the head: "<<endl;
    printList(head);
    return 0;
}
