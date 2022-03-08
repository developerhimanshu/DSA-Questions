//this solution works only on positive numbers

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

struct Mystack{
    Mstack st;
    int min;

    void push(int x)
    {
        if(st.isEmpty())
        {
            min = x;
            st.push(x);
        }
        else if(x<=min)
        {
            st.push(x-min);
            min = x;
        }
        else
        {
            st.push(x);
        }
    }
    int pop()
    {
       int t = st.top(); st.pop();
        if(t<=0)
        {
            int res = min;
            min = min - t;
            return res;
        }
        else
            return t;
    }

    int getmin()
    {
        return min;
    }
};

int main()
{
    Mystack s;
    s.push(4);
    s.push(5);
    s.push(8);
    s.push(1);
    s.pop();
 
    cout<<" Minimum Element from Stack: " <<s.getmin();
  
    return 0; 
}
