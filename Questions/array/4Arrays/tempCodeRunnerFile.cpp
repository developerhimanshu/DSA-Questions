bool arr_sort(int arr[], int size)
{
    for(int i=1;i<size; i++)
    {
        if(arr[i]<arr[i-1])
            return false;
    }
    return true;
}