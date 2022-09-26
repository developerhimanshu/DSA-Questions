/*
    Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int lis(int ind, int prev, vector<int>&nums, vector<vector<int>>&dp){
    //     if(ind == nums.size())return 0;
    //     if(dp[ind][prev+1] != -1)return dp[ind][prev+1];
    //     int len = lis(ind+1, prev, nums, dp);
    //     if(prev == -1 || nums[ind]>nums[prev]){
    //         len = max(len,1+ lis(ind+1, ind, nums, dp));
    //     }
    //     return dp[ind][prev+1]=len;
    // }
    int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();
        vector<vector<int>>dp(n+2, vector<int>(n+1, 0));
        for(int i = n; i>=1; i--){
            for(int prev = i-1; prev >=0; prev--){
                int pick = -1e2;
                if(prev==0|| nums[i-1]>nums[prev-1]){
                    pick = 1+dp[i+1][i];
                }
                int notPick = dp[i+1][prev];
                dp[i][prev] = max(pick, notPick);
            }
        }
        return dp[1][0];
    }
};

int main()
{


    return 0;
}