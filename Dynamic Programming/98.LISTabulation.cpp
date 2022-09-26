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
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int ind = n-1; ind >=0; ind--){
            for(int prev = ind -1; prev>=-1; prev--){
                int res = dp[ind+1][prev+1];
                if(prev == -1 || nums[ind]>nums[prev]){
                    res = max(res, 1+dp[ind+1][ind+1]);
                }
                dp[ind][prev+1] = res;
            }
        }
      
        return dp[0][0];
    }
};

int main()
{


    return 0;
}