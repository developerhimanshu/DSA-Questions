#include <bits/stdc++.h>

using namespace std;

int lar_idx(int a[], int n )
{
    int largest=0;
    for(int i=1; i<n;i++)
    {
        if(a[i]>a[largest])
        {
            largest=i;
        }
    }
    return largest;
}

int sec_largest(int a[], int n)
{
    int largest=lar_idx(a, n);
    int res=-1;

    for(int i=0; i<n; i++)
    {
        if(a[i]!=a[largest])
        {
            if(res==-1)
                res=i;
            else if(a[i]>a[res])
            {
                res=i;
            }
        }
    }
        return res;

}
int main()
{
    int arr[5]={10, 10 ,10};
    cout<<sec_largest(arr, 5);

    return 0;
}