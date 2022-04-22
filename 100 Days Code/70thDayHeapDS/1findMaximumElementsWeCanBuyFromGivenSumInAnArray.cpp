// method 1- Using Sorting
#include <bits/stdc++.h>
using namespace std;

int findMaxItems(int arr[], int n, int sum)
{
    sort(arr, arr+n);
    int res = 0;
    for(int i=0 ;i<n; i++)
    {
        if(arr[i]<sum)
        {
            sum = sum-arr[i];
            res ++;
        }
        else
        {
            break;
        }
    }
    return res;
}
int main()
{
    int n=5;
    int cost[n]={1,12,5,111,200};
    int sum=10;
    
    cout<<"The Number Of maximum elements we can find from the given sum is: "<<findMaxItems(cost, n, sum)<<endl;
    return 0;
}
