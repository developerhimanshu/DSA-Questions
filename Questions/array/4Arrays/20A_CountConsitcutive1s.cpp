#include <iostream>
#include<cstring>
using namespace std;
int maxConsecutive1(bool str[],int length)
{
    int i=0, res=0;
    int count=0;
    while(i<length)
    {
        if(str[i]==0)
        {
            count=0;
        }
        else
        {
            count++;
            res=max(count, res);
        }
        i++;
    }
    return res;
}
int main()
{
    bool arr[]={1, 1, 0,0,1, 1, 1};
    cout<<maxConsecutive1(arr, 7);
    return 0;
}
