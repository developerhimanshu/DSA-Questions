#include <iostream>
#include <unordered_map>
using namespace std;

int loSuArrLenWthZeroOne(int arr[], int n)
{
    int res=0;
    int pre_sum=0; 
    unordered_map<int, int>m;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==0)
            arr[i]=-1;
    }
    for(int i=0; i<n; i++)
    {
        pre_sum+=arr[i];
        if(pre_sum==0)
            res=i+1;
        if(m.find(pre_sum)==m.end())
            m.insert({pre_sum, i});
        if(m.find(pre_sum)!=m.end())
        {
            res=max(res, (i-m[pre_sum]));
        }

    }
    return res;
}
int main()
{
    int arr[]={1, 0, 1, 1};
    cout<<loSuArrLenWthZeroOne(arr, 7)<<endl;
    return 0;
}