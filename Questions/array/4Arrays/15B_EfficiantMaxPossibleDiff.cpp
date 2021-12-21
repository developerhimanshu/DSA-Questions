#include <iostream>

using namespace std;
int minpossiblediff(int arr[], int n)
{
    int res=arr[1]-arr[0], minval=arr[0];
    for(int j=1; j<n; j++)  //time complexity= O(n)
    {
        res=max(res, arr[j]-minval);
        minval=min(minval, arr[j]);
    }
    return res;
}
int main()
{
    int arr[]={10, 8, 6, 2, 15, 9, 1};
    cout<<minpossiblediff(arr, 7);
    return 0;
}