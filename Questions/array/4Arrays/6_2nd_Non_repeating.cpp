#include <bits/stdc++.h>
using namespace std;
void sec_non_rep(int arr[], int n)
{
    int c, d=0;
    
    for(int i=0; i<n;i++)
    {
        c=0;
        for(int j=0; j< n; j++)
        {
            if(i!=j&&arr[i]==arr[j])
            {
                c++;
            }
        }
        if(c==0)
        {
            d++;
        }
        if(d==2)
        {
            cout<<"The second non repeating element is "<<arr[i];
        }
    }
}
int main()
{
    int arr[]={12, 12, 5, 6};
    sec_non_rep(arr, 4);
    return 0;
}