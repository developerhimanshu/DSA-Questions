#include <iostream>
using namespace std;

struct MyStack{
int capacity;
int *arr;
int top;
MyStack(int x)
{
    capacity = x;
    arr = new int[x];
    top = -1;
}

void push(int ele)
    {
        if(top ==capacity-1){cout<<"Stack is full\n";return;}
        top++;
        arr[top]= ele;
    }
    int pop()
    {
        if(top == -1){cout<<"Stack is Empty\n"; return-1;}
        int res = arr[top];
        top--;
        return res;
    }
    int peek()
    {
        if(top==-1){cout<<"Stack is empty\n";return-1;}
        return arr[top];
    }
    bool isEmpty()
    {
        return top==-1;
    }
    int size()
    {
        return top+1;
    }

};
int main()
{
    MyStack s(5);
    s.pop();
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    cout<<"size of stack is: "<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}
