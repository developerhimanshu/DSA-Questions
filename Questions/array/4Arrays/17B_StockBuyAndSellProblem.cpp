#include <bits/stdc++.h>

using namespace std;
int max_profit(int arr[], int n)
{
    int profit=0; 
    for(int i=1; i<n; i++)
    {
        if(arr[i]>arr[i-1])
        {
            profit=profit+(arr[i]-arr[i-1]);
        }
    }
    return profit;

}
int main()
{
    int prices[]={1, 5, 3, 7, 4, 9, 2};
    cout<<max_profit(prices, 7);
    return 0;
}