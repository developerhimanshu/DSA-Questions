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


bool checkLoop(Node * head)
{
    Node *temp = new Node(1);
    Node *curr = head;
    
    while(curr != NULL)
    {
        if(curr == NULL)
            return false;
        if(curr == temp)
            return true;
        Node *currnxt = curr->next;
        curr->next = temp;
        curr = currnxt;
    }
    return false;
}
int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next = new Node(40);
    head->next->next = head->next;

    if(checkLoop(head))
    {
        cout<<"Yeah! its a loop"<<endl;
    }
    else
        cout<<"Its not a loop"<<endl;
    return 0;
}
