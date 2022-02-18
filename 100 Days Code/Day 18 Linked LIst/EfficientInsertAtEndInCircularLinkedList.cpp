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

Node *insertEnd(Node *head, int data)
{
    Node *newNode = new Node(data);
    if(head == NULL)
    {
        newNode->next=newNode;
        return newNode;
    }
    else
    {
        newNode->next = head->next;  //Firstly Insert node between head Node and its next Node
        head->next = newNode;
        int x = head->data;     // Then swap the head node and the inserted node's data
        head->data = newNode->data;
        newNode->data = x;

        return newNode; //  Then the newNode will be returned as head
    }
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
    cout<<"Before Inserting at end: "<<endl;
    printList(head);
    head=insertEnd(head, 15);
    cout<<"\nAfter Inserting at end: "<<endl;
    printList(head);
    return 0;
}
