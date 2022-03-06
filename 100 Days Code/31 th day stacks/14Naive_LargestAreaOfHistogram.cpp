#include <bits/stdc++.h>
using namespace std;


int largestHistoArea(int *arr, int n)
{
    int area=0,sum;
    for(int i=0; i<n; i++) 
    {
        sum=arr[i];
        for(int j=i-1; j>=0; j--)
        {
            if(arr[i]<=arr[j])
            {
                sum+=arr[i];
            }
            else
                break;
        }
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]<=arr[j])
            {
                sum+=arr[i];
            }
            else 
                break;
        }        
        area = max(sum, area);
    }
    return area;
}
int main()
{
    int arr[]={6,2,5,4,1,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<largestHistoArea(arr, n)<<endl;

    return 0;
}