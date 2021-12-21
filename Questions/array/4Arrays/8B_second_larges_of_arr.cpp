#include <iostream>
using namespace std;

int seclar(int arr[], int n)
{
    int slar=-1, lar=0;
    for(int i=1;i< n; i++)    
    {
        if(arr[i]>arr[lar])
        {
            slar=lar;
            lar=i;
        }
        else if(arr[i]!=arr[lar])
        {
            if(slar==-1||arr[i]>arr[slar])
            {
                slar=i;
            }
        }
    }
    return slar;
}
int main()
{
    int arr[]={11, 54, 21, 67, 92};
    cout<<arr[seclar(arr, 5)];
    return 0;
}