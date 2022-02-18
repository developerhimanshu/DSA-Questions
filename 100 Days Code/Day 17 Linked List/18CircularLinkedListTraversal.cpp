#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
/*  Method 1
void crclrTravrse(Node* head)
{
    if(head==NULL)return ;
    cout<<head->data<<" ";
    for(Node* p=head->next; p!=head; p=p->next)
        cout<<p->data<<" ";
}
*/


//Mehtod 2:-
void crclrTraverse(Node* head)
{
    if(head==NULL)return;
    Node *p = head;
    do
    {
        cout<<p->data<<" ";
        p=p->next;  
    } while (p!=head);
    
}

int main()
{
    Node* head=new Node(10);
    head->next=new Node(30);
    head->next->next=new Node(20);
    head->next->next->next=head;

    crclrTraverse(head);
    return 0;
}