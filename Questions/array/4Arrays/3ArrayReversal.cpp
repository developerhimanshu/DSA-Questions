#include <bits/stdc++.h>
using namespace std;

void arrRev(int arr[], int n)
{
    for(int i=0; i<n/2; i++)
    {
        int temp= arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={11, 22, 33, 44, 55};
    arrRev(arr, 5);
    return 0;
}