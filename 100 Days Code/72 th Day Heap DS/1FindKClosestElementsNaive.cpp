#include <bits/stdc++.h>
using namespace std;

void printKClosestNumbers(int arr[], int k,int x,  int n)  //the input parameters of the function are array, no of closest elements, closest number to which element, number of elements in that array
{
    bool visited[n]={false};
    for(int i=0; i<k; i++)
    {
        int min_diff=INT_MAX;
        int min_diff_idx;
        for(int j=0; j<n; j++)
        {
            if(visited[j]==false&&abs(arr[j]-x)<=min_diff)
            {
                min_diff=abs(arr[j]-x);
                min_diff_idx=j;
            }
        }
            cout<<arr[min_diff_idx]<<" ";
            visited[min_diff_idx]=true;
    }
}
int main()
{
    int arr[]={23, 11, 56, 43, 10};
    int size=sizeof(arr)/sizeof(arr[0]);
    printKClosestNumbers(arr, 3, 12, size);
    return 0;
}
