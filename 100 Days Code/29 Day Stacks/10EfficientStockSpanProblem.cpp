#include <bits/stdc++.h>
using namespace std;

void stockSpan(int *arr, int n)
{
    stack<int>s;
    s.push(0);
    cout<<1<<" ";
    for(int i=1; i<n; i++)
    {
        while(s.empty()==false && arr[s.top()]<=arr[i])
            s.pop();
        int span = s.empty()?i+1:i-s.top();
        cout<<span<<" ";
        s.push(i);
    }
}
int main()
{
    int arr[]={5, 23, 45, 12, 9, 90};
    int size= sizeof(arr)/sizeof(arr[0]);
    stockSpan(arr, size);
    return 0;

}