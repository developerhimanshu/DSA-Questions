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

Node *insertBegin(Node *head, int x)
{
    Node *newNode = new Node(x);
    if(head==NULL)
    {
        newNode->next=newNode;
        return newNode;
    }
    else
    {
        newNode->next=head->next;
        head->next=newNode;
        int t=head->data;
        head->data=newNode->data;
        newNode->data=t;

        return head;
    }
}

void printlist(Node *head){
    if(head==NULL)return;
    Node *p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
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