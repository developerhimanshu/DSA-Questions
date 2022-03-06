#include <bits/stdc++.h>
using namespace std;

int largeAreaHisto(int arr[], int n)
{
    stack<int>s;
    int res = 0;
    int tp;
    int curr;
    for(int i=0; i<n; i++)
    {
        while(s.empty()==false && arr[i]<=arr[s.top()])
        {
            tp =s.top(); 
            s.pop();
            curr = arr[i]*(s.empty()?i:(i-s.top()-1));
            res = max (curr, res);
        }
        s.push(i);
    }
    while(s.empty()==false)
    {
        tp = s.top(); s.pop();
        curr = arr[tp]*(s.empty()?n:(n-s.top()-1));
        res = max(curr, res);
    }
    return res;
}

int main() 
{ 
    int arr[]={6,2,5,4,1,5,6};
    int n=7;
    cout<<"Maximum Area: "<<largeAreaHisto(arr,n);
    return 0; 
}
