// method 2 - Using heap data Structure
#include <bits/stdc++.h>
using namespace std;

int maximumItems(int arr[], int n, int sum)
{
    priority_queue<int, vector<int>, greater<int>>pq;
    int res = 0;
    for(int i=0; i<n; i++)
    {
        pq.push(arr[i]);
    }
    for(int i=0; i<n; i++)
    {
        if(pq.top()<sum)
        {
            sum-=pq.top();
            pq.pop();
            res++;
        }
        else
            break;
    }
    return res;
}
int main()
{
    int n=5;
    int cost[n]={1,12,5,111,200};
    int sum=500;
    
    cout<<"The Number Of maximum elements we can find from the given sum are: "<<maximumItems(cost, n, sum)<<endl;
    return 0;
}
