/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fn(int ind, int buy, vector<int>&prices, vector<vector<int>>&dp){
        if(ind == prices.size())return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        int profit;
        if(buy){
            profit = max((-prices[ind]+fn(ind+1, 0, prices, dp)), fn(ind+1, 1, prices, dp));
        }else{
            profit = max((prices[ind]+fn(ind+1, 1, prices, dp)), fn(ind+1, 0, prices, dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
        return fn(0, 1, prices, dp);
        
    }
};

int main()
{

    return 0;
}