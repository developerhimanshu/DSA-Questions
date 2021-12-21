#include <iostream>
using namespace std;

int rem_dup(int arr[], int n)
{
    int res=1;
    for(int i=1; i<n ;i++)
    {
        if(arr[i]!=arr[res-1])/*10 10 20 20 30
      i=1; arr[1]==arr[0]  10 10 20 20 30 
      i=2; arr[2]!=arr[0] r=2  10 20 20 20 30
      i=3; arr[3]!=arr[1] 
      i=4; arr[4]!=arr[1] r=3 10 20 30 20 20
        */   
        {
            arr[res]=arr[i];
            res++;
        }
    }
    return res;
}
 int main()
{
    int arr[]={10 ,10,20, 20, 30};
    int n=rem_dup(arr, 5);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<",";
    }

    return 0;
}