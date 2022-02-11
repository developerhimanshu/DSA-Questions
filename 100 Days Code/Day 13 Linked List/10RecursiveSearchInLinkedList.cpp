#include <bits/stdc++.h>
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

struct Node *insertBegin(struct Node *head, int data)  //Time complexity of this function is O(1)
{
    struct Node *temp = new Node(data);
    temp->next=head;
    return temp;
}

int searchInLL(struct Node* head, int key)
{
    if(head==NULL)
        return -1;
    if(head->data==key)
        return 1;
    else
    {
      int  res=searchInLL(head->next, key);
        if(res==-1)return -1;
        return (res+1);
    }

}
void printLL(struct Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
    struct Node *head = NULL;
    head = insertBegin(head, 10);
    head = insertBegin(head, 20);
    head = insertBegin(head, 30);
    cout<<searchInLL(head,10)<<endl;
    cout<<searchInLL(head,1)<<endl;

    printLL(head);
    return 0;
}