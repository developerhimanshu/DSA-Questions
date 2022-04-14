#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    int *arr;
    int capacity;
    int size;

public:
    MinHeap(int c)
    {
        capacity = c;
    }
    int leftChild(int i) { return (2 * i + 1); }
    int rightChild(int i) { return (2 * i + 2); }
    int parent(int i) { return (i + 1) / 2; }
};
int main()
{
    MinHeap h(11);
    return 0;
    return 0;
}
