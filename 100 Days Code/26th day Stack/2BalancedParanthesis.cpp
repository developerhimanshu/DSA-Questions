#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct MyStack
{
    Node *head;
    int sz;
    MyStack()
    {
        head = NULL;
        sz = 0;
    }
    void push(int d)
    {
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
        sz++;
    }
    int pop()
    {
        if (head == NULL)
            return INT_MAX;
        Node *temp = head;
        int res = head->data;
        head = head->next;
        delete (temp);
        sz--;
        return res;
    }
    int top()
    {
        return head->data;
    }
    int size()
    {
        return sz;
    }
    bool isEmpty()
    {
        return (head == NULL);
    }
};

bool matching(char a, char b)
{
    return ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'));
}
bool balancedParanthesis(string str)
{
    MyStack s;
    int i = 0;
    for (char x : str)
    {
        if (x == '(' || x == '{' || x == '[')
            s.push(x);
        else
        {
            if(s.isEmpty() == true)
                return false;
            if(matching(s.top(), x)==false)
            {
                return false;
            }
            else
                s.pop();
        }
    }
    return (s.isEmpty()==true);
}
int main()
{
    string str = "{{(())}}]";
    cout << balancedParanthesis(str);
    return 0;
}
