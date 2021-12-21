#include <iostream>
using namespace std;

int Max_possible_diff(int arr[], int n)
{
    int max_dif=arr[1]-arr[0];
    for(int i=0; i<n-1; i++)
    {
        // int max_dif=arr[i]-arr[i+1];
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]-arr[i]>max_dif)
            {
                max_dif=arr[j]-arr[i];
            }
        }
    }
    return max_dif;

}
int main()
{
    int arr[]={2, 3, 10, 6, 4, 5};
    cout<<(Max_possible_diff(arr, 6));

    return 0;
}