#include <iostream>
#include <unordered_map>

using namespace std;

int longstCommnSpan(int a[], int b[], int n)
{
    int temp[n];
    for(int i=0; i<n; i++)
    {
        temp[i]=(a[i]-b[i]);
    }

    //Now, we will find the longest sub array having sum zero
    unordered_map<int, int>m;
    int pre_sum=0, res=0;
    for(int i=0; i<n ;i++)
    {
        pre_sum+=temp[i];

        if(pre_sum==0)
            res=i+1;
        
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
    int a[]={0,1,0,0,0,0};
    int b[]={1,0,0,1,0,1};
    cout<<longstCommnSpan(a, b, 6);
    

    return 0;
}
