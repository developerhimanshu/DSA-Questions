#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
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

void printLL(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *reverseLL(Node *head)
{
    vector<int>v;
    Node * curr= head;
    while(curr != NULL)
    {
        v.push_back(curr->data);
        curr = curr->next;
    }
    curr = head;
    while(curr != NULL)
    {
        curr -> data = v.back();
        v.pop_back();
        curr = curr->next;
    }
    return head;
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
    head = reverseLL(head);
    printLL(head);
    return 0;
}
