#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next = NULL;
    }
};


void midOfLL(Node *head)
{
    if(head == NULL)
        return;
    Node *curr;int count = 0;
    for(curr = head; curr != NULL; curr = curr->next)
    {
        count++;
    }
    curr = head;
    for(int i=0; i<count/2; i++)
        curr = curr->next;
    cout<<curr->data<<endl;
}

Node *insertAtEndLL(Node *head, int data)
{
    Node *temp = new Node(data);
    if(head==NULL)
        return temp;
    Node *curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
void printLL(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    Node *head = new Node(10);
    head = insertAtEndLL(head, 20);
    head = insertAtEndLL(head, 30);
    head = insertAtEndLL(head, 40);
    head = insertAtEndLL(head, 50);
    printLL(head);
    cout<<"\nMiddle of above linked list is: \n";
    midOfLL(head);
    return 0;
}
