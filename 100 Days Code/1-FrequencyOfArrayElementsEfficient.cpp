#include <iostream>
#include <unordered_map>
using namespace std;

void frequency(int arr[], int n)
{
    unordered_map<int, int>h;

    for(int i=0; i<n; i++)
    {
        h[arr[i]]++;
    }
    for(auto e: h)
    {
        cout<<e.first<<" "<<e.second<<endl;
    }
}

int main()
{
    int arr[]={10, 20, 10, 15, 30};
    frequency(arr, 5);
    return 0;
}
