#include <bits/stdc++.h>

using namespace std;

int main()
{   
    int arr[5]={12, 5, 43, 11, 7};
    int lar=arr[0];
    for(int i=0; i<5-1; i++)
    {
        if(arr[i]>lar)
            lar=arr[i];
    }
    cout<<lar<<endl;

    return 0;
}