#include <bits/stdc++.h>
using namespace std;

void printQueue(queue <int>q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}


void ReverseAQueue(queue<int> &q)  //This is recursive function is also using stack it's a function call stack
{
    if(q.empty())
    {
        return;
    }
    int x = q.front();
    q.pop();
    ReverseAQueue(q);
    q.push(x);
}


int main()
{
    queue<int>q;
    q.push(12);
    q.push(10);
    q.push(11);
    q.push(13);
    cout<<"Before Reversing:\n";
    printQueue(q);
    ReverseAQueue(q);
    cout<<"\nAfter Reversing:\n";
    printQueue(q);
    return 0;
}
