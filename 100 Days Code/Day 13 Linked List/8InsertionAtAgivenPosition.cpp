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


struct Node*insertAtpos(struct Node* head, int data, int pos)
{
    struct Node* temp=new Node(data);
    if(pos==1)
    {
        temp->next=head;
        return temp;
    }
    
    struct Node*curr=head;
    for(int i=1; i<=pos-2&&curr!=NULL; i++)
    {
        curr=curr->next;
    }
    if(curr==NULL)
        return 0;
    temp->next=curr->next;
    curr->next=temp;

    return head;
}
int main()
{
    struct Node *head = NULL;
    head = insertBegin(head, 10);
    head = insertBegin(head, 20);
    head = insertBegin(head, 30);
    head = insertAtpos(head, 12, 2);

    printLL(head);
    return 0;
}