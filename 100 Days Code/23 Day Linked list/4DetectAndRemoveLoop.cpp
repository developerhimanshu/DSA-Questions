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


void detectRemoveLoop(Node* head) 
{
   Node *slow = head, *fast = head;
   while(fast != NULL && fast->next != NULL)  //Loop Detection
   {
      slow = slow->next;
      fast = fast->next->next;
      if(slow == fast)
      {
          break;
      }
   }
    if(slow != fast)
        return;
    slow = head;
    while(slow->next != fast->next) //Loop Removal
    {
        slow=slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}
int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next = new Node(40);
    head->next->next = head->next;
    detectRemoveLoop(head);
    return 0;
}
