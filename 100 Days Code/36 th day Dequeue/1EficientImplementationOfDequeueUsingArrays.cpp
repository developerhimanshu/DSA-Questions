#include <bits/stdc++.h>
using namespace std;

struct DQ{
    int cap, size, front;
    int *arr;
    DQ(int c)
    {
        cap = c;
        size = 0;
        front = 0;
        arr = new int[cap];
    }

    bool isFull()
    {
        return (size==cap);
    }
    bool isEmpty()
    {
        return (size==0);
    }
    
    int getFront()
    {
        if(isEmpty())return -1;
        return arr[front];
    }

    int getRear()
    {
        if(isEmpty())return -1;
        return arr[(front+size-1)%cap];
    }
    void insertFront(int x)
    {
        if(isFull())return;
        front = (front-1+cap)%cap;
        arr[front]=x;
        size++;
    }
    void deleteFront()
    {
        if(isEmpty())return;
        front = (front+1)%cap;
        size--;
    }

    void insertRear(int x)
    {
        if(isFull())return;
        int rear = (front+size)%cap;
        arr[rear]=x;
        size++;
    }

    void deleteRear()
    {
        if(isEmpty())return;
        size--;
    }
};
int main()
{
    DQ dq(5);
    dq.insertFront(10);
    dq.insertFront(11);
    dq.insertFront(12);
    dq.insertRear(34);
    dq.insertRear(35);
    dq.insertRear(36);
    cout<<dq.getFront()<<endl;
    cout<<dq.getRear()<<endl;
    return 0;
}
