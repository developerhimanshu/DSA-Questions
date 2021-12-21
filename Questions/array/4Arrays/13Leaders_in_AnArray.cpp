#include <iostream>

using namespace std;

void leadersInArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        bool flag=true;
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]<=arr[j])
            {
                flag=false;
                break; 
            }
        }
        if (flag==true)
            cout<<arr[i]<<" ";
    }

}
int main()
{
    int arr[]={11, 4, 6,11, 3, 1};
    leadersInArray(arr, 5);
    return 0;
}