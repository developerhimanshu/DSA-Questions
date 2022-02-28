#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *segEvenOdd(Node * head)
{
    Node *eS=NULL, *eE=NULL, *oS=NULL, *oE=NULL;
    for(Node *curr = head; curr != NULL; curr = curr->next)
    {
        if(curr->data %2 == 0)
        {
            if(eS == NULL)
            {
                eS = curr;
                eE = eS;
            }
            else
            {
                eE-> next = curr;
                eE= eE->next;
            }
        }
        else
        {
            if(oS == NULL)
            {
                oS = curr;
                oE = oS;
            }
            else
            {
                oE->next = curr;
                oE = oE->next;
            }
        }
    }
        if(oS == NULL || eS == NULL)
            return head;
        else
        {
            eE->next = oS;
            oE->next = NULL;
            return eS;
        }
    return NULL;
}

void printList(Node *head)
{
    while(head!= NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }cout<<endl;
}
int main()
{
    Node *head=new Node(17);
	head->next=new Node(15);
	head->next->next=new Node(8);
	head->next->next->next=new Node(12);
	head->next->next->next->next=new Node(10);
	head->next->next->next->next->next=new Node(5);
	head->next->next->next->next->next->next=new Node(4);
	printList(head);
    head = segEvenOdd(head);
    printList(head);

    return 0;
}
