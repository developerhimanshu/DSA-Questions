#include <iostream>
using namespace std;

void ArrRight(int arr[], int n, int k)
{
    for(int i=0; i<k; i++)
    {
        int last,j;
        last=arr[n-1];
        for(int j=n-2; j>=0; j--)
        {
            arr[j+1]=arr[j];
        }
        arr[0]=last;
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={11, 22, 33, 44, 55};
    ArrRight(arr, 5, 2);

    return 0;
}