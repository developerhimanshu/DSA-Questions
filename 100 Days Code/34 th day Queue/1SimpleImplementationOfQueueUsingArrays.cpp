#include <bits/stdc++.h>
using namespace std;

struct Queue{
    int cap, size;
    int *arr;
    Queue(int x)
    {
        cap = x;
        size = 0;
        arr = new int[cap];
    }

    bool isEmpty()
    {
        return (size == 0);
    }
    bool isFull()
    {
        return (size==cap);
    }
    void enqueue(int x)
    {
        if(isFull())
        {
            cout<<"Memory Overflow\n";
            return;
        }
        arr[size] = x;
        size++;
    }
    void dequeue() //O(n)
    {
        if(isEmpty())
        {
            cout<<"Memory Underflow\n";
            return;
        }
        for(int i=0; i<size-1; i++)
        {
            arr[i] = arr[i+1];
        }
        size--;
    }

    int getFront()
    {
        if(!isEmpty())
            return arr[0];
        return -1;
    }
    int getRear()
    {
        if(!isEmpty())
            return arr[size-1];
        return -1;
    }
};
int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout << q.getFront()<<endl;
    cout<<q.size<<endl;
    q.dequeue();
    cout << q.getFront()<<endl;
    cout<<q.size<<endl;
    q.dequeue();
    cout << q.getFront()<<endl;
    cout<<q.size<<endl;
    return 0;
}
