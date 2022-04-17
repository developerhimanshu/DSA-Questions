#include <bits/stdc++.h>
using namespace std;

class Heap
{
    int *arr;
    int size;
    int capacity;

public:
    Heap(int c)
    {
        capacity = c;
        size = 0;
        arr = new int[c];
    }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }

    void insert(int x)
    {
        if (size == capacity)
            return;
        arr[size] = x;
        size++;
        for (int i = size - 1; i >= 0 && arr[i] < arr[(parent(i))];)
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void minHeapify(int i)
    {
        int minimum = i;
        int lc = left(i);
        int rc = right(i);
        if (lc < size && arr[lc] < arr[i])
            minimum = lc;
        if (rc < size && arr[rc] < arr[minimum])
            minimum = rc;
        if (i != minimum)
        {
            swap(arr[minimum], arr[i]);
            minHeapify(minimum);
        }
    }
    int extractMin()
    {
        if (size == 0)
            return INT_MAX;
        if (size == 1)
        {
            size--;
            return arr[size];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        minHeapify(0);
        return arr[size];
    }
    void decreaseKey(int i, int k)
    {
        arr[i] = k;
        while (i != 0 && arr[i] < arr[parent(i)])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
};
int main()
{
    Heap h(11);
    h.insert(3); 
    h.insert(2);
    h.deleteKey(0);
    h.insert(15);
    h.insert(20);
    cout << h.extractMin() << endl;
    h.decreaseKey(2, 1);
    cout << h.extractMin() << endl;
    return 0;
}
