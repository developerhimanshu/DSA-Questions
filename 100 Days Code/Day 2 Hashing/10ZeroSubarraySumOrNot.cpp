#include <iostream>
#include <unordered_set>

using namespace std;

bool ZeroSubarraySum(int a[],int n)
{
    int prf_sm=0;
    unordered_set<int>s;
    for(int i=0; i<n; i++)
    {
        prf_sm+=a[i];
        if(s.find(prf_sm)!=s.end())
        {
            return true;
        }
        if(prf_sm==0)return true;
        s.insert(prf_sm);
    }
    return false;
}
int main()
{
    int a[]={13, 12 , -11, -1};
    cout<<ZeroSubarraySum(a, 4);
    return 0;
}