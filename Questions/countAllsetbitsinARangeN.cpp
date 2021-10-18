#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int maxcountof2(int n)
    {
        int x=0;
        while((1<<x)<=n)
        {
            x++;
        }
        return x-1;
    }
    int countSetBits(int n)
    {
        if(n==0)
            return 0;
        int x=maxcountof2(n);
        int s1=x*(1<<(x-1));
        int s2=(n-(1<<x)+1);
        int s3=(n-(1<<x));
        int ans= s1+s2+countSetBits(s3);
        return ans;
    }
};

int main()
{
    int t;
    cout<<"Enter the total number of test cases: ";
    cin>>t;
  white(t--)
  {
    int n;
    cin>>n;
    Solution ob;
    cout<<ob.countSetBits(n);
  }  
  return 0;
}
