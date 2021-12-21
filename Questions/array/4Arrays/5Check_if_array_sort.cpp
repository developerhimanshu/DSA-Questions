#include <iostream>

using namespace std;
bool arr_sort(int arr[], int size)
{
    for(int i=1;i<size; i++)
    {
        if(arr[i]<arr[i-1])
            return false;
    }
    return true;
}


int main()
{

    int arr[5]={10, 20 , 30, 40,50};
    cout<<arr_sort(arr, 5);
    if(arr_sort(arr, 5))
        cout<<"Array is sorted "<<endl;
    else 
        cout<<"Array is not sorted"<<endl;
  

}