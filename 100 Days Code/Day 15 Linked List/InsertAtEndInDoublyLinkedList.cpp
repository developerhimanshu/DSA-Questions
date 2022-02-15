#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node*prev;

    Node(int x)
    {
        data=x;
        next=prev=NULL;
    }
};

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

    printList(head);
    return 0;
}
