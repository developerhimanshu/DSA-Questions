#include <bits/stdc++.h>
using namespace std;
int frogJump(int n, vector<int> &heights)
{
     vector<int>dp(n, 0);
   int prev = 0, prev2 = 0;  //dp[i-1]=prev and dp[i-2]=prev2
     for(int i=1; i<n; i++){
        int fs = prev+abs(heights[i]-heights[i-1]);
         int ss =INT_MAX;
         if(i>1)
             ss = prev2+abs(heights[i]-heights[i-2]);
         int curr=min(fs, ss);
         prev2= prev;
         prev = curr;
     }
    return prev;
}
int main()
{
    vector<int>heights={10, 20, 30, 10 , 15};
    cout<<frogJump(5, heights);
    return 0;    
}
