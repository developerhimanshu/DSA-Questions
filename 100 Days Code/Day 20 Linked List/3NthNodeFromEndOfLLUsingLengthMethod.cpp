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


int nthNodeFromEnd(Node *head, int n)
{
    if(head == NULL)
        return -1;
    Node *curr; int count = 0;
    for(curr = head; curr != NULL; curr = curr->next)
        count++;
    curr = head;
    for(int i=0; i<count-n; i++)
    {
        curr = curr->next;
    }
    return curr->data;
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
    cout<<endl;
    int n;
    cin>>n;
    cout<<n<<"th node form the end of the linked list is: \n";

   cout<< nthNodeFromEnd(head, n);
    return 0;
}
