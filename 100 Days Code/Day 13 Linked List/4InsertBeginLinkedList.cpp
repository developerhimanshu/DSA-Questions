#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *insertBegin(struct Node *head, int data)  //Time complexity of this function is O(1)
{
    struct Node *temp = new Node(data);
    temp->next=head;
    return temp;
}

void printLL(struct Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
    struct Node *head = NULL;
    head = insertBegin(head, 10);
    head = insertBegin(head, 20);
    head = insertBegin(head, 30);

    printLL(head);
    return 0;
}