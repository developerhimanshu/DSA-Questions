/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        for (int ind = prices.size() - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                    dp[ind][buy] = max((-prices[ind] + dp[ind + 1][0]), dp[ind + 1][1]);
                else
                    dp[ind][buy] = max(((prices[ind] - fee) + dp[ind + 1][1]), dp[ind + 1][0]);
            }
        }
        return dp[0][1];
    }
};

int main()
{

    return 0;
}