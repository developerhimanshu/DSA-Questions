#include <bits/stdc++.h>
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
struct Mstack{
    Node *head;
    int sz;
    Mstack()
    {
        head = NULL;
        sz = 0;
    }

    void push(int x)
    {
        Node* temp = new Node(x);
        temp->next = head;
        head= temp;
        sz++;
    }

    int pop()
    {
        Node *temp = head;
        int res = head->data;
        head = head->next;
        delete(temp);
        sz--;
        return res;
    }

    bool isEmpty()
    {
        return head == NULL;
    }
    int top()
    {
        if(isEmpty()==false)
        {
            return head->data;
        }
        else
            return -1;
    }
};

struct MyStack{
    Mstack ms;
    Mstack as;
    void push(int x)
    {
        if(ms.isEmpty())
        {
            ms.push(x);
            as.push(x); return;
        }
        ms.push(x);
        if(ms.top()<= as.top())
            as.push(x);
    }

    void pop()
    {
        if(as.top()== ms.top())
            as.pop();
        ms.pop();
    }

    int top()
    {
        return ms.top();
    }

    int getmin()
    {
        return as.top();
    }
};

int main()
{
    MyStack s;
    s.push(4);
    s.push(5);
    s.push(8);
    s.push(1);
    s.pop();
 
    cout<<" Minimum Element from Stack: " <<s.getmin();
  
    return 0; 
    

    return 0;
}
