/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fn(int ind, bool buy, int fee, vector<int>&prices, vector<vector<int>>&dp){
        if(ind==prices.size())return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        if(buy){
            return dp[ind][buy] = max(-prices[ind]+fn(ind+1, 0, fee, prices, dp), fn(ind+1, 1, fee, prices, dp));
        }else{
            return dp[ind][buy] = max((prices[ind]-fee)+fn(ind+1, 1, fee, prices, dp), fn(ind+1, 0, fee, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
        return fn(0, 1, fee, prices, dp);
    }
};

int main()
{


    return 0;
}