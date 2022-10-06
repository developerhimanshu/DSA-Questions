#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fn(int i, int j, vector<int>&nums, vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int maxi = INT_MIN;
        for(int ind = i; ind <=j; ind++){
            int cost = (nums[i-1]*nums[ind]*nums[j+1])+fn(i, ind-1, nums, dp)+fn(ind+1, j, nums, dp);
            // int maxi = max(maxi, cost);
            if(cost > maxi)maxi = cost;
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return fn(1, n, nums, dp);
    }
};

int main()
{
    return 0;
}