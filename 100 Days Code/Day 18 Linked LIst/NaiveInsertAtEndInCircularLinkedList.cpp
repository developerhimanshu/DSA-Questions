#include <iostream>
using namespace std;


struct Node{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *insertEnd(Node *head, int data)
{
    Node *newNode = new Node(data);
    if(head==NULL)
    {
        newNode->next=newNode;
        return newNode;
    }
    else
    {
        Node *curr = head;

        while(curr->next != head)
        {
            curr=curr->next;
        }
        curr->next=newNode;
        newNode->next=head;
        return head;
    }
}

void printCircuLL(Node *head)
{
    if(head==NULL)
    {
        return;
    }
    else{
        Node *p = head;
        do{
            cout<<p->data<<" ";
            p=p->next;
        }while(p!=head);
    }
}
int main()
{
    Node*head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=head;
    cout<<"Before Inserting at end: "<<endl;
    printCircuLL(head);
    head=insertEnd(head, 15);
    cout<<"\nAfter Inserting at end: "<<endl;
    printCircuLL(head);
    return 0;
}
