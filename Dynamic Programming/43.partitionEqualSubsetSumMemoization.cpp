/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool targetS(int ind, int target, vector<int>&nums, vector<vector<int>>dp){
        if(target==0)return true;
        if(ind == 0)return (nums[ind]==target);
        if(dp[ind][target] != -1)return dp[ind][target];
        bool notPick = targetS(ind-1, target, nums, dp);
        bool pick = false;
        if(target>=nums[ind])
            pick = targetS(ind-1, target-nums[ind], nums, dp);
        return dp[ind][target] = pick|notPick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x:nums){
            sum+=x;
        }
        if(sum%2)return false;
        sum = sum/2;
        vector<vector<int>>dp(nums.size(), vector<int>(sum+1, -1));
        return targetS(nums.size()-1, sum, nums, dp);
    }
};

int main()
{

    return 0;
}