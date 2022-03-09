#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int size, cap, front;
    int *arr;
    Queue(int c)
    {
        cap = c;
        front = 0;
        size = 0;
        arr = new int[cap];
    }
    bool isFull()
    {
        return (size == cap);
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    int getFront()
    {
        if (isEmpty())
            return -1;
        return front;
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        int rear = (size + front - 1) % cap;
        return rear;
    }

    void enqueue(int x)
    {
        if (isFull())
            return;
        int rear = getRear();
        rear = (rear + 1) % cap;
        arr[rear] = x;
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
            return;
        front = (front + 1) % cap;
        size--;
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
