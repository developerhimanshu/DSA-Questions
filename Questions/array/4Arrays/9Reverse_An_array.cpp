#include <bits/stdc++.h>

using namespace std;
void reverseArray(int arr[], int n)
{
    int low=0, high=n-1;
    while(low<high)
    {
        int temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;
        high--;
        low++;
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<",";
    }
}
int main()
{
    int arr[5]={11, 22, 33, 44, 55};
    reverseArray(arr, 5);
    return 0;
}