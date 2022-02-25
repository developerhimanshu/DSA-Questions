#include <iostream>
#include <unordered_set>
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
  Node *slow = head, *fast = head;
  while(fast != NULL && fast->next != NULL)
  {
      slow = slow->next;
      fast = fast->next->next;
      if(slow == fast)
      {
          return true;
      }
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
