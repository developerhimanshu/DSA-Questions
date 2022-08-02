#include <bits/stdc++.h>
using namespace std;

int kJumps(int n, vector<int>&heights, int k){
    vector<int>dp(n, 0);
    dp[0]=0;
    int minValue=INT_MAX;
    for(int i=1; i<n; i++)
    {
        for(int j = 1; j<=k; j++)
        {
            if(i-j>0){
                int jump = dp[i-j]+abs(heights[i]-heights[i-j]);
                minValue = min(jump, minValue);
            }
        }
        dp[i]=minValue;
    }
    return dp[n-1];
}

int main()
{


    return 0;
}
