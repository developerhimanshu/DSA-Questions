/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fn(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (ind >= prices.size())
            return 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        if (buy)
        {
            return dp[ind][buy] = max(-prices[ind] + fn(ind + 1, 0, prices, dp), fn(ind + 1, 1, prices, dp));
        }
        else
        {
            return dp[ind][buy] = max(prices[ind] + fn(ind + 2, 1, prices, dp), fn(ind + 1, 0, prices, dp));
        }
    }
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return fn(0, 1, prices, dp);
    }
};

int main()
{

    return 0;
}