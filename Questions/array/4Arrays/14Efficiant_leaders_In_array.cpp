#include <iostream>
using namespace std;

void Leaders(int arr[], int n)
{
    int curr_leader=arr[n-1];
    cout<<curr_leader<<" ";
    for(int i=n-2; i>=0; i--)
    {
        if(curr_leader<arr[i])
        {
            curr_leader=arr[i];
            cout<<curr_leader<<" ";
        }
    }
}
int main()
{
    int arr[]={52, 11, 54, 8, 13};
    Leaders(arr, 5);


    return 0;
}