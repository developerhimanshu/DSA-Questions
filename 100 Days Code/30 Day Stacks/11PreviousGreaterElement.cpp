#include <bits/stdc++.h>
using namespace std;

void previousGreater(int *arr, int n)
{
    stack<int>s;
    s.push(arr[0]);
    cout<<-1<<" ";
    for(int i=1; i<n; i++)
    {
        while(s.empty()==false && s.top()<arr[i])
            s.pop();
        int greater = s.empty()?-1:s.top();
        cout<<greater<<" ";
        s.push(arr[i]);

    }
}
int main()
{
    int arr[]={15, 10, 18, 12, 4, 6, 2, 8};
    int size = sizeof(arr)/sizeof(arr[0]);
    previousGreater(arr, size);
    return 0;
}