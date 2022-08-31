/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fn(int ind, int target, vector<int>&nums,  vector<vector<int>>&dp){
        if(ind==0){
            if(target == 0 && nums[ind] == 0)return 2;
            if(target == 0 || nums[ind] == target)return 1;
            return 0;
        }
        if(dp[ind][target] != -1)return dp[ind][target];
        int notPick = fn(ind-1, target, nums, dp);
        int pick = 0;
        if(target >= nums[ind])pick = fn(ind-1, target-nums[ind], nums, dp);
        return dp[ind][target] = pick+notPick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
   
        int sum = 0;
        for(auto x:nums)
            sum+=x;
        if(sum-target < 0 || (sum-target) % 2)return 0;
        vector<vector<int>>dp(n, vector<int>((sum-target)/2+1, -1));
        return fn(n-1, (sum-target)/2, nums, dp);
    }
};

int main()
{

    return 0;
}
