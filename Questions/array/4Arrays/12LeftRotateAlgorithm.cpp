#include <iostream>
using namespace std;

void left_Rotate_by_d(int arr[], int n, int d)
{
    reverse(arr, 0, d-1);//1=> we have to reverse the array from 0 to d-1  d= no. of steps we have to rotate the array left
    reverse(arr, d, n-1);//2=> we have to reverse the array form d to n-1
    reveres(arr, 0, n-1);//3=> we have to reverse the whole array
}
void reverse(int arr[], int low, int high)
{
    while(low<high)
    {
        arr[low]=arr[high];
        low--;
        high++;
    }
}
int main()
{
    int arr[]={11, 22, 33, 44, 55};
    return 0;
}