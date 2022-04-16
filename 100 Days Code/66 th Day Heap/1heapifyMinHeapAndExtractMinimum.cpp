#include <bits/stdc++.h>
using namespace std;

class Heap{
    int *arr;
    int size;
    int capacity;
    public:
    Heap(int c)
    {
        size=0;
        capacity = c;
        arr = new int[c];
    }
    int left(int i)
    {
        return (2*i+1);
    }
    int right(int i)
    {
        return (2*i+2);
    }
    int parent(int i)
    {return (i-1)/2;}

    void insert(int x)
    {
        if(size==capacity)return;
        size++;
        arr[size-1]=x;

        for(int i=size-1; i!=0 && arr[i]<arr[parent(i)];)
        {
            swap(arr[i], arr[parent(i)]);
            i=parent(i);
        }
    }
    void minheapify(int i)
    {
        int minimum = i;
        int lc = left(i);
        int rc = right(i);
        if(lc<size && arr[lc]<arr[i])
        {
            minimum = lc;
        }
        if(rc<size && arr[rc]<arr[minimum])
            minimum = rc;
        if(minimum != i)
        {
            swap(arr[minimum], arr[i]);
            minheapify(minimum);
        }
    }
    int extractMinimum()
    {
        if(size<=0)
            return INT_MAX;
        if(size==1)
        {
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size-1]);
        size--;
        minheapify(0);
        return arr[size];
    }
};
int main()
{
    Heap h(11);
    h.insert(3); 
    h.insert(2);
    h.insert(15);
    h.insert(20);
    cout << h.extractMinimum() << " ";
    return 0;
}
