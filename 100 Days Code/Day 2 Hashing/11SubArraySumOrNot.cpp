#include <iostream>
#include <unordered_set>

using namespace std;

bool CheckSubArrSum(int a[], int n, int sum)
{
    int prefix_sum=0;
    unordered_set<int>s;
    for(int i=0; i<n; i++)
    {
        prefix_sum+=a[i];
        if(prefix_sum==sum)return true;
        if(s.find(prefix_sum-sum)!=s.end())
        {
            return true;
        }
        s.insert(prefix_sum);
    }
    return false;
}
int main()
{
    int a[]={10, 22, 11, 1,2 ,3 };
    cout<<CheckSubArrSum(a, 6, 112);
    return 0;
}