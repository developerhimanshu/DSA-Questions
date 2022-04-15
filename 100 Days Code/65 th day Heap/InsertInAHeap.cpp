#include <bits/stdc++.h>
using namespace std;

class minHeap{
    int size;
    int cap;
    int *arr;
    public:
    minHeap(int c)
    {
        cap = c;
    }
    int leftChild(int i){return 2*i+1;}
    int rightChild(int i){return 2*i+2;}
    int parent(int i){return (i-1)/2;}

    void insert(int x)
    {
        if(size == cap)
            return;
        size++;
        arr[size-1]=x;
        for(int i=size-1;i!=0&&arr[parent(i)]>arr[i];)
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }
};

int main()
{
    minHeap h(11);
    h.insert(3); 
    h.insert(2);
    h.insert(15);
    h.insert(20);
    return 0;
    return 0;
}
