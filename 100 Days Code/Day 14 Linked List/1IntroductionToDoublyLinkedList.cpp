#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;

    Node(int x)
    {
        data=x;
        prev=NULL;
        next=NULL;
    }
};
int main()
{
    struct Node* head=new Node(10);
    struct Node* temp1=new Node(20);
    struct Node* temp2=new Node(30);

    head->next=temp1;
    temp1->prev=head;
    temp1->next=temp2;
    temp2->prev=temp1;


    return 0;
}
