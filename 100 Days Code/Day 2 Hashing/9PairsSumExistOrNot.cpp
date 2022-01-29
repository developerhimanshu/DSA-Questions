#include <iostream>
#include <unordered_set>
using namespace std;

bool pairSumExist(int a[], int n, int key)
{
    unordered_set<int>s;
    for(int i=0; i<n ;i++)
    {
        if(s.find(key-a[i])!=s.end())
        {
            return true;
        }
        s.insert(a[i]);
    }
    return false;
}
int main()
{
    int a[]={1, 3, 5, 9, 4};
    cout<<pairSumExist(a, 5, 13)<<endl;
    cout<<pairSumExist(a, 5, 112)<<endl;
    cout<<pairSumExist(a, 5, 14)<<endl;

    return 0;
}