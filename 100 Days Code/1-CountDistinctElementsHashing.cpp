#include <iostream>
#include <unordered_set>
using namespace std;

int countDistinctEle(int arr[], int n)
{
    unordered_set<int>s;
    for(int i=0; i<n; i++)
    {
        s.insert(arr[i]);
    }
    return s.size();
}
int main()
{
    int arr[]={12, 43, 23, 12, 43, 23};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<countDistinctEle(arr, size);
    return 0;
}
