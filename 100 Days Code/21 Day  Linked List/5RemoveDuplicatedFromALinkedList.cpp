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

void removeDuplicates(Node *head)
{
    Node * curr = head;
    while(curr!=NULL&&curr->next != NULL) // we are not checking for the NULL exception because this while loop is aleready checking
    {
        if(curr->data == curr->next->data)
        {
            Node *temp = curr->next;
             curr->next = temp->next;
            delete temp;
        }
        curr = curr->next;
    }

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
    head = insertAtEndLL(head, 20);
    head = insertAtEndLL(head, 40);
    head = insertAtEndLL(head, 40);
    printLL(head);
    cout<<endl;
 removeDuplicates(head);
    printLL(head);
    return 0;
}
