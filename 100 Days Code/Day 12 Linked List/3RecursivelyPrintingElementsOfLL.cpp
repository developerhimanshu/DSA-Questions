#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
void printLL(struct Node* head)
{
    if(head==NULL)return ;
    cout<<head->data<<" ";
    printLL(head->next);
}
int main()
{
    struct Node *head=new struct Node(10);
    head->next=new struct Node(20);
    head->next->next=new struct Node(30);
    printLL(head);

    return 0;
}