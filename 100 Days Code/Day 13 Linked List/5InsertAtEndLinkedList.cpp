#include <iostream>
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

struct Node *insertEnd(struct Node *head, int data)
{
    struct Node *temp = new Node(data);
    if (head == NULL)
        return temp;
    struct Node *point = head;
    while (point->next != NULL)
    {
        point = point->next;
    }
    point->next = temp;
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
    struct Node*head=NULL;
    head=insertEnd(head, 10);
    head=insertEnd(head, 20);
    head=insertEnd(head, 30);
    head=insertEnd(head, 40);
    printLL(head);
    return 0;
}