#include <iostream>
#include <climits>
using namespace std;


struct Node {   //Creating a linked list Node
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct MyStack{
    Node *head;  //because we are using linked list insted of array
    int sz;
    MyStack()
    {
        head = NULL;
        sz = 0;
    }

    void push(int x)
    {
        Node *temp = new Node(x);
        temp ->next = head;
        head = temp;
        sz++;
    }
    int pop()
    {
        if(head == NULL)
            return INT_MIN;
        int res = head->data;
        Node *temp = head;
        head = head->next;
        delete(temp);
        sz--;
        return res;
    }
    int size()
    {
        return sz;
    }
    bool isEmpty()
    {
        return head==NULL;
    }
    int peek()
    {
        return head->data;
    }
};
int main()
{
    MyStack m;
    m.push(10);
    m.push(30);
    m.push(20);
    cout<<m.peek()<<endl;
    cout<<m.size()<<endl;
    m.pop();
    cout<<m.peek()<<endl;
    cout<<m.size()<<endl;
    

    return 0;
}
