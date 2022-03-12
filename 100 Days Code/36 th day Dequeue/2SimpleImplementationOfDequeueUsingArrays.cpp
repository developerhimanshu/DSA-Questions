#include <bits/stdc++.h>
using namespace std;

struct DQ{
    int size, cap;
    int *arr;
    DQ(int c)
    {
        cap = c;
        arr = new int[cap];
        size = 0;
    }
    bool isEmpty()
    {
        return (size==0);
    }

    bool isFull()
    {
        return (size==cap);
    }
    
    int getRear()
    {
        if(isEmpty())return -1;
        return arr[size-1];
    }

    int getFront()
    {
        if(isEmpty())return -1;
        return arr[0];
    }
    void insertRear(int x)
    {
        if(isFull())return;
        arr[size] = x;
        size++;
    }

    void deleteRear()
    {
        if(isEmpty())return;
        size--;
    }

    void insertFront(int x)
    {
        if(isFull())return;
        for(int i= size-1; i>=0;i--)
        {
            arr[i+1] = arr[i];
        }
        arr[0]=x;
        size++;
    }

    void deleteFront()
    {
        if(isEmpty())return;
        for(int i=0;i<size; i++)
        {
            arr[i]=arr[i+1];
        }
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
