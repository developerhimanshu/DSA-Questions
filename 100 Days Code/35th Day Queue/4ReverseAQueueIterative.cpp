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
void ReverseAQueue(queue<int> &q)
{
    stack<int>s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
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
