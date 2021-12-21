#include <iostream>
using namespace std;

int maxsubarrsum(int arr[], int n)
{
    int res=arr[0];
    for(int i=0; i<n; i++)
    {
        int curr=0;
        for(int j=i; j<n ;j++)
        {
            curr=curr+arr[j];
            res=max(curr, res);
        }
    }
    return res;


}
int main()
{

    int n;
    cout<<"Enter the number of elements of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"The maximum sum of the subsets of the array is: "<<maxsubarrsum(arr, n);
    return 0;
}