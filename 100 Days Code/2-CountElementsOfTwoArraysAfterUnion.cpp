#include <iostream>
#include <unordered_set>
using namespace std;

int unionnum(int a[], int b[], int m, int n)
{
    unordered_set<int>s;
    for(int i=0; i<m; i++)    
        s.insert(a[i]);
    for(int i=0; i<n; i++)
        s.insert(b[i]);
    for(auto x:s)
        cout<<x<<" ";
    return s.size();
}
int main()
{
    int a[]={2,2,2,2,2};
    int b[]={1,1,1,1,1};
   cout<< unionnum(a, b, 4, 5);
    return 0;
}
