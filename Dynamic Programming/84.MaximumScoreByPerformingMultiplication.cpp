/*
    You are given two integer arrays nums and multipliers of size n and m respectively, where n >= m. The arrays are 1-indexed.

You begin with a score of 0. You want to perform exactly m operations. On the ith operation (1-indexed), you will:

Choose one integer x from either the start or the end of the array nums.
Add multipliers[i] * x to your score.
Remove x from the array nums.
Return the maximum score after performing m operations.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int fn(int m, int i, int n,vector<int>& nums, vector<int>& multi,vector<vector<int>>&dp){
        if(m==multi.size())
            return 0;
        if(dp[m][i]!=INT_MIN)return dp[m][i];
        
        int start = nums[i]*multi[m] + fn(m+1, i+1, n, nums, multi, dp);
        int end = nums[n]*multi[m] + fn(m+1,i,n-1, nums, multi, dp);
        return dp[m][i] = max(start, end);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int sz = multipliers.size(),  n =nums.size();
        // vector<vector<int>>dp(sz, vector<int>(n, -1));
    vector<vector<int>>dp(sz, vector<int>(sz, INT_MIN));
       return fn(0,0,n-1, nums, multipliers, dp); 
    }
};

int main()
{

    return 0;
}