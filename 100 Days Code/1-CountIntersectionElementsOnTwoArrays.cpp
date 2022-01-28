#include <iostream>
using namespace std;


void frequency(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        bool flag=false;
        for(int j=0; j<i; j++)
        {
            if(arr[i]==arr[j])
                flag=true;
        }
        if(flag==true)
            continue;
        int freq=1;
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]==arr[j])
                freq++;
        }
        cout<<arr[i]<<" "<<freq<<endl;
    }
}
int main()
{
    int arr[]={324, 213,324, 123, 213};
    frequency(arr, 5);
    return 0;
}
