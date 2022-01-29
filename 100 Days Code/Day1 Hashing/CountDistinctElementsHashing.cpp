#include <iostream>
#include <unordered_set>

using namespace std;

int intersection(int a[], int b[], int m, int n)
{
    int res=0;
    unordered_set<int>s_a(a, a+m); //It also has inserted all the array a[] elements to the set
    for(int i=0; i<n; i++)
    {
        if(s_a.find(b[i])!=s_a.end())
        {
            res++;
            s_a.erase(b[i]);
        }
    }
    return res;
}
int main()
{
    int a[]={12, 32, 45, 12};
    int b[]={12, 43, 45};
    cout<<"The number of common elements on both the sets are: "<<intersection(a, b, 4, 3)<<endl;
    return 0;
}
