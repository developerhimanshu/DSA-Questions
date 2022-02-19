#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *sortedInsertLL(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
        return temp;
    if (x < head->data)
    {
        temp->next = head;
        return temp;
    }

    Node *curr = head;
    while(curr->next != NULL && curr->next->data < x)
        curr = curr->next;
    temp->next = curr->next;
    curr->next = temp;

    return head;
}

void printLL(Node *head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head= head->next;
    
    }
}
int main()
{
    Node * head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    cout<<"Before Inserting: ";
    printLL(head);
    head = sortedInsertLL(head, 35);
    cout<<"\nAfter Inserting: ";
    printLL(head);

    return 0;
}
