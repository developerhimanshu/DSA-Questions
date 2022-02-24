#include <bits/stdc++.h>
using namespace std;


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

Node * RevInGroup(Node *head, int k)
{
    Node *curr = head, *prev = NULL, *nxt = NULL;
    int count = 0;
    while(curr != NULL && count < k)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }
    if(nxt != NULL)
    {
        Node *restHead = RevInGroup(nxt, k);
        head -> next = restHead;  //It will connect the recursively reverse LL and head
    }
    return prev;
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
    head = RevInGroup(head, 2);
    printLL(head);
    return 0;
}
