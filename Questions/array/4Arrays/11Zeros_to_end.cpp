#include <bits/stdc++.h>
using namespace std;
void remzero_to_end(int arr[], int n)
{
    for(int i=0; i<n ;i++)
    {
        if(arr[i]==0)
        {
            for(int j=i; j<n; j++)
            {
                arr[j]=arr[j+1];
            }
            arr[n-1]=0;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n; i++)
    {
        cin>>arr[i];
    }
    remzero_to_end(arr, n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}