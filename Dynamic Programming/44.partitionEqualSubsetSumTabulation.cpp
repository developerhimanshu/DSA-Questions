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
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x:nums){
            sum+=x;
        }
        if(sum%2)return false;
        sum = sum/2;
        vector<vector<bool>>dp(nums.size(), vector<bool>(sum+1, 0));
        for(int ind = 0; ind<nums.size(); ind++){
            dp[ind][0]=true;
        }
        if(sum>=nums[0])dp[0][nums[0]]=true;
        for(int ind = 1; ind<nums.size(); ind++){
            for(int tar = 1; tar<=sum; tar++){
                bool notPick = dp[ind-1][tar];
                bool pick = false;
                if(tar>=nums[ind])
                    pick = dp[ind-1][tar-nums[ind]];
                dp[ind][tar] = pick|notPick;
            }
        }
        return dp[nums.size()-1][sum];
    }
};

int main()
{

    return 0;
}