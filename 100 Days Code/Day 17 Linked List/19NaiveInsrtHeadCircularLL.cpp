#include <iostream>
using namespace std;


struct Node{
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};


void printlist(Node *head){
    if(head==NULL)return;
    Node *p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
}


Node *insertBegin(Node *head, int x)
{
    Node *new_node = new Node(x);
    if(head==NULL)
    {
        new_node->next=new_node;
    }
    else{
        Node *curr = head;
        while(curr->next!=head)
            curr=curr->next;
        curr->next=new_node;
        new_node->next=head;
    }
    return new_node;
}
int main()
{
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=head;
	head=insertBegin(head,15);
	printlist(head);
	return 0;
    return 0;
}